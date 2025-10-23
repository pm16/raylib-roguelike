## New roguelike game
Creating a game on my own without a tutorial since I'm having trouble getting libtcod to work with C++.
Raylib textdrawing doesn't do the unicode characters correctly, so I'll need to add some custom files.

## TODO
- [] Make a better Makefile, need to handle building on other systems and building on windows

- [] step 1, render a font as tiles. I think I want to use the [BlexMono nerd font](https://github.com/ryanoasis/nerd-fonts/releases/download/v3.4.0/IBMPlexMono.zip).
    - [] Maybe use [Alloy Curses 12x12 font from the libtcod tutorial](https://raw.githubusercontent.com/HexDecimal/python-tcod-tutorial-2023/6b69bf9b5531963a0e5f09f9d8fe72a4001d4881/data/Alloy_curses_12x12.png)
    - [] Figure out how to use the above tilesheet as a font.
- [X] Move everything back to raylib.
- [X] Create class for the game engine
    - [] load assets
    - [] initialize
    - [] update game state
    - [] render game state
    - [] handle input
- [X] Create entity class
- [] Create state machine
    - [] Move input handling to its associated state
    - [] Move draing to its associated state
    - [] Move updating to its associated state
    - [] Create state stack and use it
- [] Display map in a view port, use a camera to scroll around so the map can be much larger than the screen.
    Total screen size is 80x25 tiles
    Maybe set the view port to 40x20 tiles
- [] Add settings
    - [] Store settings in a .json file?
    - [] Custom tilesets or fonts?
- [] Add log to the UI
- [] Add a menu system
- [] Display some stats on the UI
- [] Map class
- [] Map generator
- [] Add saving and loading
- [] Build on windows
    - [] Check window resizing
- [] Enable resizeable window
    - [X] Minimum size needs to be set to tilesize * width and height
    - [] calculate new scale when the screen is resized.