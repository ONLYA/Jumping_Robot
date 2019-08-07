/* 
** ============================================================================ 
** 
** FILE 
**  control_IO.h 
** 
** DESCRIPTION 
**  Header file for IO control routines 
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
#ifndef CONTROL_IO_H 
#define CONTROL_IO_H 
 
 
 
                /* ======================================= * 
                 *  F U N C T I O N   P R O T O T Y P E S  * 
		           * ======================================= */ 
 
void InitIO(void); 
void SetLed(U8 number); 
void ClearLed(U8 number); 
BIT GetPB(U8 number); 
 
 
#endif
