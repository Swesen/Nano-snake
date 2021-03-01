#ifndef SNAKE_H
#define SNAKE_H

#include "vector2d.h"

class Snake
{
public:
    Vector2D direction;
    Vector2D body[255];
    unsigned char bodySize;

    void Start(unsigned char startSize, Vector2D startDirection, Vector2D startPosition);
    void Move();
    void AddLength();
};

#endif