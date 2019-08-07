//----------------------------------------------------------------------------- 
// C8051F960_defs.h 
//----------------------------------------------------------------------------- 
// Copyright 2011 Silicon Laboratories, Inc. 
// http://www.silabs.com 
// 
// Program Description: 
// 
// Register/bit definitions for the C8051F96x family. 
// 
// 
// Target:         C8051F96x 
// Tool chain:     Keil, Raisonance, SDCC 
// Command Line:   None 
// 
// 
// Version 0.3 
//    - Initial Release - KB 
// 
//----------------------------------------------------------------------------- 
// Bracketed to avoid multiple inclusion errors. 
//----------------------------------------------------------------------------- 
#ifndef C8051F960_DEFS_H 
#define C8051F960_DEFS_H 
//----------------------------------------------------------------------------- 
// Conditional inclusion of compiler_defs.h to avoid inclusion errors. 
//----------------------------------------------------------------------------- 
#ifndef COMPILER_DEFS_H 
#include <compiler_defs.h> 
#endif 
//----------------------------------------------------------------------------- 
// Page 0x0 sfrs 
//----------------------------------------------------------------------------- 
SFR (P0, 0x80);                        // Port 0 Latch 
SFR (SP, 0x81);                        // Stack Pointer 
SFR (DPL, 0x82);                       // Data Pointer Low 
SFR (DPH, 0x83);                       // Data Pointer High 
SFR (PSBANK, 0x84);                    // Flash Page Switch Bank SFR 
SFR (SFRNEXT, 0x85);                   // SFR Page Stack Next 
SFR (SFRLAST, 0x86);                   // SFR Page Stack Last 
SFR (PCON, 0x87);                      // Power Control 
SFR (TCON, 0x88);                      // Timer/Counter Control 
SFR (TMOD, 0x89);                      // Timer/Counter Mode 
SFR (TL0, 0x8A);                       // Timer/Counter 0 Low 
SFR (TL1, 0x8B);                       // Timer/Counter 1 Low 
SFR (TH0, 0x8C);                       // Timer/Counter 0 High 
SFR (TH1, 0x8D);                       // Timer/Counter 1 High 
SFR (CKCON, 0x8E);                     // Clock Control 
SFR (PSCTL, 0x8F);                     // Program Store R/W Control 
SFR (P1, 0x90);                        // Port 1 Latch 
SFR (TMR3CN, 0x91);                    // Timer/Counter 3 Control 
SFR (TMR3RLL, 0x92);                   // Timer/Counter 3 Reload Low 
SFR (TMR3RLH, 0x93);                   // Timer/Counter 3 Reload High 
SFR (TMR3L, 0x94);                     // Timer/Counter 3 Low 
SFR (TMR3H, 0x95);                     // Timer/Counter 3 High 
SFR (SCON0, 0x98);                     // UART0 Control 
SFR (SBUF0, 0x99);                     // UART0 Data Buffer 
SFR (CPT1CN, 0x9A);                    // Comparator1 Control 
SFR (CPT0CN, 0x9B);                    // Comparator0 Control 
SFR (CPT1MD, 0x9C);                    // Comparator1 Mode Selection 
SFR (CPT0MD, 0x9D);                    // Comparator0 Mode Selection 
SFR (CPT1MX, 0x9E);                    // Comparator1 Mux Selection 
SFR (CPT0MX, 0x9F);                    // Comparator0 Mux Selection 
SFR (P2, 0xA0);                        // Port 2 Latch 
SFR (SPI0CFG, 0xA1);                   // SPI0 Configuration 
SFR (SPI0CKR, 0xA2);                   // SPI0 Clock Rate Control 
SFR (SPI0DAT, 0xA3);                   // SPI0 Data 
SFR (P0MDOUT, 0xA4);                   // Port 0 Output Mode Configuration 
SFR (P1MDOUT, 0xA5);                   // Port 1 Output Mode Configuration 
SFR (P2MDOUT, 0xA6);                   // Port 2 Output Mode Configuration 
SFR (SFRPAGE, 0xA7);                   // SFR Page 
SFR (IE, 0xA8);                        // Interrupt Enable 
SFR (CLKSEL, 0xA9);                    // Clock Select 
SFR (EMI0CN, 0xAA);                    // EMIF Control 
SFR (EMI0CF, 0xAB);                    // EMIF Configuration 
SFR (RTC0ADR, 0xAC);                   // RTC0 Address 
SFR (RTC0DAT, 0xAD);                   // RTC0 Data 
SFR (RTC0KEY, 0xAE);                   // RTC0 Key 
SFR (EMI0TC, 0xAF);                    // EMIF Timing Control 
SFR (P3, 0xB0);                        // Port 3 
SFR (OSCXCN, 0xB1);                    // External Oscillator Control 
SFR (OSCICN, 0xB2);                    // Internal Oscillator Control 
SFR (PMU0MD, 0xB3);                    // Internal Oscillator Calibration 
SFR (PMU0CF, 0xB5);                    // PMU0 Configuration 0 
SFR (PMU0FL, 0xB6);                    // PMU0 flag 
SFR (FLKEY, 0xB7);                     // Flash Lock And Key 
SFR (IP, 0xB8);                        // Interrupt Priority 
SFR (IREF0CN, 0xB9);                   // Current Reference IREF0 Configuration 
SFR (ADC0AC, 0xBA);                    // ADC0 Accumulator Configuration 
SFR (ADC0MX, 0xBB);                    // ADC0 MUX 
SFR (ADC0CF, 0xBC);                    // ADC0 Configuration 
SFR (ADC0L, 0xBD);                     // ADC0 Low 
SFR (ADC0H, 0xBE);                     // ADC0 High 
SFR (P1MASK, 0xBF);                    // Port 1 Mask 
SFR (SMB0CN, 0xC0);                    // SMBus0 Control 
SFR (SMB0CF, 0xC1);                    // SMBus0 Configuration 
SFR (SMB0DAT, 0xC2);                   // SMBus0 Data 
SFR (ADC0GTL, 0xC3);                   // ADC0 Greater-Than Compare Low 
SFR (ADC0GTH, 0xC4);                   // ADC0 Greater-Than Compare High 
SFR (ADC0LTL, 0xC5);                   // ADC0 Less-Than Compare Word Low 
SFR (ADC0LTH, 0xC6);                   // ADC0 Less-Than Compare Word High 
SFR (P0MASK, 0xC7);                    // Port 0 Mask 
SFR (TMR2CN, 0xC8);                    // Timer/Counter 2 Control 
SFR (REG0CN, 0xC9);                    // Voltage Regulator (REG0) Control 
SFR (TMR2RLL, 0xCA);                   // Timer/Counter 2 Reload Low 
SFR (TMR2RLH, 0xCB);                   // Timer/Counter 2 Reload High 
SFR (TMR2L, 0xCC);                     // Timer/Counter 2 Low 
SFR (TMR2H, 0xCD);                     // Timer/Counter 2 High 
SFR (PCA0CPM5, 0xCE);                  // PCA0 Module 5 Mode Register 
SFR (P1MAT, 0xCF);                     // Port 1 Match 
SFR (PSW, 0xD0);                       // Program Status Word 
SFR (REF0CN, 0xD1);                    // Voltage Reference Control 
SFR (PCA0CPL5, 0xD2);                  // PCA0 Capture 5 Low 
SFR (PCA0CPH5, 0xD3);                  // PCA0 Capture 5 High 
SFR (P0SKIP, 0xD4);                    // Port 0 Skip 
SFR (P1SKIP, 0xD5);                    // Port 1 Skip 
SFR (P2SKIP, 0xD6);                    // Port 2 Skip 
SFR (P0MAT, 0xD7);                     // Port 0 Match 
SFR (PCA0CN, 0xD8);                    // PCA0 Control 
SFR (PCA0MD, 0xD9);                    // PCA0 Mode 
SFR (PCA0CPM0, 0xDA);                  // PCA0 Module 0 Mode Register 
SFR (PCA0CPM1, 0xDB);                  // PCA0 Module 1 Mode Register 
SFR (PCA0CPM2, 0xDC);                  // PCA0 Module 2 Mode Register 
SFR (PCA0CPM3, 0xDD);                  // PCA0 Module 3 Mode Register 
SFR (PCA0CPM4, 0xDE);                  // PCA0 Module 4 Mode Register 
SFR (PCA0PWM, 0xDF);                   // PCA0 PWM Configuration 
SFR (ACC, 0xE0);                       // Accumulator 
SFR (XBR0, 0xE1);                      // Port I/O Crossbar Control 0 
SFR (XBR1, 0xE2);                      // Port I/O Crossbar Control 1 
SFR (XBR2, 0xE3);                      // Port I/O Crossbar Control 2 
SFR (IT01CF, 0xE4);                    // INT0/INT1 Configuration 
SFR (FLWR, 0xE5);                      // Flash Write Only Register 
SFR (EIE1, 0xE6);                      // Extended Interrupt Enable 1 
SFR (EIE2, 0xE7);                      // Extended Interrupt Enable 2 
SFR (ADC0CN, 0xE8);                    // ADC0 Control 
SFR (PCA0CPL1, 0xE9);                  // PCA0 Capture 1 Low 
SFR (PCA0CPH1, 0xEA);                  // PCA0 Capture 1 High 
SFR (PCA0CPL2, 0xEB);                  // PCA0 Capture 2 Low 
SFR (PCA0CPH2, 0xEC);                  // PCA0 Capture 2 High 
SFR (PCA0CPL3, 0xED);                  // PCA0 Capture 3 Low 
SFR (PCA0CPH3, 0xEE);                  // PCA0 Capture 3 High 
SFR (RSTSRC, 0xEF);                    // Reset Source Configuration/Status 
SFR (B, 0xF0);                         // B Register 
SFR (P0MDIN, 0xF1);                    // Port 0 Input Mode Configuration 
SFR (P1MDIN, 0xF2);                    // Port 1 Input Mode Configuration 
SFR (P2MDIN, 0xF3);                    // Port 2 Input Mode Configuration 
SFR (SMB0ADR, 0xF4);                   // SMBus Slave Address 
SFR (SMB0ADM, 0xF5);                   // SMBus Slave Address Mask 
SFR (EIP1, 0xF6);                      // Extended Interrupt Priority 1 
SFR (EIP2, 0xF7);                      // Extended Interrupt Priority 2 
SFR (SPI0CN, 0xF8);                    // SPI0 Control 
SFR (PCA0L, 0xF9);                     // PCA0 Counter Low 
SFR (PCA0H, 0xFA);                     // PCA0 Counter High 
SFR (PCA0CPL0, 0xFB);                  // PCA0 Capture 0 Low 
SFR (PCA0CPH0, 0xFC);                  // PCA0 Capture 0 High 
SFR (PCA0CPL4, 0xFD);                  // PCA0 Capture 4 Low 
SFR (PCA0CPH4, 0xFE);                  // PCA0 Capture 4 High 
SFR (VDM0CN, 0xFF);                    // VDD Monitor Control 
//----------------------------------------------------------------------------- 
// Page 0x2 sfrs 
//----------------------------------------------------------------------------- 
SFR (LCD0D0, 0x89);                    // LCD0 Data 0 
SFR (LCD0D1, 0x8A);                    // LCD0 Data 1 
SFR (LCD0D2, 0x8B);                    // LCD0 Data 2 
SFR (LCD0D3, 0x8C);                    // LCD0 Data 3 
SFR (LCD0D4, 0x8D);                    // LCD0 Data 4 
SFR (LCD0D5, 0x8E);                    // LCD0 Data 5 
SFR (LCD0D6, 0x91);                    // LCD0 Data 6 
SFR (LCD0D7, 0x92);                    // LCD0 Data 7 
SFR (LCD0D8, 0x93);                    // LCD0 Data 8 
SFR (LCD0D9, 0x94);                    // LCD0 Data 9 
SFR (LCD0DA, 0x95);                    // LCD0 Data A 
SFR (LCD0DB, 0x96);                    // LCD0 Data B 
SFR (LCD0DC, 0x97);                    // LCD0 Data C 
SFR (LCD0DD, 0x99);                    // LCD0 Data D 
SFR (LCD0DE, 0x9A);                    // LCD0 Data E 
SFR (LCD0DF, 0x9B);                    // LCD0 Data F 
SFR (LCD0CNTRST, 0x9C);                // LCD0 Contrast 
SFR (LCD0CN, 0x9D);                    // LCD0 Control 
SFR (LCD0BLINK, 0x9E);                 // LCD0 Blink Mask 
SFR (LCD0TOGR, 0x9F);                  // LCD0 Toggle Rate 
SFR (SPI1CFG, 0xA1);                   // SPI1 Configuration 
SFR (SPI1CKR, 0xA2);                   // SPI1 Clock Rate Control 
SFR (SPI1DAT, 0xA3);                   // SPI1 Data 
SFR (LCD0PWR, 0xA4);                   // LCD0 Power 
SFR (LCD0CF, 0xA5);                    // LCD0 Configuration 
SFR (LCD0VBMCN, 0xA6);                 // LCD0 VBAT Monitor Control 
SFR (LCD0CLKDIVL, 0xA9);               // LCD0 Clock Divider Low 
SFR (LCD0CLKDIVH, 0xAA);               // LCD0 Clock Divider High 
SFR (LCD0MSCN, 0xAB);                  // LCD0 Master Control 
SFR (LCD0MSCF, 0xAC);                  // LCD0 Master Configuration 
SFR (LCD0CHPCF, 0xAD);                 // LCD0 Charge Pump Configuration 
SFR (LCD0CHPMD, 0xAE);                 // LCD0 Charge Pump Mode 
SFR (LCD0VBMCF, 0xAF);                 // LCD0 VBAT Monitor Configuration 
SFR (DC0CN, 0xB1);                     // DC0 Control 
SFR (DC0CF, 0xB2);                     // DC0 Configuration 
SFR (DC0MD, 0xB3);                     // DC0 Mode 
SFR (LCD0CHPCN, 0xB5);                 // LCD0 Charge Pump Control 
SFR (LCD0BUFMD, 0xB6);                 // LCD0 Buffer Mode 
SFR (CRC1IN, 0xB9);                    // CRC1 In 
SFR (CRC1OUTL, 0xBA);                  // CRC1 Out Low 
SFR (CRC1OUTH, 0xBB);                  // CRC1 Out High 
SFR (CRC1POLL, 0xBC);                  // CRC1 Polynomial Low 
SFR (CRC1POLH, 0xBD);                  // CRC1 Polynomial High 
SFR (CRC1CN, 0xBE);                    // CRC1 Control 
SFR (PC0STAT, 0xC1);                   // PC0 Status 
SFR (ENC0L, 0xC2);                     // ENC0 Low 
SFR (ENC0M, 0xC3);                     // ENC0 Middle 
SFR (ENC0H, 0xC4);                     // ENC0 High 
SFR (ENC0CN, 0xC5);                    // ENC0 Control 
SFR (VREGINSDL, 0xC6);                 // VREGIN Switch Delay Low 
SFR (VREGINSDH, 0xC7);                 // VREGIN Switch Delay High 
SFR (DMA0NCF, 0xC9);                   // DMA0 Configuration 
SFR (DMA0NBAL, 0xCA);                  // DMA0 Base Address Low (Selected Channel) 
SFR (DMA0NBAH, 0xCB);                  // DMA0 Base Address High (Selected Channel) 
SFR (DMA0NAOL, 0xCC);                  // DMA0 Address Offset Low (Selected Channel) 
SFR (DMA0NAOH, 0xCD);                  // DMA0 Address Offset High (Selected Channel) 
SFR (DMA0NSZL, 0xCE);                  // DMA0 Size Low (Selected Channel) 
SFR (DMA0NSZH, 0xCF);                  // DMA0 Size High (Selected Channel) 
SFR (DMA0SEL, 0xD1);                   // DMA0 Channel Select 
SFR (DMA0EN, 0xD2);                    // DMA0 Enable 
SFR (DMA0INT, 0xD3);                   // DMA0 Interrupt 
SFR (DMA0MINT, 0xD4);                  // DMA0 Middle Interrupt 
SFR (DMA0BUSY, 0xD5);                  // DMA0 Busy 
SFR (DMA0NMD, 0xD6);                   // DMA0 Mode (Selected Channel) 
SFR (PC0PCF, 0xD7);                    // PC0 Pull-up Configuration 
SFR (PC0MD, 0xD9);                     // PC0 Mode 
SFR (PC0CTR0L, 0xDA);                  // PC0 Counter 0 Low 
SFR (PC0CTR0M, 0xDB);                  // PC0 Counter 0 Middle 
SFR (PC0CTR0H, 0xDC);                  // PC0 Counter 0 High 
SFR (PC0CTR1L, 0xDD);                  // PC0 Counter 1 Low 
SFR (PC0CTR1M, 0xDE);                  // PC0 Counter 1 Middle 
SFR (PC0CTR1H, 0xDF);                  // PC0 Counter 1 High 
SFR (PC0CMP0L, 0xE1);                  // PC0 Comparator 0 Low 
SFR (PC0CMP0M, 0xE2);                  // PC0 Comparator 0 Middle 
SFR (PC0CMP0H, 0xE3);                  // PC0 Comparator 0 High 
SFR (PC0TH, 0xE4);                     // PC0 Threshold 
SFR (AES0BCFG, 0xE9);                  // AES0 Block Configuration 
SFR (AES0DCFG, 0xEA);                  // AES0 Data Configuration 
SFR (AES0BIN, 0xEB);                   // AES0 Block Input 
SFR (AES0XIN, 0xEC);                   // AES0 XOR Input 
SFR (AES0KIN, 0xED);                   // AES0 Key Input 
SFR (AES0DBA, 0xEE);                   // AES0 Data Byte Address 
SFR (AES0KBA, 0xEF);                   // AES0 Key Byte Address 
SFR (PC0CMP1L, 0xF1);                  // PC0 Comparator 1 Low 
SFR (PC0CMP1M, 0xF2);                  // PC0 Comparator 1 Middle 
SFR (PC0CMP1H, 0xF3);                  // PC0 Comparator 1 High 
SFR (PC0HIST, 0xF4);                   // PC0 History 
SFR (AES0YOUT, 0xF5);                  // AES Y Out 
SFR (SPI1CN, 0xF8);                    // SPI1 Control 
SFR (PC0DCL, 0xF9);                    // PC0 Debounce Configuration Low 
SFR (PC0DCH, 0xFA);                    // PC0 Debounce Configuration high 
SFR (PC0INT0, 0xFB);                   // PC0 Interrupt 0 
SFR (PC0INT1, 0xFC);                   // PC0 Interrupt 1 
SFR (DC0RDY, 0xFD);                    // DC0 Ready 
//----------------------------------------------------------------------------- 
// Page 0xF sfrs 
//----------------------------------------------------------------------------- 
SFR (SFRPGCN, 0x8E);                   // SFR Page Control 
SFR (CRC0DAT, 0x91);                   // CRC0 Data 
SFR (CRC0CN, 0x92);                    // CRC0 Control 
SFR (CRC0IN, 0x93);                    // CRC0 Input 
SFR (CRC0FLIP, 0x94);                  // CRC0 Flip 
SFR (CRC0AUTO, 0x96);                  // CRC0 Automatic Control 
SFR (CRC0CNT, 0x97);                   // CRC0 Automatic Flash Sector Count 
SFR (LCD0BUFCN, 0x9C);                 // LCD0 Buffer Control 
SFR (P3DRV, 0xA1);                     // Port 3 Drive Strength 
SFR (P4DRV, 0xA2);                     // Port 4 Drive Strength 
SFR (P5DRV, 0xA3);                     // Port 5 Drive Strength 
SFR (P0DRV, 0xA4);                     // Port 0 Drive Strength 
SFR (P1DRV, 0xA5);                     // Port 1 Drive Strength 
SFR (P2DRV, 0xA6);                     // Port 2 Drive Strength 
SFR (P6DRV, 0xAA);                     // Port 6 Drive Strength 
SFR (P7DRV, 0xAB);                     // Port 7 Drive Strength 
SFR (LCD0BUFCF, 0xAC);                 // LCD0 Buffer Configuration 
SFR (P3MDOUT, 0xB1);                   // P3 Mode Out 
SFR (OSCIFL, 0xB2);                    // Internal Oscillator Flash 
SFR (OSCICL, 0xB3);                    // Internal Oscillator Calibration 
SFR (FLSCL, 0xB6);                     // Flash Scale Register 
SFR (IREF0CF, 0xB9);                   // Current Reference IREF0 Configuration 
SFR (ADC0PWR, 0xBB);                   // ADC0 Burst Mode Power-Up Time 
SFR (ADC0TK, 0xBC);                    // ADC0 Tracking Control 
SFR (TOFFL, 0xBD);                     // Temperature Offset Low 
SFR (TOFFH, 0xBE);                     // Temperature Offset High 
SFR (P4, 0xD9);                        // Port 4 Latch 
SFR (P5, 0xDA);                        // Port 4 Latch 
SFR (P6, 0xDB);                        // Port 4 Latch 
SFR (P7, 0xDC);                        // Port 4 Latch 
SFR (HWID, 0xE9);                      // Hardware ID 
SFR (REVID, 0xEA);                     // Revision ID 
SFR (DEVICEID, 0xEB);                  // Device ID 
SFR (P3MDIN, 0xF1);                    // Port 3 Input Mode Configuration 
SFR (P4MDIN, 0xF2);                    // Port 4 Input Mode Configuration 
SFR (P5MDIN, 0xF3);                    // Port 5 Input Mode Configuration 
SFR (P6MDIN, 0xF4);                    // Port 6 Input Mode Configuration 
SFR (PCLKACT, 0xF5);                   // Peripheral Clock Enable Active Mode 
SFR (P4MDOUT, 0xF9);                   // P4 Mode Out 
SFR (P5MDOUT, 0xFA);                   // P5 Mode Out 
SFR (P6MDOUT, 0xFB);                   // P6 Mode Out 
SFR (P7MDOUT, 0xFC);                   // P7 Mode Out 
SFR (CLKMODE, 0xFD);                   // Clock Mode 
SFR (PCLKEN, 0xFE);                    // Peripheral Clock Enables (LP Idle) 
//----------------------------------------------------------------------------- 
// 16-bit Register Definitions (might not be supported by all compilers) 
//----------------------------------------------------------------------------- 
SFR16 (DP, 0x82);                      // Data Pointer 
SFR16 (TOFF, 0x85);                    // Temperature Sensor Offset 
SFR16 (TMR3RL, 0x92);                  // Timer 3 Reload 
SFR16 (TMR3, 0x94);                    // Timer 3 Counter 
SFR16 (ADC0, 0xBD);                    // ADC0 Data 
SFR16 (ADC0GT, 0xC3);                  // ADC0 Greater-Than Compare 
SFR16 (ADC0LT, 0xC5);                  // ADC0 Less-Than Compare 
SFR16 (TMR2RL, 0xCA);                  // Timer 2 Reload 
SFR16 (TMR2, 0xCC);                    // Timer 2 Counter 
SFR16 (PCA0CP5, 0xD2);                 // PCA0 Module 5 Capture/Compare 
SFR16 (PCA0CP1, 0xE9);                 // PCA0 Module 1 Capture/Compare 
SFR16 (PCA0CP2, 0xEB);                 // PCA0 Module 2 Capture/Compare 
SFR16 (PCA0CP3, 0xED);                 // PCA0 Module 3 Capture/Compare 
SFR16 (PCA0, 0xF9);                    // PCA0 Counter 
SFR16 (PCA0CP0, 0xFB);                 // PCA0 Module 0 Capture/Compare 
SFR16 (PCA0CP4, 0xFD);                 // PCA0 Module 4 Capture/Compare 
//----------------------------------------------------------------------------- 
// Indirect RTC Register Addresses 
//----------------------------------------------------------------------------- 
#define CAPTURE0  0x00                 // RTC address of CAPTURE0 register 
#define CAPTURE1  0x01                 // RTC address of CAPTURE1 register 
#define CAPTURE2  0x02                 // RTC address of CAPTURE2 register 
#define CAPTURE3  0x03                 // RTC address of CAPTURE3 register 
#define RTC0CN    0x04                 // RTC address of RTC0CN register 
#define RTC0XCN   0x05                 // RTC address of RTC0XCN register 
#define RTC0XCF   0x06                 // RTC address of RTC0XCF register 
#define RTC0CF    0x07                 // RTC address of RTC0CF register 
#define ALARM0B0  0x08                 // RTC address of ALARM0 Byte 0 
#define ALARM0B1  0x09                 // RTC address of ALARM0 Byte 1 
#define ALARM0B2  0x0A                 // RTC address of ALARM0 Byte 2 
#define ALARM0B3  0x0B                 // RTC address of ALARM0 Byte 3 
#define ALARM1B0  0x0C                 // RTC address of ALARM1 Byte 0 
#define ALARM1B1  0x0D                 // RTC address of ALARM1 Byte 1 
#define ALARM1B2  0x0E                 // RTC address of ALARM1 Byte 2 
#define ALARM1B3  0x0F                 // RTC address of ALARM1 Byte 3 
#define ALARM2B0  0x10                 // RTC address of ALARM2 Byte 0 
#define ALARM2B1  0x11                 // RTC address of ALARM2 Byte 1 
#define ALARM2B2  0x12                 // RTC address of ALARM2 Byte 2 
#define ALARM2B3  0x13                 // RTC address of ALARM2 Byte 3 
//----------------------------------------------------------------------------- 
// Address Definitions for Bit-addressable Registers 
//----------------------------------------------------------------------------- 
#define SFR_P0       0x80 
#define SFR_TCON     0x88 
#define SFR_P1       0x90 
#define SFR_SCON0    0x98 
#define SFR_P2       0xA0 
#define SFR_IE       0xA8 
#define SFR_P3       0xB0 
#define SFR_IP       0xB8 
#define SFR_SMB0CN   0xC0 
#define SFR_TMR2CN   0xC8 
#define SFR_PSW      0xD0 
#define SFR_PCA0CN   0xD8 
#define SFR_ACC      0xE0 
#define SFR_ADC0CN   0xE8 
#define SFR_B        0xF0 
#define SFR_SPI0CN   0xF8 
#define SFR_SPI1CN   0xF8 
//----------------------------------------------------------------------------- 
// Bit Definitions 
//----------------------------------------------------------------------------- 
 
// TCON 0x88 
SBIT (TF1, SFR_TCON, 7);               // Timer 1 Overflow Flag 
SBIT (TR1, SFR_TCON, 6);               // Timer 1 On/Off Control 
SBIT (TF0, SFR_TCON, 5);               // Timer 0 Overflow Flag 
SBIT (TR0, SFR_TCON, 4);               // Timer 0 On/Off Control 
SBIT (IE1, SFR_TCON, 3);               // External Interrupt 1 Edge Flag 
SBIT (IT1, SFR_TCON, 2);               // External Interrupt 1 Type 
SBIT (IE0, SFR_TCON, 1);               // External Interrupt 0 Edge Flag 
SBIT (IT0, SFR_TCON, 0);               // External Interrupt 0 Type 
 
// SCON0 0x98 
SBIT (S0MODE, SFR_SCON0, 7);           // UART0 Mode 
                                       // Bit6 UNUSED 
SBIT (MCE0, SFR_SCON0, 5);             // UART0 MCE 
SBIT (REN0, SFR_SCON0, 4);             // UART0 RX Enable 
SBIT (TB80, SFR_SCON0, 3);             // UART0 TX Bit 8 
SBIT (RB80, SFR_SCON0, 2);             // UART0 RX Bit 8 
SBIT (TI0, SFR_SCON0, 1);              // UART0 TX Interrupt Flag 
SBIT (RI0, SFR_SCON0, 0);              // UART0 RX Interrupt Flag 
 
// IE 0xA8 
SBIT (EA, SFR_IE, 7);                  // Global Interrupt Enable 
SBIT (ESPI0, SFR_IE, 6);               // SPI0 Interrupt Enable 
SBIT (ET2, SFR_IE, 5);                 // Timer 2 Interrupt Enable 
SBIT (ES0, SFR_IE, 4);                 // UART0 Interrupt Enable 
SBIT (ET1, SFR_IE, 3);                 // Timer 1 Interrupt Enable 
SBIT (EX1, SFR_IE, 2);                 // External Interrupt 1 Enable 
SBIT (ET0, SFR_IE, 1);                 // Timer 0 Interrupt Enable 
SBIT (EX0, SFR_IE, 0);                 // External Interrupt 0 Enable 
 
 
// IP 0xB8 
                                       // Bit7 UNUSED 
SBIT (PSPI0, SFR_IP, 6);               // SPI0 Priority 
SBIT (PT2, SFR_IP, 5);                 // Timer 2 Priority 
SBIT (PS0, SFR_IP, 4);                 // UART0 Priority 
SBIT (PT1, SFR_IP, 3);                 // Timer 1 Priority 
SBIT (PX1, SFR_IP, 2);                 // External Interrupt 1 Priority 
SBIT (PT0, SFR_IP, 1);                 // Timer 0 Priority 
SBIT (PX0, SFR_IP, 0);                 // External Interrupt 0 Priority 
 
// SMB0CN 0xC0 
SBIT (MASTER, SFR_SMB0CN, 7);          // SMBus0 Master/Slave 
SBIT (TXMODE, SFR_SMB0CN, 6);          // SMBus0 Transmit Mode 
SBIT (STA, SFR_SMB0CN, 5);             // SMBus0 Start Flag 
SBIT (STO, SFR_SMB0CN, 4);             // SMBus0 Stop Flag 
SBIT (ACKRQ, SFR_SMB0CN, 3);           // SMBus0 Acknowledge Request 
SBIT (ARBLOST, SFR_SMB0CN, 2);         // SMBus0 Arbitration Lost 
SBIT (ACK, SFR_SMB0CN, 1);             // SMBus0 Acknowledge Flag 
SBIT (SI, SFR_SMB0CN, 0);              // SMBus0 Interrupt Pending Flag 
 
// TMR2CN 0xC8 
SBIT (TF2H, SFR_TMR2CN, 7);            // Timer 2 High Byte Overflow Flag 
SBIT (TF2L, SFR_TMR2CN, 6);            // Timer 2 Low Byte Overflow Flag 
SBIT (TF2LEN, SFR_TMR2CN, 5);          // Timer 2 Low Byte Interrupt Enable 
SBIT (TF2CEN, SFR_TMR2CN, 4);          // Timer 2 LFO Capture Enable 
SBIT (T2SPLIT, SFR_TMR2CN, 3);         // Timer 2 Split Mode Enable 
SBIT (TR2, SFR_TMR2CN, 2);             // Timer 2 On/Off Control 
SBIT (T2RCLK, SFR_TMR2CN, 1);          // Timer 2 Capture Mode 
SBIT (T2XCLK, SFR_TMR2CN, 0);          // Timer 2 External Clock Select 
 
// PSW 0xD0 
SBIT (CY, SFR_PSW, 7);                 // Carry Flag 
SBIT (AC, SFR_PSW, 6);                 // Auxiliary Carry Flag 
SBIT (F0, SFR_PSW, 5);                 // User Flag 0 
SBIT (RS1, SFR_PSW, 4);                // Register Bank Select 1 
SBIT (RS0, SFR_PSW, 3);                // Register Bank Select 0 
SBIT (OV, SFR_PSW, 2);                 // Overflow Flag 
SBIT (F1, SFR_PSW, 1);                 // User Flag 1 
SBIT (P, SFR_PSW, 0);                  // Accumulator Parity Flag 
 
// PCA0CN 0xD8 
SBIT (CF, SFR_PCA0CN, 7);              // PCA0 Counter Overflow Flag 
SBIT (CR, SFR_PCA0CN, 6);              // PCA0 Counter Run Control Bit 
SBIT (CCF5, SFR_PCA0CN, 5);            // PCA0 Module 5 Interrupt Flag 
SBIT (CCF4, SFR_PCA0CN, 4);            // PCA0 Module 4 Interrupt Flag 
SBIT (CCF3, SFR_PCA0CN, 3);            // PCA0 Module 3 Interrupt Flag 
SBIT (CCF2, SFR_PCA0CN, 2);            // PCA0 Module 2 Interrupt Flag 
SBIT (CCF1, SFR_PCA0CN, 1);            // PCA0 Module 1 Interrupt Flag 
SBIT (CCF0, SFR_PCA0CN, 0);            // PCA0 Module 0 Interrupt Flag 
 
// ADC0CN 0xE8 
SBIT (AD0EN, SFR_ADC0CN, 7);           // ADC0 Enable 
SBIT (BURSTEN, SFR_ADC0CN, 6);         // ADC0 Burst Enable 
SBIT (AD0INT, SFR_ADC0CN, 5);          // ADC0 EOC Interrupt Flag 
SBIT (AD0BUSY, SFR_ADC0CN, 4);         // ADC0 Busy Flag 
SBIT (AD0WINT, SFR_ADC0CN, 3);         // ADC0 Window Interrupt Flag 
SBIT (AD0CM2, SFR_ADC0CN, 2);          // ADC0 Convert Start Mode Bit 2 
SBIT (AD0CM1, SFR_ADC0CN, 1);          // ADC0 Convert Start Mode Bit 1 
SBIT (AD0CM0, SFR_ADC0CN, 0);          // ADC0 Convert Start Mode Bit 0 
 
// SPI0CN 0xF8 
SBIT (SPIF0, SFR_SPI0CN, 7);           // SPI0 Interrupt Flag 
SBIT (WCOL0, SFR_SPI0CN, 6);           // SPI0 Write Collision Flag 
SBIT (MODF0, SFR_SPI0CN, 5);           // SPI0 Mode Fault Flag 
SBIT (RXOVRN0, SFR_SPI0CN, 4);         // SPI0 RX Overrun Flag 
SBIT (NSS0MD1, SFR_SPI0CN, 3);         // SPI0 Slave Select Mode 1 
SBIT (NSS0MD0, SFR_SPI0CN, 2);         // SPI0 Slave Select Mode 0 
SBIT (TXBMT0, SFR_SPI0CN, 1);          // SPI0 TX Buffer Empty Flag 
SBIT (SPI0EN, SFR_SPI0CN, 0);          // SPI0 Enable 
 
// SPI1CN 0xF8 
SBIT (SPIF1, SFR_SPI1CN, 7);           // SPI1 Interrupt Flag 
SBIT (WCOL1, SFR_SPI1CN, 6);           // SPI1 Write Collision Flag 
SBIT (MODF1, SFR_SPI1CN, 5);           // SPI1 Mode Fault Flag 
SBIT (RXOVRN1, SFR_SPI1CN, 4);         // SPI1 RX Overrun Flag 
SBIT (NSS1MD1, SFR_SPI1CN, 3);         // SPI1 Slave Select Mode 1 
SBIT (NSS1MD0, SFR_SPI1CN, 2);         // SPI1 Slave Select Mode 0 
SBIT (TXBMT1, SFR_SPI1CN, 1);          // SPI1 TX Buffer Empty Flag 
SBIT (SPI1EN, SFR_SPI1CN, 0);          // SPI1 Enable 
 
//----------------------------------------------------------------------------- 
// Interrupt Priorities 
//----------------------------------------------------------------------------- 
 
#define INTERRUPT_INT0             0   // External Interrupt 0 
#define INTERRUPT_TIMER0           1   // Timer0 Overflow 
#define INTERRUPT_INT1             2   // External Interrupt 1 
#define INTERRUPT_TIMER1           3   // Timer1 Overflow 
#define INTERRUPT_UART0            4   // Serial Port 0 
#define INTERRUPT_TIMER2           5   // Timer2 Overflow 
#define INTERRUPT_SPI0             6   // Serial Peripheral Interface 0 
#define INTERRUPT_SMBUS0           7   // SMBus0 Interface 
#define INTERRUPT_RTC0ALARM        8   // RTC0 (SmaRTClock) Alarm 
#define INTERRUPT_ADC0_WINDOW      9   // ADC0 Window Comparison 
#define INTERRUPT_ADC0_EOC         10  // ADC0 End Of Conversion 
#define INTERRUPT_PCA0             11  // PCA0 Peripheral 
#define INTERRUPT_COMPARATOR0      12  // Comparator0 
#define INTERRUPT_COMPARATOR1      13  // Comparator1 
#define INTERRUPT_TIMER3           14  // Timer3 Overflow 
#define INTERRUPT_VDDMON           15  // VDD Monitor Early Warning 
#define INTERRUPT_PORT_MATCH       16  // Port Match 
#define INTERRUPT_RTC0_OSC_FAIL    17  // RTC0 (smaRTClock) Oscillator Fail 
#define INTERRUPT_SPI1             18  // Serial Peripheral Interface 1 
#define INTERRUPT_PC0              19  // Pulse Counter 0 
#define INTERRUPT_DMA0             20  // Direct Memory Access 0 
#define INTERRUPT_ENC0             21  // Encoder/Decoder 0 
#define INTERRUPT_AES0             22  // Advanced Encryption Standard 0 
 
//----------------------------------------------------------------------------- 
// SFR Page Definitions 
//----------------------------------------------------------------------------- 
#define LEGACY_PAGE       0x00         // LEGACY SFR PAGE 
#define DPPE_PAGE         0x02         // DPPE SFR PAGE 
#define DMA0_PAGE         0x02         // DMA0 SFR PAGE 
#define AES0_PAGE         0x02         // AES0 SFR PAGE 
#define ENC0_PAGE         0x02         // ENC0 SFR PAGE 
#define CRC1_PAGE         0x02         // CRC1 SFR PAGE 
#define SPI1_PAGE         0x02         // SPI1 SFR PAGE 
#define LCD0_PAGE         0x02         // LCD0 SFR PAGE 
#define CONFIG_PAGE       0x0F         // SYSTEM AND PORT CONFIGURATION PAGE 
#define CRC0_PAGE         0x0F         // CRC0 
#define TOFF_PAGE         0x0F         // TEMPERATURE SENSOR OFFSET PAGE 
 
//----------------------------------------------------------------------------- 
// Header File PreProcessor Directive 
//----------------------------------------------------------------------------- 
#endif                                 // #define C8051F960_DEFS_H 
//----------------------------------------------------------------------------- 
// End Of File 
//-----------------------------------------------------------------------------
