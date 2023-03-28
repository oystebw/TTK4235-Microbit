#include "uart.h"

void uart_init(){
    GPIO0->PIN_CNF[6] = 0;
    GPIO1->PIN_CNF[8] = 1;

    UART->PSEL_TXD = 0;
    UART->PSEL_TXD = 0b110;

    UART->PSEL_RXD = 0;
    UART->PSEL_RXD = 0b101000;

    UART->BAUDRATE = 0x00275000;
    UART->PSEL_RTS = 1<<31;
    UART->PSEL_CTS = 1<<31;
    UART->ENABLE = 4;
    UART->TASKS_STARTRX = 1;
}

void uart_send(char letter){
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;
    while(!UART->EVENTS_TXDRDY){

    }
    UART->TASKS_STOPTX = 1;
    UART->TASKS_STARTTX = 0;
    UART->EVENTS_TXDRDY = 0;
}

char uart_read(){
    char temp;
    while(!UART->EVENTS_RXDRDY){

    }
    if(GPIO0->IN & 1<<21){
        gpio_lights_off();
    }
    else{
        gpio_lights_on();
    }
    UART->EVENTS_RXDRDY = 0;
    temp = UART->RXD;
    UART->TASKS_STOPTX = 1;
    return temp;
}

ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}