#include "entity.hpp"

MapTile::MapTile(const char* id, Vector2 position, Color color) {
    this->id = id;
    this->tile = Tile[this->id];
    this->position = position;
    this->color = color;
    setFlags();              
}

MapTile::MapTile() {
    this->id = "Unused";
    this->tile = Tile[id.c_str()];
    this->position = Vector2{0,0};
    this->color = RAYWHITE;
    setFlags();
}

std::string MapTile::getTile() {
    return Tile[id.c_str()];
}

void MapTile::setFlags() {
    this->explored = false;

    if (this-> id == "Unused") {
        this->passable = false;
        this->opaque = true;
    }
    else if (this->id == "Floor") {
        this->passable = true;
        this->opaque = false;
    }
    else if (this->id == "Corridor") {
        this->passable = true;
        this->opaque = false;
    }
    else if (this->id == "Wall") {
        this->passable = false;
        this->opaque = true;            
    }
    else if (this->id == "ClosedDoor") {
        this->passable = false;
        this->opaque = true;            
    }
    else if (this->id == "OpenDoor") {
        this->passable = true;
        this->opaque = false;            
    }
    else if (this->id == "UpStairs") {
        this->passable = true;
        this->opaque = false;            
    }
    else if (this->id == "DownStairs") {
        this->passable = true;
        this->opaque = false;            
    }
    else if (this->id == "SmileyFace") {
        this->passable = false;
        this->opaque = true;            
    }
}