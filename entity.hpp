#pragma once
#include <string>
#include <vector>
#include "include/raylib.h"
#include "component.hpp"

class Entity {
    public:
    std::string name;
    unsigned int *id;
    vector<Component*> components;
    Entity (std::string name) {
        this->name = name;
        this->id = ComputeSHA1((unsigned char *)name.c_str(), sizeof(name));
    }
};
