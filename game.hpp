#pragma once
#include "include/raylib.h"
#include "include/raymath.h"
#include "entity.hpp"
#include <algorithm>
#include <string>

class Game {
    public:
    Vector2 TILE_DIMENSIONS;
    Vector2 TILES;
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;

    std::string TITLE;

    Rectangle CANVAS_RECT;
    Rectangle WINDOW_RECT;
    RenderTexture2D CANVAS;
    Font FONT;
    int FONT_SIZE;
    float SCREEN_SCALE;

    Entity player;

    Game();
    void Initialize();
    void Update();
    void Draw();
    void HandleInput();
    void DrawTile(int x, int y , std::string tile, Color color);
    void DrawTile(Entity entity);
    ~Game();
};