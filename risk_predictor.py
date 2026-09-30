import sys
import pandas as pd
import numpy as np
from sklearn.cluster import KMeans
from sklearn.preprocessing import StandardScaler

def main():

    if len(sys.argv) != 2:      
        print("Usage: python risk_predictor.py <input_csv_file>")
        sys.exit(1)

    input_file = sys.argv[1]
    
    try:
        df = pd.read_csv(input_file)
    except FileNotFoundError:
        print(f"Error: The file '{input_file}' was not found.")
        sys.exit(1)
    
    # Clean column spaces and verify required columns exist
    df.columns = df.columns.str.strip()
    required_columns = ['gpa', 'backlogs']
    
    missing_cols = [col for col in required_columns if col not in df.columns]
    if missing_cols:
        print(f"Error: Missing required columns in CSV: {missing_cols}")
        sys.exit(1)

    # Handle missing values
    df = df.dropna(subset=required_columns)

    # Guard: K-Means needs enough data points to form clusters
    if len(df) < 3:
        print("Error: Dataset too small. Need at least 3 students to form clusters.")
        sys.exit(1)

    # 1. Extract features for clustering
    X = df[required_columns]
    
    # 2. Scale features (Crucial: backlogs are small numbers like 0-5, GPAs are larger. 
    # Scaling ensures GPA doesn't dominate the distance math).
    scaler = StandardScaler()
    X_scaled = scaler.fit_transform(X)


     # 3. Apply K-Means to find 3 distinct groups of students
    # (Safe, Moderate Risk, High Risk)
    kmeans = KMeans(n_clusters=3, random_state=42, n_init=10)
    df['ClusterID'] = kmeans.fit_predict(X_scaled)
    
    # 4. Automatically identify which cluster is the "At Risk" cluster.
    # The cluster with the lowest average GPA is mathematically our high-risk group.
    cluster_profiles = df.groupby('ClusterID')['gpa'].mean()
    at_risk_cluster = cluster_profiles.idxmin()
    safe_cluster = cluster_profiles.idxmax()
    
    # Map ClusterIDs to human-readable labels for your C program
    def label_cluster(cluster_id):
        if cluster_id == at_risk_cluster:
            return "High Risk"
        elif cluster_id == safe_cluster:
            return "Safe"
        else:
            return "Moderate Risk"


    df['RiskCategory'] = df['ClusterID'].apply(label_cluster)
    
    # Create a simple binary flag (1 for High Risk, 0 for others) to match your old C logic
    df['PredictedRisk'] = (df['ClusterID'] == at_risk_cluster).astype(int)

    # 5. Print a summary profile of the discovered groups to the console
    print("\n================ AI CLUSTER PROFILES ================")
    for cluster_num in sorted(df['ClusterID'].unique()):
        cluster_data = df[df['ClusterID'] == cluster_num]
        print(f"Group {label_cluster(cluster_num)} (Cluster {cluster_num}):")
        print(f"  - Count: {len(cluster_data)} students")
        print(f"  - Avg GPA: {cluster_data['gpa'].mean():.2f}")
        print(f"  - Avg Backlogs: {cluster_data['backlogs'].mean():.1f}\n")
    print("=====================================================\n")
        
    # Export results back to the C interface file
    output_file = "risk_output.csv"
    df.to_csv(output_file, index=False)
    print(f"Clustering complete. Results written to {output_file}")

if __name__ == "__main__":
    main()