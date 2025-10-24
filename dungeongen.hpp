#pragma once
#include "include/raylib.h"
#include <random>
#include <vector>
#include <iostream>
#include <string>
#include <map>

struct Rect {
    int x, y;
    int width, height;
};

struct MapTile {
    bool explored;
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
        {"DownStairs", ">"}
    };

    MapTile(std::string id, Vector2 position, Color color) {
        this->id = id;
        this->tile = Tile[id.c_str()];
        this->position = position;
        this->color = color;

        if (this-> id == "Unused") {
            this->explored = false;
            this->passable = false;
            this->opaque = true;
        }
        else if (this->id == "Floor") {
            this->explored = false;
            this->passable = true;
            this->opaque = false;
        }
        else if (this->id == "Corridor") {
            this->explored = false;
            this->passable = true;
            this->opaque = false;
        }
        else if (this->id == "Wall") {
            this->explored = false;
            this->passable = false;
            this->opaque = true;            
        }
        else if (this->id == "ClosedDoor") {
            this->explored = false;
            this->passable = false;
            this->opaque = true;            
        }
        else if (this->id == "OpenDoor") {
            this->explored = false;
            this->passable = true;
            this->opaque = false;            
        }
        else if (this->id == "UpStairs") {
            this->explored = false;
            this->passable = true;
            this->opaque = false;            
        }
        else if (this->id == "DownStairs") {
            this->explored = false;
            this->passable = true;
            this->opaque = false;            
        }      
    }
};


class Dungeon {
    private:
	int _width, _height;
	std::vector<MapTile> _tiles;
	std::vector<Rect> _rooms; // rooms for place stairs or monsters
	std::vector<Rect> _exits; // 4 sides of rooms or corridors
    
    public:
    enum Direction {
        North,
		South,
		West,
		East,
		DirectionCount
    };
   
    Dungeon(int width, int height): 
        _width(width)
		, _height(height)
		, _tiles(width * height, MapTile{"Unused", Vector2{0,0}, RAYWHITE})
		, _rooms()
		, _exits() 
	{}

    void generate(int maxFeatures);
    void print();
    std::vector<MapTile> getMap();
    MapTile getTile(Vector2 position);

    private:
    MapTile getTile(int x, int y) const;
    void setTile(int x, int y, const char* tile);
    bool createFeature();
    bool createFeature(int x, int y, Direction dir);
    bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);
    bool makeCorridor(int x, int y, Direction dir);
    bool placeRect(const Rect& rect, const char* tile);
    bool placeObject(const char* tile);
};