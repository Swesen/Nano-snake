#include <Arduino.h>
#include <main.h>


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

struct Vector2D
{
public:
    int X, Y;

    Vector2D()
    {
        X, Y = 0;
    }

    Vector2D(int x, int y)
    {
        X = x;
        Y = y;
    }

    Vector2D operator*(int i){
        return Vector2D(X * i, Y * i);
    }

    Vector2D operator-(Vector2D b){
        return Vector2D(X - b.X, Y - b.Y);
    }

    Vector2D operator+(Vector2D b){
        return Vector2D(X + b.X, Y + b.Y);
    }


};

struct Snake
{
    Vector2D direction;
    Vector2D body[255];
    short int bodySize;

    Snake(short int startSize, Vector2D startDirection, Vector2D startPosition)
    {
        direction = startDirection;
        bodySize = startSize;
        for (short int i = 0; i < bodySize; i++)
        {
            body[i] = startPosition - (startDirection * i);
        }
    }

    void Move(){
        for (short int i = bodySize - 1; i > 0; i--)
        {
            body[i] = body[i - 1];
        }
        
    }
};