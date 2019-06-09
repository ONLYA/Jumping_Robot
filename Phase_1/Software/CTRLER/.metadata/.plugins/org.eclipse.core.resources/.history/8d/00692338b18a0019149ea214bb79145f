#include <msp430.h> 

#define MIDx 500
#define MIDy 500

void Move(int x, int y);

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P2DIR |= BIT1 | BIT2 | BIT3 | BIT4;

	P1SEL = BIT0 | BIT2 | BIT4; // P1.0,2,4 (P1.5 as SS)
	P1SEL2= BIT0 | BIT2 | BIT4;
	UCA0CTL1 = UCSWRST;
	UCA0CTL0 |= BIT7 | BIT5 | BIT1; // MSB, 8-bit, Slave, 4-pin STE active high, Async
	UCA0CTL1 |= UCSSEL_2;

	P2DIR |= BIT1 | BIT5; // P2.1 y P2.4 como salida
	P2SEL |= BIT1 | BIT5; // Asociado al Timer_A1

	TA1CCR0 = 1000-1; // Cargamos el periodo PWM
	TA1CCR1 = 100; // PWM duty cycle, 10% CCR1/(CCR0+1) * 100
	TA1CCR2 = 500; // PWM duty cycle, 50% CCR2/(CCR0+1) * 100
	TA1CCTL1 = OUTMOD_7; //Modo7 reset/set
	TA1CCTL2 = OUTMOD_7; //Modo7 reset/set
	TA1CTL = TASSEL_2 + MC_1; // Timer SMCLK Modo UP

	_BIS_SR(LPM0_bits + GIE); // Bajo consumo LPM0

	return 0;
}

void Move(int x, int y){
    int temp_speed, tempx;
    int tempL, tempR;
    if (y == MIDy){
        P2OUT = 0;
        temp_speed = 0;
    }
    else if (y > MIDy){ // Forward
        P2OUT = BIT2 | BIT4;
        temp_speed = ((y - MIDy) * 1000) / MIDy;
    }
    else if (y < MIDy){ // Backward
        P2OUT = BIT0 | BIT3;
        temp_speed = ((MIDy - y) * 1000) / MIDy;
    }

    if (x >= MIDx){ // Right
        tempx = ((x - MIDx) * 1000) / MIDx;
        tempL = temp_speed + tempx;
        tempR = temp_speed - tempx;
    }
    else if (x < MIDx){ // Left
        tempx = ((MIDx - x) * 1000) / MIDx;
        tempL = temp_speed - tempx;
        tempR = temp_speed + tempx;
    }

    if (tempL > 1000) tempL = 1000;
    else if (tempL < 0) tempL = 0;
    if (tempR > 1000) tempR = 1000;
    else if (tempR < 0) tempR = 0;

    TA1CCR1 = tempL;
    TA1CCR2 = tempR;
}
