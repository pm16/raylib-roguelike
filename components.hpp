#pragma once
#include "component.hpp"
#include "include/raylib.h"

struct Position : public Component {
    Vector2 position;
};

struct PreviousPosition : public Component {
    Vector2 prevPosition;
};

struct Health : public Component {
    int currentHealth;
    int baseHealth;
};

struct CharacterStatistics : public Component {
  int baseMight;
  int currentMight;
  int baseAgility;
  int currentAgility;
  int baseEndurance;
  int currentEndurance;
  int baseErudition;
  int currentErudition;
  int baseAcuity;
  int currentAcuity;
  int basePresence;
  int currentPresence;
};
