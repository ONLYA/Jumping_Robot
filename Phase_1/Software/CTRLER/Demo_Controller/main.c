#include <msp430.h>
#include <stdint.h>

#define STARTING_SEQ 0b10100101

void ADC10_init(void);
void SPI_send(unsigned char data);
void judge_wait(uint8_t judge, uint8_t sent);
void send_manual_data(uint8_t X, uint8_t Y);
void send_auto_data(uint8_t distance, double rad_angle, uint8_t direction);

// SPI data
uint8_t rx_data;
volatile uint8_t rx_flag = 0;

// ADC data read X&Y on A7 & A6
uint8_t X, Y;
uint8_t state = 0;

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer

    /* Configure the Clock
     * to run it from DCO @16MHz and SMCLK = DCO / 4 */
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
    BCSCTL2 = DIVS_2 + DIVM_0;

    ADC10_init();               // ADC10 init

    /* SPI */
    P1DIR |= BIT5;               // P1.5 for CS
    P1OUT |= BIT5;
    P1SEL = BIT1 | BIT2 | BIT4; // P1.1,2,4
    P1SEL2= BIT1 | BIT2 | BIT4;
    UCA0CTL1 = UCSWRST;
    UCA0CTL0 |= UCCKPL + UCMSB + UCMST + UCSYNC; // MSB, 8-bit, Master, 3-pin , Sync
    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0 |= 0x20;
    UCA0BR1 = 0;
    UCA0MCTL = 0;               // No modulation
    UCA0CTL1 &= ~UCSWRST;
    IE2 |= UCA0RXIE;

    /* State Select */
    P1DIR |= BIT0;
    P1OUT &= ~(BIT0);

//    __bis_SR_register(LPM0_bits + GIE);
    __bis_SR_register(GIE);

    // Self-Check
    SPI_send(0xFF);
    judge_wait(0xFF, 0xFF);

    while (1){
        ADC10CTL0 |= BIT7 | BIT0 | BIT1;    // Start Conversion on A1
        __bis_SR_register(LPM0_bits+GIE);   // Enable Global Interrupt
        __no_operation();
        __no_operation();
        // manual
        P1OUT &= ~BIT0;
        send_manual_data(X, Y);
    }

    return 0;
}

void ADC10_init(void){
    ADC10CTL0 = 0; ADC10CTL1 = 0;               // Clear all the control registers
    ADC10CTL1 |= INCH_7| BIT2 | BIT1;           // INCH1, Enable Repeated Sequence Conversion
    ADC10CTL1 &= ~(BITB | BITA);                // SHS=0
    ADC10AE0 |= BIT7 | BIT6;                    // A7 and A6
    ADC10CTL0 |= BIT4 | BIT3 | BIT7;            // ADC_ON & ADC10_Interrupt
}

void SPI_send(unsigned char data)
{
    UCA0TXBUF = data;                         // Sende Wert
    while (!(IFG2 & UCA0TXIFG));              // USCI_A0 TX buffer ready?
}

void judge_wait(uint8_t judge, uint8_t sent){
    while (1){
        if (rx_flag){
            if (rx_data == judge)
                break;
            else
                SPI_send(sent);
        }
    }
}

void send_manual_data(uint8_t X, uint8_t Y){
    SPI_send(STARTING_SEQ);
    judge_wait(0b000, STARTING_SEQ);
    SPI_send(X);
    judge_wait(0b001, X);
    SPI_send(Y);
    judge_wait(0b010, Y);
}

void send_auto_data(uint8_t distance, double rad_angle, uint8_t direction){
    uint8_t temp, angle0, angle1;
    temp = (uint8_t)(rad_angle * 10000);
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
//    while(UCA0STAT & UCBUSY);
    if ((IFG2 & UCA0RXIFG)){                        // USCI_A0 TX buffer fertig?
        rx_data = UCA0RXBUF;
        rx_flag = 1;
    }
}

#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
    switch(state){
        case 0: X = ADC10MEM>>8; state = 1; break;
        case 1: Y = ADC10MEM>>8; state = 0; break;
        default: state = 0; break;
    }
    __bic_SR_register_on_exit(LPM0_bits);
}
