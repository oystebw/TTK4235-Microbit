#include "uart.h"
#include "gpio.h"

int main(){
    gpio_init();
    uart_init();
    while(1){
        if(!(GPIO0->IN & 1<<14)){
            uart_send('A');
            while(!(GPIO0->IN & 1<<14)){

            }
        }
        if(!(GPIO0->IN & 1<<23)){
            uart_send('B');
            while(!(GPIO0->IN & 1<<23)){

            }
        }
        
    }
}