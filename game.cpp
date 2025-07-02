#include "game.hpp"
#include <algorithm>


Game::Game() {
    /* Initialize curses*/
    
    initscr();
    /* Set color pairs*/

    init_pair(1, COLOR_WHITE, COLOR_BLACK);


    TITLE = "Roguelike game";
   
    RUNNING = true;
     player = Entity(4, 4, u8"@", COLOR_WHITE);
     map = Map();
     map.Generate(80, 25);
}

void Game::Initialize() {
    
    
}

void Game::Update() {

}

void Game::Draw() {
           
    for (MapTile tile : map.tiles) {
        DrawTile(tile);
    }

    DrawTile(player);       
    
    refresh();
    
}

void Game::HandleInput() {
    noecho();
    int ch = getch();
     if (ch == KEY_UP) {
        player.y -= 1;        
    }

    if (ch == KEY_DOWN) {
        player.y += 1;
    }

   if (ch == KEY_LEFT) {
        player.x -= 1;
    }

    if (ch == KEY_RIGHT) {
        player.x += 1;
    }

    if (ch == 'q') {
        RUNNING = false;
    }

}

void Game::DrawTile(int x, int y, std::string tile, int color) {
    mvprintw(y, x, tile.c_str());
   
   
    // DrawTextEx(FONT, tile.c_str(), 
   // (Vector2){(float)x * TILE_DIMENSIONS.x, (float)y * TILE_DIMENSIONS.y}, 
   // FONT_SIZE, 0, color);
}

void Game::DrawTile(Entity entity) {
   // DrawTextEx(FONT, entity.tile.c_str(), 
   // (Vector2){(float)entity.x * TILE_DIMENSIONS.x, (float)entity.y * TILE_DIMENSIONS.y}, 
   // FONT_SIZE, 0, entity.color);
}

Game::~Game() {
   // UnloadFont(FONT);
    //UnloadRenderTexture(CANVAS);
    //CloseWindow();
    endwin();
}