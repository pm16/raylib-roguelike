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
    tilesHigh = 25;
    // Load font
    font_size = 12;
    int *codepoints = (int *)calloc(256, sizeof(int));
    //font = LoadFontEx("assets/BlexMonoNerdFontMono-Regular.ttf", font_size, NULL, 0);
    font = LoadFontEx("assets/Alloy_curses_12x12.png", font_size, codepoints, 256);
    TILE_DIMENSIONS = MeasureTextEx(font, u8"X", font_size, 0);
    canvasWidth = tilesWide * TILE_DIMENSIONS.x;
    canvasHeight = tilesHigh * TILE_DIMENSIONS.y;
    SetWindowMinSize(canvasWidth, canvasHeight);
    // Render texture initialization, used to hold the rendering result so we can easily resize it
    canvas = LoadRenderTexture(canvasWidth, canvasHeight);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_POINT);  // Texture scale filter to use
    SetTargetFPS(60);                   // Set our game to run at 60 frames-per-second
    scale = std::min((float)GetScreenWidth()/canvasWidth, (float)GetScreenHeight()/canvasHeight);
    
   
    
     player = Entity(4, 4, u8"@", WHITE);
     map = Map();
     map.Generate(80, 25);
}

void Game::Initialize() {
    
    
}

void Game::Update() {

}

void Game::Draw() {
    BeginTextureMode(canvas);
        ClearBackground(BLACK);  // Clear render texture background color

            
        for (MapTile tile : map.tiles) {
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
    DrawTextCodepoint(font, 156, 
    (Vector2){(float)x * TILE_DIMENSIONS.x, (float)y * TILE_DIMENSIONS.y}, 
    font_size, color);
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