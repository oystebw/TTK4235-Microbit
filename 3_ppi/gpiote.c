#include "gpiote.h"

void gpiote_init(){
    // Event will be triggered when button A is pressed
    GPIOTE->CONFIG[0] = 1<<17 | 14<<8 | 1;

    // Configure five tasks for toggling supply voltage for rows
    GPIOTE->CONFIG[1] = 1<<20 | 3<<16 | 21<<8 | 3;
    GPIOTE->CONFIG[2] = 3<<16 | 22<<8 | 3;
    GPIOTE->CONFIG[3] = 1<<20 | 3<<16 | 15<<8 | 3;
    GPIOTE->CONFIG[4] = 3<<16 | 24<<8 | 3;
    GPIOTE->CONFIG[5] = 1<<20 | 3<<16 | 19<<8 | 3;

    // Making event tied to button B
    GPIOTE->CONFIG[6] = 1<<17 | 23<<8 | 1;

    // Only one register left, will use it on middle column
    GPIOTE->CONFIG[7] = 1<<20 | 3<<16 | 31<<8 | 3;
}