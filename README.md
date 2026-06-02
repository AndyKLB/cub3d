# cub3d

Summary
-------
`cub3d` is a small 3D raycasting project implemented in C for learning graphics and low-level windowing. The program renders a simple 3D view from a 2D map and supports textures, basic movement, and simple collision detection.

Features
--------
- Raycasting-based rendering pipeline
- Texture mapping for walls and sprites
- Player movement and collision
- Configurable maps in the `maps/` directory

Requirements
------------
- Linux
- X11 development libraries (for `minilibx`)
- `make`, `gcc`

Build
-----
1. From the project root run:

```
make
```

Makefile highlights:

```
CC = cc
FLAG = -Wall -Wextra -Werror -g3
# Links to libft and minilibx in `lib/`
```

If `minilibx` is provided in `lib/`, the `Makefile` will link against it automatically.

Usage
-----
1. Run the compiled binary with a map file:

```
./cub3d maps/good/map.cub
```

2. Controls: arrow keys / WASD for movement, ESC to exit.

Project Layout
--------------
- `srcs/` — main source files and game logic
- `inc/` — public headers
- `lib/` — bundled libraries (`libft`, `mlx`)
- `maps/` — example maps (good and bad)
- `textures/` — texture assets

Notes
-----
- Map files must follow the project-specific `.cub` format. Use provided maps as references.
- For development, run the binary from the project root to ease asset loading.

Author / Attribution
--------------------
Authors: wzeraig and ankammer (Walid Zeraig and Andy Kammerer)

License
-------
Unlicensed (add a LICENSE file if you want to publish this project).
