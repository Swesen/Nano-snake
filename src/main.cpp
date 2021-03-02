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

unsigned char buttonPins[4] = {UP, DOWN, LEFT, RIGHT};

void setup()
{
  randomSeed(analogRead(0));
  // initialize the screen.
  screen.Start();

  SetupButtons();

  delay(1000);
  screen.Clear();

  NewGame();
}

void loop()
{
  unsigned long timer = millis();

  if (CheckCollition())
  {
    EndGame();
  }

  snake.Move();

  UpdateScreen();

  ReadButtons(timer, updateInterval);
}

void SetupButtons()
{
  // set pins to input with internal pullup
  for (unsigned char i = 0; i < 4; i++)
  {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void NewGame()
{
  Vector2D startPosition = Vector2D(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
  InputDirection startDirection = Right;
  snake.Start(4, startDirection, startPosition);

  SpawnFood();
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
    for (unsigned char i = 0; i < 4; i++)
    {
      if (!digitalRead(buttonPins[i]))
      {
        newInputDirection = Direction(static_cast<InputDirection>(buttonPins[i]));
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
    // this shouldn't be possible
    return Vector2D();
  }
}

void SpawnFood()
{
  Vector2D newFoodPosition;
  bool validNewPosition = true;
  do
  {
    newFoodPosition.X = random(1, SCREEN_WIDTH);
    newFoodPosition.Y = random(1, SCREEN_HEIGHT);

    for (unsigned char i = 0; i < snake.bodySize; i++)
    {
      if (newFoodPosition == snake.body[i] || newFoodPosition == foodPosition)
      {
        validNewPosition = false;
      }
    }

  } while (!validNewPosition);
  foodPosition = newFoodPosition;
}

bool CheckCollition()
{
  Vector2D nextPosition = snake.body[0] + snake.direction;

  // check if food was hit
  if (nextPosition == foodPosition)
  {
    snake.AddLength();
    SpawnFood();
  }
  // check if border was hit
  else if (nextPosition.X <= 0 || nextPosition.Y <= 0 || nextPosition.X >= SCREEN_WIDTH || nextPosition.Y >= SCREEN_HEIGHT)
  {
    return true;
  }
  // check if self was hit
  else if (snake.IsBody(nextPosition))
  {
    return true;
  }
  return false;
}

void EndGame()
{
  screen.DrawEndScreen();
  while (true)
  {
  }
}