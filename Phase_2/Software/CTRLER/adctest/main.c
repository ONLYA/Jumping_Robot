#include <msp430.h> 

unsigned int adc[3] = {0};
unsigned int X_Axis, Y_Axis, Z_Axis;

/**
 * main.c
 */
int main(void)
{
  Setup_HW();
  while (1)
  {
        Read_Acc(); // This function reads the ADC and stores the x, y and z values
  }
}

// ADC10 interrupt service routine
#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void)
{
  __bic_SR_register_on_exit(CPUOFF);        // Clear CPUOFF bit from 0(SR)
}

void Setup_HW(void)
{
      WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
      ADC10CTL1 = INCH_2 + CONSEQ_1;            // A2/A1/A0, single sequence
      ADC10CTL0 = ADC10SHT_2 + MSC + ADC10ON + ADC10IE;
      ADC10DTC1 = 0x03;                         // 3 conversions
      ADC10AE0 |= 0x03;                         // Disable digital I/O on P1.0 to P1.2
}
void Read_Acc(void)
{
    ADC10CTL0 &= ~ENC;
    while (ADC10CTL1 & BUSY);               // Wait if ADC10 core is active
    ADC10SA = (unsigned int)adc;            // Copies data in ADC10SA to unsigned int adc array
    ADC10CTL0 |= ENC + ADC10SC;             // Sampling and conversion start

    X_Axis = adc[0];                        // adc array 0 copied to the variable X_Axis
    Y_Axis = adc[1];                        // adc array 1 copied to the variable Y_Axis
    Z_Axis = adc[2];                        // adc array 2 copied to the variable Z_Axis
    __bis_SR_register(GIE);        // LPM0, ADC10_ISR will force exit
}
