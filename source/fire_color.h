#ifndef FIRE_COLOR_H
#define FIRE_COLOR_H

#include <tonc.h>

#define FIRE_COLOR_SIZE 36

enum FireColorPalette {
    FIRE_COLOR_PALETTE_RED,
    FIRE_COLOR_PALETTE_YELLOW,
    FIRE_COLOR_PALETTE_BLUE,
    FIRE_COLOR_PALETTE_GREEN,
    FIRE_COLOR_PALETTE_PURPLE
};

typedef struct ColorRGB {
    u8 r;
    u8 g;
    u8 b;
} ColorRGB;

ColorRGB* FireColor_getPalette(void);
void FireColor_nextPalette(void);
void FireColor_previousPalette(void);

#endif