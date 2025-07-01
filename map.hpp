#pragma once
#include "entity.hpp"
#include <vector>

enum MapTileType {
    DARKNESS,
    GROUND,
    WALL,
    FLOOR,
    DOOR,
    STAIRS_UP,
    STAIRS_DOWN    
};

struct Tile {
    MapTileType id;
    std::string tile;
};

class MapTile: public Entity {
    public:
    MapTileType id;
    MapTile(int x, int y, MapTileType id, std::string tile, Color color);
};

class Map {
    public:
    std::vector<Tile> tileset;
    std::vector<MapTile> tiles;
    Map();
    void Generate(int width, int height);

    ~Map();
};