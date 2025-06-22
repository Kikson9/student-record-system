#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char id[20];
    char grade;
} Student;

// Removes trailing newline from input
void trimNewline(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}

// Validates that the student ID is exactly 10 digits
int isValidID(const char *id) {
    return strlen(id) == 10 && strspn(id, "0123456789") == 10;
}

// Gets student input and validates grade and ID
void inputStudent(Student *s) {
    char gradeInput[10];
    int validGrade = 0;

    printf("What's the student's full name? ");
    fgets(s->name, sizeof(s->name), stdin);
    trimNewline(s->name);

    while (1) {
        printf("Enter the student's ID (10 digits): ");
        fgets(s->id, sizeof(s->id), stdin);
        trimNewline(s->id);
        if (isValidID(s->id)) break;
        printf("Invalid ID. Please enter exactly 10 digits.\n");
    }

    while (!validGrade) {
        printf("What grade did the student get (A-F)? ");
        fgets(gradeInput, sizeof(gradeInput), stdin);
        trimNewline(gradeInput);
        s->grade = gradeInput[0];

        if ((s->grade >= 'A' && s->grade <= 'F') || (s->grade >= 'a' && s->grade <= 'f')) {
            validGrade = 1;
        } else {
            printf("Invalid grade. Please enter a letter between A and F.\n");
        }
    }
}

// Maps grade to performance message
void printPerformanceLevel(char grade) {
    switch (grade) {
        case 'A': case 'a': printf("Performance Level: Excellent\n"); break;
        case 'B': case 'b': printf("Performance Level: Good\n"); break;
        case 'C': case 'c': printf("Performance Level: Fair\n"); break;
        case 'D': case 'd': printf("Performance Level: Needs Improvement\n"); break;
        case 'F': case 'f': printf("Performance Level: Failed\n"); break;
        default: printf("Unknown grade entered.\n");
    }
}

// Prints all student info
void printStudent(Student *s, int index) {
    printf("\n---- Student %d Info ----\n", index + 1);
    printf("Name: %s\n", s->name);
    printf("ID: %s\n", s->id);
    printf("Grade: %c\n", s->grade);
    printPerformanceLevel(s->grade);
}

// Saves student list to binary file
void saveToFile(Student *list, int count, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error saving file.\n");
        return;
    }
    fwrite(&count, sizeof(int), 1, fp);
    fwrite(list, sizeof(Student), count, fp);
    fclose(fp);
    printf("Data saved to file.\n");
}

// Loads student list from binary file
void loadFromFile(Student **list, int *count, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("No file found. Starting fresh.\n");
        return;
    }
    fread(count, sizeof(int), 1, fp);
    *list = malloc(sizeof(Student) * (*count));
    if (*list == NULL) {
        printf("Memory allocation failed while loading.\n");
        fclose(fp);
        exit(1);
    }
    fread(*list, sizeof(Student), *count, fp);
    fclose(fp);
    printf("Data loaded from file.\n");
}

// Exports student list to readable text file
void exportToTextFile(Student *list, int count, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating text file.\n");
        return;
    }

    fprintf(fp, "==== Student Report ====\n\n");
    for (int i = 0; i < count; i++) {
        fprintf(fp, "Student %d\n", i + 1);
        fprintf(fp, "Name: %s\n", list[i].name);
        fprintf(fp, "ID: %s\n", list[i].id);
        fprintf(fp, "Grade: %c\n", list[i].grade);

        switch (list[i].grade) {
            case 'A': case 'a': fprintf(fp, "Performance: Excellent\n"); break;
            case 'B': case 'b': fprintf(fp, "Performance: Good\n"); break;
            case 'C': case 'c': fprintf(fp, "Performance: Fair\n"); break;
            case 'D': case 'd': fprintf(fp, "Performance: Needs Improvement\n"); break;
            case 'F': case 'f': fprintf(fp, "Performance: Failed\n"); break;
            default: fprintf(fp, "Performance: Unknown\n");
        }

        fprintf(fp, "-------------------------\n");
    }

    fclose(fp);
    printf("Student report saved to %s\n", filename);
}

int main() {
    Student *students = NULL;
    int studentCount = 0;
    int choice;
    const char *filename = "students.dat";

    loadFromFile(&students, &studentCount, filename);

    while (1) {
        printf("\n==== Student Management Menu ====\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Save to File\n");
        printf("4. Load from File\n");
        printf("5. Export to TXT\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume leftover newline

        switch (choice) {
            case 1:
                students = realloc(students, sizeof(Student) * (studentCount + 1));
                if (students == NULL) {
                    printf("Memory allocation failed.\n");
                    exit(1);
                }
                inputStudent(&students[studentCount]);
                studentCount++;
                break;
            case 2:
                if (studentCount == 0) {
                    printf("No students to show.\n");
                } else {
                    printf("Total students: %d\n", studentCount);
                    for (int i = 0; i < studentCount; i++) {
                        printStudent(&students[i], i);
                    }
                }
                break;
            case 3:
                saveToFile(students, studentCount, filename);
                break;
            case 4:
                free(students);
                students = NULL;
                studentCount = 0;
                loadFromFile(&students, &studentCount, filename);
                break;
            case 5:
                exportToTextFile(students, studentCount, "student_report.txt");
                break;
            case 6:
                saveToFile(students, studentCount, filename);
                free(students);
                printf("Exiting... Bye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
