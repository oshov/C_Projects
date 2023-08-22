#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a Student
struct Student {
    char name[50];
    int rollNumber;
    float CGPA;
};

// Function to read a Student object
void readStudent(struct Student *student) {
    printf("Enter name: ");
    scanf("%s", student->name);

    printf("Enter roll number: ");
    scanf("%d", &student->rollNumber);

    printf("Enter CGPA: ");
    scanf("%f", &student->CGPA);
}

// Function to display a Student object
void displayStudent(struct Student *student) {
    printf("Name: %s\n", student->name);
    printf("Roll Number: %d\n", student->rollNumber);
    printf("CGPA: %.2f\n", student->CGPA);
}

// Function to compare two Student objects for sorting
int compareStudents(const void *a, const void *b) {
    return ((struct Student *)a)->rollNumber - ((struct Student *)b)->rollNumber;
}

int main() {
    int numStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for an array of Student structures
    struct Student *students = (struct Student *)malloc(numStudents * sizeof(struct Student));

    // Read student details
    for (int i = 0; i < numStudents; i++) {
        printf("Enter details for student %d:\n", i + 1);
        readStudent(&students[i]);
    }

    // Display student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        displayStudent(&students[i]);
        printf("\n");
    }

    // Sort the array of students based on roll number
    qsort(students, numStudents, sizeof(struct Student), compareStudents);

    // Display sorted student details
    printf("\nSorted Student Details (by Roll Number):\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        displayStudent(&students[i]);
        printf("\n");
    }

    // Free allocated memory
    free(students);

    return 0;
}
