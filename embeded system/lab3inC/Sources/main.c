/**************************************************************************
*HC12 Program:	YourProg - MiniExplanation
*Processor:		MC9S12XDP512
*Xtal Speed:	16 MHz
*Author:		Marc Anderson
*Date:		  May 25, 2016                                       
*Details:   Skeleton File with some additions
**************************************************************************/

#include <hidef.h>         	// common defines and macros
//#include <stdio.h>		    // ANSI C Standard Input/Output functions
//#include <math.h>			      // ANSI C Mathematical functions

#include "derivative.h"    	// derivative-specific definitions

/********************************************************************
*		Library includes - your libraries' header files
********************************************************************/
//#include "IIC0_Lib.h"
//#include "LCD_4Line_C.h" 
//#include "Misc_Lib.h"
//#include "LEDS_7Seg_C.h"
//#include "LEDS_7Seg_C.h"

#include "Delay_C.h"
#include "RYG_LEDs.h"
#include "Switches_C.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/
  /*0000 <-> 0  
0001 <-> 1  
0010 <-> 2   
0011 <-> 3
0100 <-> 4
0101 <-> 5
0110 <-> 6
0111 <-> 7
1000 <-> 8
1001 <-> 9
1010 <-> A
1011 <-> B
1100 <-> C
1101 <-> D
1110 <-> E
1111 <-> F*/
 //unsigned char Pos;
 unsigned char switchState;
 

/********************************************************************
*		Lookups
********************************************************************/



void main(void) 	// main entry point
{
	_DISABLE_COP();

/********************************************************************
*		Initializations
********************************************************************/
 
  led_sw_init();
  
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
       switchState=Get_Switches();
       if(switchState ==0x01)     //if Only centerswitch is pressed 
          PT1AD1 &=0b00011111;
       if(switchState &0x08)       //if left key is pressed down 
       {    
           if(switchState &0b00010000) //if up switch is pressed 
           {
                  PT1AD1 +=0b00100000;
                  Wait_For_UpSwitch_Up();    //No override method for C?
           
           }
           
            if(switchState &0b00000100) //if down switch is pressed 
           {
                  PT1AD1 -=0b00100000;
                  Wait_For_DownSwitch_Up();
           
           }
           
          
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
