#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int age;
};
struct Student s[100];
int count = 0;

void addStudent() {
    printf("\nEnter ID: ");
    scanf("%d", &s[count].id);
    printf("Enter Name: ");
    scanf("%s", s[count].name);
    printf("Enter Age: ");
    scanf("%d", &s[count].age);
    count++;
    printf("Student Added!\n");
}

void viewStudents() {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\n", s[i].id, s[i].name, s[i].age);
    }
}

void searchStudent() {
    int id;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (s[i].id == id) {
            printf("Found: %d %s %d\n", s[i].id, s[i].name, s[i].age);
            return;
        }
    }
    printf("Student Not Found!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add\n2. View\n3. Search\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
