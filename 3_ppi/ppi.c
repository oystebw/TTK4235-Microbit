#include "ppi.h"
#include "gpiote.h"

void init_PPI(){
    // Logic for toggling on and off rows
    PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[1]);
    PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[2]);
    PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[3]);
    PPI->PPI_CH[3].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[3].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[4]);
    PPI->PPI_CH[4].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[0]);
    PPI->PPI_CH[4].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[5]);

    // Logic for toggling on and off middle column
    PPI->PPI_CH[5].EEP = (uint32_t)&(GPIOTE->EVENTS_IN[6]);
    PPI->PPI_CH[5].TEP = (uint32_t)&(GPIOTE->TASKS_OUT[7]);

    PPI->CHENSET = 0b111111;
}