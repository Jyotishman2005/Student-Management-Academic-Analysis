#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LENGTH 50

typedef struct
{
    char name[NAME_LENGTH];
    int semester;
    int year;
    int studentID;
    int backlogs;
    char department[NAME_LENGTH];
    float gpa;
} Student;

void inputStudent(Student *students);
void printStudent(const Student* students, int n);
void updateStudent(Student *students, int n);

//CSV Import and Export functions
void exportToCSV(const Student* students, int n, const char* filename);
void importFromCSV(Student* students, int* n, int maxCapacity,const char* filename);
void updateStudentInCSV(const char* filename, int studentID);

#endif // STUDENT_H
