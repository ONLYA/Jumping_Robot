#include <msp430.h> 
#include <stdint.h>

/* Macros */
#define STARTING_SEQ 0b10100101

#define MIDx 128
#define MIDy 128

#define PI 3.141592654f
#define BODY_RADIUS 50  // mm
#define WHEEL_RADIUS 60 // mm
#define WHEEL_LENGTH 2*WHEEL_RADIUS*PI // mm
#define GEAR_RATIO 44   // :1

/* Global Variables */
uint8_t rx_data;
uint16_t x, y;
uint16_t distance, angle0, angle1;

volatile uint32_t COUNTL = 0;
volatile uint32_t COUNTR = 0;

/* State Machine Definition */
typedef enum Modes{
    SELFCHECK,
    IDLE_MODE,
    // Controller
    CTRL_X,
    CTRL_Y,
    // Auto
    AUTO_D,
    AUTO_A0,
    AUTO_A1
} Mode;
Mode State = SELFCHECK, nextstate;

/* Function Prototypes */
void Move(uint16_t x, uint16_t y);
void Auto_Move(uint8_t distance, uint8_t angle0, uint8_t angle1);
void SPI_send(uint8_t data);
void clear_count(void);

void init_CLK_16MHZ(void);
void init_GPIO(void);
void init_SPI(void);
void init_PWM(void);

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	init_CLK_16MHZ();
	init_GPIO();
	init_SPI();
	init_PWM();

	__bis_SR_register(LPM0_bits + GIE);       // Enter LPM4, enable interrupts
	__no_operation();

	return 0;
}

/* Init functions */

void init_CLK_16MHZ(void){
    /* Configure the Clock
     * to run it from DCO @16MHz and SMCLK = DCO / 4 */
    BCSCTL1 = CALBC1_16MHZ;
    DCOCTL = CALDCO_16MHZ;
    BCSCTL2 = DIVS_2 + DIVM_0;
}

void init_GPIO(void){
    /* Motor DIR */
    P2DIR |= BIT0 | BIT2 | BIT3 | BIT4;

    P1DIR |= BIT7;  // Warning Indicator

    /* GPIO Interrupt for Sensor feedback */
    P1IES |= BIT3 | BIT6;
    P1IFG &= ~BIT3 | ~BIT6;
    P1IE |= BIT3 | BIT6;
}

void init_SPI(void){
    /* SPI */
    P1DIR &= ~BIT5;
    P1OUT &= ~BIT5;
    P1SEL = BIT1 | BIT2 | BIT4; // P1.1,2,4
    P1SEL2= BIT1 | BIT2 | BIT4;
    UCA0CTL1 = UCSWRST;                         // reset the SPI
    UCA0CTL0 |= UCCKPL + UCMSB + UCSYNC;      // 3-pin, 8-bit SPI Slave
    UCA0CTL1 &= ~UCSWRST;
    IE2 |= UCA0RXIE;
}

void init_PWM(void){
    /* PWM output */
    P2DIR |= BIT1 | BIT5; // P2.1 y P2.4 como salida
    P2SEL |= BIT1 | BIT5; // Asociado al Timer_A1

    TA1CCR0 = 1000-1; // Cargamos el periodo PWM
    TA1CCR1 = 100; // PWM duty cycle, 10% CCR1/(CCR0+1) * 100
    TA1CCR2 = 500; // PWM duty cycle, 50% CCR2/(CCR0+1) * 100
    TA1CCTL1 = OUTMOD_7; //Modo7 reset/set
    TA1CCTL2 = OUTMOD_7; //Modo7 reset/set
    TA1CTL = TASSEL_2 + MC_1; // Timer SMCLK Modo UP
}

/* Functions */

void Move(uint16_t x, uint16_t y){
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

void Auto_Move(uint8_t distance, uint8_t angle0, uint8_t angle1){
    //what?
    // Stop moving
    P2OUT = 0;
    TA1CCR1 = 0;
    TA1CCR2 = 0;

    uint32_t angle = angle0 << 7 | (angle1 >> 1);
    uint8_t direction = angle1 & 1;
    double angle_distance = angle * BODY_RADIUS * GEAR_RATIO / WHEEL_LENGTH / 10000.0;
    uint16_t COUNT_MAX = (uint16_t)angle_distance;

    if (direction) P2OUT = BIT2 | BIT3;
    else P2OUT = BIT0 | BIT4;

    clear_count();
    while (COUNTL <= COUNT_MAX){
        TA1CCR1 = 300;
        TA1CCR2 = 300;
    }
    P2OUT = 0;
    TA1CCR1 = 0;
    TA1CCR2 = 0;

    // Move Forward within a specified distance
    angle_distance = distance * GEAR_RATIO / WHEEL_LENGTH;
    COUNT_MAX = (uint16_t)angle_distance;
    P2OUT = BIT2 | BIT4;
    clear_count();
    while (COUNTR <= COUNT_MAX){
        TA1CCR1 = 500;
        TA1CCR2 = 500;
    }
    P2OUT = 0;
    TA1CCR1 = 0;
    TA1CCR2 = 0;
}

void SPI_send(uint8_t data)
{
    while (!(IFG2 & UCA0TXIFG));              // USCI_A0 TX buffer ready?
    UCA0TXBUF = data;                                                              // Sende Wert
}

void clear_count(void){
    COUNTL = 0;
    COUNTR = 0;
}

// GPIO Interrupt for Sensor
#pragma vector=PORT1_VECTOR
__interrupt void Sensor_INT_ISR(void){
    if (P1IFG & BIT3){
        COUNTL += 1;
        P1IFG &= ~BIT3;
    }
    else if (P1IFG & BIT6){
        COUNTR += 1;
        P1IFG &= ~BIT6;
    }
}

// SPI Interrupt
#pragma vector=USCIAB0RX_VECTOR
__interrupt void SPI_RX_ISR(void){
    if (IFG2 & UCA0RXIFG){
        rx_data = UCA0RXBUF;
        if (P1IN && BIT5){
            switch (State){
                case (SELFCHECK):
                    P1OUT |= BIT7;  // Turn on Indicator
                    if (rx_data == 0xFF){
                        SPI_send(0xFF);
                        P1OUT &= ~BIT7; // Turn off Indicator
                        nextstate = IDLE_MODE;
                    }
                    else{
                        SPI_send(0x00);
                        nextstate = SELFCHECK;
                    }
                    break;
                case (IDLE_MODE):
                    if (P1IN && BIT0){
                        P1OUT |= BIT7;
                        if (rx_data == STARTING_SEQ){
                            SPI_send(0b100);
                            P1OUT &= ~BIT7;
                            nextstate = AUTO_D;
                        }
                        else{
                            SPI_send(0xFF);
                            nextstate = IDLE_MODE;
                        }
                    }
                    else{
                        P1OUT |= BIT7;
                        if (rx_data == STARTING_SEQ){
                            SPI_send(0b000);
                            P1OUT &= ~BIT7;
                            nextstate = CTRL_X;
                        }
                        else{
                            SPI_send(0xFF);
                            nextstate = IDLE_MODE;
                        }
                    }
                    break;
                case (CTRL_X):
                    P1OUT |= BIT7;
                    x = rx_data;
                    SPI_send(0b001);
                    nextstate = CTRL_Y;
                    break;
                case (CTRL_Y):
                    y = rx_data;
                    P1OUT &= ~BIT7;
                    Move(x, y);
                    SPI_send(0b010);
                    nextstate = IDLE_MODE;
                    break;
                case (AUTO_D):
                    P1OUT |= BIT7;
                    distance = rx_data;
                    SPI_send(0b101);
                    nextstate = AUTO_A0;
                    break;
                case (AUTO_A0):
                    angle0 = rx_data;
                    SPI_send(0b110);
                    nextstate = AUTO_A1;
                    break;
                case (AUTO_A1):
                    angle1 = rx_data;
                    P1OUT &= ~BIT7;
                    Auto_Move(distance, angle0, angle1);
                    SPI_send(0b111);
                    nextstate = IDLE_MODE;
                    break;
                default:
                    __no_operation();
                    break;
            }
            State = nextstate;
        }
    }
}
