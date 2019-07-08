#include <msp430.h> 
#include <stdint.h>

void ADC10_init(void);
void ADC10_loop(void);

uint8_t X, Y;
uint8_t state = 0;

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	ADC10_init();

	while(1){
	    ADC_loop()
	}

	return 0;
}

void ADC10_init(void){
    ADC10CTL1 |= BITC | BIT2 | BIT1;    // INCH1, Enable Repeated Sequence Conversion
    ADC10CTL1 &= ~(BITB | BITA);        // SHS=0
    ADC10AE0 |= BIT1 | BIT0;            // A0 and A1
    ADC10CTL0 |= BIT4 | BIT3;           // ADC_ON & ADC10_Interrupt
}

void ADC10_loop(void){
    ADC10CTL0 |= BIT0 | BIT1;           // Start Conversion on A1
    __bis_SR_register(GIE);             // Enable Global Interrupt
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
    switch(state){
        case 0: X = ADC10MEM>>8; state = 1; break;
        case 1: Y = ADC10MEM>>8; state = 0; break;
        default: state = 0; break;
    }
}
