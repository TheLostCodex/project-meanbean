# Project Meanbean

This repository contains our working code for "Project Meanbean". This is meant to be a naive implementation of a simple game using the NCurses library to help implement a simple GUI that runs in a terminal environment.

To try the game either download the `.zip` file or run `git clone git@github.com:TheLostCodex/project-meanbean.git` in the terminal in order to clone the repository.

You can first run the compatibility test to see if your terminal supports ncurses.

## v0.0.1

Initial attempt at developing a game. 

5/24/17 - Implemented a start screen and game over screen in ASCII artwork

Game start screen:
![screen shot 2017-05-24 at 2 55 59 am 2](https://cloud.githubusercontent.com/assets/16892494/26404162/9645985e-402c-11e7-9ee4-bdc1423b5678.png)

Game over screen:
![screen shot 2017-05-24 at 2 56 59 am 2](https://cloud.githubusercontent.com/assets/16892494/26404190/ac383914-402c-11e7-927c-81fdfe419171.png)


## Utilities

### Test Compatibility

In the `/utilities` directory, you can run the command: `make`.

Your screen should look the like the following:
![screen shot 2017-05-21 at 5 03 16 pm 2](https://cloud.githubusercontent.com/assets/16892494/26291058/72857d4e-3e47-11e7-9d9d-6cbe7c2fd149.png)

## Sandbox

### Character Movement

In the `/sandbox/character_movement` directory, you can run the command: `make`

This shows the character `@` moving leaving a trail of `#` characters in spaces that were visited.

![screen shot 2017-05-21 at 5 05 44 pm 2](https://cloud.githubusercontent.com/assets/16892494/26291105/c2fc2be2-3e47-11e7-8f42-db1e6eb2f50f.png)

### Map Testing and Traversal

In the `/sandbox/map` directory, you can run the command: `make`

This shows the character `@` moving throughout the map and the viewport staying focused on the main character. As the character moves it leaves blank characters in spaces that were visited.

![screen shot 2017-05-21 at 5 06 45 pm 2](https://cloud.githubusercontent.com/assets/16892494/26291121/e528e6b0-3e47-11e7-918c-563d8ed1b8fe.png)


### Random Map Generation, Map Coloring, and Collision Detection

In the `/sandbox/map_generation` directory, you can run the command: `make`

This shows the character `@` moving throughout a colored map and the viewpoint staying focused on the main character. As the character moves the character that was originally there gets replaced.

Blue `~` represent water.  
Green `^` represent grass.  
Yellow `#` represent mountains.  
White `*` represent snow.  

You can currently only walk on grass.

Finally, based on the key that you press on the welcome screen, a random map is generated using the key input as a seed value. If your character spawns inside a mountain, you will have to press `Q` to restart and try a different seed.

![screen shot 2017-05-21 at 5 07 32 pm 2](https://cloud.githubusercontent.com/assets/16892494/26291140/00f8263a-3e48-11e7-914f-5fea4d023d56.png)

### Monster Chase

In the `sandbox/monster_chase` directory, you can run the command: `make`

This shows the character `@` and the monster `$` in a colored map with the viewpoint staying focuses on the main character. As the character moves, the monster attempts to chase the main character. The monster moves using an algorithm attempting to minimize the Euclidean distance (distance formula) between the monster and the character. When the monster catches the player, a game over screen is displayed.

Random generation of the map has been disabled for this module because sometimes the monster would spawn in an unreachable location (i.e. in a mountain). The starting location of the monster has been hard-coded.

![screen shot 2017-05-23 at 11 39 45 am 2](https://cloud.githubusercontent.com/assets/16892494/26377578/917251e4-3fac-11e7-92e1-9b4ad153b234.png)
