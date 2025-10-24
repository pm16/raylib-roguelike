#pragma once
#include "include/raylib.h"
#include "entity.hpp"
#include <string>
#include "load_font.hpp"
#include "dungeongen.hpp"

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
    Dungeon dungeon = Dungeon(50,50);

    Game();
    void Initialize();
    void Update();
    void Draw();
    void HandleInput();
    void DrawTile(int x, int y , std::string tile, Color color);
    void DrawTile(Entity entity);
    ~Game();
};