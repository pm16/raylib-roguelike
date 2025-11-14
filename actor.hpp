#pragma once
#include "mapTile.hpp"
#include <vector>

class Species {
    public:
    std::string name;
    std::string description;
    int baseStr;
    int baseDex;
    int baseCon;
    int baseInt;
    int baseWis;
    int baseCha;

    enum Size {
        xSmall,
        Small,
        Medium,
        Large,
        xLarge
    } size;

    int baseResFire;
    int baseResWater;
    int baseResEarth;
    int baseResAir;
    int baseResLight;
    int baseResDark;
    std::vector<Ability> abilities;
};

class Specialty {
    public:
    std::string hitDie;
    int level;
    std::string name;
    std::string description;
    std::vector<Ability> abilities;
    //std::vector<Item> forbiddenItems;
};

class Ability {
    public:
    int minValue, maxValue;
    std::string name;
    std::string description;
    //int onUse();
};

class Actor {
    public:
    MapTile mapTile;
    Species species;
    Specialty specialty;
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;
    int health, maxHealth;
    int mana, maxMana;
    std::vector<std::string> inventory;

};
