
#include "game.hpp"



int main() {
    Game game;

    while(game.RUNNING) {
        
        game.Draw();
        game.HandleInput();        
    }

    //game.~Game(); // this was calling the deconstructor twice.
    return 0;
}
