/*  
 ** ============================================================================  
 **  
 ** FILE  
 **  spi.c  
 **  
 ** DESCRIPTION  
 **   Main file for controlling SPI interface .  
 **  
 ** CREATED  
 **  Silicon Laboratories Hungary Ltd  
 **  
 ** COPYRIGHT  
 **  Copyright 2011 Silicon Laboratories, Inc.  
 ** http://www.silabs.com  
 **  
 ** ============================================================================  
 */   
   
/*------------------------------------------------------------------------*/   
/*                      INCLUDE                                                          */   
/*------------------------------------------------------------------------*/   
#include "compiler_defs.h"   
#include "c8051f960_defs.h"   
#include "hardware_defs.h"   
#include "spi.h"   
   
   
SEGMENT_VARIABLE(fSelectState, U8 , SEG_DATA);   
BIT fSPIDisabled;   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 Spi1ReadWrite(U8 data_in)  
  +  
  + DESCRIPTION:    read/write one byte to the SPI  
  +  
  + INPUT:          data needs to be sent  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None   
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 Spi1ReadWrite(U8 data_in)   
{     
  U8 value;   
  BIT restoreEA;   
  U8  restoreSFRPAGE;   
   
  // disable interrupts during SPI transfer   
  restoreEA = EA;   
  EA = 0;   
  // save SFR page and switch to SPI1 page   
  restoreSFRPAGE= SFRPAGE;   
  SFRPAGE = SPI1_PAGE;   
   
  // Send SPI data using double buffered write   
  SPIF1 = 0;                          // cleat SPIF   
  SPI1DAT = ( data_in );                  // write reg address   
  while(!TXBMT1);                     // wait on TXBMT   
  while((SPI1CFG & 0x80) == 0x80);    // wait on SPIBSY   
  value = SPI1DAT;                    // read value   
  SPIF1 = 0;                          // leave SPIF cleared   
   
  // Restore SFR page and interrupts after SPI transfer   
  SFRPAGE= restoreSFRPAGE;   
  EA = restoreEA;   
   
  return value;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  void Spi1Enable(void)  
  +  
  + DESCRIPTION:    enable SPI and associate to XBAR  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None   
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
void Spi1Enable(void)   
{   
  U8  restoreSFRPAGE;   
   
  // save SFR page and switch to SPI1 page   
  restoreSFRPAGE= SFRPAGE;   
  SFRPAGE = SPI1_PAGE;   
  //enable SPI port   
  SPI1CN |= 0x01;   
   
  SFRPAGE = LEGACY_PAGE;   
  //assiciate to the XBAR   
  XBR1 |= 0x02;   
  //configure IO pins   
  P2SKIP = 0xC8;   
  //set default state for pins   
  MCU_SCK = 1;   
  MCU_MOSI = 1;   
  fSPIDisabled = 0;   
   
  // Restore SFR page and interrupts after SPI transfer   
  SFRPAGE= restoreSFRPAGE;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  void SpiDisable(void)  
  +  
  + DESCRIPTION:    disable SPI and disconnect from XBAR  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None   
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
void Spi1Disable(void)   
{   
  U8  restoreSFRPAGE;   
   
  // save SFR page and switch to SPI1 page   
  restoreSFRPAGE= SFRPAGE;   
  SFRPAGE = SPI1_PAGE;   
  //disable SPI port   
  SPI1CN &=0xFE;   
   
  SFRPAGE = LEGACY_PAGE;   
  //disconnect from XBAR   
  XBR1 &= 0xFD;   
  //configure IO port directions   
  P2SKIP = 0xCF;   
  //set default state for the pins   
  MCU_SCK = 0;   
  MCU_MOSI = 1;   
  fSPIDisabled = 1;   
   
  // Restore SFR page and interrupts after SPI transfer   
  SFRPAGE= restoreSFRPAGE;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  void SpiClearNsel(U8 sel)  
  +  
  + DESCRIPTION:    pull down nSEL of the selected device  
  +  
  + INPUT:          sel - 0-DUT / 2-EEPROM / 3-MCU2  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
void SpiClearNsel(U8 sel)   
{   
   
  fSelectState = 0;   
   
  switch(sel)   
  {   
    case 0:   
      MCU_NSEL = 0;   
      break;   
   
    default:   
      break;   
  }   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  void SpiSetNsel(U8 sel)  
  +  
  + DESCRIPTION:    pull up nSEL of the selected device  
  +  
  + INPUT:          sel - 0-DUT / 2-EEPROM / 3-MCU2  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
void SpiSetNsel(U8 sel)   
{   
   
  fSelectState = 1;   
   
  switch(sel)   
  {   
    case 0:   
      MCU_NSEL = 1;   
      break;   
   
    default:   
      break;   
  }   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 bSpi_SendDataNoResp(U8 bDataInLength, U8 *pbDataIn)  
  +  
  + DESCRIPTION:    send data over SPI no response expected  
  +  
  + INPUT:          bDataInLength - length of data  
  +                 *pbDataIn     - pointer to the data  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 bSpi_SendDataNoResp(U8 bDataInLength, U8 *pbDataIn)   
{   
  SEGMENT_VARIABLE(bCnt, U8, SEG_XDATA);   
   
  for (bCnt=0; bCnt<bDataInLength; bCnt++)    // Send input data array via SPI   
  {   
    Spi1ReadWrite(pbDataIn[bCnt]);   
  }   
  return 0;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 bSpi_SendDataGetResp(U8 bDataOutLength, U8 *pbDataOut)  
  +  
  + DESCRIPTION:    send dummy data over SPI and get the response  
  +  
  + INPUT:          bDataOutLength  - length of data to be read  
  +                 *pbDataOut      - response  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 bSpi_SendDataGetResp(U8 bDataOutLength, U8 *pbDataOut)   // Send data, get the response   
{   
  SEGMENT_VARIABLE(bCnt, U8, SEG_XDATA);   
   
  // send command and get response from the radio IC   
  for (bCnt=0; bCnt<bDataOutLength; bCnt++)   
  {   
    pbDataOut[bCnt] = Spi1ReadWrite(0xFF);            // Store data byte that came from the radio IC   
  }   
  return 0;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 bSpi_SendDataByte(U8 bDataIn)  
  +  
  + DESCRIPTION:    send one byte via SPI  
  +  
  + INPUT:          bDataIn - data to be sent  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 bSpi_SendDataByte(U8 bDataIn)      // Send a single byte via SPI   
{   
  Spi1ReadWrite(bDataIn);   
  return 0;   
}   
