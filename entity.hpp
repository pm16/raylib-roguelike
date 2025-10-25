#pragma once
#include <string>
#include <map>
#include "include/raylib.h"
/*
    The tile type needs to set some properties only for MapTiles?
    Is there a way to create a type from the Tile std::map? I want to make a single place to 
    translate a string to a tile (as std::string). 

*/

namespace Tile {
    
    std::map<std::string, std::string> Tile {
        {"Unused", " "},
        {"Floor",  " "},
        {"Corridor", " "},
        {"Wall", "█"},
        {"ClosedDoor", "+"},
        {"OpenDoor", "-"},
        {"UpStairs","<"},
        {"DownStairs", ">"},
        {"SmileyFace", "☺"}
    };
}

struct Entity {
    bool explored;
    bool passable;
    bool opaque;
    std::string id;
    std::string tile;
    Vector2 position;
    Color color;
    Entity() {
        this->id = "Unused";
        this->tile = Tile::Tile[id.c_str()];
        this->position = Vector2{0,0};
        this->color = RAYWHITE;
        setFlags(this->id);
    };
    Entity(std::string id, Vector2 position, Color color) {
        this->id = id;
        this->tile = Tile::Tile[id.c_str()];
        this->position = position;
        this->color = color;
        setFlags(id);              
    };

    void setFlags(std::string id) {
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
    };
};

