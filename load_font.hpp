#pragma once
#include "include/raylib.h"
#include <string>

Font load_font_cp437(std::string font_file, int base_size);
int convert_to_unicode(int code);