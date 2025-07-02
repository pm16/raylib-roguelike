#pragma once
#include <string>
#include "include/curses.h"

class Entity {
    public:
    int x;
    int y;
    std::string tile;
    int color;
    Entity();    
    Entity(int x, int y, std::string tile, int color);
};