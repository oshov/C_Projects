#include <stdio.h>
#include <stdlib.h>

// Structure for Date of Birth
struct DOB {
    int day;
    int *month;
    int year;
};

// Structure for Student Information
struct STU_INFO {
    int reg_no;
    char *name;
    char *address;
};

// Structure for College Information
struct COLLEGE {
    char *college_name;
    char *university_name;
};

// Main STUDENT Structure
struct STUDENT {
    struct DOB *dob;
    struct STU_INFO *info;
    struct COLLEGE *college;
};

int main() {
    // Allocate memory for DOB, STU_INFO, and COLLEGE structures
    struct DOB *dob_ptr = (struct DOB *)malloc(sizeof(struct DOB));
    struct STU_INFO *info_ptr = (struct STU_INFO *)malloc(sizeof(struct STU_INFO));
    struct COLLEGE *college_ptr = (struct COLLEGE *)malloc(sizeof(struct COLLEGE));

    // Allocate memory for student structure
    struct STUDENT *student_ptr = (struct STUDENT *)malloc(sizeof(struct STUDENT));

    // Assign values to the DOB structure
    dob_ptr->day = 15;
    dob_ptr->month = (int *)malloc(sizeof(int));
    *(dob_ptr->month) = 8;  // Example month value (using pointer)
    dob_ptr->year = 2000;

    // Assign values to the STU_INFO structure
    info_ptr->reg_no = 12345;
    info_ptr->name = "John Doe";
    info_ptr->address = "123 Main St, City";

    // Assign values to the COLLEGE structure
    college_ptr->college_name = "MIT Manipal";
    college_ptr->university_name = "Manipal Academy of Higher Education";

    // Assign structures to the student_ptr
    student_ptr->dob = dob_ptr;
    student_ptr->info = info_ptr;
    student_ptr->college = college_ptr;

    // Display student information
    printf("Student Name: %s\n", student_ptr->info->name);
    printf("Registration Number: %d\n", student_ptr->info->reg_no);
    printf("Address: %s\n", student_ptr->info->address);
    printf("Date of Birth: %d-%d-%d\n", student_ptr->dob->day, *(student_ptr->dob->month), student_ptr->dob->year);
    printf("College: %s\n", student_ptr->college->college_name);
    printf("University: %s\n", student_ptr->college->university_name);

    // Free allocated memory
    free(dob_ptr->month);
    free(dob_ptr);
    free(info_ptr);
    free(college_ptr);
    free(student_ptr);

    return 0;
}
