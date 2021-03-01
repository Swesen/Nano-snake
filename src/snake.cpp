#include "snake.h"

// Snake implementations
void Snake::Start(unsigned char startSize, Vector2D startDirection, Vector2D startPosition)
{
  direction = startDirection;
  bodySize = startSize;
  for (unsigned char i = 0; i < bodySize; i++)
  {
    body[i] = startPosition - (startDirection * i);
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