# student-crud-c

Low-level C practice — not a showcase project, just fundamentals done right.

I keep this repo to prove I can still write correct systems code: pointers, stdin handling, and `-Wall` clean compiles. Useful before touching embedded drivers or ROS nodes where sloppy I/O causes real bugs.

## Build & run

```bash
gcc -Wall -Wextra -std=c11 -o student_crud src/main.c
./student_crud
```

## What it covers

- Fixed-size array storage (100 records)
- Insert / delete / search / display
- `scanf` + `fgets` newline bug handled
- Invalid menu input doesn't crash the loop

## Why it exists

Robotics work still hits C at the edges — firmware, serial bridges, drivers. This is deliberate fundamentals practice, not portfolio filler.