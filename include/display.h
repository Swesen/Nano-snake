#ifndef DISPLAY_H
#define DISPLAY_H

#include "vector2d.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)

class Display
{
public:
    void Start();
    void Clear();
    void DrawGameFrame(Vector2D pixles[], unsigned char length);
};
#endif