#ifndef SNAKE_H
#define SNAKE_H

#include "main.h"

class Snake
{
public:
    Vector2D direction;
    // needs to be more memory efficient since the memory runs out if this is larger.
    Vector2D body[200];
    unsigned char bodySize;

    void Start(unsigned char startSize, InputDirection startDirection, Vector2D startPosition);
    void Move();
    void AddLength();
    bool IsBody(Vector2D position);
};

#endif