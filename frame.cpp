#include "frame.hpp"

std::vector<MapTile> Frame::DrawFrame(int x, int y, int width, int height) {
    std::vector<MapTile> window;
    Color color = GREEN;
    for (int i = 1; i < width -1 ; i++) {
        window.push_back((MapTile){"borderHorizontal",(Vector2){(float)x + i, (float)y}, color });
        window.push_back((MapTile){"borderHorizontal",(Vector2){(float)x + i, (float)y + height -1}, color });
    };

    for (int i = 1; i < height -1 ; i++) {
        window.push_back((MapTile){"borderVertical",(Vector2){(float)x, (float)y + i}, color });
        window.push_back((MapTile){"borderVertical",(Vector2){(float)x + width -1, (float)y + i}, color });
    };

    window.push_back((MapTile){"borderTopLeft",(Vector2){(float)x, (float)y}, color });
    window.push_back((MapTile){"borderTopRight",(Vector2){(float)x + width -1, (float)y}, color });
    window.push_back((MapTile){"borderBottomLeft",(Vector2){(float)x, (float)y + height -1}, color });
    window.push_back((MapTile){"borderBottomRight",(Vector2){(float)x + width -1, (float)y + height -1}, color });
    return window;
}
