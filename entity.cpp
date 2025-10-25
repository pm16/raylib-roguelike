#include "entity.hpp"

Entity::Entity() {
    this->x = 0;
    this->y = 0;
    this->tile = " ";
    this->color = RAYWHITE;
}

Entity::Entity(int x, int y, std::string tile, Color color) {
        this->x = x;
        this->y = y;
        this->tile = tile;
        this->color = color;
}

