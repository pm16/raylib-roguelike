#pragma once
#include "include/raylib.h"
#include <random>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <entity.hpp>

struct Rect {
    int x, y;
    int width, height;
};

class Dungeon {
    private:
	int _width, _height;
	std::vector<Entity> _tiles;
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
		, _tiles(width * height, Entity{"Unused", Vector2{0,0}, RAYWHITE})
		, _rooms()
		, _exits() 
	{}

    void generate(int maxFeatures);
    void print();
    std::vector<Entity> getMap();
    Entity getTile(Vector2 position);

    private:
    Entity getTile(int x, int y) const;
    void setTile(int x, int y, const char* tile);
    bool createFeature();
    bool createFeature(int x, int y, Direction dir);
    bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);
    bool makeCorridor(int x, int y, Direction dir);
    bool placeRect(const Rect& rect, const char* tile);
    bool placeObject(const char* tile);
};