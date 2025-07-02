#include "entity.hpp"

Entity::Entity() {
    this->x = 0;
    this->y = 0;
    this->tile = " ";
    this->color = COLOR_WHITE;
}

Entity::Entity(int x, int y, std::string tile, int color) {
        this->x = x;
        this->y = y;
        this->tile = tile;
        this->color = color;
}