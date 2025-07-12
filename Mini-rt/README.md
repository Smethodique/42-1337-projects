# MiniRT - Ray Tracing Renderer

## Overview
MiniRT is a minimalist ray tracing engine developed in C, implementing fundamental techniques for realistic 3D scene rendering. This project follows the 42 school's curriculum guidelines and focuses on creating a renderer that can handle basic geometric primitives while producing visually appealing results.

## Features
- **Primitive Shapes:** Supports rendering of spheres, planes, and cylinders
- **Lighting System:** Implements ambient lighting and point lights with shadows
- **Camera Controls:** Interactive camera movement and rotation
- **Object Manipulation:** Select and modify scene objects in real-time
- **Ray Tracing:** Calculate realistic lighting, shadows, and object intersections

## Requirements
- GCC compiler
- MinilibX graphics library
- Linux/macOS environment

## Installation

```bash
# Clone the repository
git clone https://github.com/Smethodique/42-1337-projects.git
cd Mini-rt

# Compile the program
make

# Run with a scene file
./miniRT scenes/example.rt
```

## Usage

### Scene Files
Create scene files with `.rt` extension following this format:
```
# Comments start with '#'
A 0.2 255,255,255          # Ambient light
C 0,0,0 0,0,1 70           # Camera
L 0,5,0 0.6 255,255,255    # Light
sp 0,0,3 2 255,0,0         # Sphere
pl 0,-1,0 0,1,0 0,255,0    # Plane
cy 0,0,3 0,1,0 1 2 0,0,255 # Cylinder
```

### Controls
- **WASD:** Move camera position
- **Arrow Keys:** Rotate camera
- **Mouse Click:** Select objects
- **Page Up/Down:** Move selected object
- **Home/End:** Rotate selected object
- **ESC:** Exit program

## Technical Details

### Ray Tracing Implementation
MiniRT implements a basic ray tracing algorithm that:
1. Generates rays from camera through each pixel
2. Calculates intersections with scene objects
3. Determines light contributions for hit points
4. Handles shadows through shadow ray calculations

### Mathematics
The project utilizes vector mathematics for:
- Ray-object intersections (quadratic formulas for spheres and cylinders)
- Normal vector calculations
- Light diffusion models
- Vector operations (addition, subtraction, normalization, etc.)

### Architecture
- **Parser Module:** Reads and validates scene files
- **Render Engine:** Performs ray tracing calculations
- **Vector Library:** Handles vector mathematics operations
- **Event System:** Processes user input for camera and object manipulation

## Project Structure
- `includes/`: Header files
- `src/`: Source code files
- `scenes/`: Example scene files

##  Show case
<img width="1594" height="1000" alt="Screenshot from 2025-07-12 22-32-33" src="https://github.com/user-attachments/assets/32ea8681-e40f-4922-b6ff-bba38ec0b1e9" />
<img width="1425" height="1000" alt="Screenshot from 2025-07-12 22-38-56" src="https://github.com/user-attachments/assets/50cddc85-d267-46ac-b2ef-0934ea1bc300" />

## Contributors
- [Smethodique (me)](https://github.com/Smethodique)
- [Weismann](https://github.com/WeismannS)
