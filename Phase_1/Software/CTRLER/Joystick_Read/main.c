#include <msp430.h>
#include <stdint.h>

void ADC10_init(void);
void ADC10_loop(void);

uint8_t X, Y;
uint8_t state = 0;
volatile uint16_t X_Y[2] = {0}; // {X, Y}

void CLK_init(void);
void GPIO_init(void);
void PWM_init(void);

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	CLK_init();
	GPIO_init();
	PWM_init();
	ADC10_init();

	__bis_SR_register(GIE);

	while(1){
	    ADC10_loop();
	}

	return 0;
}

/* Configure the Clock
 * to run it from DCO @16MHz and SMCLK = DCO / 4
 * */
void CLK_init(void){
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
    BCSCTL2 = DIVS_2 + DIVM_0;
}

void GPIO_init(void){
    P1DIR |= BIT2;
    P1SEL |= BIT2;
    P2DIR |= BIT1;
    P2SEL |= BIT1;
}

void PWM_init(void){
    /*** Timer0_A Set-Up ***/
    TA0CCR0 |= 0xff - 1;
    TA0CCTL1 |= OUTMOD_7;
    TA0CCR1 = 0;
    TA0CTL |= TASSEL_2 + MC_1;

    /*** Timer1_A Set-Up ***/
    TA1CCR0 |= 0xff - 1;
    TA1CCTL1 |= OUTMOD_7;
    TA1CCR1 = 0;
    TA1CTL |= TASSEL_2 + MC_1;
}

void ADC10_init(void){
//    ADC10CTL1 |= BITC | BIT2 | BIT1;    // INCH1, Enable Repeated Sequence Conversion
//    ADC10CTL1 &= ~(BITB | BITA);        // SHS=0
//    ADC10AE0 |= BIT1 | BIT0;            // A0 and A1
//    ADC10CTL0 |= BIT4 | BIT3;           // ADC_ON & ADC10_Interrupt
    ADC10CTL1 |= INCH_7 + CONSEQ_1;                     // INCH7, Enable Single Sequence Conversion
    ADC10CTL0 = ADC10SHT_2 + MSC + ADC10ON + ADC10IE;   // 16xSample&Hold, Multiple sample and conversion, ADCON, Interrupt En
    ADC10DTC1 = 0x02;                                   // 2 conversions
    ADC10AE0 |= BIT7 | BIT6;                            // A6 and A7
}

void ADC10_loop(void){
//    ADC10CTL0 |= BIT0 | BIT1;           // Start Conversion on A1
//    __bis_SR_register(GIE);             // Enable Global Interrupt
    ADC10SA = (uint16_t)X_Y;        // Data buffer start
    ADC10CTL0 |= ENC + ADC10SC;     // Sampling and conversion start
    while (ADC10CTL1 & ADC10BUSY);  // Wait if ADC10 core is active
    X = X_Y[0]>>2;                  // 10-bit to 8-bit - X
    Y = X_Y[1]>>2;                  // 10-bit to 8-bit - Y
    TA0CCR1 = X;
    TA1CCR1 = Y;
    __bis_SR_register(GIE);         // Enable Global Interrupt for ADC10 on every cycle
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
//    switch(state){
//        case 0: X = ADC10MEM>>8; state = 1; break;
//        case 1: Y = ADC10MEM>>8; state = 0; break;
//        default: state = 0; break;
//    }
}
