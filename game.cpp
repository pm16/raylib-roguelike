#include "game.hpp"
#include <algorithm>

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
    
   
     map = Map();
     //map.Generate(40, 25, (Vector2){(float)40 / 2, (float)25 / 2});
     
     dungeon.generate(10);
     player = Entity(40 / 2, 25 / 2, "☺", GREEN);
    for (MapTile tile : dungeon.getMap()) {
        if (tile.tile == "<") {
            player.x = tile.x;
            player.y = tile.y;
        }
    }
     
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
    DrawTextEx(font, tile.c_str(), 
    (Vector2){(float)x * TILE_DIMENSIONS.x, (float)y * TILE_DIMENSIONS.y}, 
    font_size, 0, color);
}

void Game::DrawTile(Entity entity) {
DrawTextEx(font, entity.tile.c_str(), 
(Vector2){(float)entity.x * TILE_DIMENSIONS.x, (float)entity.y * TILE_DIMENSIONS.y}, 
font_size, 0, entity.color);
}

Game::~Game() {
    UnloadFont(font);
    UnloadRenderTexture(canvas);
    CloseWindow();    
}