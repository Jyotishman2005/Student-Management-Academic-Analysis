#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the number of Students: ");
    scanf("%d", &n);

    Student* s = malloc(n * sizeof(Student)); // Dynamically allocate memory for n students
    if(s == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit if memory allocation fails
    }

    int i = 0;
    int choice;


    printf("\nMenu:\n");
    printf("1. Input Student Details\n");
    printf("2. Print Student Details\n");
    printf("3. Update Student (in memory)\n");
    printf("4. Export to CSV\n");
    printf("5. Import from CSV\n");
    printf("6. Update Student in CSV file\n");
    printf("7. Show Menu Again\n");
    printf("8. Exit\n");

    do {

        printf("\nPress 7 to see the menu again.\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character left by scanf

        switch (choice) {
            case 1:
                if (i < n) {
                    inputStudent(&s[i]);
                    i++;
                } else {
                    printf("No more space for students!\n");
                }
                break;
            case 2:
                printStudent(s, i);
                break;
            case 3:
                updateStudent(s, i);
                break;
            case 4:{
                char filename[100];                // Buffer to hold the filename, only active within this case
                printf("Enter filename to export (e.g. students.csv): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                exportToCSV(s, i, filename); // just pass all current students, dedup handled internally
                break;
            }
            case 5:{
                char filename[100];         // Buffer to hold the filename, only active within this case
                printf("Enter filename to import (e.g. students.csv): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;
                importFromCSV(s, &i, n, filename); // pass address of i, and n as maxCapacity
                break;
            }
            case 6:{
                printf("Updating student records in CSV...\n");

                char filename[100];               // Buffer to hold the filename, only active within this case
                int idToUpdate;
                printf("Enter filename (e.g. students.csv): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;

                printf("Enter student ID to update: ");
                scanf("%d", &idToUpdate);
                getchar();

                updateStudentInCSV(filename, idToUpdate);
                break;
            }
            case 7:
                printf("\nMenu:\n");
                printf("1. Input Student Details\n");
                printf("2. Print Student Details\n");
                printf("3. Update Student (in memory)\n");
                printf("4. Export to CSV\n");
                printf("5. Import from CSV\n");
                printf("6. Update Student in CSV file\n");
                printf("7. Show Menu Again\n");
                printf("8. Exit\n");
                break;
            case 8:
                printf("Exiting.........\n");
                break;
            
            case 9:{
                char filename[100];               // Buffer to hold the filename, only active within this case
                printf("Enter filename (e.g. students.csv): ");
                fgets(filename, sizeof(filename), stdin);
                filename[strcspn(filename, "\n")] = 0;

                char cmd[200];
                snprintf(cmd, sizeof(cmd), "risk_predictor.py %s", filename);

                int result = system(cmd);
                if(result != 0){
                    printf("Error executing the Python script. Please ensure Python is installed and the script exists.\n");
                    break;
                }

                printf("\nRisk analysis complete. Reading results from risk_output.csv:\n\n");
                FILE* fp = fopen("risk_output.csv", "r");
                if (fp != NULL) {
                    char line[512];
                    while (fgets(line, sizeof(line), fp) != NULL) {
                        printf("%s", line);
                    }
                    fclose(fp);
                } else {
                    printf("Could not open risk_output.csv\n");
                }
                break;
            }
            default:
                printf("Invalid choice! Please try again.\n");

                printf("\nMenu:\n");
                printf("1. Input Student Details\n");
                printf("2. Print Student Details\n");
                printf("3. Update Student (in memory)\n");
                printf("4. Export to CSV\n");
                printf("5. Import from CSV\n");
                printf("6. Update Student in CSV file\n");
                printf("7. Show Menu Again\n");
                printf("8. Exit\n");
                break;
        }
    } while (choice != 9);

    free(s); // Free the dynamically allocated memory
    return 0;
}