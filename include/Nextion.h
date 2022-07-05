#include <Arduino.h>

#ifdef __NEXTION__
#define NEXTION_EXTRN
#else
#define NEXTION_EXTRN   extern 
#endif

// Label Name   La0 to La11
// Pot          Po0 to Po11

#define RXD_NEX 23 /* U2RRXD */
#define TXD_NEX 18

//#define RXD_NEX 21 /* Nextion ES8388 V1 */
//#define TXD_NEX 19 /* Nextion ES8388 V1 */

#define NEXTION_MAX_LABEL 10
#define NEXTION_MAX_POT 10

#define NEXTION_MAX_OVER_TIME   SAMPLE_RATE*BackDelay

#define MAX_MESS_TASK0  40*2
NEXTION_EXTRN  bool     NextionSendTask;
NEXTION_EXTRN  char     messnextask[MAX_MESS_TASK0][60];		    // Buffer transmit
NEXTION_EXTRN  char     messnexfree[MAX_MESS_TASK0];	    	    // 1 Buffer not free 0 Buffer free

NEXTION_EXTRN  bool     overon;
NEXTION_EXTRN  uint32_t overcpt;
NEXTION_EXTRN  uint16_t doubleclick; 
NEXTION_EXTRN  uint8_t  nbclick; 

NEXTION_EXTRN char recept;
NEXTION_EXTRN char messnex[60];		    // Buffer transmit
NEXTION_EXTRN char Nextion_Mess[30];	// Buffer recept
NEXTION_EXTRN unsigned char cptm;
NEXTION_EXTRN unsigned char Nextion_Begin_Receive;
NEXTION_EXTRN unsigned char Nextion_Cmd_Receive;

NEXTION_EXTRN uint8_t IsSelectGraWave;


NEXTION_EXTRN unsigned char Nextion_Send(char *ptmess);
NEXTION_EXTRN void Nextion_Init();
NEXTION_EXTRN void Nextion_Process();
NEXTION_EXTRN uint8_t Nextion_PrintCC(uint8_t cc,int data,uint8_t source);

NEXTION_EXTRN void Nextion_PrintLabel();
NEXTION_EXTRN void Nextion_PrintValues();
NEXTION_EXTRN void Nextion_PotValue(uint8_t value);
NEXTION_EXTRN void Nextion_PotTxt(uint8_t pot,char* ms);
NEXTION_EXTRN void Nextion_Parse();
NEXTION_EXTRN void Nextion_Plot();