#include "student.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int studentexistcheck(int studentID, const char* filename){
    
    FILE* fp = fopen(filename, "r");
    if(fp == NULL) return -1; //file doesnt exist
    
    char input[256];
    fgets(input, sizeof(input), fp); //skipping the header by reading it as inout before actual loop starts
    
    int count = 0;
    
    while(fgets(input, sizeof(input), fp) != NULL){
        char inputcopy[256];
        strncpy(inputcopy, input, sizeof(inputcopy));
        
        //start tokenizing till we extract the studentID
        strtok(inputcopy, ","); //extracted name
        strtok(NULL, ",");       //extracted semester
        strtok(NULL, ",");      //extracted year
        
        char* ID_token = strtok(NULL,","); //extracted student ID into a variable
        
        if(ID_token != NULL && atoi(ID_token)==studentID){
            fclose(fp);
            return count; //found match.....already existing record
        }
        count++;
    }
    
    fclose(fp);
    return -1;
}


void exportToCSV(const Student* students, int n, const char* filename) {
    
    int file_has_content = 0;
    
    FILE* checkfp = fopen(filename, "r");
    if(checkfp != NULL) {
        fseek(checkfp, 0, SEEK_END);
        if(ftell(checkfp)>0) file_has_content = 1;
        fclose(checkfp);
    }
    
    FILE* fp = fopen(filename, "a"); // append mode
    if (fp == NULL) {
        printf("Error: could not open '%s' for writing.\n", filename);
        return;
    }

    if (!file_has_content) {
        fprintf(fp, "Name,Semester,Year,StudentID,Backlogs,Department,GPA\n");
    }
    
    int addedCount = 0, skippedCount = 0;
    
    for (int i = 0; i < n; i++) {
    
        if (studentexistcheck(students[i].studentID, filename) != -1) {
            skippedCount++;
            continue;
        }
        fprintf(fp, "%s,%d,%d,%d,%d,%s,%.2f\n",
                students[i].name,
                students[i].semester,
                students[i].year,
                students[i].studentID,
                students[i].backlogs,
                students[i].department,
                students[i].gpa);
        addedCount++;
    }
    
    fclose(fp);
    printf("Export done: %d new record(s) added, %d duplicate(s) skipped.\n", addedCount, skippedCount);
    
}


void updateStudentInCSV(const char* filename, int studentID) {
    int pos = studentexistcheck(studentID, filename);
    if (pos == -1) {
        printf("No student found with ID %d in '%s'.\n", studentID, filename);
        return;
    }

    Student updated;
    updated.studentID = studentID; // ID stays the same, that's how we find the record

    printf("Enter updated details for student ID %d:\n", studentID);

    printf("Enter student name: ");
    fgets(updated.name, NAME_LENGTH, stdin);
    updated.name[strcspn(updated.name, "\n")] = 0;

    printf("Enter semester: ");
    scanf("%d", &updated.semester);
    printf("Enter year: ");
    scanf("%d", &updated.year);
    printf("Enter number of backlogs: ");
    scanf("%d", &updated.backlogs);
    getchar();

    printf("Enter department: ");
    fgets(updated.department, NAME_LENGTH, stdin);
    updated.department[strcspn(updated.department, "\n")] = 0;

    printf("Enter GPA: ");
    scanf("%f", &updated.gpa);
    getchar();

    // Rewrite the file, replacing only the matching line
    const char* tempFilename = "temp_update.csv";
    FILE* oldFp = fopen(filename, "r");
    FILE* tempFp = fopen(tempFilename, "w");

    if (oldFp == NULL || tempFp == NULL) {
        printf("Error opening files for update.\n");
        if (oldFp) fclose(oldFp);
        if (tempFp) fclose(tempFp);
        return;
    }

    char line[256];
    fgets(line, sizeof(line), oldFp); // copy header unchanged
    fputs(line, tempFp);

    while (fgets(line, sizeof(line), oldFp) != NULL) {
        char parseCopy[256];
        strncpy(parseCopy, line, sizeof(parseCopy));

        strtok(parseCopy, ",");             // name
        strtok(NULL, ",");                  // semester
        strtok(NULL, ",");                  // year
        char* idToken = strtok(NULL, ",");  // studentID
        int existingID = (idToken != NULL) ? atoi(idToken) : -1;

        if (existingID == studentID) {
            // write the new data instead of copying the old line
            fprintf(tempFp, "%s,%d,%d,%d,%d,%s,%.2f\n",
                    updated.name, updated.semester, updated.year,
                    updated.studentID, updated.backlogs,
                    updated.department, updated.gpa);
        } else {
            fputs(line, tempFp); // unrelated line, copy as-is
        }
    }

    fclose(oldFp);
    fclose(tempFp);
    remove(filename);
    rename(tempFilename, filename);

    printf("Student ID %d updated successfully in '%s'.\n", studentID, filename);
}


void importFromCSV(Student* students, int* n, int maxCapacity, const char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open '%s' for reading.\n", filename);
        return;
    }

    char line[256];

    // Skip header row
    if (fgets(line, sizeof(line), fp) == NULL) {
        fclose(fp);
        printf("File is empty.\n");
        return;
    }

    int importedCount = 0;

    while (*n < maxCapacity && fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\n")] = 0;
        if (strlen(line) == 0) continue; // skip blank lines

        char* token;
        Student temp;

        token = strtok(line, ",");
        if (token == NULL) continue;
        strncpy(temp.name, token, NAME_LENGTH - 1);
        temp.name[NAME_LENGTH - 1] = 0;

        token = strtok(NULL, ","); if (token == NULL) continue;
        temp.semester = atoi(token);

        token = strtok(NULL, ","); if (token == NULL) continue;
        temp.year = atoi(token);

        token = strtok(NULL, ","); if (token == NULL) continue;
        temp.studentID = atoi(token);

        token = strtok(NULL, ","); if (token == NULL) continue;
        temp.backlogs = atoi(token);

        token = strtok(NULL, ","); if (token == NULL) continue;
        strncpy(temp.department, token, NAME_LENGTH - 1);
        temp.department[NAME_LENGTH - 1] = 0;

        token = strtok(NULL, ","); if (token == NULL) continue;
        temp.gpa = atof(token);

        students[*n] = temp; // write at current count position
        (*n)++;              // advance the caller's count
        importedCount++;
    }

    fclose(fp);

    if (*n == maxCapacity) {
        printf("Warning: array full. Some rows in the file may not have been imported.\n");
    }
    printf("Imported %d new student record(s) from '%s'. Total students now: %d\n", importedCount, filename, *n);
}