#include "include/raylib.h"
#include "include/raymath.h"
#include "game.hpp"
#include <algorithm>
#include <string>


int main() {
    Game game;

    while(!WindowShouldClose()) {
        
        game.Draw();
        game.HandleInput();        
    }

    game.~Game();
    return 0;
}
