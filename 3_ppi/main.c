#include "ppi.h"
#include "gpiote.h"

int main(){
    gpio_init();
    gpiote_init();
    init_PPI();

    while(1){
        
    }
}