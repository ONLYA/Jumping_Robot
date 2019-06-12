#include <msp430.h> 

#define STARTING_SEQ 0b10100101

void SPI_send(unsigned char data);
void judge_wait(unsigned int judge, unsigned int sent);
void send_manual_data(unsigned int X, unsigned int Y);
void send_auto_data(unsigned int distance, double rad_angle, unsigned int direction);

unsigned char rx_data;
volatile unsigned int rx_flag = 0;

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	/* SPI */
	P1DIR = BIT5;               // P1.5 for CS
	P1SEL = BIT1 | BIT2 | BIT4; // P1.1,2,4
	P1SEL2= BIT1 | BIT2 | BIT4;
	UCA0CTL1 &= ~UCSWRST;
	UCA0CTL0 |= BIT7 | BIT5 | BIT3; // MSB, 8-bit, Master, 3-pin , Async
	UCA0CTL1 |= UCSSEL_2;
	IE2 |= UCA0RXIE;

	__enable_interrupt();

	while (1){
	    // manual
	    send_manual_data(186,56);
	}

	return 0;
}


void SPI_send(unsigned char data)
{
    P1OUT &= ~BIT5;                                                                // Ziehe CS auf Low, Frame startet

    UCA0TXBUF = data;                                                              // Sende Wert
    while(UCA0STAT & UCBUSY);                                                      // Warte bis Wert gesendet wurd, Alternativ: while (!(IFG2 & UCA0TXIFG));

    P1OUT |= BIT5;                                                                 // Ziehe CS wieder auf High, Frame beendet
}

void judge_wait(unsigned int judge, unsigned int sent){
    while (1){
        if (rx_flag){
            if (rx_data == judge)
                break;
            else
                SPI_send(sent);
        }
    }
}

void send_manual_data(unsigned int X, unsigned int Y){
    SPI_send(STARTING_SEQ);
    judge_wait(0b000, STARTING_SEQ);
    SPI_send(X);
    judge_wait(0b001, X);
    SPI_send(Y);
    judge_wait(0b010, Y);
}

void send_auto_data(unsigned int distance, double rad_angle, unsigned int direction){
    unsigned int temp, angle0, angle1;
    temp = (unsigned int)(rad_angle * 10000);
    angle0 = temp >> 7;
    angle1 = ((temp & 0b1111111) << 1) | (direction & 0b1);
    SPI_send(STARTING_SEQ);
    judge_wait(0b100, STARTING_SEQ);
    SPI_send(distance);
    judge_wait(0b101, distance);
    SPI_send(angle0);
    judge_wait(0b110, angle0);
    SPI_send(angle1);
    judge_wait(0b111, angle1);
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void SPI_RX_ISR(void){
    while(UCA0STAT & UCBUSY);
    while (!(IFG2 & UCA0RXIFG));                        // USCI_A0 TX buffer fertig?
    rx_data = UCA0RXBUF;
    P1OUT |= BIT7;
    rx_flag = 1;
}
