#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include "vector2d.h"

void SetupButtons();
void UpdateScreen();
void ReadButtons(unsigned long timer, int updateInterval);
Vector2D Direction(InputDirection input);
void SpawnFood();

#endif