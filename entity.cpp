#include "entity.hpp"

Entity::Entity(int x, int y, std::string tile, Color color) {
        this->x = x;
        this->y = y;
        this->tile = tile;
        this->color = color;
}