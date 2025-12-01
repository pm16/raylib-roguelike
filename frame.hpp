#pragma once
#include "include/raylib.h"
#include "mapTile.hpp"
#include <string>
#include <vector>

class Frame {

    //TODO: Scrollbar and up/down arrows, paging left and right arrows too.

    public:
    std::vector<MapTile> DrawFrame(int x, int y, int width, int height);
};
