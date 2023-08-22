#include <stdio.h>

// Define the structure for Date of Birth
struct Date {
    int day;
    int month;
    int year;
};

// Define the structure for Address
struct Address {
    int houseNumber;
    int zipCode;
    char state[50];
};

// Define the structure for Employee
struct Employee {
    char name[50];
    struct Date dob;
    struct Address address;
};

int main() {
    int N;
    printf("Enter the number of employees: ");
    scanf("%d", &N);

    // Declare an array of structures
    struct Employee employees[N];

    // Input data for each employee
    for (int i = 0; i < N; i++) {
        printf("\nEmployee %d:\n", i + 1);
        
        printf("Enter name: ");
        scanf("%s", employees[i].name);
        
        printf("Enter date of birth (day, month, year): ");
        scanf("%d %d %d", &employees[i].dob.day, &employees[i].dob.month, &employees[i].dob.year);
        
        printf("Enter address (house number, zip code, state): ");
        scanf("%d %d %s", &employees[i].address.houseNumber, &employees[i].address.zipCode, employees[i].address.state);
    }

    // Display data for each employee using pointers
    printf("\nEmployee data:\n");
    for (int i = 0; i < N; i++) {
        struct Employee *ptr = &employees[i];
        
        printf("\nEmployee %d:\n", i + 1);
        printf("Name: %s\n", ptr->name);
        printf("Date of Birth: %d/%d/%d\n", ptr->dob.day, ptr->dob.month, ptr->dob.year);
        printf("Address: %d, %d, %s\n", ptr->address.houseNumber, ptr->address.zipCode, ptr->address.state);
    }

    return 0;
}
