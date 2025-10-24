#pragma once
#include <random>
#include <vector>
#include <iostream>
#include <string>
#include "map.hpp"

struct Rect {
    int x, y;
    int width, height;
};

class Dungeon {
    private:
	int _width, _height;
	std::vector<char> _tiles;
	std::vector<Rect> _rooms; // rooms for place stairs or monsters
	std::vector<Rect> _exits; // 4 sides of rooms or corridors
    
    public:
    enum Tile {
		Unused		= ' ',
		Floor		= '.',
		Corridor	= ',',
		Wall		= '#',
		ClosedDoor	= '+',
		OpenDoor	= '-',
		UpStairs	= '<',
		DownStairs	= '>'
	};

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
		, _tiles(width * height, Unused)
		, _rooms()
		, _exits() 
	{}

    void generate(int maxFeatures);
    void print();
    std::vector<MapTile> getMap();

    private:
    char getTile(int x, int y) const;
    void setTile(int x, int y, char tile);
    bool createFeature();
    bool createFeature(int x, int y, Direction dir);
    bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);
    bool makeCorridor(int x, int y, Direction dir);
    bool placeRect(const Rect& rect, char tile);
    bool placeObject(char tile);


};