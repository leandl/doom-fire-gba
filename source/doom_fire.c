#include "doom_fire.h"

u8 fireDataStructure[FIRE_HEIGHT * FIRE_WIDTH];

void DoomFire_createFireDataStructure() {
    for (int y = 0; y < FIRE_HEIGHT; y++) {
        for (int x = 0; x < FIRE_WIDTH; x++) {
            int pixelIndex = y * FIRE_WIDTH + x;
            fireDataStructure[pixelIndex] = 0;
        }
    }
}

void DoomFire_createFireSourceStructure() {
    for (int x = 0; x < FIRE_WIDTH; x++) {
        int pixelIndex = (FIRE_HEIGHT - 1) * FIRE_WIDTH + x;
        fireDataStructure[pixelIndex] = FIRE_COLOR_SIZE - 1;
    }
}



int getWindDirection(int currentPixelIndex, int decay) {
    return currentPixelIndex; // sem vento
}

void updateFireIntesityPerPixel(int currentPixelIndex) {
    int sizeFireDataStructure = FIRE_HEIGHT * FIRE_WIDTH;
    int belowPixelIndex = currentPixelIndex + FIRE_WIDTH;

    if (belowPixelIndex >= sizeFireDataStructure) {
        return;
    }

    u8 decay = (rand() % 3) + 1;
    u8 belowPixelFireIntensity = fireDataStructure[belowPixelIndex];
    
    int newPixelIndex = getWindDirection(currentPixelIndex, decay);
    if (newPixelIndex < 0 || newPixelIndex >= sizeFireDataStructure)
        return;

    u8 newFireIntensity = belowPixelFireIntensity > decay ? belowPixelFireIntensity - decay : 0;
    fireDataStructure[newPixelIndex] = newFireIntensity;
}


void DoomFire_update() {
    for (int y = 0; y < FIRE_HEIGHT; y++) {
        for (int x = 0; x < FIRE_WIDTH; x++) {
            int pixelIndex = y * FIRE_WIDTH + x;
            updateFireIntesityPerPixel(pixelIndex);
        }
    }

    DoomFire_createFireSourceStructure();
}



void draw_pixel(u8 x, u8 y, u8 intensity) {
    if (x < 0 || x >= FIRE_WIDTH || y < 0 || y >= FIRE_HEIGHT)
        return;

    u8 realX = x * SIZE_PIXEL;
    u8 realY = y * SIZE_PIXEL;

    ColorRGB* palette = FireColor_getPalette();

    for (u8 yAdditional = 0; yAdditional < SIZE_PIXEL; yAdditional++) {
        for (u8 xAdditional = 0; xAdditional < SIZE_PIXEL; xAdditional++) {
            m3_plot(
                realX + xAdditional,
                realY + yAdditional,
                RGB15(palette[intensity].r, palette[intensity].g, palette[intensity].b)
            );
        }
    }
}

void DoomFire_render() {
    for (int y = 0; y < FIRE_HEIGHT; y++) {
        for (int x = 0; x < FIRE_WIDTH; x++) {
            int pixelIndex = y * FIRE_WIDTH + x;
            u8 fireIntensity = fireDataStructure[pixelIndex];

            // garantir que está dentro da paleta (0–FIRE_COLOR_SIZE)
            if (fireIntensity >= FIRE_COLOR_SIZE)
                fireIntensity = FIRE_COLOR_SIZE - 1;

            draw_pixel(x, y, fireIntensity);
        }
    }
}