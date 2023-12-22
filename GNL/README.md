# GetNextLine - Bonus

## Table of Contents
- [Description](#description)
- [Features](#features)
- [How to Use](#how-to-use)
- [Compilation](#compilation)
- [Function Descriptions](#function-descriptions)
- [Example](#example)
- [Contributing](#contributing)

## Description
GetNextLine is a function that reads a line from a file descriptor.
This version includes bonus functionalities.

## Features
- Handles reading lines from a file descriptor.
- Supports multiple file descriptors using a static variable.
- Customizable buffer size.

## How to Use
1. Clone the repository:
   ```bash
   git clone <repository-url>
   ```
1)Include the get_next_line_bonus.h header file in your project.

2)Call the get_next_line function to read lines from a file descriptor.

Compilation
Compile your program with the source file get_next_line_bonus.c and include the necessary flags.
```bash
gcc -Wall -Wextra -Werror *.c
```
## Function Descriptions
char *get_next_line(int fd): Reads a line from the given file descriptor.

char *ft_strjoin(char *line, char *buff): Joins two strings.

size_t ft_strlen(char *s): Calculates the length of a string.

char *ft_strchr(const char *s, int c): Locates the first occurrence of a character in a string.

char *readex_line(int fd, char *line): Reads and extends the line.
## Example
 ```bash
#include "get_next_line_bonus.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}
```
# Contributing
Feel free to contribute by opening issues or submitting pull requests.
