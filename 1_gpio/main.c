#include <stdint.h>

#define GPIO0 ((NRF_GPIO_REGS0*)0x50000000) // GPIO 0 base address
#define GPIO1 ((NRF_GPIO_REGS1*)0x50000300) // GPIO 1 base address

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_0[118];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS0;

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_1[118];
	volatile uint32_t PIN_CNF[10];
} NRF_GPIO_REGS1;

void configure(){
	// Configure leds
	GPIO0->PIN_CNF[21] = 1; //Row 1
	GPIO0->PIN_CNF[22] = 1; //Row 2
	GPIO0->PIN_CNF[15] = 1; //Row 3
	GPIO0->PIN_CNF[24] = 1; //Row 4
	GPIO0->PIN_CNF[19] = 1; //Row 5

	GPIO0->PIN_CNF[28] = 1; //Col 1
	GPIO0->PIN_CNF[11] = 1; //Col 2
	GPIO0->PIN_CNF[31] = 1; //Col 3
	GPIO1->PIN_CNF [5] = 1; //Col 4
	GPIO0->PIN_CNF[30] = 1; //Col 5 

	// Set rows high
	GPIO0->OUTSET = 1 << 21;
	GPIO0->OUTSET = 1 << 22;
	GPIO0->OUTSET = 1 << 15;
	GPIO0->OUTSET = 1 << 24;
	GPIO0->OUTSET = 1 << 19;

	// Set cols high
	GPIO0->OUTSET = 1 << 28;
	GPIO0->OUTSET = 1 << 11;
	GPIO0->OUTSET = 1 << 31;
	GPIO1->OUTSET = 1 << 5;
	GPIO0->OUTSET = 1 << 30;
	
	// Configure buttons 
	GPIO0->PIN_CNF[14] = 0; // button A 
	GPIO0->PIN_CNF[23] = 0; // button B
}

void ledOff(){
	// Columns are set high, and thus no voltage potential
	// in the matrix
	GPIO0->OUTSET = 1 << 28;
	GPIO0->OUTSET = 1 << 11;
	GPIO0->OUTSET = 1 << 31;
	GPIO1->OUTSET = 1 << 5;
	GPIO0->OUTSET = 1 << 30;
}

void ledOn(){
	// Columns are set low, and thus we have a voltage potential
	// in the matrix
	GPIO0->OUTCLR = 1 << 28;
	GPIO0->OUTCLR = 1 << 11;
	GPIO0->OUTCLR = 1 << 31;
	GPIO1->OUTCLR = 1 << 5;
	GPIO0->OUTCLR = 1 << 30;
}

int main(){
	configure();

	while(1){
		if(!(GPIO0->IN & 1 << 14)){
			ledOff();
		}
		if(!(GPIO0->IN & 1 << 23)){
			ledOn();
		}
	}
	return 0;
}
