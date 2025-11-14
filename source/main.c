#include <tonc.h>
#include <stdlib.h>
#include "fire_color.h"
#include "doom_fire.h"


void changeWindDirection() {
    if (key_hit(KEY_L)) {
        DoomFire_addWindLeft();
    } 
    
    if (key_hit(KEY_R)) {
        DoomFire_addWindRight();
    }
}

void changeFireColorPalette() {
    if (key_hit(KEY_RIGHT)) {
        FireColor_nextPalette();
    } 
    
    if (key_hit(KEY_LEFT)) {
        FireColor_previousPalette();
    }
}


int main(void)
{
    irq_init(NULL);
    irq_add(II_VBLANK, NULL);

    srand(qran());  // qran() é o RNG rápido do Tonc (ou use time(NULL) se preferir)

    REG_DISPCNT = DCNT_MODE3 | DCNT_BG2; // Modo 3
    DoomFire_createFireDataStructure();
    DoomFire_createFireSourceStructure();

    while(1)
    {   
        VBlankIntrWait();

        key_poll();
        changeFireColorPalette();
        changeWindDirection();

        DoomFire_update();
        DoomFire_render();
    }

    return 0;
}