# get_next_line

**get_next_line** is a project from the 42 Cursus that implements a function which reads a line from a file descriptor, one line at a time. This task involves managing a static buffer, handling memory allocation, and supporting multiple file descriptors.

## 📌 Project Objectives

- Implement `get_next_line(int fd)` that:
  - Returns a line from the given file descriptor.
  - Manages partial reads using a buffer.
  - Handles memory safely without leaks.
  - Supports simultaneous reads from multiple file descriptors (bonus).
- Restrictions:
  - Only allowed functions: `read`, `malloc`, `free`
  - No use of standard C library functions (e.g., `strchr`, `strlen`)
  - No global variables
  - No `lseek`

## 🔧 Compilation

This repository does not include a `Makefile`. To compile manually:

### Mandatory part

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c sample_main.c -o gnl
````

### Bonus part (multiple file descriptors)

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c sample_bonus_main.c -o gnl_bonus
```

> ℹ️ You can replace `42` with any buffer size you'd like to test.

## ▶️ Example Usage

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("sample.txt", O_RDONLY);
    char *line;

    if (fd == -1)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 📁 File Structure

```text
get_next_line/
|── text/                         # Test text files
├── get_next_line.c               # Core logic
├── get_next_line_utils.c         # Helper functions (mandatory)
├── get_next_line_bonus.c         # Bonus logic for multiple FDs
├── get_next_line_utils_bonus.c   # Bonus helper functions
├── get_next_line.h               # Header file (mandatory)
├── get_next_line_bonus.h         # Header file (bonus)
└── README.md
```

## ⭐ Bonus Features

- Handles multiple file descriptors simultaneously.
- Uses a separate static stash per file descriptor.

## 🧪 Testing Tips

- Try different `BUFFER_SIZE` values (e.g., 1, 42, 4096).
- Feed it files with varying newline placements.
- Test edge cases like empty files, huge files, or files without newlines.

## 📚 Keywords

`file descriptor`, `buffered reading`, `static storage`, `line-by-line input`, `C memory management`
