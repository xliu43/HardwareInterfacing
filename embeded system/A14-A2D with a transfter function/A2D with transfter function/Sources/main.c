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
//#include <math.h>			      // ANSI C Mathematical functions

#include "derivative.h"    	// derivative-specific definitions

/********************************************************************
*		Library includes - your libraries' header files
********************************************************************/
//#include "IIC0_Lib.h"
#include "LCD_4Line_C.h" 
//#include "Misc_Lib.h"
#include "LEDS_7Seg_C_Revised.h"
//#include "LEDS_7Seg_C.h"

#include "Delay_C.h"
//#include "RYG_LEDs.h"
#include "A2D_Lib_C.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/

 //unsigned char Pos;
 double temp;
 unsigned int  sampleRaw;
 double voltageIn;
int counter=0;
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
       ATD0_Init();
        lcdInit();
        LEDS_7Seg_Init_C();
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{       counter++;
             sampleRaw=ATD0_Sample7();
             Top_16Out_C(sampleRaw);
             voltageIn=sampleRaw*0.005;
             temp=  1.564*voltageIn+22;
             if(sprintf(str,"Hex Value: %03X",sampleRaw)>0){
              Set_R_C(0,0);
              lcdString(str);
             }
              if(sprintf(str,"Voltage In: %5.3f",voltageIn)>0){
              Set_R_C(1,0);
              lcdString(str);
             }
                 if(sprintf(str,"Temp out: %4.1f",temp)>0){
              Set_R_C(2,0);
              lcdString(str);
                 }
              if(sprintf(str,"Sample Number: %3u",counter)>0){
              Set_R_C(3,0);
              lcdString(str);
                 }
                 
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
