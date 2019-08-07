/* 
** ============================================================================ 
** 
** FILE 
**  hardware_defs.c 
** 
** DESCRIPTION 
**  Contains 8051 specific definition. 
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
#ifndef HARDWARE_DEFS_H 
#define HARDWARE_DEFS_H 
 
/*------------------------------------------------------------------------*/ 
/*						GLOBAL definitions				                 */ 
/*------------------------------------------------------------------------*/ 
 
 
 
/*------------------------------------------------------------------------*/ 
/*						INCLUDE							                 */ 
/*------------------------------------------------------------------------*/ 
 
 
/*------------------------------------------------------------------------*/ 
/*	C8051F930 Hardware bit definitions (using compiler_def.h macros)       */ 
/*------------------------------------------------------------------------*/ 
 
SBIT(MCU_SDA, SFR_P0, 6); 
SBIT(MCU_SCL, SFR_P0, 7); 
 
SBIT(MCU_SCK, SFR_P2, 0); 
SBIT(MCU_MISO,SFR_P2, 1); 
SBIT(MCU_MOSI,SFR_P2, 2); 
SBIT(MCU_NSEL, SFR_P2, 3); 
 
SBIT(EZRP_NIRQ, SFR_P1, 6); 
SBIT(EZRP_PWRDN, SFR_P1, 7); 
 
SBIT(PB1, SFR_P3, 0); 
SBIT(PB2, SFR_P3, 1); 
SBIT(PB3, SFR_P3, 2); 
SBIT(PB4, SFR_P3, 3); 
SBIT(LED1, SFR_P3, 0); 
SBIT(LED2, SFR_P3, 1); 
SBIT(LED3, SFR_P3, 2); 
SBIT(LED4, SFR_P3, 3); 
 
 
#define TRUE 		1 
#define FALSE		0 
 
 
#endif //HARDWARE_DEFS_H
