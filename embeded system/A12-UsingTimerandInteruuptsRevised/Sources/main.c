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
//#include "LEDS_7Seg_C.h"

//#include "Delay_C.h"
//#include "RYG_LEDs.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/

 //unsigned char Pos;
 unsigned int iTicks=0;
 unsigned int iSeconds=50;
 unsigned int iMinutes=59;
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
       //Write registers to set up the timer 
       TSCR1= 0b10000000; //turn the timer on 
       TSCR2 &=0b11111000; //start by clearing hte prescaler bits 
       TSCR2 |=0b00000111;//now set the prescaler 
       TIOS |=0b00000001;// Tios0 set to output compare 
       TCTL2 &=0b11111100; //start by clearing bits for output to PT0 
       TCTL2 |=0b00000001;//set low bit for TC0 for toggle (01) on PT0
       TIE|=0b00000001; //enable channel 0 interuppts 
       TFLG1=0b00000001; //clear TC0 flag 
       
       TC0=TCNT+625; //first interval set up 10ms TC(timer compare)
       
       EnableInterrupts; //Let interrupts proceed Must Do this ! 
       
       lcdInit();
       
       
 
  
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
	     
          iSeconds=(++iTicks/100);
              
          iMinutes=(iSeconds/60);
          
          iSeconds%=60;   
          iMinutes%=60;
         if(sprintf(str,"%02u", iMinutes) >0) {
                   Set_R_C(1,5);
                   lcdString(str);
          }
          if(sprintf(str,":%02u", iSeconds) >0) {
                   Set_R_C(1,8);                  lcdString(str);

          }
          
          asm WAI; //wait for interrupt /inline assembly                                   
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
  interrupt VectorNumber_Vtimch0 void TimerInterval(void) 
  {
        TFLG1 =0b00000001; //acknowledge the interrupts 
        TC0 +=625; //next time 
   
   }


