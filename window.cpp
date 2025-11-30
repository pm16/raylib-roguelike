#include "window.hpp"

std::vector<MapTile> Window::DrawWindow(int x, int y, int width, int height) {
    std::vector<MapTile> window;
    for (int i = 0; i < width ; i++) {
        window.push_back((MapTile){"borderHorizontal",(Vector2){x + i, y}, RAYWHITE });
        window.push_back((MapTile){"borderHorizontal",(Vector2){x + i, y + height}, RAYWHITE });
    };

    for (int i = 0; i < height ; i++) {
        window.push_back((MapTile){"borderHorizontal",(Vector2){x, y + i}, RAYWHITE });
        window.push_back((MapTile){"borderHorizontal",(Vector2){x + width, y + i}, RAYWHITE });
    };

    window.push_back((MapTile){"borderTopLeft",(Vector2){x, y}, RAYWHITE });
    window.push_back((MapTile){"borderTopRight",(Vector2){x + width, y}, RAYWHITE });
    window.push_back((MapTile){"borderBottomLeft",(Vector2){x, y + height}, RAYWHITE });
    window.push_back((MapTile){"borderBottomRight",(Vector2){x + width, y + height}, RAYWHITE });
    return window;
}