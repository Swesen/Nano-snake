#include "main.h"
#include "snake.h"
#include "display.h"
#include "vector2d.h"

Vector2D foodPosition;
Snake snake;
Display screen;

void SetupButtons();

void setup()
{
  // initialize the screen.
  screen.Start();

  SetupButtons();

  // create snake at center position
  Vector2D startPosition = Vector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  Vector2D startDirection = Vector2D(0, 1);
  snake.Start(4, startDirection, startPosition);

  delay(2000);
  screen.Clear();
}

void loop()
{
  DrawFrame();

  delay(500);
}

void SetupButtons()
{
  // set pins D3-D6 to input with internal pullup
  for (unsigned char i = 3; i <= 6; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
}

void DrawFrame(){
  unsigned char lengthOfArray = snake.bodySize + 1;
  Vector2D pixelsToDraw[lengthOfArray];

  for (unsigned char i = 0; i < snake.bodySize; i++)
  {
    pixelsToDraw[i] = snake.body[i];
  }

  pixelsToDraw[snake.bodySize] = foodPosition;

  screen.DrawGameFrame(pixelsToDraw, lengthOfArray);
}