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

#include "Delay_C.h"
#include "RYG_LEDs.h"
#include "LCD_4Line_C.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/

 //unsigned char Pos;

/********************************************************************
*		Lookups
********************************************************************/



void main(void) 	// main entry point
{
 

	
	
	

/********************************************************************
*		Initializations
********************************************************************/
             	double pi=3.141592654;
         	int diameter=11;
         	double circleArea=0;
         	double sphereArea=0;
         	double sphereVolumn=0; 
	     //char strArray[21];
	        lcdInit();
            lcdLabels("INPUT DIAMETER: ","CIRCLE AREA: ","SPHERE AREA: ","SPHERE  VOL: ");  
 
 
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
               circleArea= 4*pi*(diameter/2.0) *   (diameter/2.0)*sqrt(diameter);
                                                   
  
    

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
