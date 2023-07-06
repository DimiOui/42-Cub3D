# Cub3d

cub3d is a simple raycasting game engine inspired by the classic game Wolfenstein 3D. It utilizes the concept of raycasting to render a 3D graphical representation of a maze-like environment. This project is implemented in the C programming language and uses the MiniLibX graphics library for graphical output.

<div id="rc" align="center">
  <img src="https://upload.wikimedia.org/wikipedia/commons/e/e7/Simple_raycasting_with_fisheye_correction.gif"/>
</div>

## Raycasting Overview

Raycasting is a technique used to render a 3D perspective in a 2D environment. It involves simulating the behavior of light rays originating from the player's perspective and casting them onto a 2D grid representing the game world. By performing calculations on each ray, the engine can determine the distance to the walls and render a 3D representation.

## Game Display

The game display consists of several elements, including the ceiling, floor, and walls.

### Ceiling, Floor and Walls

The ceiling and floor are rendered using the `display_ceilling` and `display_floor` functions, respectively. These functions create rectangular shapes and fill them with the appropriate colors defined in the game's data. The walls are rendered using the `display_walls` function. This function iterates over each ray in the game and renders the corresponding wall based on the calculated wall height and texture mapping.
<br/>

To render a specific wall, the `display_wall_ray` function is used. It calculates the texture coordinates of the wall and maps the corresponding texture pixel to the screen. This creates the illusion of a textured wall.
```c
static void display_ceilling(t_game *game);
static void display_floor(t_game *game);
static void display_walls(t_game *game);
void display_wall_ray(t_rect *rect, int *img, t_res *res, t_ray *ray);
```
## Raycasting Process
The raycasting process involves several steps, including ray initialization, ray casting, and wall rendering.

### Ray Initialization
To begin the raycasting process, rays are initialized using the `get_rays` function. This function calculates the intersections of the rays with the game's grid and determines the initial size of each ray.

### Ray Casting
Ray casting is performed by the `matrix_x_crossing` and `matrix_y_crossing` functions. These functions handle the ray casting process for each ray, determining the intersections of the ray with the vertical and horizontal lines of the game's grid and calculating the size of the ray based on the distance traveled.

<div id="rc" align="center">
  <img src="https://permadi.com/tutorial/raycast/images/figure14.gif" height="200"/>
  <img src="https://permadi.com/tutorial/raycast/images/figure17.gif" height="200"/>
</div>

### Wall Rendering
The `display_walls` function iterates over each ray and renders the walls based on the calculated wall height and texture mapping. It also utilizes the `get_wall_xpm` function to determine the appropriate texture for each wall based on its orientation.

<div id="rc" align="center">
  <img src="https://permadi.com/tutorial/raycast/images/figure20.gif" height="300"/>
</div>

## Usage
To run the cub3d Raycasting Engine, you need to compile the project and provide a valid map file as a command-line argument. The map file should follow a specific format defined by the game.

Here's an example of how to run the engine:

```bash
$ make
$ ./cub3d path/to/map.cub
```
Make sure to replace `path/to/map.cub` with the actual path of a valid map file.

### Map File Format
The map file should have the `.cub` extension and follow a specific format. Here's an example of a valid map file:

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

C 0,0,0
F 255,255,255

1111111111111111111111111
1000000000110000000000001
1011000001110000002000001
1001000000000000000000001
1111111110110000011100001
1000000000110000011101111
1111011111111101110000001
1111011111111101111111111
1111111111111101111111111
```
The map file consists of several elements:

- Texture paths (NO, SO, WE, EA, S): Specifies the paths to the textures used for walls and sprites.
- Ceiling and floor colors (F, C): Specifies the RGB color values for the ceiling and floor.
- Map: A grid of characters representing the game world, where 1 represents a wall, 0 represents an empty space, and other characters can be used to represent different elements.
<br/>

Please note that the provided example is just a template, and you should customize it to match your desired game world.

## Resources
The below links will give you a deep and thorough understanding of raycasting and were used expansively to create the project :

- https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents
- https://lodev.org/cgtutor/raycasting.html
- https://youtube.com/playlist?list=PL0H9-oZl_QOHM34HvD3DiGmwmj5X7GvTW
