/*
 * Auto Sender
 * This sends the data to the tx chip, including Joystick Data and Auto data. Send
 *  data through 8-bit parallel GPIO ports.
 * INT(R) -> Data -> INT(R) -> ... -> INT(R)
 */
#include <msp430.h> 
#include <stdint.h>

#define MAX_BUFFER_SIZE 10
#define SS BIT0 // Bit 0 as State Select
#define INT BIT3// Bit 3 as INT indicate
#define CS BIT5 // Bit 5 as Chip Select of SPI

uint8_t rx_data;
volatile uint8_t rx_flag;

uint8_t state = 0;
uint8_t X, Y;

volatile uint8_t TX_Buffer[MAX_BUFFER_SIZE] = {0};

uint8_t SPI_index = 0;  // index for SPI RX
volatile uint8_t SPI_DONE = 0;   // indicate transaction is done (FLAG)

void CLK_init(void);
void GPIO_init(void);
void SPI_init(void);
void ADC10_init(void);

uint8_t Send_data(uint8_t *data, uint8_t length);

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	CLK_init();
	GPIO_init();
	SPI_init();
	ADC10_init();

	__bis_SR_register(GIE);

	while (1){
	    if (P1IN & CS){
	        P1OUT |= SS;
	        while (!SPI_DONE);
	        Send_data(TX_Buffer, 3);
	        SPI_DONE = 0;
	    }
	    else {
	        P1OUT &= ~SS;
	        ADC10CTL0 |= BIT7 | BIT6;   // Start Conversion on A6 A7
	        __bis_SR_register(GIE);     // Enable Global Interrupt for ADC10 on every cycle

	        TX_Buffer[0] = X;
	        TX_Buffer[1] = Y;

	        Send_data(TX_Buffer, 2);
	    }
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
//    P1IES |= BIT3 | BIT6;  // TO receive NIRQ & INPUT rising edge
//    P1IFG |= BIT3 | BIT6;  // Rising Edge
//    P1IE |= BIT3 | BIT6;   // Enable Port 1 Interrupt
    P1DIR = SS | INT;   // Set SS and INT output
    P2DIR = 0xFF;   // Set all P2 ports as output
}

void SPI_init(void){
    P1DIR |= NSEL_PIN;
    P1OUT |= NSEL_PIN;  // NSEL
    P1SEL = BIT1 | BIT2 | BIT4; // P1.1, 1.2, 1.4
    P1SEL2= BIT1 | BIT2 | BIT4;
    UCA0CTL1 = UCSWRST;
    UCA0CTL0 |= UCCKPL + UCMSB + UCSYNC;    // MSB, 8-bit, Slave, 3-pin , Sync<- it should be slave
    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0 |= 0x20;
    UCA0BR1 = 0;
    UCA0MCTL = 0;   // No modulation
    UCA0CTL1 &= ~UCSWRST;
    IE2 |= UCA0RXIE;
}

void ADC10_init(void){
    ADC10CTL1 |= BITE | BITD | BITC | BIT2 | BIT1;  // INCH7, Enable Repeated Sequence Conversion
    ADC10CTL1 &= ~(BITB | BITA);        // SHS = 0
    ADC10AE0 |= BIT7 | BIT6;            // A6 and A7
    ADC10CTL0|= BIT4 | BIT3;            // ADC_ON & ADC10_interrupt
}

uint8_t Send_data(uint8_t *data, uint8_t length){
    uint8_t i;
    for (i=0; i<length; i++){
        P1OUT |= INT;
        P2OUT = data[i];
        __delay_cycles(10);
        P1OUT &= ~INT;
    }
    P1OUT |= INT;
    P2OUT = 0;
    __delay_cycles(10);
    P1OUT &= ~INT;
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void SPI_RX_ISR(void){
    if (IFG2 & UCA0RXIFG){
        if (P1IN & CS){
            if (!SPI_DONE){
                SPI_DONE = 0;
                if (SPI_index == 2){
                    SPI_index = 0;
                    SPI_DONE = 1;
                }
                TX_Buffer[SPI_index] = UCA0RXBUF;
            }
        }
    }
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
    switch (state){
    case 0: X = ADC10MEM >> 8; state = 1; break;
    case 1: Y = ADC10MEM >> 8; state = 0; break;
    default: state = 0; break;
    }
}
