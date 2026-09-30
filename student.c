#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void inputStudent(Student* student) {
    printf("Enter student name: ");
    fgets(student->name, NAME_LENGTH, stdin);
    student->name[strcspn(student->name, "\n")] = 0; // Remove newline character

    printf("Enter semester: ");
    scanf("%d", &student->semester);

    printf("Enter year: ");
    scanf("%d", &student->year);

    printf("Enter student ID: ");
    scanf("%d", &student->studentID);

    printf("Enter number of backlogs: ");
    scanf("%d", &student->backlogs);
    getchar(); // Consume the newline character left by scanf

    printf("Enter department: ");
    fgets(student->department, NAME_LENGTH, stdin);
    student->department[strcspn(student->department, "\n")] = 0; // Remove newline character

    printf("Enter GPA: ");
    scanf("%f", &student->gpa);
}

void printStudent(const Student* student, int n) {
    printf("\nStudent Details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", student[i].name);
        printf("Semester: %d\n", student[i].semester);
        printf("Year: %d\n", student[i].year);
        printf("Student ID: %d\n", student[i].studentID);
        printf("Backlogs: %d\n", student[i].backlogs);
        printf("Department: %s\n", student[i].department);
        printf("GPA: %.2f\n", student[i].gpa);
    }
}

void updateStudent(Student *student, int n) {
    int id;
    printf("Enter the student ID to update: ");
    scanf("%d", &id);
    getchar(); // Consume the newline character left by scanf

    for (int i = 0; i < n; i++) {
        if (student[i].studentID == id) {
            printf("Updating details for student ID %d:\n", id);
            printf("What do you want to update?\n");
            printf("1. Name\n");
            printf("2. Semester\n");
            printf("3. Year\n");
            printf("4. Backlogs\n");
            printf("5. Department\n");
            printf("6. GPA\n");
            int choice;
            printf("Enter your choice: ");
            scanf("%d", &choice);
            getchar(); // Consume the newline character left by scanf

            switch (choice) {
                case 1:
                    printf("Enter new name: ");
                    fgets(student[i].name, NAME_LENGTH, stdin);
                    student[i].name[strcspn(student[i].name, "\n")] = 0; // Remove newline character
                    break;
                case 2:
                    printf("Enter new semester: ");
                    scanf("%d", &student[i].semester);
                    getchar(); // Consume the newline character left by scanf   
                    break;
                case 3:
                    printf("Enter new year: ");
                    scanf("%d", &student[i].year);
                    getchar(); // Consume the newline character left by scanf
                    break;
                case 4:
                    printf("Enter new number of backlogs: ");
                    scanf("%d", &student[i].backlogs);
                    getchar(); // Consume the newline character left by scanf   
                    break;
                case 5:
                    printf("Enter new department: ");
                    fgets(student[i].department, NAME_LENGTH, stdin);
                    student[i].department[strcspn(student[i].department, "\n")] = 0;
                    break;
                case 6:
                    printf("Enter new GPA: ");
                    scanf("%f", &student[i].gpa);
                    getchar(); // Consume the newline character left by scanf
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}



