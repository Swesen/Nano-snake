#include <Arduino.h>

// 'snakelogo', 64x64px
const unsigned char snakeLogo[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1f, 0x08, 0x21, 0xf0, 0x84, 0x7e, 0x00, 0x00, 0x20, 0x88, 0x21, 0x10, 0x88, 0x40, 0x00,
    0x00, 0x20, 0x0c, 0x22, 0x08, 0x90, 0x40, 0x00, 0x00, 0x20, 0x0a, 0x22, 0x08, 0xa0, 0x40, 0x00,
    0x00, 0x1f, 0x09, 0x23, 0xf8, 0xc0, 0x7c, 0x00, 0x00, 0x00, 0x88, 0xa2, 0x08, 0xa0, 0x40, 0x00,
    0x00, 0x00, 0x88, 0x62, 0x08, 0x90, 0x40, 0x00, 0x00, 0x20, 0x88, 0x22, 0x08, 0x88, 0x40, 0x00,
    0x00, 0x1f, 0x08, 0x22, 0x08, 0x84, 0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x02, 0x00, 0x00, 0x07, 0xf8, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x40,
    0x02, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x40,
    0x02, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x04, 0x08, 0x00, 0x00, 0x40,
    0x02, 0x00, 0xfe, 0x04, 0x08, 0x00, 0x00, 0x40, 0x02, 0x00, 0x82, 0x04, 0x08, 0x00, 0x00, 0x40,
    0x02, 0x00, 0x82, 0x04, 0x08, 0x7f, 0x10, 0x40, 0x02, 0x00, 0x82, 0x04, 0x08, 0x40, 0x00, 0x40,
    0x02, 0x00, 0x82, 0x04, 0x08, 0x40, 0x00, 0x40, 0x02, 0x00, 0x82, 0x04, 0x08, 0x40, 0x00, 0x40,
    0x02, 0x00, 0x82, 0x04, 0x08, 0x40, 0x00, 0x40, 0x02, 0x00, 0x82, 0x04, 0x08, 0x40, 0x00, 0x40,
    0x02, 0x00, 0x82, 0x04, 0x08, 0x40, 0x00, 0x40, 0x02, 0x00, 0x83, 0xfc, 0x08, 0x40, 0x00, 0x40,
    0x02, 0x00, 0x80, 0x00, 0x08, 0x40, 0x00, 0x40, 0x02, 0x00, 0x80, 0x00, 0x08, 0x40, 0x00, 0x40,
    0x02, 0x00, 0x80, 0x00, 0x08, 0x40, 0x00, 0x40, 0x02, 0x00, 0x80, 0x00, 0x0f, 0xc0, 0x00, 0x40,
    0x02, 0x3f, 0x80, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};