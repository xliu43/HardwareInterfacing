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

#include "Delay_C.h"
//#include "RYG_LEDs.h"
#include "SCI_Lib_C.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/

 //unsigned char Pos;
  char counter=0;
  char countFlag=0;
  char str[20]="";

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
  //print the menu
  SCI0_TxString("\x1B[1;20H") ;  //x-hex, 1B-key escape set cursor postition to first row column 20 
  SCI0_TxString("Counter Menue Choices") ; 
  SCI0_TxString("\x1B[3;10H") ;  
  SCI0_TxString("1       -Start the count") ; 
  SCI0_TxString("\x1B[4;10H") ;  
  SCI0_TxString("2       -Stop the Count") ; 
  SCI0_TxString("\x1B[5;10H") ;  
  SCI0_TxString("3      -Clear the count") ; 
  SCI0_TxString("\x1B[6;10H") ;  
  SCI0_TxString("4     -Exit the program") ;
  SCI0_TxString("\x1B[7;30H") ;  
  SCI0_TxString("Current Count: 00") ;
   
  
  
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
          if( SCI0_Key_hit()){
                switch(SCI0_RxByte()){
                  case 0x31: //1 is pressed
                  countFlag=1;
                  break;
                  case 0x32:
                  countFlag=0;
                  break;
                  case 0x33:
                  counter=0;
                  break;
                  case 0x34:
                  SCI0_TxString("\x1B[2J\x1B[H") ;    //clear and home 
                  break;
                
                }
          }
          if(countFlag){
              counter++;
              if (counter>240)
                 counter=0;
               SCI0_TxString("\x1B[7;30H") ;              
              sprintf(str,"Current Count: %03X",counter);
                SCI0_TxString(str) ;     
              Delay_C(500);
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
