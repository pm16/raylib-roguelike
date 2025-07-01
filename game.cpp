#include "game.hpp"
#include "include/raymath.h"
#include <algorithm>
#include <iostream>


Game::Game() {
    WINDOW_WIDTH = 1280;
    WINDOW_HEIGHT = 720;
    TITLE = "Roguelike game";

    FONT_SIZE = 20;
    //SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, TITLE.c_str());
    SetTargetFPS(60);
    // must run after InitWindow
        
    FONT = LoadFontEx("./assets/BlexMonoNerdFontMono-Regular.ttf", FONT_SIZE, NULL, 256);
    //FONT = LoadFontEx("./assets/Unifontexmono.ttf", FONT_SIZE, NULL, 256);
    Vector2 font_dimensions = MeasureTextEx(FONT, "@", FONT_SIZE, 0);
    TILE_DIMENSIONS.x = font_dimensions.x;
    TILE_DIMENSIONS.y = font_dimensions.y;
    TILES = {80, 25};
    int canvas_width = TILE_DIMENSIONS.x * TILES.x;
    int canvas_height = TILE_DIMENSIONS.y * TILES.y;
    
    CANVAS = LoadRenderTexture(canvas_width, canvas_height);
    SetTextureFilter(CANVAS.texture, TEXTURE_FILTER_POINT);
    
    SCREEN_SCALE = std::min((float)GetScreenWidth() / (float)CANVAS.texture.width, (float)GetScreenHeight() / (float)CANVAS.texture.height);
    
    CANVAS_RECT = {0, 0, (float)CANVAS.texture.width, -(float)CANVAS.texture.height};
    WINDOW_RECT = {(GetScreenWidth() - ((float)CANVAS.texture.width * SCREEN_SCALE))*0.5f,
        (GetScreenHeight() - ((float)CANVAS.texture.height * SCREEN_SCALE))*0.5f,
        (float)GetScreenWidth(), (float)GetScreenHeight() };

     player = Entity(4, 4, u8"@", RAYWHITE);
     map = Map();
     map.Generate(80, 25);
}

void Game::Initialize() {
    
    
}

void Game::Update() {

}

void Game::Draw() {
    // Draw to scaleable texture
    BeginTextureMode(CANVAS);
        ClearBackground(BLACK);
        
        
        /*for (MapTile tile : map.tiles) {
            DrawTile(tile);
        }*/
        
        DrawTile(100, 100, "Þ", BLUE);

        DrawTile(player);

        //int i = 0;
        //for (int y = 0; y <=25; y++) {
         //   for (int x = 0; x <= 80; x++){
         //       DrawTextCodepoint(FONT, i, (Vector2){(float)x * TILE_DIMENSIONS.x, (float)y*TILE_DIMENSIONS.y}, 20, WHITE);
         //       i++;
         //       if (i > 256) {
         //           break;
         //       }
         //   }
       // }
       
        
    EndTextureMode();
    
    // Draw texture to window
    BeginDrawing();
        ClearBackground(WHITE);
        // Draw render texture to screen, properly scaled
        DrawTexturePro(CANVAS.texture, CANVAS_RECT, 
            WINDOW_RECT,(Vector2){ 0, 0 }, 0.0f, WHITE);
    EndDrawing();    
}

void Game::HandleInput() {
    if (IsKeyPressed(KEY_UP)) {
        player.y -= 1;        
    }

    if (IsKeyPressed(KEY_DOWN)) {
        player.y += 1;
    }

    if (IsKeyPressed(KEY_LEFT)) {
        player.x -= 1;
    }

    if (IsKeyPressed(KEY_RIGHT)) {
        player.x += 1;
    }

}

void Game::DrawTile(int x, int y, std::string tile, Color color) {
    DrawTextEx(FONT, tile.c_str(), 
    (Vector2){(float)x * TILE_DIMENSIONS.x, (float)y * TILE_DIMENSIONS.y}, 
    FONT_SIZE, 0, color);
}

void Game::DrawTile(Entity entity) {
    DrawTextEx(FONT, entity.tile.c_str(), 
    (Vector2){(float)entity.x * TILE_DIMENSIONS.x, (float)entity.y * TILE_DIMENSIONS.y}, 
    FONT_SIZE, 0, entity.color);
}

Game::~Game() {
    UnloadFont(FONT);
    UnloadRenderTexture(CANVAS);
    CloseWindow();
}