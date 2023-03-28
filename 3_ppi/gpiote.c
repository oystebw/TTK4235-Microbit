#include "gpiote.h"

void gpiote_init(){
    // Event will be triggered when button A is pressed
    GPIOTE->CONFIG[0] = 1<<17 | 14<<8 | 1;

    // Configure five tasks for toggling supply voltage for rows
    GPIOTE->CONFIG[1] = 3<<16 | 21<<8 | 3;
    GPIOTE->CONFIG[2] = 3<<16 | 22<<8 | 3;
    GPIOTE->CONFIG[3] = 3<<16 | 15<<8 | 3;
    GPIOTE->CONFIG[4] = 3<<16 | 24<<8 | 3;
    GPIOTE->CONFIG[5] = 3<<16 | 19<<8 | 3;

    // Toggle on row 1, 3 and 5
    GPIOTE->TASKS_OUT[1] = 1;
    GPIOTE->TASKS_OUT[3] = 1;
    GPIOTE->TASKS_OUT[5] = 1;
}