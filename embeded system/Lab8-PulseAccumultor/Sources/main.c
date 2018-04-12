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

#include "derivative.h"    	// derivative-specific definitions

/********************************************************************
*		Library includes - your libraries' header files
********************************************************************/
//#include "IIC0_Lib.h"
#include "LCD_4Line_C.h" 
//#include "Misc_Lib.h"
//#include "LEDS_7Seg_C.h"
#include "LEDS_7Seg_C.h"

#include "Delay_C.h"
//#include "RYG_LEDs.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/

 //unsigned char Pos;
 unsigned int iCount=0;
 double dSpeed=0;
 char str[21];

/********************************************************************
*		Lookups
********************************************************************/



void main(void) 	// main entry point
{
	_DISABLE_COP();

/********************************************************************
*		Initializations
********************************************************************/
          LEDS_7Seg_Init_C();
          PACTL=0x40;  //turn the thing on 
          lcdInit();
          
          Set_R_C(0,3);
          lcdString("WindSpeedSensor");
  
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
          Delay_C(1000);
          iCount=PACN32;        
          Top_16Out_C(HexToBCD (iCount ));
          PACN32=0;  
           
          dSpeed=0.1873*iCount+4.1643; //calculate Speed 
          
          
            if(sprintf(str,"SenSor Freq %3u HZ", iCount) >0) {
                   Set_R_C(1,0);
                   lcdString(str);
          } 
              
                if(sprintf(str,"Wind Speed %3.0f HZ", dSpeed) >0) {
                   Set_R_C(2,0);
                   lcdString(str);
          }  
           
               
                                          
   
    

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
