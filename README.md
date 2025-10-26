## New roguelike game
Creating a game on my own without a tutorial since I'm having trouble getting libtcod to work with C++.
Raylib textdrawing doesn't do the unicode characters correctly, so I'll need to add some custom files. 
Using [Raylib](https://github.com/raysan5/raylib) to create a rogue-like game.

## Build instructions (Linux)
01. Follow the [Raylib](https://github.com/raysan5/raylib) build instructions for your distro to install the dependencies.
02. Clone this repo and enter its directory.
03. ```mkdir build```
04. ```make game```
05. ```./build/game```

## TODO
- [ ] Make a better Makefile, need to handle building on other systems and building on windows

- [X] step 1, render a font as tiles.
    - [X] Maybe use [Alloy Curses 12x12 font from the libtcod tutorial](https://raw.githubusercontent.com/HexDecimal/python-tcod-tutorial-2023/6b69bf9b5531963a0e5f09f9d8fe72a4001d4881/data/Alloy_curses_12x12.png)
    - [X] Figure out how to use the above tilesheet as a font.
    - [X] downloaded [PerfectDOSVGA437.ttf](https://cp437.github.io/) to use with loadfontex and the codepoint example. -- does not work as intended --
- [X] Move everything back to raylib.
- [X] Create class for the game engine
    - [ ] load assets
    - [ ] initialize
    - [ ] update game state
    - [ ] render game state
    - [ ] handle input
        - [ ] Abstract input so it can be used with a 6 button controller. Use the menuing system for interactions.
        - [ ] Use a button for default interaction with a direction as the second input.
        - [ ] Second button will bring up a context menu, which will bring up another context menu in a menu.
            - [ ] First button will select the default action for the selection in a menu like inventory (i.e., if over a potion then quaff).
- [X] Create entity class
    - [ ] NPCs
    - [ ] Monsters
    - [ ] Items
    - [ ] Interactable tiles
- [ ] Create state machine
    - [ ] Move input handling to its associated state
    - [ ] Move draing to its associated state
    - [ ] Move updating to its associated state
    - [ ] Create state stack and use it
- [ ] Display map in a view port, use a camera to scroll around so the map can be much larger than the screen.
    Total screen size is 80x25 tiles
    Maybe set the view port to 40x20 tiles
- [ ] Add settings
    - [ ] Store settings in a .json file?
    - [ ] Custom tilesets or fonts?
- [ ] Add log to the UI
- [ ] Add a menu system
    - [ ] Use menu system for interaction.
- [ ] Display some stats on the UI
- [ ] Map class
- [ ] Map generator
    - [X] Basic map generator
        - [ ] Ensure all rooms are reachable
        - [ ] Ensure there is a path from the up stairs to the down stairs
    - [ ] Cave generator
    - [ ] Town generator
- [ ] Add saving and loading
- [ ] Build on windows
    - [ ] Check window resizing
- [ ] Enable resizeable window
    - [X] Minimum size needs to be set to tilesize * width and height
    - [ ] calculate new scale when the screen is resized.