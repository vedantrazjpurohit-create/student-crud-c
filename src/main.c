#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
};

int findIndex(struct Student s[], int n, int roll) {
    for (int i = 0; i < n; i++) {
        if (s[i].roll == roll) {
            return i;
        }
    }
    return -1;
}

void insert(struct Student s[], int *n) {
    int roll;

    if (*n >= 100) {
        printf("List full.\n");
        return;
    }

    printf("Enter roll number: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        while (getchar() != '\n') {
        }
        return;
    }

    if (findIndex(s, *n, roll) != -1) {
        printf("Roll %d already exists.\n", roll);
        while (getchar() != '\n') {
        }
        return;
    }

    s[*n].roll = roll;
    getchar();
    printf("Enter name: ");
    fgets(s[*n].name, 50, stdin);
    s[*n].name[strcspn(s[*n].name, "\n")] = '\0';

    (*n)++;
    printf("Student added.\n");
}

void deleteByRoll(struct Student s[], int *n) {
    int roll, idx;

    if (*n == 0) {
        printf("No students to delete.\n");
        return;
    }

    printf("Enter roll number to delete: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        while (getchar() != '\n') {
        }
        return;
    }

    idx = findIndex(s, *n, roll);
    if (idx == -1) {
        printf("Student not found.\n");
        return;
    }

    for (int i = idx; i < *n - 1; i++) {
        s[i] = s[i + 1];
    }
    (*n)--;
    printf("Student deleted.\n");
}

void updateByRoll(struct Student s[], int n) {
    int roll, idx;

    if (n == 0) {
        printf("No students to update.\n");
        return;
    }

    printf("Enter roll number to update: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        while (getchar() != '\n') {
        }
        return;
    }

    idx = findIndex(s, n, roll);
    if (idx == -1) {
        printf("Student not found.\n");
        return;
    }

    getchar();
    printf("Enter new name: ");
    fgets(s[idx].name, 50, stdin);
    s[idx].name[strcspn(s[idx].name, "\n")] = '\0';
    printf("Student updated.\n");
}

void search(struct Student s[], int n) {
    int roll, idx;

    if (n == 0) {
        printf("No students to search.\n");
        return;
    }

    printf("Enter roll number to search: ");
    if (scanf("%d", &roll) != 1) {
        printf("Invalid roll number.\n");
        while (getchar() != '\n') {
        }
        return;
    }

    idx = findIndex(s, n, roll);
    if (idx == -1) {
        printf("Student not found.\n");
        return;
    }

    printf("Student found:\n");
    printf("Roll No: %d\n", s[idx].roll);
    printf("Name: %s\n", s[idx].name);
}

void display(struct Student s[], int n) {
    if (n == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Student list (%d):\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d. Roll No: %d, Name: %s\n", i + 1, s[i].roll, s[i].name);
    }
}

int main(void) {
    struct Student s[100];
    int n = 0, ch;

    while (1) {
        printf("\n--- Student CRUD ---\n");
        printf("1. Insert\n2. Delete by roll\n3. Update by roll\n4. Search\n5. Display\n6. Exit\n");
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
            deleteByRoll(s, &n);
        } else if (ch == 3) {
            updateByRoll(s, n);
        } else if (ch == 4) {
            search(s, n);
        } else if (ch == 5) {
            display(s, n);
        } else if (ch == 6) {
            printf("Exiting.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}