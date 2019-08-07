/*  
** ============================================================================  
**  
** FILE  
**  control_IO.c  
**  
** DESCRIPTION  
**   Main file for controlling LEDs and PBs .  
**  
** CREATED  
**  Silicon Laboratories Hungary Ltd  
**  
** COPYRIGHT  
**  Copyright 2011 Silicon Laboratories, Inc.    
**  http://www.silabs.com  
**  
** ============================================================================  
*/   
/*------------------------------------------------------------------------*/   
/*                      INCLUDE                                                          */   
/*------------------------------------------------------------------------*/   
#include "compiler_defs.h"   
#include "c8051f960_defs.h"   
#include "hardware_defs.h"   
#include "control_IO.h"   
   
SEGMENT_VARIABLE(P3State, U8, SEG_DATA);   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  void InitIO(void)  
  +  
  + DESCRIPTION:    Initialize the P1 for LED & PB  
  +  
  + RETURN:         None  
  +  
  + NOTES:          It has to be called from the Initialization section  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
void InitIO(void)   
{   
    P3State = 0xFF;   
    P3 = P3State;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  void SetLed(U8 number)  
  +  
  + DESCRIPTION:    switch on the proper LED  
  +  
  + RETURN:         None  
  +  
  + NOTES:          the function input is the number (1,2,3,4) of the proper LED   
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
void SetLed(U8 number)   
{   
   
    U8  restoreSFRPAGE;   
   
    restoreSFRPAGE = SFRPAGE;   
    SFRPAGE   = CONFIG_PAGE;   
   
    switch(number)   
    {   
        case 1:    
            LED1 = 0;   
            P3State &= 0xFE;   
            break;   
        case 2:    
            LED2 = 0;   
            P3State &= 0xFD;   
            break;   
        case 3:   
            LED3 = 0;   
            P3State &= 0xFB;   
            break;   
        case 4:   
            LED4 = 0;   
            P3State &= 0xF7;   
            break;   
        default:   
            break;   
    }   
   
   SFRPAGE= restoreSFRPAGE;   
   
   
}   
   
   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  void ClearLed(U8 number)  
  +  
  + DESCRIPTION:    switch off the proper LED  
  +  
  + RETURN:         None  
  +  
  + NOTES:          the function input is the number (1,2,3,4) of the proper LED   
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
void ClearLed(U8 number)   
{   
    U8  restoreSFRPAGE;   
   
    restoreSFRPAGE = SFRPAGE;   
    SFRPAGE   = CONFIG_PAGE;   
       
    switch(number)   
    {   
        case 1:    
            //LED1 = 1;   
            P3State |= 0x01;   
            P3MDOUT &= 0xFE;   
            P3 |= 0x01;   
            break;   
        case 2:    
            //LED2 = 1;   
            P3State |= 0x02;   
            P3MDOUT &= 0xFD;   
            P3 |= 0x02;   
            break;   
        case 3:   
            //LED3 = 1;   
            P3State |= 0x04;   
            P3MDOUT &= 0xFB;   
            P3 |= 0x04;    
            break;   
        case 4:   
            //LED4 = 1;   
            P3State |= 0x08;   
            P3MDOUT &= 0xF7;   
            P3 |= 0x08;   
            break;   
        default:   
            break;   
    }   
   
   SFRPAGE= restoreSFRPAGE;   
   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  bit GetPB(U8 number)  
  +  
  + DESCRIPTION:    read the proper bit status  
  +  
  + RETURN:         None  
  +  
  + NOTES:          the function input is the number (1,2,3,4) of the PB pin   
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
BIT GetPB(U8 number)   
{   
    BIT s;   
  U8  restoreSFRPAGE;   
   
  restoreSFRPAGE = SFRPAGE;   
    SFRPAGE   = CONFIG_PAGE;   
   
    //check whether the selected button was pressed or not   
    switch(number)   
    {   
        case 1:   
            //Disable Global interrupt   
            EA = 0;   
            //latch P2.0 to '1'   
            LED1 = 1;   
            //set P2.0 to input   
            P3MDOUT = 0xFE;   
            NOP();   
            s = LED1;   
            //set P2.0 to output   
            P3MDOUT = 0xFF;   
            //restore LED1   
            if((P3State & 0x01) == 0)   
                SetLed(1);   
            else   
                ClearLed(1);   
            //Enable Global interrupt   
            EA = 1;   
            //return with the value of the button   
//  return s;   
        break;   
   
        case 2:   
            //Disable Global interrupt   
            EA = 0;   
            //latch P2.1 to '1'   
            LED2 = 1;   
            //set P2.1 to input   
            P3MDOUT = 0xFD;   
            NOP();   
            s = LED2;   
            //set P1.5 to output   
            P3MDOUT = 0xFF;   
            //restore LED1   
            if((P3State & 0x02) == 0)   
                SetLed(2);   
            else   
                ClearLed(2);   
            //Enable Global interrupt   
            EA = 1;   
            //return with the value of the button   
//  return s;   
        break;   
   
        case 3:   
            //Disable Global interrupt   
            EA = 0;   
            //latch P2.2 to '1'   
            LED3 = 1;   
            //set P2.2 to input   
            P3MDOUT = 0xFB;   
            NOP();   
            s = LED3;   
            //set P2.2 to output   
            P3MDOUT = 0xFF;   
            //restore LED1   
            if((P3State & 0x04) == 0)   
                SetLed(3);   
            else   
                ClearLed(3);   
            //Enable Global interrupt   
            EA = 1;   
            //return with the value of the button   
//  return s;   
        break;   
   
        case 4:   
            //Disable Global interrupt   
            EA = 0;   
            //latch P2.3 to '1'   
            LED4 = 1;   
            //set P2.3 to input   
            P3MDOUT = 0xF7;   
            NOP();   
            s = LED4;   
            //set P2.3 to output   
            P3MDOUT = 0xFF;   
            //restore LED1   
            if((P3State & 0x08) == 0)   
                SetLed(4);   
            else   
                ClearLed(4);   
            //Enable Global interrupt   
            EA = 1;   
            //return with the value of the button   
//  return s;   
        break;   
   
        default:   
            s = 1;   
        break;   
    }   
   
  SFRPAGE= restoreSFRPAGE;   
   
  return s;   
}   
