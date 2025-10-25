#pragma once
#include <string>
#include <map>
#include "include/raylib.h"

class MapTile {
    public:
    bool explored;
    bool passable;
    bool opaque;
    std::string id;
    std::string tile;
    Vector2 position;
    Color color;
    
    MapTile();
    MapTile(const char* id, Vector2 position, Color color);
    
    std::string getTile();

    private:
    void setFlags();

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
    
};



