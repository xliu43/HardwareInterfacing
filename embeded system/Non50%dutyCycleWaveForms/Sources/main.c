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
//#include "LCD_4Line_C.h" 
//#include "Misc_Lib.h"
//#include "LEDS_7Seg_C_Revised.h"
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
 unsigned int  sampleRaw;
 double voltageIn;
 char str[21];
 double dutyCycle=0;
 int iCount=0;

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
        
        
          /*
           set up prescalser 
                            divided by 
                     0        1
                     1        2
                     2        4
                     3        8
                     4        16
                     5        32
                     6        64
                     7        128
                     
         */
      
       //Write registers to set up the timer 
       TSCR1= 0b10000000; //turn the timer on 
       TSCR2 &=0b11111000; //start by clearing hte prescaler bits 
       TSCR2 |=0b00000011;//now set the prescaler 
       TIOS |=0b00000001;// Tios0 set to output compare 
       TCTL2 &=0b11111100; //start by clearing bits for output to PT0 
       TCTL2 |=0b00000001;//set low bit for TC0 for toggle (01) on PT0
       TIE|=0b00000001; //enable channel 0 interuppts 
       TFLG1=0b00000001; //clear TC0 flag 
       
       TC0=TCNT+4761; //first interval  TC(timer compare)
       
       EnableInterrupts; //Let interrupts proceed Must Do this ! 
       
    


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{         
             sampleRaw=ATD0_Sample7();
             Set_R_C(0,2);
            
             Top_16Out_C(sampleRaw);
             voltageIn=sampleRaw*0.005;
                 if(sprintf(str,"%5.1f", voltageIn) >0) {
                   Set_R_C(1,5);
                   lcdString(str);
              }   
              
             dutyCycle=voltageIn/5.0;
             if(voltageIn<=0.5)
                 dutyCycle=0.1;
             if(voltageIn>=4.5)
                 dutyCycle=0.9;
             
             
                 
              
               asm WAI; 
             
             
             
             
                                            
  
    

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
        iCount++;
        TFLG1 =0b00000001; //acknowledge the interrupts 
        if(iCount%2==1)
        TC0 +=(int)(dutyCycle*10000); //next time 
         else 
            TC0 +=(int)((1-dutyCycle)*10000);
        
     
   
   }

/*******************************************************************/
