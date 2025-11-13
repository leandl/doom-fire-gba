#ifndef FIRE_COLOR_RED_H
#define FIRE_COLOR_RED_H

#include <tonc.h>

typedef struct {
    u8 r;
    u8 g;
    u8 b;
} ColorRGB;

extern const ColorRGB FIRE_RED[];
extern const int FIRE_RED_SIZE;

#endif