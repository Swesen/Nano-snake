#include "logo.h"
#include "display.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void Display::Start()
{
    while (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C));

    // flip display 180 degrees
    display.setRotation(2);

    display.clearDisplay();
    display.display();

    display.drawBitmap((SCREEN_WIDTH - 64) / 2, 0, snakeLogo, 64, 64, 1);
    display.display();
}

void Display::Clear(){
    display.clearDisplay();
    display.display();
}

void Display::DrawFrame(Vector2D pixles[], unsigned char length)
{
    display.clearDisplay();
    
    for (unsigned char i = 0; i < length; i++)
    {
        display.drawPixel(pixles[i].X, pixles[i].Y, 1);
    }
    
    display.display();
}