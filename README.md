# student-crud-c

Minimal student record manager in C — menu-driven insert, delete, search, display.

I wrote this while revisiting pointer basics before heavier systems work. Nothing fancy, but it's clean, compiles with `gcc`, and handles the edge cases that usually break classroom submissions (newline after `scanf`, empty list deletes).

## Build & run

```bash
gcc -Wall -Wextra -std=c11 -o student_crud src/main.c
./student_crud
```

## Features

- Fixed-size array (max 100 records)
- Insert with roll number + name
- Delete last entry (stack-style — good enough for the assignment spec)
- Search by roll number
- Display all records

## Why it's here

Recruiters for AI roles still want to see you can write correct low-level code. This repo is intentionally small and honest — one file, no over-engineering.