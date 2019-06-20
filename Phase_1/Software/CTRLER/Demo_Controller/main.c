#include <msp430.h>
#include <stdint.h>

#define STARTING_SEQ 0b10100101

void SPI_send(unsigned char data);
void judge_wait(uint8_t judge, uint8_t sent);
void send_manual_data(uint8_t X, uint8_t Y);
void send_auto_data(uint8_t distance, double rad_angle, uint8_t direction);

uint8_t rx_data;
volatile uint8_t rx_flag = 0;
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
    P1DIR |= BIT0 | BIT7;
    P1OUT &= ~(BIT0 | BIT7);
    P1OUT |= BIT7;

//    __bis_SR_register(LPM0_bits + GIE);
    __bis_SR_register(GIE);

    // Self-Check
    SPI_send(0xFF);
    judge_wait(0xFF, 0xFF);
    P1OUT &= ~BIT7;

    while (1){
        // manual
        P1OUT &= ~BIT0;
        send_manual_data(186,56);
    }

    return 0;
}


void SPI_send(unsigned char data)
{
    UCA0TXBUF = data;                                                              // Sende Wert
    while (!(IFG2 & UCA0TXIFG));              // USCI_A0 TX buffer ready?
    P1OUT &= ~BIT7;
//    UCA0TXBUF = data;                                                              // Sende Wert
}

void judge_wait(uint8_t judge, uint8_t sent){
    while (1){
        if (rx_flag){
            P1OUT |= BIT7;
//            P1OUT &= ~BIT7;
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
    P1OUT &= ~BIT7;
    SPI_send(X);
    judge_wait(0b001, X);
    P1OUT &= ~BIT7;
    SPI_send(Y);
    judge_wait(0b010, Y);
    P1OUT &= ~BIT7;
}

void send_auto_data(uint8_t distance, double rad_angle, uint8_t direction){
    uint8_t temp, angle0, angle1;
    temp = (uint8_t)(rad_angle * 10000);
    angle0 = temp >> 7;
    angle1 = ((temp & 0b1111111) << 1) | (direction & 0b1);
    SPI_send(STARTING_SEQ);
    judge_wait(0b100, STARTING_SEQ);
    P1OUT &= ~BIT7;
    SPI_send(distance);
    judge_wait(0b101, distance);
    P1OUT &= ~BIT7;
    SPI_send(angle0);
    judge_wait(0b110, angle0);
    P1OUT &= ~BIT7;
    SPI_send(angle1);
    judge_wait(0b111, angle1);
    P1OUT &= ~BIT7;
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void SPI_RX_ISR(void){
//    while(UCA0STAT & UCBUSY);
    if ((IFG2 & UCA0RXIFG)){                        // USCI_A0 TX buffer fertig?
        rx_data = UCA0RXBUF;
        P1OUT |= BIT7;
        rx_flag = 1;
    }
}
