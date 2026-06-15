#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
};

void insert(struct Student s[], int *n) {
    if (*n >= 100) {
        printf("List full.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &s[*n].roll);

    getchar();
    printf("Enter name: ");
    fgets(s[*n].name, 50, stdin);
    s[*n].name[strcspn(s[*n].name, "\n")] = '\0';

    (*n)++;
    printf("Student added.\n");
}

void deleteLast(struct Student s[], int *n) {
    (void)s;
    if (*n == 0) {
        printf("No student to delete.\n");
        return;
    }

    (*n)--;
    printf("Last student deleted.\n");
}

void search(struct Student s[], int n) {
    int r, found = 0;
    printf("Enter roll number to search: ");
    scanf("%d", &r);

    for (int i = 0; i < n; i++) {
        if (s[i].roll == r) {
            printf("Student found:\n");
            printf("Roll No: %d\n", s[i].roll);
            printf("Name: %s\n", s[i].name);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void display(struct Student s[], int n) {
    if (n == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Student list:\n");
    for (int i = 0; i < n; i++) {
        printf("Roll No: %d, Name: %s\n", s[i].roll, s[i].name);
    }
}

int main(void) {
    struct Student s[100];
    int n = 0, ch;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &ch) != 1) {
            printf("Invalid input.\n");
            while (getchar() != '\n') {
            }
            continue;
        }

        if (ch == 1) {
            insert(s, &n);
        } else if (ch == 2) {
            deleteLast(s, &n);
        } else if (ch == 3) {
            search(s, n);
        } else if (ch == 4) {
            display(s, n);
        } else if (ch == 5) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}