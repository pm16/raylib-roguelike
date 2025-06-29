#include "include/raylib.h"
#include "include/raymath.h"
#include <algorithm>

int main() {
    int window_width = 800;
    int window_height = 600;
    
    int canvas_width = 480;
    int canvas_height = 270;
    
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitWindow(window_width, window_height, "Roguelike game");
    SetTargetFPS(60);
    // must run after InitWindow
    RenderTexture2D canvas = LoadRenderTexture(canvas_width, canvas_height);
    SetTextureFilter(canvas.texture, TEXTURE_FILTER_POINT);

    while(!WindowShouldClose()) {
        float scale = std::min((float)window_width / canvas_width, (float)window_height / canvas_height);
        
        BeginTextureMode(canvas);
            ClearBackground(BLACK);
            DrawText("Hello World!", canvas_width / 2, canvas_height / 2, 20, RAYWHITE);
        EndTextureMode();
        
        BeginDrawing();
            ClearBackground(WHITE);
            // Draw render texture to screen, properly scaled
            DrawTexturePro(canvas.texture, (Rectangle){ 0.0f, 0.0f, (float)canvas.texture.width, (float)-canvas.texture.height },
                        (Rectangle){ (window_width - ((float)canvas_width*scale))*0.5f, (window_height - ((float)canvas_height*scale))*0.5f,
                        (float)window_width*scale, (float)window_height*scale }, (Vector2){ 0, 0 }, 0.0f, WHITE);
        EndDrawing();
    }

    UnloadRenderTexture(canvas);
    CloseWindow();

    return 0;
}
