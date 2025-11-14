#ifndef DOOM_FIRE_H
#define DOOM_FIRE_H

#include <tonc.h>
#include <stdlib.h>
#include "fire_color.h"

#define SIZE_PIXEL 8
#define FIRE_HEIGHT (160 / SIZE_PIXEL)
#define FIRE_WIDTH  (240 / SIZE_PIXEL)


void DoomFire_createFireDataStructure(void);
void DoomFire_createFireSourceStructure(void);
void DoomFire_update(void);
void DoomFire_render(void);

#endif // DOOM_FIRE_H