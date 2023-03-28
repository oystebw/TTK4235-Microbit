#include "uart.h"
#include "gpio.h"

int main(){
    gpio_init();
    uart_init();
    
    iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
    while(1){
        if(!(GPIO0->IN & 1<<14)){
            uart_send('A');
            gpio_lights_off();
            while(!(GPIO0->IN & 1<<14)){

            }
        }
        if(!(GPIO0->IN & 1<<23)){
            uart_send('B');
            gpio_lights_on();
            while(!(GPIO0->IN & 1<<23)){

            }
        }
        UART->TASKS_STARTRX = 1;
        if(UART->EVENTS_RXDRDY){
            uart_send(uart_read());
        }
        else{
            UART->TASKS_STOPRX = 1;
        }
    }
}