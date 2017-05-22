## Project Meanbean

This repository contains our working code for "Project Meanbean". This is meant to be a naive implementation of a simple game using the NCurses library to help implement a simple GUI that runs in a terminal environment.

To try the game either download the `.zip` file or run `git clone git@github.com:TheLostCodex/project-meanbean.git` in the terminal in order to clone the repository.

You can first run the compatibility test to see if your terminal supports ncurses.

# Utilities

## Test Compatibility

In the `/utilities` directory, you can run the command: `make`.

Your screen should look the like the following:
![screen shot 2017-05-21 at 5 03 16 pm 2](https://cloud.githubusercontent.com/assets/16892494/26291058/72857d4e-3e47-11e7-9d9d-6cbe7c2fd149.png)

# Sandbox

## Character Movement

In the `/sandbox/character_movement` directory, you can run the command: `make`

This shows the character `@` moving leaving a trail of `#` characters in spaces that were visited.

## Map Testing and Traversal

In the `/sandbox/map` directory, you can run the command: `make`

This shows the character `@` moving throughout the map and the viewport staying focused on the main character. As the character moves it leaves blank characters in spaces that were visited.

## Random Map Generation, Map Coloring, and Collision Detection

In the `/sandbox/map_generation` directory, you can run the command: `make`

This shows the character `@` moving throughout a colored map and the viewpoint staying focused on the main character. As the character moves the character that was originally there gets replaced.

Blue `~` represent water.
Green `^` represent grass.
Yellow `#` represent mountains.
White `*` represent snow.

You can currently only walk on grass.

Finally, based on the key that you press on the welcome screen, a random map is generated using the key input as a seed value. If your character spawns inside a mountain, you will have to press `Q` to restart and try a different seed.
