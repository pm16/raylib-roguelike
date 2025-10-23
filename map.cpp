#include "map.hpp"

MapTile::MapTile(int x, int y, MapTileType id, std::string tile, Color color) {
    this->x = x;
    this->y = y;
    this->id = id;
    this->tile = tile;
    this->color = color;
}
template <typename T>
const T& getRandomElement(const std::unordered_set<T>& s) {
    // Check if the set is empty (crucial to avoid crashes)
    if (s.empty()) {
        throw std::runtime_error("Cannot select a random element from an empty set.");
    }

    // Generate the random index
    size_t random_index = rand() % s.size();

    // Advance the iterator
    // Start at the beginning of the set
    auto it = s.begin();
    // Use std::advance to efficiently move the iterator to the random position
    std::advance(it, random_index);

    // 6. Return the element
    // The dereferenced iterator is the random element
    return *it;
}

Map::Map() {
    tileset.push_back(Tile{DARKNESS, " "});
    tileset.push_back(Tile{GROUND, ","});
    tileset.push_back(Tile{WALL, "█"});
    tileset.push_back(Tile{FLOOR, "."});
    tileset.push_back(Tile{DOOR, "+"});
    tileset.push_back(Tile{STAIRS_UP, "<"});
    tileset.push_back(Tile{STAIRS_DOWN, ">"});   

}

void Map::Generate(int width, int height) {
    /*for (int columns = 0; columns <= height; columns++) {
            for (int rows = 0; rows <= width; rows++) {
                tiles.push_back(MapTile{rows, columns, tileset[FLOOR].id, tileset[FLOOR].tile, GRAY});
            }
        }
    */

    Vector2 start_position = Vector2Zero();
    int iterations = 10;
    int walk_length = 10;
    bool start_randomly_each_iteration = true;

    std::unordered_set<Vector2> floor_positions = run_random_walk(iterations, walk_length, start_randomly_each_iteration, start_position);
    for (Vector2 position : floor_positions) {
        std::cout << position.x << ", " << position.y << std::endl;
        tiles.push_back(MapTile{(int)position.x, (int)position.y, tileset[FLOOR].id, tileset[FLOOR].tile, GRAY});
    }
}

std::unordered_set<Vector2> Map::run_random_walk(int iterations, int walk_length, bool start_randomly_each_iteration, Vector2 start_position) {
    Vector2 current_position = start_position;
    std::unordered_set<Vector2> floor_positions;

    for (int i = 0; i < iterations; i++) {
        std::unordered_set<Vector2> path = simple_random_walk(current_position, walk_length);
        floor_positions.merge(path);
        if (start_randomly_each_iteration) {
            current_position = getRandomElement(floor_positions);
        }
    }
    return floor_positions;
}

std::unordered_set<Vector2> Map::simple_random_walk(Vector2 start_position, int walk_length) {
    srand(time(0));
    std::unordered_set<Vector2> path;
    path.insert(start_position);    
    Vector2 previous_position = start_position;

    for (int i = 0; i < walk_length; i++) {
        Vector2 new_position = Vector2Add(previous_position, get_random_cardinal_direction(direction2d()));
        path.insert(new_position);
        previous_position=new_position; 
    }

    return path;
}

std::vector<Vector2> Map::direction2d() {
    std::vector<Vector2> cardinal_direction_list;
    cardinal_direction_list.push_back((Vector2){0,1}); // Up
    cardinal_direction_list.push_back((Vector2){1,0}); // Right
    cardinal_direction_list.push_back((Vector2){0,-1}); // Down
    cardinal_direction_list.push_back((Vector2){-1,0}); // Left

    return cardinal_direction_list;
}

Vector2 Map::get_random_cardinal_direction(std::vector<Vector2> directions) {
    return directions[rand() % directions.size()];
}

Map::~Map() {

}