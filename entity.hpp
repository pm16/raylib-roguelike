#pragma once
#include <string>
#include <map>
#include "include/raylib.h"

struct Entity {
    bool passable;
    bool opaque;
    std::string id;
    std::string tile;
    Vector2 position;
    Color color;
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
    Entity(std::string id, Vector2 position, Color color) {
        this->id = id;
        this->tile = Tile[id.c_str()];
        this->position = position;
        this->color = color;

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

