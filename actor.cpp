/*#include "actor.hpp"

Actor::initializeSpecies() {
    std::vector<Species> speciesList;
    Species currentSpecies;
    currentSpecies.baseStr = 10;
    currentSpecies.baseDex = 10;
    currentSpecies.baseCon = 10;
    currentSpecies.baseInt = 10;
    currentSpecies.baseWis = 10;
    currentSpecies.baseCha = 10;
    currentSpecies.size = Species::Size::Medium;
    currentSpecies.name = "Human";
    currentSpecies.description = "Default human.\nThere is nothing particularly intresting about this species.";
    currentSpecies.baseResAir = 0;
    currentSpecies.baseResDark = 0;
    currentSpecies.baseResEarth = 0;
    currentSpecies.baseResFire = 0;
    currentSpecies.baseResLight = 0;
    currentSpecies.baseResWater = 0;
    currentSpecies.abilities.push_back()
}

Actor::initializeAbilties() {
    std::vector<Ability> abilityList;
    Ability currentAbility;
    currentAbility.name = "Attack";
    currentAbility.description = "Basic attack action.\nUnarmed human attack.";
    currentAbility.minValue = 1;
    currentAbility.maxValue = 3;
}*/

/*
How is this going to work out? I want derrived stats from the main stats that adjust the base stats.
Ideally, all of this stuff would be loaded from a text file of some sort. Use JSON to store? Looks
like SQLite is the best choice.

*/