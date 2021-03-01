#include "vector2d.h"

// Vector2D implementation
Vector2D::Vector2D()
{
  X = 0;
  Y = 0;
}

Vector2D::Vector2D(unsigned char x, unsigned char y)
{
  X = x;
  Y = y;
}

Vector2D Vector2D::operator*(unsigned char i)
{
  return Vector2D(X * i, Y * i);
}

Vector2D Vector2D::operator-(Vector2D b)
{
  return Vector2D(X - b.X, Y - b.Y);
}

Vector2D Vector2D::operator+(Vector2D b)
{
  return Vector2D(X + b.X, Y + b.Y);
}