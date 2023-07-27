# cub3d
Cub3d is a 3D maze exploration game, inspired by the classic Wolfenstein 3D game. It is a project from the 42 school curriculum and serves as an introduction to the world of raycasting and graphics programming.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Getting Started](#getting-started)
- [How to Play](#how-to-play)
- [Map Configuration](#map-configuration)
- [Building and Running](#building-and-running)
- [Controls](#controls)

## Description
Cub3d is a simple 3D maze game where players navigate through a maze-like environment with walls, sprites, and enemies. The game is rendered using raycasting, a technique that simulates a 3D perspective on a 2D plane.
The project challenges students to understand raycasting algorithms, work with graphics libraries (such as the MiniLibX), and create an immersive gaming experience within the constraints of the 42 school norm.

## Features
- 3D Maze Exploration: Navigate through a 3D maze using raycasting techniques.
- Wall Textures: Customize the maze walls with different textures.
- Sprite Rendering: Display sprites (enemies, items) on the map with proper scaling.
- Colorful and Immersive: Enjoy a visually immersive experience with vibrant colors and smooth animations.

## Getting Started
Before running cub3d, make sure you have the required dependencies installed on your system. The project uses the MiniLibX graphics library, which provides the necessary functions for rendering graphics and handling user input.

## How to Play
The objective of the game is to navigate through the maze and find the exit. You can move forward, backward, and strafe left or right using the arrow keys. Look around and change your view direction with the mouse.

## Map Configuration
The game map can be configured using a `.cub` file. This file contains information about the maze layout, textures, sprite positions, and other game settings. Make sure to follow the correct format for the `.cub` file as described in the resources section.

## Building and Running
To build and run cub3d, follow these steps:

1. Clone the cub3d repository to your local machine:
```bash
git clone https://github.com/cj4ck/cub3d.git
```
2. Navigate to the project directory:

```go
cd cub3d
```

3. Build the game:

```go
make
```

4. Run the game with a `.cub` map file:
```bash
./cub3D path_to_map.cub
```

## Controls
- **W:** Move forward
- **S:** Move backward
- **A:** Strafe left
- **D:** Strafe right
- **←:** Rotate left
- **→:** Rotate right
- **ESC:** Exit the game

## Disclaimer
> This project was developed on 42 Wolfsburg MAC therefore it's not supported on other computers but I will fix it once I have a bit more time. ;P