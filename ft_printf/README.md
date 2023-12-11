# 42 project : ft_printf 100/100

# Description
`ft_printf` is a custom printf function implementation in C.

## Table of Contents
- [Usage](#usage)
- [Format Specifiers](#format-specifiers)
- [Example](#example)
- [Contributing](#contributing)

## Usage
To use `ft_printf`, include the "ft_printf.h" header file in your project. The function has the following prototype:

```c
int ft_printf(const char *format, ...);
```
# Format Specifiers

`ft_printf` supports the following format specifiers:

- `%c`: Character
- `%s`: String
- `%d` or `%i`: Integer
- `%u`: Unsigned Integer
- `%x`: Lowercase Hexadecimal
- `%X`: Uppercase Hexadecimal
- `%p`: Pointer
- `%%`: Percent Sign


# Example
```c
#include "ft_printf.h"

int main() {
    ft_printf("Formatting examples: %d, %s, %c\n", 42, "Hello", 'A');
    return 0;
}
```
# Contributing
Contributions are welcome! If you have improvements or bug fixes, please open an issue or submit a pull request. 
