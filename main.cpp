#include "include/raylib.h"
#include "game.hpp"



int main() {
    Game game;

    while(!WindowShouldClose()) {
        
        game.Draw();
        game.HandleInput();        
    }

    game.~Game();
    return 0;
}
