#include <msp430.h> 
#include <stdint.h>
#include "Si466x_B0_defs.h"

#define MAX_BUFFER_SIZE 20
#define NSEL_PIN BIT5
#define NIRQ BIT3   // NIRQ pin is P1.3
#define INT BIT7    // INT/DONE pin is P1.7
#define LED BIT6    // LED pin is P1.6

#define CMD_FAST_RESPONSE_REG_A 0x50
#define CMD_FAST_RESPONSE_REG_B 0x51
#define CMD_FAST_RESPONSE_REG_C 0x53
#define CMD_FAST_RESPONSE_REG_D 0x57

/*
 * This is RX terminal. Currently there's no plan for Robot Arm, so it's not insured that this terminal is the
 *  rx master controller or just a receiver which needs an FPGA to cooperate with.
 * Two modes:
 *  1. Manual   (RX[0] & BIT7 == 0)
 *  2. Auto     (RX[0] & BIT7 == 1)
 * It controls:
 *  1. Wheels
 *  2. Robot Arm
 *  3. Jump mechanism
 */

uint8_t rx_data;
volatile uint8_t rx_flag;

uint8_t state = 0;
uint8_t X, Y;

uint8_t API_Write[MAX_BUFFER_SIZE] = {0};
uint8_t API_Read[MAX_BUFFER_SIZE] = {0};

uint8_t GPIO_Write[MAX_BUFFER_SIZE] = {0};
//volatile uint8_t NIRQ = 0;  // NIRQ flag

/* RX: Buffer used to receive data in the ISR
 * RXByteCtr: Number of bytes left to receive
 * ReceiveIndex: The index of the next byte to be received in ReceiveBuffer
 * TX: Buffer used to transmit data in the ISR
 * TXByteCtr: Number of bytes left to transfer
 * TransmitIndex: The index of the next byte to be transmitted in TransmitBuffer
 * */
uint8_t RX[MAX_BUFFER_SIZE] = {0};
uint8_t RXByteCtr = 0;
uint8_t ReceiveIndex = 0;
uint8_t TX[MAX_BUFFER_SIZE] = {0};
uint8_t TXByteCtr = 0;
uint8_t TransmitIndex = 0;


void CLK_init(void);
void GPIO_init(void);
void SPI_init(void);
//void ADC10_init(void);

uint8_t SPI_ReadWrite(uint8_t data_in);
uint8_t SPI_byte_send(uint8_t dataIN);
uint8_t SPI_muti_send(uint8_t length, uint8_t *dataIN);
uint8_t SPI_SendResponse(uint8_t length, uint8_t *dataOUT);
void SPI_setNSEL(void);
void SPI_clearNSEL(void);

void Write_Array(uint8_t *src, uint8_t *dest, uint8_t count);

uint8_t API_send_CMD(uint8_t length, uint8_t *CMD_data);
uint8_t API_wait_CTS(void);
uint8_t API_get_response(uint8_t length, uint8_t *RespData);
uint8_t API_Write_TX_FIFO(uint8_t length, uint8_t *TX_FIFO_DATA);
uint8_t API_Read_RX_FIFO(uint8_t length, uint8_t *RX_FIFO_DATA);
uint8_t API_Read_FastResponse_REG(uint8_t REG_Addr, uint8_t REG_num, uint8_t *REG_Value);

uint8_t POWER_UP(void);
void Setup(void);

void GPIO_TX(uint8_t length, uint8_t *data);

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	uint8_t TX_length;
	uint8_t fValidPacket;

	CLK_init();
	GPIO_init();
	SPI_init();

	__bis_SR_register(GIE);

    if (!POWER_UP())
        return 0;

    Setup();

    while (1){
        P1OUT &= ~LED;  // Clear LED bit
        // Wait for detect interrupt
        if ((P1IN & NIRQ) == 0){
            //Read PH IT registers to see the cause for the IT
            API_Write[0] = CMD_GET_PH_STATUS;       // Use packet handler status command
            API_Write[1] = 0x00;                    // Dummy byte
            API_send_CMD(2, API_Write);             // Send command to radio IC
            API_get_response(1, API_Read);          // Get the response
            // Check if packet received
            if ((API_Read[0] & 0x10) == 0x10){
                // packet received
                // Get RSSI
                API_Read_FastResponse_REG(CMD_FAST_RESPONSE_REG_C, 1, API_Read);
                // Read the FIFO
                API_Read_RX_FIFO(8, API_Read);
                /*
                 * CODE BLOCK
                 */
                fValidPacket = 0;
                // Check the packet content
                if (API_Read[0] == 0xFF){
                    // Auto
                    fValidPacket = 1;   // RX valid packet
                    TX_length = 4;      // Set length of TX
                    GPIO_TX(TX_length, API_Read);
                } else if (API_Read[0] == 0 || API_Read[0] == 1){
                    // Manual
                    fValidPacket = 1;   // RX valid packet
                    TX_length = 3;      // Set length of TX
                    GPIO_TX(TX_length, API_Read);
                }
                if (!fValidPacket){
                    // Not received a valid packet, LED on
                    P1OUT |= LED;
                }
                /*
                 * CODE BLOCK
                 */

                // Read ITs, clear pending ones
                API_Write[0] = CMD_GET_INT_STATUS;  // Use interrupt status command
                API_Write[1] = 0;                   // Clear PH_CLE_PEND
                API_Write[2] = 0;                   // Clear MODEM_CLR_PEND
                API_Write[3] = 0;                   // Clear CHIP_CLR_PEND
                API_send_CMD(4, API_Write);         // Send API command to radio IC
                API_get_response(8, API_Read);      // Make sure CTS is ready and read the response

                // Start RX
                API_Write[0] = CMD_START_RX;        // Use start RX command
                API_Write[1] = 0;                   // set Channel number
                API_Write[2] = 0x00;                // Start RX immediately
                API_Write[3] = 0x00;                // 8 bytes to rx
                API_Write[4] = 0x08;                // 8 bytes to rx
                API_Write[5] = 0x00;                // No change if RX timeout
                API_Write[6] = 0x03;                // Ready state after Rx
                API_Write[7] = 0x03;                // Ready if RX invalid
                API_send_CMD(8, API_Write);         // Send API command to radio IC
                API_wait_CTS();                     // Wait for CTS
            }
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
//    P1IES |= BIT3;  // TO receive NIRQ rising edge
//    P1IFG |= BIT3;  // Rising Edge
//    P1IE |= BIT3;   // Enable Port 1 Interrupt
    P2DIR = 0xFF;       // Set all P2.x as output
    P1DIR |= INT | LED; // Set INT bit to output
}

void SPI_init(void){
    P1DIR |= NSEL_PIN;
    P1OUT |= NSEL_PIN;  // NSEL
    P1SEL = BIT1 | BIT2 | BIT4; // P1.1, 1.2, 1.4
    P1SEL2= BIT1 | BIT2 | BIT4;
    UCA0CTL1 = UCSWRST;
    UCA0CTL0 |= UCCKPL + UCMSB + UCMST + UCSYNC;    // MSB, 8-bit, Master, 3-pin , Sync
    UCA0CTL1 |= UCSSEL_2;
    UCA0BR0 |= 0x20;
    UCA0BR1 = 0;
    UCA0MCTL = 0;   // No modulation
    UCA0CTL1 &= ~UCSWRST;
    IE2 |= UCA0RXIE;
}

//void ADC10_init(void){
//    ADC10CTL1 |= BITC | BIT2 | BIT1;    // INCH1, Enable Repeated Sequence Conversion
//    ADC10CTL1 &= ~(BITB | BITA);        // SHS = 0
//    ADC10AE0 |= BIT1 | BIT0;            // A0 and A1
//    ADC10CTL0|= BIT4 | BIT3;            // ADC_ON & ADC10_interrupt
//}

            /*
             * SPI FUNCTIONS
             */

/*
 * SPI Write a byte and Read a byte
 */
uint8_t SPI_ReadWrite(uint8_t data_in){
    while (!(IFG2 & UCA0TXIFG));    // Wait until TX Ready
    rx_flag = 1;    // Enable the RX interrupt
    UCA0TXBUF = data_in;    // Input the data to TX Buffer
    while (rx_flag);// Wait for the rx_flag to be cleared
    return rx_data; // Return the received data
}

/*
 * SPI Send a Single byte
 */
uint8_t SPI_byte_send(uint8_t dataIN){
    SPI_ReadWrite(dataIN);  // Send a byte of data "dataIN"
    return 0;
}

/*
 * SPI Send Multiple data in an array
 */
uint8_t SPI_multi_send(uint8_t length, uint8_t *dataIN){
    uint8_t cnt;    // Declare the count of the current index
    for (cnt = 0; cnt<length; cnt++)
        SPI_ReadWrite(dataIN[cnt]); // A for loop inside the length to send the data array
    return 0;
}

/*
 * SPI Send dummy byte to get response
 */
uint8_t SPI_SendResponse(uint8_t length, uint8_t *dataOUT){
    uint8_t cnt;    // Declare the count of the current index
    for (cnt = 0; cnt<length; cnt++)    // For loop within the length of buffer
        dataOUT[cnt] = SPI_ReadWrite(0xFF); // Send dummy byte to get the response of the data
    return 0;
}

/*
 * Set NSEL to 1 (Disable)
 */
void SPI_setNSEL(void){
    P1OUT |= NSEL_PIN;  // Set NSEL as 1
}

/*
 * Clear NSEL (Enable)
 */
void SPI_clearNSEL(void){
    P1OUT &= ~NSEL_PIN; // Set NSEL as 0
}

            /*
             * General FUNCTIONS
             */

/*
 * Copy Array to the other array
 */
void Copy_Array(uint8_t *src, uint8_t *dest, uint8_t count){
    uint8_t copyIndex = 0;
    for (copyIndex = 0; copyIndex < count; copyIndex++)
    {
        dest[copyIndex] = source[copyIndex];
    }
}

            /*
             * API FUNCTIONS
             */

/*
 * Send Command with data to RF IC
 */
uint8_t API_send_CMD(uint8_t length, uint8_t *CMD_data){
    SPI_clearNSEL();    // Enable SPI select
    SPI_multi_send(length, CMD_data);   // Send multiple bytes including the CMD
    SPI_setNSEL();  // Disable SPI select

    return 0;
}

/*
 * Wait for CTS
 */
uint8_t API_wait_CTS(void){
    uint8_t CTS_Value = 0;
    uint16_t Err_cnt = 0;

    while (CTS_Value != 0xFF){
        SPI_clearNSEL();// Enable SPI select
        SPI_byte_send(0x44);// Send CTS CMD
        SPI_SendResponse(1, &CTS_Value);// Get the response of CTS and write into CTS_Value
        SPI_setNSEL();  // Disable SPI select
        if (++Err_cnt > MAX_CTS_RETRY)  // If the CTS count is greater than the max defined CTS responses
            return 1;   // Return as a fault
    }

    return 0;
}

/*
 * Get response from RF IC
 */
uint8_t API_get_response(uint8_t length, uint8_t *RespData){
    uint8_t CTS_Value = 0;
    uint16_t Err_cnt = 0;

    while (CTS_Value != 0xFF){
        SPI_clearNSEL();// Enable SPI select
        SPI_byte_send(0x44);// Send CTS CMD
        SPI_SendResponse(1, &CTS_Value);// Get the response of CTS and write into CTS_Value
        if (CTS_Value != 0xFF)  // If the returned CTS is not 0xFF
            SPI_setNSEL();  // Disable the SPI select and loop again
        if (Err_cnt++ > MAX_CTS_RETRY)  // If the count is greater than the defined max CTS retry
            return 1;   // Return false attempt
    }
    SPI_SendResponse(length, RespData); // After the CTS 0xFF, read the real data into RespData
    SPI_setNSEL();  // Disable the SPI select

    return 0;
    }
}

/*
 * Write to TX FIFO
 */
uint8_t API_Write_TX_FIFO(uint8_t length, uint8_t *TX_FIFO_DATA){
    SPI_clearNSEL();// Enable SPI select
    SPI_byte_send(0x66);// Send TX_FIFO CMD
    SPI_multi_send(length, TX_FIFO_DATA);   // Write TX FIFO
    SPI_setNSEL();  // Disable SPI select

    return 0;
}

/*
 * Read RX FIFO to output
 */
uint8_t API_Read_RX_FIFO(uint8_t length, uint8_t *RX_FIFO_DATA){
    SPI_cleaarNSEL();// Enable SPI select
    SPI_byte_send(0x77);// Send RX_FIFO CMD
    SPI_SendResponse(length, RX_FIFO_DATA); // Read RX FIFO into RX_FIFO_DATA
    SPI_setNSEL();  // Disbale SPI select

    return 0;
}

/*
 * Read the Fats response registers
 */
uint8_t API_Read_FastResponse_REG(uint8_t REG_Addr, uint8_t REG_num, uint8_t *REG_Value){
    if ((REG_num == 0) || (REG_num > 4))    // if the number of registers is 0 or greater than 4
        return 1;   // return false attempt

    SPI_clearNSEL();// Enable the SPI select
    SPI_byte_send(REG_Addr);// Send Fast Response CMD
    SPI_SendResponse(REG_num, REG_Value);   // Get responses into REG_Value
    SPI_setNSEL();  // Disable the SPI select

    return 0;
}

/*
 * POWER UP the radio, return 0 if something wrong.
 * Normally return 1
 */
uint8_t POWER_UP(void){
    /* Reset the Radio
     * <Write something here>
     */
    __delay_cycles(330);    // Delay for 330 cycles to wait for reset
    /* Wake up Radio from SDN
     * <Write something here>
     */
    __delay_cycles(5500);   // Wait for Power On Reset: ~5ms

    // Start the Radio
    API_Write[0] = CMD_POWER_UP;// Power-up CMD
    API_Write[1] = 0x01;    // Boot normally as a transceiver
    API_Write[2] = 0x00;    // XTAl is not TCXO
    API_send_CMD(3, API_Write); // Send the CMD to RF IC
    // Wait for boot
    if (API_wait_CTS())
        return 0;   // FAIL to Power up

    // Read ITs, clear pending ones
    API_Write[0] = CMD_GET_INT_STATUS;  // Send Interrupt status CMD
    API_Write[1] = 0;   // Clear PH_CLR_PEND
    API_Write[2] = 0;   // Clear MODEM_CLR_PEND
    API_Write[3] = 0;   // Clear CHIP_CLR_PEND
    API_send_CMD(4, API_Write); // Send CMD with data to RF IC
    API_get_response(8, API_Read);  // Read the response into API_Read

    return 1;
}

/*
 * void Setup(void)
 * This is the setup function to set the radio to work as a receiver
 */
void Setup(void){
    // Set packet content
    // Set preamble length
    API_Write[0] = CMD_SET_PROPERTY;            // Use property command
    API_Write[1] = PROP_PREAMBLE_GROUP;         // Select property group
    API_Write[2] = 1;                           // Number of properties to be written
    API_Write[3] = PROP_PREAMBLE_CONFIG_STD_1;  // Specify property
    API_Write[4] = 20;                          // 20 bits preamble detection to the radio IC
    API_send_CMD(5, API_Write);                 // Send API command to radio IC
    API_wait_CTS();                             // Wait for CTS

    //Set preamble pattern
    API_Write[0] = CMD_SET_PROPERTY;            // Use property command
    API_Write[1] = PROP_PREAMBLE_GROUP;         // Select property group
    API_Write[2] = 1;                           // Number of properties to be written
    API_Write[3] = PROP_PREAMBLE_CONFIG;        // Specify property
    API_Write[4] = 0x31;                        // Use '1010' pattern, length defined in bytes
    API_send_CMD(5, API_Write);                 // Send API Command to radio IC
    API_wait_CTS();                             // Wait for CTS


    // Set sync word
    API_Write[0] = CMD_SET_PROPERTY;            // Use property command
    API_Write[1] = PROP_SYNC_GROUP;             // Select property group
    API_Write[2] = 3;                           // Number of properties to be written
    API_Write[3] = PROP_SYNC_CONFIG;            // Specify property
    API_Write[4] = 0x01;                        // 2 bytes sync word: 0x2DD4
    API_Write[5] = 0xB4;                        // 1st sync byte: 0x2D; NOTE LSB transmitted first!
    API_Write[6] = 0x2B;                        // 22n sync byte: 0xD4; NOTE LSB transmitted first!
    API_send_CMD(7, API_Write);                 // Send API Command to radio IC
    API_wait_CTS();                             // Wait for CTS
}


void GPIO_TX(uint8_t length, uint8_t *data){
    uint8_t i;
    for (i = 0; i < length; i++){
        P1OUT |= INT;       // INT rising edge
        P2OUT = data[i];    // TX data
        __delay_cycles(10); // delay for 10 cycles to maintain rising edge
        P1OUT &= ~INT;      // clear INT bit
    }
    P1OUT |= INT;           // INT rising edge
    P2OUT = 0;              // Clear P2 output
    __delay_cycles(10);     // delay for 10 cycles to maintain rising edge
    P1OUT &= ~INT;          // clear INT bit
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void SPI_RX_ISR(void){
    if (rx_flag){
        if (IFG2 & UCA0RXIFG){
            rx_data = UCA0RXBUF;
            rx_flag = 0;
        }
    }
}

//#pragma vector=PORT1_VECTOR
//__interrupt void PORT1_ISR(void){
//    if (P1IFG & BIT3){
//        NIRQ = 1;
//        P1IFG &= ~BIT3;
//    }
//}
