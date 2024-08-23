# Push Swap

## Overview

The `push_swap` project is an algorithmic challenge that involves sorting a stack of integers using a limited set of operations. The goal is to sort the stack in the fewest possible moves using the following operations:

- `sa` (swap a): Swap the first two elements at the top of stack A.
- `sb` (swap b): Swap the first two elements at the top of stack B.
- `ss`: `sa` and `sb` at the same time.
- `pa` (push a): Take the first element at the top of stack B and put it at the top of stack A.
- `pb` (push b): Take the first element at the top of stack A and put it at the top of stack B.
- `ra` (rotate a): Shift all elements of stack A up by one.
- `rb` (rotate b): Shift all elements of stack B up by one.
- `rr`: `ra` and `rb` at the same time.
- `rra` (reverse rotate a): Shift all elements of stack A down by one.
- `rrb` (reverse rotate b): Shift all elements of stack B down by one.
- `rrr`: `rra` and `rrb` at the same time.

## Chunks Algorithm

To efficiently sort large sets of numbers, this implementation of `push_swap` uses a **chunk-based** algorithm. The idea is to divide the array of numbers into smaller chunks and sort them incrementally.

### Steps of the Algorithm

1. **Initial Setup:**
   - The stack A is initialized with the list of numbers to be sorted.
   - Stack B is initially empty.

2. **Dividing into Chunks:**
   - The array of numbers is divided into chunks. The size of each chunk is determined based on the total number of elements in the stack. Typically, the chunk size increases with the size of the array.
   - For example, if sorting 100 elements, chunks of size 15 might be used; for 500 elements, chunks of size 30 might be used.

3. **Pushing Chunks to Stack B:**
   - Numbers from stack A are pushed to stack B in chunks. During this process, each number is checked if it belongs to the current chunk range. If it does, it is pushed to stack B.
   - The algorithm ensures that the smallest elements end up at the top of stack B.

4. **Sorting Stack B:**
   - After all elements of a chunk are in stack B, they are pushed back to stack A in a sorted order using the `pa` operation.

5. **Repeat Until Sorted:**
   - The process is repeated for each chunk until all numbers are sorted and back in stack A.


## Compilation

To compile the project, run:

```bash
make

Usage
