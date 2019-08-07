/* 
** ============================================================================ 
** 
** FILE 
**  spi.h 
** 
** DESCRIPTION 
**  Header file for SPI routines 
** 
** CREATED 
**  Silicon Laboratories Hungary Ltd 
** 
** COPYRIGHT 
**  Copyright 2011 Silicon Laboratories, Inc.   
**	http://www.silabs.com 
** 
** ============================================================================ 
*/ 
#ifndef SPI_H 
#define SPI_H 
 
 
extern SEGMENT_VARIABLE(fSelectState, U8, SEG_DATA); 
extern BIT fSPIDisabled; 
 
                /* ======================================= * 
                 *  F U N C T I O N   P R O T O T Y P E S  * 
                 * ======================================= */ 
U8 Spi1ReadWrite(U8 data_in); 
void Spi1Enable(void); 
void Spi1Disable(void); 
void SpiClearNsel(U8 sel); 
void SpiSetNsel(U8 sel); 
 
U8 bSpi_SendDataNoResp(U8 bDataInLength, U8 *pbDataIn); 
U8 bSpi_SendDataGetResp(U8 bDataOutLength, U8 *pbDataOut); 
U8 bSpi_SendDataByte(U8 bDataIn); 
 
#endif
