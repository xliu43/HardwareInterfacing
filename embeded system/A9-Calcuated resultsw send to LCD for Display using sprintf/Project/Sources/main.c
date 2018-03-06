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
#include "LCD_4Line_C.h"                                                                                                         //dont forget to inlucde the lirary in code !!!!!! 
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
  double cArea=0;
  double sArea=0;
  double sVol=0;
   double diameter=18;
  double radius=0;   
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
 lcdInit();
  radius=diameter/2.0;                                                                                                              //be careful of int dividing if not 2.0
 
     cArea=_M_PI* pow(radius,2);
     sVol=(4.0/3.0)*_M_PI*pow(radius,3.0);
     sArea=4*cArea;
  
           if(diameter>20||diameter<1){
               Set_R_C(1,5);
               lcdString("Out Of Range");
            } 
            else
            {         if(sprintf(str,"Input Diameter: %2.0f",diameter)>0){
                            Set_R_C(0,0);
                        lcdString(str);
                       }
            
           
                     if(sprintf(str,"Circle Area: %6.2f",cArea)>0){
                      Set_R_C(1,0);
                      lcdString(str);
                     }
            
                       if(sprintf(str,"Sphere Area: %6.1f",sArea)>0){
                         Set_R_C(2,0);
                        lcdString(str);
                       }
                       
                       if(sprintf(str,"Sphere  Vol: %6.1f",sVol)>0){
                           Set_R_C(3,0);
                        lcdString(str);
                        }   
           }
         
          

         
         
         

/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
           

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
