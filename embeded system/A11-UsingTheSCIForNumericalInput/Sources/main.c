/**************************************************************************
*HC12 Program:	YourProg - MiniExplanation
*Processor:		MC9S12XDP512
*Xtal Speed:	16 MHz
*Author:		Marc Anderson
*Date:		  May 25, 2016                                       
*Details:   Skeleton File with some additions
**************************************************************************/

#include <hidef.h>         	// common defines and macros
#include <stdio.h>		    // ANSI C Standard Input/Output functions
#include <math.h>			      // ANSI C Mathematical functions
#include <string.h>
#include <stdlib.h>

#include "derivative.h"    	// derivative-specific definitions

/********************************************************************
*		Library includes - your libraries' header files
********************************************************************/
//#include "IIC0_Lib.h"
#include "LCD_4Line_C.h" 
//#include "Misc_Lib.h"
//#include "LEDS_7Seg_C.h"
//#include "LEDS_7Seg_C.h"
#include "SCI_Lib_C.h"
#include "Delay_C.h"
//#include "RYG_LEDs.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/

 //unsigned char Pos;
 	char destString[25]="";
	char srcString[2]="";
	char RxData;
	float x=0;

/********************************************************************
*		Lookups
********************************************************************/



void main(void) 	// main entry point
{
	_DISABLE_COP();


/********************************************************************
*		Initializations
********************************************************************/
          SCI0_Init19200();
          lcdInit();
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
              do{
                  RxData=SCI0_RxByte();
                  SCI0_TxByte(RxData);
                  srcString[0]=RxData;
                  strcat(destString,srcString);
                  
                
              
              
              
              }while(RxData!=0x0d);
  
               x=atof(destString);
               Delay_C(1000);

	}
}
/**************************************************************************
*		Function:  Note that functions reside outside of Main - so if you call
*              these from within Main, you must include its prototype     
*              above
***************************************************************************/



/********************************************************************
*		Interrupt Service Routines
********************************************************************/



/*******************************************************************/
#include <hidef.h>      /* common defines and macros */






