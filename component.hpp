#pragma once

typedef struct Component{
    virtual ~Component() = 0;
};

inline Component::~Component(){}
