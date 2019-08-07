/**************************************************************
*** Configuration File generated automatically by           ***
*** SILICON LABS's Wireless Development Suite               ***
*** WDS GUI Version: 3.1.4.4                                ***
*** Device: Si4464 Rev.: B0                                 ***
***                                                         ***
***                                                         ***
*** For further details please consult with the device      ***
*** datasheet, available at <http://www.silabs.com>         ***
***************************************************************/

/* 
//IMPORTANT USAGE GUIDE
//If you intend to use this definition:
#define Si4460_DEFINED_VALUES

//then use it this way:
U8 commandArray[] = {Si4460_DEFINED_VALUES}; 

// U8 is a macro for 'byte' value at different compilers
// defined in the compiler_defs.h
*/
#define EZRADIO2_SI4464_B0

#define XO_TUNE 0x11, 0x00, 0x01, 0x00, 0x52


/* Input file content:
%%	Crys_freq(Hz)	Crys_tol(ppm)	IF_mode	High_perf_Ch_Fil	OSRtune	Ch_Fil_Bw_AFC	ANT_DIV	PM_pattern
 	30000000	20	2	1	0	0	0	0
%%	MOD_type	Rsymb(bps)	Fdev(Hz)	OOK_BW(Hz)	Mancheste	AFC_en	Rsymb_error	Chip-Version
 	3	50000	25000	200000	0	1	0	3
%%	RF Freq.(MHz)	API_TC	fhst	Hi_pfm_cp	BERT	RAW_dout	D_source	Hi_pfm_div
 	915	28	0	1	0	0	0	1
*/

#define CENTER_FREQ 915000000
#define XTAL_FREQ 30000000
#define CHANNEL_SPACING 250000
#define CHANNEL_NUMBER 0
#define XTAL_CAP_BANK 0x52
#define MODULATION_TYPE "2GFSK"
#define MANCHESTER_CODE "Off"
#define DEVIATION 25000
#define DATA_RATE 50000
#define ANTENNA_DIVERSITY "Disabled"


// # WB filter 2 (BW = 103.06 kHz);  NB-filter 2 (BW = 103.06 kHz) 

// EZRadio PRO2 modem calculator output header file  modem_params.h

// RF frequency is 915.00 MHz
// Mod type is 2GFSK,	DataRate: 50.00 ksps;   FreqDev: 25.00 kHz 

// all for TX in this section:
// DataRate: 3 API bytes;  NCOMODulus: 4 bytes; FreqDev: 3 bytes, for TX 
#define MODEM_DATA_RATE_2_14 0x11, 0x20, 0x0A, 0x03,   0x01, 0x86, 0xA0, 0x08, 0x2D, 0xC6, 0xC0, 0x00, 0x03, 0x6A
#define MODEM_TX_RAMP_DELAY_5 0x11, 0x20, 0x01, 0x18,   0x01
// PA ramp time control: 1 byte
#define PA_TC_5  0x11, 0x22, 0x01, 0x03, 0x1C


// all for general parameters in both TRX 
#define MODEM_MOD_TYPE_7 0x11, 0x20, 0x03, 0x00,  0x03, 0x00, 0x07
#define MODEM_CLKGEN_BAND_5 0x11, 0x20, 0x01, 0x51,   0x08
// SYNTH CONTROL GROUP: 7 API bytes, for both TRX 
#define SYNTH_PFDCP_CPFF_11 0x11, 0x23, 0x07, 0x00, 0x2C, 0x0E, 0x0B, 0x04, 0x0C, 0x73, 0x03
// FREQ CONTROL GROUP: 8 API bytes,  TRX
#define FREQ_CONTROL_INTE_12 0x11, 0x40, 0x08, 0x00,  0x3C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x20,  0xFF


// all for RX below:
// MDM_CTRL: 1 byte,  IF_CONTROL: 1B,  IF_FREQ: 3B,  DECIMATION_CFG: 2B,  for all RX 
#define MODEM_MDM_CTRL_11 0x11, 0x20, 0x07, 0x19,   0x00, 0x08, 0x03, 0xC0, 0x00, 0x20, 0x20
// BCR: 10 bytes,  for all RX 
#define MODEM_BCR_OSR_1_14 0x11, 0x20, 0x0A, 0x22,  0x00, 0x4B, 0x06, 0xD3, 0xA0, 0x06, 0xD4, 0x02, 0x00, 0x00
// AFC: 8 bytes,  for (G)FSK RX 
#define MODEM_AFC_GEAR_12 0x11, 0x20, 0x08, 0x2C,  0x00, 0x12, 0x80, 0xDA, 0x01, 0xCC, 0xE0, 0x00

// select real or complex ADC based on IF mode, effective from ROM3 on
//#define MODEM_ADC_CTRL_5 0x11, 0x20, 0x01, 0x34,   0x00

// AGC: 4 bytes,  for all RX 
#define MODEM_AGC_CONTRL_5 0x11, 0x20, 0x01, 0x35,   0xE0
#define MODEM_AGC_WINDOW_SIZE_7 0x11, 0x20, 0x03, 0x38,  0x11, 0x10, 0x10

// 4FSK: 5 bytes,  for 4(G)FSK RX 
#define MODEM_FSK4_GAIN1_9 0x11, 0x20, 0x05, 0x3B,  0x0B, 0x1C, 0x40, 0x00, 0xE1
// OOK: 4 bytes, for RX 
#define MODEM_OOK_PDTC_8 0x11, 0x20, 0x04, 0x40,  0x28, 0x0C, 0xA4, 0x03
// raw: 4 bytes, for RX 
#define MODEM_RAW_SEARCH_8 0x11, 0x20, 0x04, 0x44,  0xD6, 0x02, 0x00, 0xD5
// AntDiv: 2 bytes, for RX 
#define MODEM_ANT_DIV_MODE_6 0x11, 0x20, 0x02, 0x48,  0x02, 0x80
// RSSI_comp: 1 bytes, for RX 
#define MODEM_RSSI_COMP_5  0x11, 0x20, 0x01, 0x4E, 0x38

// RX chfil coeff:  WB filter k1=2 (BW=103.1 kHz), NB filter k2=2 (BW=103.1 kHz)
// MODEM_CHFLT_RX1 GROUP: 18 API bytes,  for all RX 
#define MODEM_CHFLT_RX1_CHFLT_COE13_7_0_13 0x11, 0x21, 0x09, 0x00,  0xFF, 0xC4, 0x30, 0x7F, 0xF5, 0xB5, 0xB8, 0xDE, 0x05
#define MODEM_CHFLT_RX1_CHFLT_COE4_7_0_13  0x11, 0x21, 0x09, 0x09,  0x17, 0x16, 0x0C, 0x03, 0x00, 0x15, 0xFF, 0x00, 0x00
// MODEM_CHFLT_RX2 GROUP: 18 API bytes, 
#define MODEM_CHFLT_RX2_CHFLT_COE13_7_0_13 0x11, 0x21, 0x09, 0x12,  0xFF, 0xC4, 0x30, 0x7F, 0xF5, 0xB5, 0xB8, 0xDE, 0x05
#define MODEM_CHFLT_RX2_CHFLT_COE4_7_0_13  0x11, 0x21, 0x09, 0x1B,  0x17, 0x16, 0x0C, 0x03, 0x00, 0x15, 0xFF, 0x00, 0x00

#define PA_MODE 0x10, 0x00, 0x00, 0x11, 0x22, 0x01, 0x00, 0x08
#define PA_PWR_LVL 0x10, 0x00, 0x00, 0x11, 0x22, 0x01, 0x01, 0x7F
#define PA_BIAS_CLKDUTY 0x10, 0x00, 0x00, 0x11, 0x22, 0x01, 0x02, 0x00

