#include "pins.h"
#include "main.h"
#include "snake.h"
#include "display.h"
#include "vector2d.h"

Vector2D foodPosition;
Snake snake;
Display screen;

// time between frame updates
unsigned int updateInterval = 400;

void setup()
{
  // initialize the screen.
  screen.Start();

  SetupButtons();

  // create snake at center position
  Vector2D startPosition = Vector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  InputDirection startDirection = Right;
  snake.Start(4, startDirection, startPosition);

  delay(2000);
  screen.Clear();

  // spawn food
}

void loop()
{
  unsigned long timer = millis();

  // check collition

  snake.Move();

  UpdateScreen();

  ReadButtons(timer, updateInterval);
}

void SetupButtons()
{
  unsigned char buttonPins[4] = {UP, DOWN, LEFT, RIGHT};

  unsigned char minPin = buttonPins[0];
  for (unsigned char i = 1; i < 4; i++)
  {
    minPin = (minPin < buttonPins[i] ? minPin : buttonPins[i]);
  }

  unsigned char maxPin = buttonPins[0];
  for (unsigned char i = 1; i < 4; i++)
  {
    maxPin = (maxPin > buttonPins[i] ? maxPin : buttonPins[i]);
  }

  // set pins D3-D6 to input with internal pullup
  for (unsigned char i = minPin; i <= maxPin; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }
}

void UpdateScreen()
{
  unsigned char lengthOfArray = snake.bodySize + 1;
  Vector2D pixelsToDraw[lengthOfArray];

  for (unsigned char i = 0; i < snake.bodySize; i++)
  {
    pixelsToDraw[i] = snake.body[i];
  }

  pixelsToDraw[snake.bodySize] = foodPosition;

  screen.DrawFrame(pixelsToDraw, lengthOfArray);
}

void ReadButtons(unsigned long timer, int updateInterval)
{
  Vector2D newInputDirection = snake.direction;

  do
  {
    // read all pins for input
    for (unsigned char i = Up; i <= Right; i++)
    {
      if (!digitalRead(i))
      {
        newInputDirection = Direction(static_cast<InputDirection>(i));
        break;
      }
    }
  } while (int(millis() - timer) < updateInterval);

  // check so new direction is not opposite to current direction
  if ((snake.direction + newInputDirection) == Vector2D())
  {
    return;
  }

  snake.direction = newInputDirection;
}

Vector2D Direction(InputDirection input)
{
  switch (input)
  {
  case Up:
    return Vector2D(0, -1);
  case Down:
    return Vector2D(0, 1);
  case Left:
    return Vector2D(-1, 0);
  case Right:
    return Vector2D(1, 0);
  default:
    return Vector2D();
  }
}