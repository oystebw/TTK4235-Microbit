#include "uart.h"
#include "gpio.h"

int main(){
    gpio_init();
    uart_init();
    while(1){
        if(!(GPIO0->IN & 1<<14)){
            uart_send('O');
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
        
    }
}