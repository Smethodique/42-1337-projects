# 42 School - C++ Modules (Part One)

This repository contains my solutions for the first part of the 42 School C++ curriculum, covering fundamental C++ programming concepts from basic syntax to object-oriented programming principles.

## 📚 Project Overview

The C++ modules are designed to progressively introduce C++ concepts, starting from the basics and building up to more advanced object-oriented programming features. Each module focuses on specific aspects of the language.

## 🗂️ Module Structure

### CPP Module 00 - Namespaces, Classes, Member Functions, stdio streams, Initialization Lists, Static, Const

| Exercise | Name | Description | Key Concepts |
|----------|------|-------------|--------------|
| **ex00** | **Megaphone** | String manipulation and basic I/O | Command line arguments, string operations, toupper() |
| **ex01** | **PhoneBook** | Contact management system | Classes, private/public members, arrays, input validation |

**Skills Learned:**
- Basic C++ syntax and compilation
- Class design and encapsulation
- Input/output streams
- String manipulation
- Basic data validation

---

### CPP Module 01 - Memory Allocation, Pointers to Members, References, Switch Statement

| Exercise | Name | Description | Key Concepts |
|----------|------|-------------|--------------|
| **ex00** | **BraiiiiiiinnnzzzZ** | Zombie class with stack/heap allocation | Constructors/destructors, new/delete |
| **ex01** | **Moar brainz!** | Zombie horde creation | Dynamic arrays, memory management |
| **ex02** | **HI THIS IS BRAIN** | Pointers vs references demonstration | Pointers, references, memory addresses |
| **ex03** | **Unnecessary violence** | Weapon system with humans | References vs pointers, object relationships |
| **ex04** | **Sed is for losers** | File text replacement tool | File I/O, string manipulation, static methods |
| **ex05** | **Harl 2.0** | Logging system with levels | Function pointers, switch statements |
| **ex06** | **Harl filter** | Enhanced logging with filtering | Switch fall-through, enum-like behavior |

**Skills Learned:**
- Dynamic memory allocation (new/delete)
- Pointers vs references
- File input/output operations
- Function pointers and member function pointers
- Object lifetime management

---

### CPP Module 02 - Ad-hoc Polymorphism, Operator Overloading, Orthodox Canonical Class Form

| Exercise | Name | Description | Key Concepts |
|----------|------|-------------|--------------|
| **ex00** | **My First Class in Orthodox Canonical Form** | Basic Fixed-point number class | Orthodox Canonical Form, copy constructor |
| **ex01** | **Towards a more useful fixed-point number class** | Enhanced Fixed class with conversions | Type conversions, stream operators |
| **ex02** | **Now we're talking** | Complete Fixed class with operators | Operator overloading, arithmetic operations |
| **ex03** | **BSP** | Point-in-triangle algorithm | Practical application, geometric algorithms |

**Skills Learned:**
- Orthodox Canonical Class Form (Rule of Four)
- Operator overloading (arithmetic, comparison, increment/decrement)
- Type conversions and casting
- Stream operator overloading
- Fixed-point arithmetic implementation

---

### CPP Module 03 - Inheritance

| Exercise | Name | Description | Key Concepts |
|----------|------|-------------|--------------|
| **ex00** | **Aaaaand... OPEN!** | Basic ClapTrap robot class | Base class design, encapsulation |
| **ex01** | **Serena, my love!** | ScavTrap inheriting from ClapTrap | Single inheritance, method overriding |
| **ex02** | **Repetitive work** | FragTrap class addition | Multiple derived classes |
| **ex03** | **Now it's weird!** | DiamondTrap with multiple inheritance | Diamond problem, virtual inheritance |

**Skills Learned:**
- Single and multiple inheritance
- Method overriding and virtual functions
- Diamond inheritance problem
- Virtual inheritance
- Protected access specifiers
- Constructor/destructor chaining in inheritance

## 🛠️ Compilation and Usage

### Prerequisites
- C++ compiler supporting C++98 standard (g++, clang++)
- Make utility

### General Compilation
Each exercise includes its own Makefile. To compile any exercise:

```bash
cd <module>/<exercise>/
make
```

### Example Usage

**CPP00/ex01 - PhoneBook:**
```bash
cd cpp00/ex01/
make
./phonebook
# Follow interactive prompts: ADD, SEARCH, EXIT
```

**CPP01/ex04 - Text Replacement:**
```bash
cd CPP01/ex04/
make
./replace filename "search_string" "replace_string"
```

**CPP02/ex02 - Fixed Point Numbers:**
```bash
cd CPP02/ex02/
make
./fixed2
```

## 🎯 Learning Objectives

By completing these modules, you will understand:

1. **C++ Fundamentals**: Syntax, compilation, basic I/O
2. **Object-Oriented Programming**: Classes, encapsulation, inheritance
3. **Memory Management**: Stack vs heap, RAII principles
4. **Operator Overloading**: Creating intuitive class interfaces
5. **Advanced Inheritance**: Virtual functions, multiple inheritance
6. **C++98 Standard**: Understanding legacy C++ constraints

## 📋 Key C++ Concepts Covered

### Memory Management
- Stack vs heap allocation
- RAII (Resource Acquisition Is Initialization)
- Proper constructor/destructor usage
- Memory leak prevention

### Object-Oriented Design
- Encapsulation and data hiding
- Inheritance hierarchies
- Polymorphism through virtual functions
- Interface design principles

### C++98 Specific Features
- Orthodox Canonical Form compliance
- Function pointer usage
- References vs pointers
- Const correctness

## 🚀 Getting Started

1. Clone the repository:
```bash
git clone <repository_url>
cd CPP_PART_ONE
```

2. Choose a module and exercise to explore:
```bash
cd CPP00/ex00  # Start with the basics
make
./megaphone "hello world"
```

3. Follow the progression through each module for optimal learning

## 📚 Additional Resources

- [C++ Reference](https://cppreference.com/)
- [42 School Norm](https://github.com/42School/norminette) - Coding standard
- [C++98 Standard Documentation](https://www.iso.org/standard/25845.html)

## 🏆 Project Status

| Module | Status | Completion |
|--------|--------|------------|
| CPP00  | ✅ Complete | 2/2 exercises |
| CPP01  | ✅ Complete | 6/6 exercises |
| CPP02  | ✅ Complete | 4/4 exercises |
| CPP03  | ✅ Complete | 4/4 exercises |

---

**Total Exercises Completed: 16/16** ✨

> **Note**: All code follows the 42 School Norm and C++98 standard requirements. Each exercise builds upon previous concepts, creating a comprehensive learning path through fundamental C++ programming.

