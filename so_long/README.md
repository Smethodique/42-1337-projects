# so_long

## Overview

`so_long` is a simple 2D game project developed as part of the 42 Network curriculum. The game involves navigating a player character through a map, collecting items, and reaching an exit while avoiding obstacles.

## Features

- **Custom Map**: Create your own maps with walls ('1'), empty spaces ('0'), collectibles ('C'), and a player character ('P').
- **Simple Controls**: Navigate the player character using keyboard inputs.
- **Graphics**: Rendered using the MiniLibX (mlx) library.

## Requirements

- **C Compiler**: GCC or Clang
- **Libraries**: MiniLibX (mlx)
- **Operating System**: Unix-based (Linux, macOS)

## Installation

1. **Clone the repository**:
    ```bash
    git clone git@github.com:Smethodique/42-1337-projects.git
    cd 42-1337-projects
    cd so_long
    ```

2. **Install mlx**:
    Follow the instructions to install the MiniLibX library on your system. Typically, you can find the library at [42 Paris' GitHub repository](https://github.com/42Paris/minilibx-linux) for Linux systems.

3. **Compile the project**:
    ```bash
    make
    ```

## Usage

1. **Create a map file**:
    Create a text file (e.g., `map.ber`) with the following format:
    ```
    11111
    1P0C1
    10001
    1C0E1
    11111
    ```
    - `1` represents a wall.
    - `0` represents an empty space.
    - `P` represents the player starting position.
    - `C` represents collectibles.
    - `E` represents the exit.

2. **Run the game**:
    ```bash
    ./so_long map.ber
    ```

3. **Controls**:
    - Use the arrow keys or `W`, `A`, `S`, `D` to move the player.
    - Collect all items and reach the exit to win the game.

## Project Structure

- `src/` - Contains the source code files.
- `include/` - Contains the header files.
- `maps/` - Contains example map files.
- `Makefile` - Makefile to build the project.
