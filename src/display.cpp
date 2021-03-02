#include "logo.h"
#include "snake.h"
#include "display.h"
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void Display::Start()
{
    while (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
        ;

    // flip display 180 degrees
    display.setRotation(2);

    display.clearDisplay();
    display.display();

    display.drawBitmap((SCREEN_WIDTH - 64) / 2, 0, snakeLogo, 64, 64, 1);
    display.display();
}

void Display::Clear()
{
    display.clearDisplay();
    display.display();
}

void Display::DrawFrame(Vector2D pixles[], unsigned char length)
{
    display.clearDisplay();
    display.drawRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 1);
    for (unsigned char i = 0; i < length; i++)
    {
        display.drawPixel(pixles[i].X, pixles[i].Y, 1);
    }

    display.display();
}

void Display::DrawEndScreen(int score)
{
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(1);
    display.setCursor(12, SCREEN_HEIGHT / 2 - 12);
    display.print("Game Over");
    display.setTextSize(1);
    display.setCursor(40, SCREEN_HEIGHT / 2 + 4);
    display.print("Score: " + String(score));
    display.display();
}