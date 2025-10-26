#include "game.hpp"
#include <algorithm>
#include "include/raymath.h"

Game::Game() {
    /* Initialize raylib*/
    
    windowWidth = 1280;
    windowHeight = 720;

    // Enable config flags for resizable window and vertical synchro
    //SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);
    title = "Roguelike game";
    InitWindow(windowWidth, windowHeight, title.c_str());
    
    tilesWide = 80;
    tilesHigh = 50;
    // Load font
    font_size = 24;
    font = load_font_cp437("assets/Alloy_curses_12x12.png", 12);
    TILE_DIMENSIONS = MeasureTextEx(font, "X", font_size, 0);
    canvasWidth = tilesWide * TILE_DIMENSIONS.x;
    canvasHeight = tilesHigh * TILE_DIMENSIONS.y;
    SetWindowMinSize(canvasWidth, canvasHeight);
    // Render texture initialization, used to hold the rendering result so we can easily resize it
    canvas = LoadRenderTexture(canvasWidth, canvasHeight);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_POINT);  // Texture scale filter to use
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    scale = std::min((float)GetScreenWidth()/canvasWidth, (float)GetScreenHeight()/canvasHeight);
    
          
     dungeon.generate(std::rand() % 100 + 10);
     player = MapTile("SmileyFace", Vector2{0,0}, GREEN);
    for (MapTile tile : dungeon.getMap()) {
        if (tile.tile == "<") {
            player.position = tile.position;
        }
    }

    state = State::Movement;
     
}

void Game::Initialize() {
    
    
}

void Game::Update() {

}

void Game::Draw() {
    BeginTextureMode(canvas);
        ClearBackground(BLACK);  // Clear render texture background color

            
        for (MapTile tile : dungeon.getMap()) {
        DrawTile(tile);
    }

        DrawTile(player); 
            
    EndTextureMode();
        
    BeginDrawing();
        ClearBackground(RAYWHITE);     // Clear screen background

        // Draw render texture to screen, properly scaled
        DrawTexturePro(canvas.texture, (Rectangle){ 0.0f, 0.0f, (float)canvas.texture.width, (float)-canvas.texture.height },
                        (Rectangle){ (GetScreenWidth() - ((float)canvasWidth*scale))*0.5f, (GetScreenHeight() - ((float)canvasHeight*scale))*0.5f,
                        (float)canvasWidth*scale, (float)canvasHeight*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
    EndDrawing();
           
    
}

void Game::HandleInput() {
    switch (state) {
        case State::Movement :
        InputMovement();
        break;

        case State::DefaultInteract :
        InputDefaultInteract();
        break;
    }    
}

void Game::InputMovement() {
    Vector2 previous = player.position;

    if (IsKeyPressed(KEY_UP)) {
        player.position.y -= 1;        
    }

    if (IsKeyPressed(KEY_DOWN)) {
        player.position.y += 1;
    }

   if (IsKeyPressed(KEY_LEFT)) {
        player.position.x -= 1;
    }

    if (IsKeyPressed(KEY_RIGHT)) {
        player.position.x += 1;
    }

    if (!dungeon.getTile(player.position).passable) {
        player.position = previous;
    }  

    if (IsKeyPressed(KEY_Z)) {        
          std::cout << "Which direction?\n";
        // Pause and wait for input.    
        state = State::DefaultInteract;
    }

    if (IsKeyPressed(KEY_X)) {
        std::cout << "Entered Menu.\n";
        // TODO
    }
}

void Game::InputDefaultInteract() {
    bool keypressed = false;
    Vector2 interactDirection = Vector2{0,0};

    if (IsKeyPressed(KEY_UP)) {
        interactDirection = Vector2Add(player.position, Vector2{0, -1}); 
        keypressed = true;        
    }

    if (IsKeyPressed(KEY_DOWN)) {
        interactDirection = Vector2Add(player.position, Vector2{0, 1});
        keypressed = true;        
    }

   if (IsKeyPressed(KEY_LEFT)) {
        interactDirection = Vector2Add(player.position, Vector2{-1, 0});
        keypressed = true;        
    }

    if (IsKeyPressed(KEY_RIGHT)) {
        interactDirection = Vector2Add(player.position, Vector2{1, 0});
        keypressed = true;        
    }

    if (IsKeyPressed(KEY_Z)) {
        interactDirection = player.position;
        keypressed = true;
    }

    if (IsKeyPressed(KEY_X)) {
        std::cout << "Cancelled.\n";
        state = State::Movement;
    }

    if (keypressed == true) {
        dungeon.defaultInteract(interactDirection);
        state = State::Movement;
    }



}

void Game::DrawTile(int x, int y, std::string tile, Color color) {
    DrawTextEx(font, tile.c_str(), 
    (Vector2){(float)x * TILE_DIMENSIONS.x, (float)y * TILE_DIMENSIONS.y}, 
    font_size, 0, color);
}

void Game::DrawTile(MapTile entity) {
DrawTextEx(font, entity.tile.c_str(), 
(Vector2){(float)entity.position.x * TILE_DIMENSIONS.x, (float)entity.position.y * TILE_DIMENSIONS.y}, 
font_size, 0, entity.color);
}

Game::~Game() {
    UnloadFont(font);
    UnloadRenderTexture(canvas);
    CloseWindow();    
}