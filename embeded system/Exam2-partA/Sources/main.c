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
//#include "LEDS_7Seg_C.h"
//#include "LEDS_7Seg_C.h"
//#include "Switches_C.h"
#include"A2D_Lib_C.h"
#include"LCD_4Line_C.h"

#include "Delay_C.h"
//#include "RYG_LEDs.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/                                                                                                         

 //unsigned char Pos;
 unsigned int ATDSample;
double VoltageIn;
 char str[21] ;
int counter=0;
    char RxData;         

/********************************************************************
*		Lookups
********************************************************************/



void main(void) 	// main entry point
{
	_DISABLE_COP();

/********************************************************************
*		Initializations
********************************************************************/
           lcdInit();         
           ATD0_Init();  
            SCI0_Init19200();
         
         //  LEDS_7Seg_Init_C();
          SCI0_TxString("\x1B[1;1H") ; 
          SCI0_TxString("A/D Sample(Hex)  Sampled Voltage") ; 
          SCI0_TxString("\x1B[2;1H") ; 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
	
	          
                 ATDSample=  ATD0_Sample7();     
                   VoltageIn=(double)ATDSample*0.005;
                   counter++;
                  
                   sprintf(str,"%03X",ATDSample);
                    SCI0_TxString(str) ; 
                   sprintf(str,"                 %5.3f",VoltageIn);
                    SCI0_TxString(str) ; 
                    
                       //cursor down
                    SCI0_TxString("\x1B[B ") ;
                    //cursor backwards
                    SCI0_TxString("\x1B[27D ") ;  
                  Delay_C(1000); 
                  
                 if(counter>24)  {
                             SCI0_TxString("\x1B[2J\x1B[H") ;    //clear and home 
                                  SCI0_TxString("\x1B[1;1H") ; 
          SCI0_TxString("A/D Sample(Hex)  Sampled Voltage") ; 
          SCI0_TxString("\x1B[2;1H") ; 
                       counter=0;
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
