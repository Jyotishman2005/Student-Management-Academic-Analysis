# Student Management & Academic Risk Analysis System

A modular **C + Python application** for managing student academic records, storing data through CSV files, and analyzing academic patterns using machine learning.

The project combines **systems programming in C** with a **Python-based data analysis and machine learning pipeline** to create a practical academic management and risk-analysis system.

---

## 📌 Overview

The **Student Management & Academic Risk Analysis System** is designed to manage student records efficiently while providing an additional layer of academic analysis.

The C application handles the core student management functionality, including:

* Adding student records
* Viewing student records
* Searching for students
* Updating student information
* Deleting records
* Validating student IDs and input
* Detecting duplicate student IDs
* Saving and loading records using CSV files

A separate Python module processes academic information and performs data analysis to identify patterns associated with academic performance.

The long-term goal of the project is to build a complete pipeline:

```text
Student Data
     │
     ▼
C Student Management System
     │
     ▼
CSV Data Storage
     │
     ▼
Python Data Processing
     │
     ▼
Machine Learning / Academic Analysis
     │
     ▼
Risk Analysis Output
     │
     ▼
C Application
```

---

## ✨ Features

### Student Management

* Add new student records
* Display stored student information
* Search students using their ID
* Update existing records
* Delete student records
* Handle multiple student records dynamically

### Data Management

* CSV-based persistent storage
* Structured student records using C `struct`
* Dynamic memory allocation
* CSV output generated for analysis
* Duplicate ID detection
* Input validation and error handling

### Academic Analysis

The Python component is designed to analyze academic information such as:

* GPA / academic performance
* Backlog information
* Other relevant academic attributes

The current analysis pipeline includes:

* Data loading
* Data preprocessing
* Feature preparation
* Feature scaling
* Clustering
* Academic pattern analysis
* Risk-related output generation

---

## 🛠️ Technology Stack

### Core Application

* **C**
* Structures
* Pointers
* Dynamic Memory Allocation
* File Handling
* Modular Programming
* CSV Processing

### Data Analysis & Machine Learning

* **Python**
* **Pandas**
* **NumPy**
* **Scikit-learn**
* **StandardScaler**
* **K-Means Clustering**

### Data Storage

* CSV

---

## 📂 Project Structure

```text
Student-Management-System/
│
├── main.c
├── student.c
├── student.h
├── csvopn.c
│
├── risk_predictor.py
│
├── data/
│   └── students.csv
│
├── output/
│   └── risk_output.csv
│
├── README.md
└── LICENSE
```

> The exact file/folder structure may change as the project is further developed.

---

## 🔄 How It Works

### 1. Student Data Entry

The user interacts with the C application through a menu-driven interface.

```text
┌─────────────────────────┐
│ Student Management      │
│ System                  │
└────────────┬────────────┘
             │
             ▼
       Add / View / Search
       Update / Delete
             │
             ▼
       Student Records
```

### 2. Data Persistence

Student information is stored in CSV format so that records remain available after the program terminates.

```text
C Program
    │
    ▼
Student Records
    │
    ▼
CSV File
```

### 3. Academic Analysis

The Python module reads the relevant academic data and prepares it for analysis.

```text
CSV Dataset
     │
     ▼
Data Loading
     │
     ▼
Preprocessing
     │
     ▼
Feature Scaling
     │
     ▼
K-Means Clustering
     │
     ▼
Academic Pattern Analysis
```

### 4. Risk Analysis Output

The analysis produces an output dataset containing the results of the academic analysis.

This output can then be consumed by the C application or inspected separately.

---

## 🧠 Machine Learning Component

The current ML component primarily uses **unsupervised learning** through **K-Means clustering**.

The purpose is to identify groups of students with similar academic characteristics.

For example:

```text
Academic Dataset
       │
       ▼
 Feature Selection
       │
       ▼
 StandardScaler
       │
       ▼
 K-Means
       │
       ▼
 ┌─────────────┐
 │ Cluster 0   │
 │ Cluster 1   │
 │ Cluster 2   │
 └─────────────┘
```

The resulting clusters can then be interpreted based on academic characteristics such as GPA and backlog-related information.

> **Note:** Cluster labels are analytical groupings rather than guaranteed predictions of a student's future academic performance.

---

## 💻 Getting Started

### Prerequisites

Make sure you have:

* A C compiler such as GCC
* Python 3.x
* pip

### Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/student-management-system.git
cd student-management-system
```

### Compile the C Application

Using GCC:

```bash
gcc main.c student.c csvopn.c -o student_management
```

Run:

```bash
./student_management
```

On Windows:

```bash
student_management.exe
```

---

## 🐍 Python Setup

Create a virtual environment:

```bash
python -m venv venv
```

Activate it on Windows:

```bash
venv\Scripts\activate
```

Install the required libraries:

```bash
pip install pandas numpy scikit-learn
```

Run the analysis:

```bash
python risk_predictor.py
```

---

## 📊 Example Workflow

A typical workflow looks like:

```text
1. Start the C application
          │
          ▼
2. Add / modify student records
          │
          ▼
3. Save records to CSV
          │
          ▼
4. Run Python analysis
          │
          ▼
5. Preprocess academic data
          │
          ▼
6. Perform clustering / analysis
          │
          ▼
7. Generate risk analysis output
          │
          ▼
8. Review results
```

---

## 🔐 Data Privacy

This project is intended for **educational and demonstration purposes**.

Do not upload real student information containing:

* Names
* Student IDs
* Phone numbers
* Email addresses
* Personal academic records
* Other personally identifiable information

Use **synthetic or anonymized data** when publishing datasets to GitHub.

---

## 🚧 Current Development Status

The project is currently under active development.

### Completed / Implemented

* [x] Student record structure
* [x] Modular C source files
* [x] Student CRUD operations
* [x] CSV-based data storage
* [x] Student search functionality
* [x] Record update functionality
* [x] Duplicate ID handling
* [x] Python-based academic analysis
* [x] Data preprocessing
* [x] Feature scaling
* [x] K-Means clustering
* [x] Risk analysis output

### 🔨 Planned Improvements

* [ ] Improve CSV parser robustness
* [ ] Strengthen input validation
* [ ] Improve error handling
* [ ] Improve C project architecture
* [ ] Add more comprehensive testing
* [ ] Add automated data validation
* [ ] Evaluate multiple ML algorithms
* [ ] Introduce supervised learning for actual risk prediction
* [ ] Add proper model evaluation metrics
* [ ] Improve integration between C and Python
* [ ] Add documentation and usage examples
* [ ] Add unit tests
* [ ] Improve reporting and visualization

---

## 📈 Future ML Pipeline

A future version of the project may move from exploratory clustering toward a properly evaluated supervised learning pipeline.

Potential architecture:

```text
Student Academic Data
          │
          ▼
   Data Validation
          │
          ▼
   Data Preprocessing
          │
          ▼
 Feature Engineering
          │
          ▼
 Train / Test Split
          │
          ▼
 ┌──────────────────────┐
 │ Classification Models│
 └──────────┬───────────┘
            │
            ▼
     Model Evaluation
            │
            ▼
 Academic Risk Prediction
```

Potential evaluation metrics include:

* Accuracy
* Precision
* Recall
* F1-score
* Confusion Matrix

The choice of model and evaluation strategy will depend on the availability and quality of labeled academic data.

---

## 🎯 Learning Objectives

This project is also being developed as a hands-on learning project covering:

### C Programming

* Structures
* Pointers
* Dynamic memory
* File handling
* Modular programming
* Input validation
* Data persistence

### Software Development

* Project organization
* Separation of responsibilities
* Error handling
* Debugging
* Incremental development
* Version control with Git

### Data Science & Machine Learning

* Data preprocessing
* Feature scaling
* Clustering
* Feature engineering
* Model evaluation
* Interpreting ML results

---

## 📚 Project Motivation

The project was created as a practical way to combine **C programming, data management, and machine learning** into one application.

Instead of treating these topics as separate exercises, the project connects them into a single workflow:

```text
Systems Programming
        +
Data Management
        +
Data Science
        +
Machine Learning
        ↓
Integrated Academic Management System
```

---

## ⚠️ Disclaimer

The academic risk analysis component is intended for **educational and experimental purposes**.

Machine learning outputs should not be treated as definitive judgments about a student's academic future. Results depend heavily on the quality, quantity, and characteristics of the underlying dataset.

---

## 📜 License

This project is licensed under the **MIT License**.

See the [`LICENSE`](LICENSE) file for details.

---

## 👨‍💻 Author

**Jyotishman Das**

B.Tech Computer Science & Engineering Student

Interested in:

* Systems Programming
* C / C++
* Data Science & Machine Learning
* High Performance Computing
* VLSI / Computer Architecture
* Research & Graduate Studies

---

⭐ If you find this project useful or interesting, consider giving the repository a star.
