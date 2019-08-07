/*  
 * ezrp_next_api.c  
 *  
 *  Created on: 2011.10.21.  
 *      Author: vihuszar  
 */   
#include "c8051f960_defs.h"   
#include "hardware_defs.h"   
#include "Si446x_B0_defs.h"   
#include "ezrp_next_api.h"   
#include "spi.h"   
   
// Global variables, arrays   
SEGMENT_VARIABLE(abApi_Write[16], U8, SEG_XDATA); // Write buffer for API communication   
SEGMENT_VARIABLE(abApi_Read[16], U8, SEG_XDATA);  // Read buffer for API communication   
   
SEGMENT_VARIABLE(bItStatus[8], U8, SEG_XDATA);          // Read buffer for API communication   
   
SEG_CODE U8 PaSettings[][5] = {   
    /*[0] - PA_MODE, [1] - PA_PWR_LVL, [2] - PA_BIAS_CLKDUTY, [3] - PA_TC_FSK, [4] - PA_TC_OOK */   
    {/*4463_TSQ20B169*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4463_TSQ20D169*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4463_TSQ27F169*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4461_TCE14D434*/0x21,0x7F,0x00,0x5D,0x14},   
    {/*4460_TCE10D434*/0x18,0x1A,0xC0,0x5D,0x14},   
    {/*4463_TCE20B460*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4463_TCE20C460*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4460_TSC10D868*/0x19,0x40,0xE8,0x5D,0x14},   
    {/*4460_TCE10D868*/0x18,0x18,0xC0,0x5D,0x14},   
    {/*4461_TSC14D868*/0x20,0x64,0x2C,0x5D,0x14},   
    {/*4461_TCE16D868*/0x21,0x7F,0x00,0x5D,0x14},   
    {/*4463_TCE20B868*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4463_TCE20C868*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4463_TCE27F868*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4463_TCE20B915*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4463_TCE20C915*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4463_TCE30E915*/0x08,0x7F,0x00,0x5D,0x14},   
    {/*4464_TCE20B420*/0x08,0x7F,0x00,0x5D,0x14}   
};   
   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 bApi_SendCommand(U8 bCmdLength, U8 *pbCmdData)  
  +  
  + DESCRIPTION:    send API command, no response expected  
  +  
  + INPUT:          bCmdLength - nmbr of bytes to be sent  
  +                 *pbCmdData - pointer to the commands  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 bApi_SendCommand(U8 bCmdLength, U8 *pbCmdData)   // Send a command + data to the chip   
{   
  SpiClearNsel(0);                              // Select radio IC by pulling its nSEL pin low   
  bSpi_SendDataNoResp(bCmdLength, pbCmdData);   // Send data array to the radio IC via SPI   
  SpiSetNsel(0);                                // De-select radio IC by putting its nSEL pin high   
  return 0;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 vApi_WaitforCTS(void)  
  +  
  + DESCRIPTION:    wait for CTS  
  +  
  + INPUT:          None  
  +  
  + RETURN:         0 - CTS arrived  
  +                 1 - CTS didn't arrive within MAX_CTS_RETRY  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 vApi_WaitforCTS(void)   
{   
  SEGMENT_VARIABLE(bCtsValue, U8, SEG_XDATA);   
  SEGMENT_VARIABLE(bErrCnt, U16, SEG_XDATA);   
   
  bCtsValue = 0;   
  bErrCnt = 0;   
   
  while (bCtsValue!=0xFF)                   // Wait until radio IC is ready with the data   
  {   
    SpiClearNsel(0);                        // Select radio IC by pulling its nSEL pin low   
    bSpi_SendDataByte(CMD_CTS_READ);        // Read command buffer; send command byte   
    bSpi_SendDataGetResp(1, &bCtsValue);    // Read command buffer; get CTS value   
    SpiSetNsel(0);                          // If CTS is not 0xFF, put NSS high and stay in waiting loop   
    if (++bErrCnt > MAX_CTS_RETRY)   
    {   
      return 1;     // Error handling; if wrong CTS reads exceeds a limit   
    }   
  }   
  return 0;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 bApi_GetFastResponseRegister(U8 bStartReg, U8 bNmbrOfRegs, U8 * pbRegValues)  
  +  
  + DESCRIPTION:    get fast response registers  
  +  
  + INPUT:          bStartReg - one of the fast response registers  
  +                 bNmbrOfRegs - number of registers (1 ... 4)  
  +                 pbRegValues - value of the registers  
  +  
  + RETURN:         0 - operation successful  
  +                 1 - error  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 bApi_GetFastResponseRegister(U8 bStartReg, U8 bNmbrOfRegs, U8 * pbRegValues)   
{   
  if((bNmbrOfRegs == 0) || (bNmbrOfRegs > 4))   
  {   
    return 1;   
  }   
   
  SpiClearNsel(0);   
  bSpi_SendDataByte(bStartReg);   
  bSpi_SendDataGetResp(bNmbrOfRegs, pbRegValues);   
  SpiSetNsel(0);   
  return 0;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 bApi_GetResponse(U8 bRespLength, U8 *pbRespData)  
  +  
  + DESCRIPTION:    wait for CTS and get the read bytes from the chip  
  +  
  + INPUT:          bRespLength - nmbr of bytes to be read  
  +                 *pbRespData - pointer to the read data  
  +  
  + RETURN:         0 - operation successful  
  +                 1 - no CTS within MAX_CTS_RETRY  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 bApi_GetResponse(U8 bRespLength, U8 *pbRespData) // Get response from the chip (used after a command)   
{   
  SEGMENT_VARIABLE(bCtsValue, U8, SEG_XDATA);   
  SEGMENT_VARIABLE(bErrCnt, U16, SEG_XDATA);   
   
  bCtsValue = 0;   
  bErrCnt = 0;   
   
  while (bCtsValue!=0xFF)                   // Wait until radio IC is ready with the data   
  {   
    SpiClearNsel(0);                        // Select radio IC by pulling its nSEL pin low   
    bSpi_SendDataByte(CMD_CTS_READ);        // Read command buffer; send command byte   
    bSpi_SendDataGetResp(1, &bCtsValue);   
    if(bCtsValue != 0xFF)   
    {   
      SpiSetNsel(0);   
    }   
    if(++bErrCnt > MAX_CTS_RETRY)   
    {   
      return 1;   
    }   
  }   
  bSpi_SendDataGetResp(bRespLength, pbRespData);  // CTS value ok, get the response data from the radio IC   
  SpiSetNsel(0);                                  // De-select radio IC by putting its nSEL pin high   
   
  return 0;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 bApi_ReadRxDataBuffer(U8 bRxFifoLength, U8 *pbRxFifoData)  
  +  
  + DESCRIPTION:    Read RX FIFO content from the chip  
  +  
  + INPUT:          bRxFifoLength - nmbr of bytes to be read  
  +  
  + RETURN:         *pbRxFifoData - pointer to the read data  
  +                 0             - operation successful  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 bApi_ReadRxDataBuffer(U8 bRxFifoLength, U8 *pbRxFifoData)   
{   
  SpiClearNsel(0);                                    // Select radio IC by pulling its nSEL pin low   
  bSpi_SendDataByte(CMD_RX_FIFO_READ);                // Send Rx read command   
  bSpi_SendDataGetResp(bRxFifoLength, pbRxFifoData);  // Write Tx FIFO   
  SpiSetNsel(0);                                      // De-select radio IC by putting its nSEL pin high   
  return 0;   
}   
   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  U8 bApi_WriteTxDataBuffer(U8 bTxFifoLength, U8 *pbTxFifoData)  
  +  
  + DESCRIPTION:    wait for CTS and get the read bytes from the chip  
  +  
  + INPUT:      bTxFifoLength - nmbr of bytes to be sent  
  +         *pbTxFifoData - pointer to the transmit data  
  +  
  + RETURN:         0 - operation successful  
  +         1 - no CTS within MAX_CTS_RETRY  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
U8 bApi_WriteTxDataBuffer(U8 bTxFifoLength, U8 *pbTxFifoData)   // Write Tx FIFO   
{   
  SpiClearNsel(0);                                    // Select radio IC by pulling its nSEL pin low   
  bSpi_SendDataByte(CMD_TX_FIFO_WRITE);                 // Send Tx write command   
  bSpi_SendDataNoResp(bTxFifoLength, pbTxFifoData); // Write Tx FIFO   
  SpiSetNsel(0);                                      // De-select radio IC by putting its nSEL pin high   
  return 0;   
}   
   
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++  
  +  
  + FUNCTION NAME:  void vSetPAMode(PA_OPTIONS PaMode)  
  +  
  + DESCRIPTION:    Set the PA operating mode  
  +  
  + INPUT:      PaMode:  
  +                     TestCard_4463_TSQ20B169  
  +                     TestCard_4463_TSQ20D169  
  +                     TestCard_4463_TSQ27F169  
  +                     TestCard_4461_TCE14D434  
  +                     TestCard_4460_TCE10D434  
  +                     TestCard_4463_TCE20B460  
  +                     TestCard_4463_TCE20C460  
  +                     TestCard_4460_TSC10D868  
  +                     TestCard_4460_TCE10D868  
  +                     TestCard_4461_TSC14D868  
  +                     TestCard_4461_TCE16D868  
  +                     TestCard_4463_TCE20B868  
  +                     TestCard_4463_TCE20C868  
  +                     TestCard_4463_TCE27F868  
  +                     TestCard_4463_TCE20B915  
  +                     TestCard_4463_TCE20C915  
  +                     TestCard_4463_TCE30E915  
  +                     TestCard_4464_TCE20B420  
  +  
  + RETURN:         None  
  +  
  + NOTES:          None  
  +  
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/   
void vSetPAMode(U8 bPaMode, U8 bModType)   
{   
   
  abApi_Write[0] = CMD_SET_PROPERTY;   
  abApi_Write[1] = PROP_PA_GROUP;   
  abApi_Write[2] = 4;   
  abApi_Write[3] = PROP_PA_MODE;   
  abApi_Write[4] = PaSettings[bPaMode][0];   
  abApi_Write[5] = PaSettings[bPaMode][1];   
  abApi_Write[6] = PaSettings[bPaMode][2];   
  if (bModType == MOD_OOK)   
  {   
    abApi_Write[7] = PaSettings[bPaMode][4];   
  }   
  else   
  {   
    abApi_Write[7] = PaSettings[bPaMode][3];   
  }   
  bApi_SendCommand(8,abApi_Write);   
  vApi_WaitforCTS();   
}   
