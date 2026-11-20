
#include <stdio.h>
#include <string.h>

struct Student {
    long long sap;
    int roll, year, semester;
    char name[50], phone[15], email[50];
    float sgpa[8];
};

struct Student students[100];
int count = 0;

float calculateCGPA(struct Student s) {
    float total = 0;
    int subjects = 0;

    for (int i = 0; i < 8; i++) {
        if (s.sgpa[i] >= 0) {
            total += s.sgpa[i];
            subjects++;
        }
    }

    if (subjects == 0) return 0;
    return total / subjects;
}

void addStudent() {
    if (count >= 100) {
        printf("Student limit reached!\n");
        return;
    }

    struct Student s;

    printf("Enter SAP ID: ");
    scanf("%lld", &s.sap);

    printf("Enter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Phone: ");
    scanf("%14s", s.phone);

    printf("Enter Email: ");
    scanf("%49s", s.email);

    printf("Enter Year (1-4): ");
    scanf("%d", &s.year);

    printf("Enter Current Semester (1-8): ");
    scanf("%d", &s.semester);

    for (int i = 0; i < 8; i++) {
        s.sgpa[i] = -1;
    }

    for (int i = 0; i < s.semester && i < 8; i++) {
        printf("Enter SGPA for Semester %d: ", i + 1);
        scanf("%f", &s.sgpa[i]);
    }

    students[count++] = s;
    printf("Student added successfully!\n");
}

void displayStudent(struct Student s) {
    printf("\nSAP ID: %lld\n", s.sap);
    printf("Roll Number: %d\n", s.roll);
    printf("Name: %s\n", s.name);
    printf("Phone: %s\n", s.phone);
    printf("Email: %s\n", s.email);
    printf("Year: %d\n", s.year);
    printf("Current Semester: %d\n", s.semester);
    printf("CGPA: %.2f\n", calculateCGPA(s));
}

void displayAllStudents() {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        displayStudent(students[i]);
    }
}

void searchStudent() {
    long long id;
    printf("Enter SAP ID to search: ");
    scanf("%lld", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].sap == id) {
            displayStudent(students[i]);
            return;
        }
    }

    printf("Student not found.\n");
}

void deleteStudent() {
    long long id;
    printf("Enter SAP ID to delete: ");
    scanf("%lld", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].sap == id) {
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

void averageCGPAByYear() {
    for (int year = 1; year <= 4; year++) {
        float total = 0;
        int number = 0;

        for (int i = 0; i < count; i++) {
            if (students[i].year == year) {
                total += calculateCGPA(students[i]);
                number++;
            }
        }

        if (number > 0)
            printf("Year %d Average CGPA: %.2f\n",
                   year, total / number);
        else
            printf("Year %d: No student records.\n", year);
    }
}

void sortBySAP() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].sap > students[j + 1].sap) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Students sorted by SAP ID.\n");
    displayAllStudents();
}

void sortByName() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (strcmp(students[j].name, students[j + 1].name) > 0) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    printf("Students sorted by Name.\n");
    displayAllStudents();
}

void academicAdvisor() {
    long long id;
    printf("Enter SAP ID for academic advice: ");
    scanf("%lld", &id);

    for (int i = 0; i < count; i++) {
        if (students[i].sap == id) {
            float cgpa = calculateCGPA(students[i]);

            printf("\n--- AI ACADEMIC ADVISOR ---\n");
            printf("Student: %s\n", students[i].name);
            printf("CGPA: %.2f\n", cgpa);

            int hasResult = 0;
            for (int j = 0; j < 8; j++) {
                if (students[i].sgpa[j] >= 0) {
                    hasResult = 1;
                    break;
                }
            }

            if (!hasResult) {
                printf("Recommendation: Enter semester results first.\n");
            }
            else if (cgpa >= 8.5) {
                printf("Category: Excellent\n");
                printf("Recommendation: Maintain your performance and explore advanced projects.\n");
            }
            else if (cgpa >= 7.0) {
                printf("Category: Good\n");
                printf("Recommendation: Keep practising and aim for a higher CGPA.\n");
            }
            else if (cgpa >= 5.0) {
                printf("Category: Needs Improvement\n");
                printf("Recommendation: Improve your study routine and revise difficult subjects.\n");
            }
            else {
                printf("Category: Requires Immediate Attention\n");
                printf("Recommendation: Seek faculty guidance and prepare a focused study plan.\n");
            }

            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== STUDENT RECORD AND RESULT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Calculate and Display CGPA\n");
        printf("6. Average CGPA by Year\n");
        printf("7. Sort by SAP ID\n");
        printf("8. Sort by Name\n");
        printf("9. AI Academic Advisor\n");
        printf("10. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: displayAllStudents(); break;
            case 6: averageCGPAByYear(); break;
            case 7: sortBySAP(); break;
            case 8: sortByName(); break;
            case 9: academicAdvisor(); break;
            case 10: printf("Thank you for using the system!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }

    } while (choice != 10);

    return 0;
}
