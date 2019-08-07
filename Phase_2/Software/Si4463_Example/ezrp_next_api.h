/* 
 * ezrp_next_api.h 
 * 
 *  Created on: 2011.10.21. 
 *      Author: vihuszar 
 */ 
 
#ifndef EZRP_NEXT_API_H_ 
#define EZRP_NEXT_API_H_ 
 
//+++++++++++++++++++++ 
//  TestCard selection 
//+++++++++++++++++++++ 
 
#define EZRP_NEXT_TestCard TestCard_4461_TSC14D868 
 
 
//++++++++++++++++++++++++ 
//  TestCard definitions 
//++++++++++++++++++++++++ 
 
#define TestCard_4463_TSQ20B169  0 
#define TestCard_4463_TSQ20D169  1 
#define TestCard_4463_TSQ27F169  2 
#define TestCard_4461_TCE14D434  3 
#define TestCard_4460_TCE10D434  4 
#define TestCard_4463_TCE20B460  5 
#define TestCard_4463_TCE20C460  6 
#define TestCard_4460_TSC10D868  7 
#define TestCard_4460_TCE10D868  8 
#define TestCard_4461_TSC14D868  9 
#define TestCard_4461_TCE16D868 10 
#define TestCard_4463_TCE20B868 11 
#define TestCard_4463_TCE20C868 12 
#define TestCard_4463_TCE27F868 13 
#define TestCard_4463_TCE20B915 14 
#define TestCard_4463_TCE20C915 15 
#define TestCard_4463_TCE30E915 16 
#define TestCard_4464_TCE20B420 17 
 
//+++++++++++++++++++++ 
//  TestCard settings 
//+++++++++++++++++++++ 
 
#if EZRP_NEXT_TestCard == TestCard_4463_TCE20C460 
  #define ONE_SMA_WITH_RF_SWITCH 
#elif EZRP_NEXT_TestCard == TestCard_4463_TCE20C868 
  #define ONE_SMA_WITH_RF_SWITCH 
#elif EZRP_NEXT_TestCard == TestCard_4463_TCE20C915 
  #define ONE_SMA_WITH_RF_SWITCH 
#endif 
 
//++++++++++++++++++++++++++++++++++++ 
//  Modulations for Si446x devices 
//++++++++++++++++++++++++++++++++++++ 
 
#define MOD_CW    0 
#define MOD_OOK   1 
#define MOD_2FSK  2 
#define MOD_2GFSK 3 
#define MOD_4FSK  4 
#define MOD_4GFSK 5 
 
//+++++++++++++++++++++ 
//  Function prototypes 
//+++++++++++++++++++++ 
 
 
// API communication functions - communication layer 2 
U8 bApi_SendCommand(U8 bCmdLength, U8 *pbCmdData);            // Send a command + data to the chip 
U8 vApi_WaitforCTS(void); 
U8 bApi_GetResponse(U8 bRespLength, U8 *pbRespData);          // Get response from the chip (to be used after a command) 
U8 bApi_ReadRxDataBuffer(U8 bRxFifoLength, U8 *pbRxFifoData); // Read Rx FIFO 
U8 bApi_GetFastResponseRegister(U8 bStartReg, U8 bNmbrOfRegs, U8 * pbRegValues); // Read Fast Response Register 
U8 bApi_WriteTxDataBuffer(U8 bTxFifoLength, U8 *pbTxFifoData);   // Write Tx FIFO 
void vSetPAMode(U8 bPaMode, U8 bModType); 
 
//+++++++++++++++++++++ 
//  Global variables 
//+++++++++++++++++++++ 
 
 
// Global variables, arrays 
extern SEGMENT_VARIABLE(abApi_Write[16], U8, SEG_XDATA); // Write buffer for API communication 
extern SEGMENT_VARIABLE(abApi_Read[16], U8, SEG_XDATA);  // Read buffer for API communication 
 
extern SEGMENT_VARIABLE(bItStatus[8], U8, SEG_XDATA);          // Read buffer for API communication 
 
 
#endif /* EZRP_NEXT_API_H_ */ 
