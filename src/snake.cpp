#include "snake.h"
#include "main.h"

// Snake implementations
void Snake::Start(unsigned char startSize, InputDirection startDirection, Vector2D startPosition)
{
  direction = Direction(startDirection);
  bodySize = startSize;
  for (unsigned char i = 0; i < bodySize; i++)
  {
    body[i] = startPosition - (direction * i);
  }
}

void Snake::Move()
{
  for (unsigned char i = bodySize - 1; i > 0; i--)
  {
    body[i] = body[i - 1];
  }

  body[0] = body[0] + direction;
}

void Snake::AddLength()
{
  bodySize++;
}