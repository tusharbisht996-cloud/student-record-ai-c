
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Student {
    long long sapID;
    int rollNo;
    char name[50];
    char phone[15];
    char email[60];
    int year;
    int semester;
    float sgpa[8];
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("\nStudent limit reached!\n");
        return;
    }

    printf("\nEnter SAP ID: ");
    scanf("%lld", &students[count].sapID);

    printf("Enter Roll Number: ");
    scanf("%d", &students[count].rollNo);

    printf("Enter Name: ");
    scanf(" %49[^\n]", students[count].name);

    printf("Enter Phone Number: ");
    scanf("%14s", students[count].phone);

    printf("Enter Email ID: ");
    scanf("%59s", students[count].email);

    printf("Enter Year (1-4): ");
    scanf("%d", &students[count].year);

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &students[count].semester);

    for (int i = 0; i < 8; i++) {
        students[count].sgpa[i] = -1;
    }

    printf("\nEnter SGPA for completed semesters:\n");

    for (int i = 0; i < students[count].semester; i++) {
        printf("Semester %d SGPA: ", i + 1);
        scanf("%f", &students[count].sgpa[i]);
    }

    count++;

    printf("\nStudent added successfully!\n");
}

void displayAllStudents() {
    if (count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n========== STUDENT RECORDS ==========\n");

    for (int i = 0; i < count; i++) {
        printf("\nSAP ID: %lld\n", students[i].sapID);
        printf("Roll Number: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Phone: %s\n", students[i].phone);
        printf("Email: %s\n", students[i].email);
        printf("Year: %d\n", students[i].year);
        printf("Semester: %d\n", students[i].semester);

        printf("SGPA values: ");

        for (int j = 0; j < 8; j++) {
            if (students[i].sgpa[j] >= 0) {
                printf("%.2f ", students[i].sgpa[j]);
            }
        }

        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n====================================\n");
        printf(" STUDENT RECORD MANAGEMENT SYSTEM\n");
        printf("====================================\n");
        printf("1. Add Student Details\n");
        printf("2. Display All Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayAllStudents();
                break;

            case 3:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while (choice != 3);

    return 0;
}
