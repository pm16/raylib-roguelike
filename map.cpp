#include "map.hpp"

MapTile::MapTile(int x, int y, MapTileType id, std::string tile, Color color) {
    this->x = x;
    this->y = y;
    this->id = id;
    this->tile = tile;
    this->color = color;
}

Map::Map() {
    tileset.push_back(Tile{DARKNESS, u8" "});
    tileset.push_back(Tile{GROUND, u8"."});
    tileset.push_back(Tile{WALL, u8"#"});
    tileset.push_back(Tile{FLOOR, u8","});
    tileset.push_back(Tile{DOOR, u8"+"});
    tileset.push_back(Tile{STAIRS_UP, u8"<"});
    tileset.push_back(Tile{STAIRS_DOWN, u8">"});   

}

void Map::Generate(int width, int height) {
    for (int columns = 0; columns <= height; columns++) {
            for (int rows = 0; rows <= width; rows++) {
                tiles.push_back(MapTile{rows, columns, tileset[FLOOR].id, tileset[FLOOR].tile, GREEN});
            }
        }
}

Map::~Map() {

}