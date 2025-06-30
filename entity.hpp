#pragma once
#include "include/raylib.h"
#include <string>

class Entity {
    public:
    int x;
    int y;
    std::string tile;
    Color color;    
    Entity(int x, int y, std::string tile, Color color);
};