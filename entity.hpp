#pragma once
#include <string>
#include "include/raylib.h"

class Entity {
    public:
    int x;
    int y;
    std::string tile;
    Color color;
    Entity();    
    Entity(int x, int y, std::string tile, Color color);
};