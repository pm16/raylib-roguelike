#pragma once
#include "include/raylib.h"
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

    MapTile player;
    Dungeon dungeon = Dungeon(80,50);

    enum State {
        Movement,
        Open
    };

    int state;

    Game();
    void Initialize();
    void Update();
    void Draw();
    void HandleInput();
    void DrawTile(int x, int y , std::string tile, Color color);
    void DrawTile(MapTile entity);
    void InputOpen();
    void InputMovement();
    ~Game();
};