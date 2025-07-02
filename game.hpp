#pragma once
#include "include/raylib.h"
#include "entity.hpp"
#include <string>
#include "map.hpp"

class Game {
    public:
    int windowWidth;
    int windowHeight;

    int canvasWidth;
    int canvasHeight;

    int tilesWide;
    int tilesHigh;

    float scale;
    RenderTexture2D canvas;

    int font_size;
    Font font;

    Vector2 TILE_DIMENSIONS;
    
    std::string title;

    Entity player;
    Map map;

    Game();
    void Initialize();
    void Update();
    void Draw();
    void HandleInput();
    void DrawTile(int x, int y , std::string tile, Color color);
    void DrawTile(Entity entity);
    ~Game();
};