#include "uart.h"


void uart_init(){
    GPIO0->PIN_CNF[8] = 1;
    UART->PSEL_TXD &= ~(1<<31 | 0b111001);
    UART->PSEL_RXD &= ~(1<<31 | 0b110111);
    UART->BAUDRATE = 9600;
    UART->ENABLE = 4;
    UART->TASKS_STARTRX = 1;
}

void uart_send(char letter){
    UART->TXD = letter;
    UART->TASKS_STARTTX = 1;
    while(!UART->EVENTS_TXDRDY){

    }
    UART->TASKS_STOPTX = 1;
}

char uart_read(){
    char temp;
    UART->TASKS_STARTRX = 1;
    while(!UART->EVENTS_TXDRDY){

    }
    UART->EVENTS_TXDRDY = 0;
    temp = UART->RXD;
    UART->TASKS_STOPTX = 1;
    return temp;
}