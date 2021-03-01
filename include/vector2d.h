#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2D
{
public:
    unsigned char X, Y;

    Vector2D();

    Vector2D(unsigned char x, unsigned char y);

    Vector2D operator*(unsigned char i);

    Vector2D operator-(Vector2D b);

    Vector2D operator+(Vector2D b);
};

#endif