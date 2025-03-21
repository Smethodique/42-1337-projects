# Minishell

## About
Minishell is a simple shell implementation, similar to bash, developed as part of the 42 curriculum. This project recreates basic shell functionalities, allowing users to execute commands, manage processes, and handle various shell features like redirections and pipes.

## Features

- Command execution
- Built-in commands:
  - `echo` with option `-n`
  - `cd` with relative or absolute path
  - `pwd` without options
  - `export` without options
  - `unset` without options
  - `env` without options
  - `exit` without options
- Environment variable expansion (`$VAR`)
- Signal handling (Ctrl-C, Ctrl-D, Ctrl-\\)
- Redirections:
  - Input redirection (`<`)
  - Output redirection (`>`)
  - Append output (`>>`)
  - Heredoc (`<<`)
- Pipes (`|`) to connect commands
- Command history using readline
- Error handling similar to bash

## Requirements

- GCC compiler
- Make
- Readline library

## Installation

Clone the repository and compile the project:

```bash
git clone https://github.com/yourusername/minishell.git
cd minishell
make
```

## Usage

Run the shell:

```bash
./minishell
```

You'll be presented with a prompt where you can enter commands:

```
minishell$ ls -la
minishell$ echo "Hello World"
minishell$ cd ..
minishell$ pwd
```

## Project Structure

- **main.c**: Entry point and shell initialization
- **minishell.h**: Main header file containing all declarations
- **tokenizer**: Tokenizes input command line into distinct tokens
- **parser**: Parses tokens into command structures
- **executor**: Executes parsed commands
- **builtins**: Implementation of built-in commands
- **redirections**: Handles input/output redirections
- **signals**: Signal handling functionalities
- **environment**: Environment variable management
- **utils**: Utility functions used throughout the project

## Implementation Details

### Tokenization
The shell breaks down the input line into tokens, identifying commands, arguments, redirections, and pipes.

### Parsing
Tokens are analyzed and organized into command structures that specify the command name, arguments, and redirections.

### Execution
Commands are executed according to their type:
- Built-in commands are handled internally
- External commands are executed using fork and execve
- Pipes and redirections modify the standard input/output streams as needed

### Memory Management
The project includes a garbage collector to manage dynamic memory allocation, preventing memory leaks.

## Contributors

- [iabboudi](https://github.com/iabboudi)
- [Smethodique](https://github.com/Smethodique)
