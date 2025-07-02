#pragma once
#include "include/curses.h"
#include "entity.hpp"
#include <string>
#include "map.hpp"

class Game {
    public:
   
    bool RUNNING;
    std::string TITLE;

    Entity player;
    Map map;

    Game();
    void Initialize();
    void Update();
    void Draw();
    void HandleInput();
    void DrawTile(int x, int y , std::string tile, int color);
    void DrawTile(Entity entity);
    ~Game();
};