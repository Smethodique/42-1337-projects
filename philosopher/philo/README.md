# Philosophers

## About
This project is a solution to the classic Dining Philosophers problem, implemented as part of the 42 curriculum. It explores the principles of multithreading, concurrency, and resource sharing in the context of a simulated scenario where philosophers must eat, sleep, and think without starving.

## The Problem
- Several philosophers sit at a round table with a large bowl of spaghetti in the center.
- Philosophers alternate between eating, thinking, and sleeping.
- While eating, they need both of their forks (one fork between each pair of philosophers).
- After eating, they put their forks back on the table and start sleeping, then thinking.
- The simulation stops when a philosopher dies of starvation or when all philosophers have eaten a certain number of times.

## Features

- Multi-threaded simulation of the dining philosophers problem
- Precise timing mechanisms for philosopher activities
- Deadlock prevention strategies
- Death monitoring system
- Configurable simulation parameters:
  - Number of philosophers
  - Time to die (in milliseconds)
  - Time to eat (in milliseconds)
  - Time to sleep (in milliseconds)
  - Number of times each philosopher must eat (optional)

## Requirements

- C compiler (gcc/clang)
- Make
- POSIX threads library (pthread)

## Installation

Clone the repository and compile the project:

```bash
git clone https://github.com/yourusername/philosophers.git
cd philosophers
make
```

## Usage

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

### Arguments:

- `number_of_philosophers`: The number of philosophers and forks (1-200)
- `time_to_die`: Time in milliseconds until a philosopher dies if they haven't started eating
- `time_to_eat`: Time in milliseconds that a philosopher takes to eat
- `time_to_sleep`: Time in milliseconds that a philosopher sleeps
- `number_of_times_each_philosopher_must_eat` (optional): If all philosophers eat this many times, the simulation stops

### Example:

```bash
./philo 5 800 200 200 7
```

This creates a simulation with:
- 5 philosophers
- 800ms time to die
- 200ms time to eat
- 200ms time to sleep
- Simulation stops if each philosopher eats 7 times

## Project Structure

- **main.c**: Entry point and cleanup functions
- **monitor.c**: Handles death monitoring and simulation start
- **parsing.c**: Argument validation and parsing
- **philosopher.h**: Main header file with structure definitions
- Other files:
  - Functions for philosopher routines (eating, sleeping, thinking)
  - Initialization functions
  - Utility functions

## Implementation Details

### Multithreading
Each philosopher is represented by a separate thread that follows its own routine of eating, sleeping, and thinking.

### Mutexes
Forks are protected by mutexes to prevent multiple philosophers from using the same fork simultaneously.

### Death Monitoring
The program continuously checks if any philosopher has exceeded their time to die since their last meal.

### Deadlock Prevention
Special care is taken to prevent deadlocks by implementing fork picking strategies (philosophers with odd IDs take forks in a different order than those with even IDs).

## Visualization

Throughout the simulation, status updates are printed to show the actions of philosophers:

```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```

Where X is the philosopher number.
