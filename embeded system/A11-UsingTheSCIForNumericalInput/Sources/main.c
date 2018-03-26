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
 	char destString[25]="";                         //declaring a srouce and destination array 
 	char destStringTwo[25]="";
	char srcString[2]="";                             //both filled with nulls 
	char RxData;                                             //raw data 
	char str[20]="";                                                                                                                                         //careful have to decalre a capacity for sprintf to run properly 
	float x=0;                                                    //atof only works on float 
	float y=0;
	
	char clearAndHome[]="\x1b[2J\x1b[H";
	char Prompt1[]="Enter the first decimal Number: ";

	char startLine2[]="\x1b[2;1H";
//	char startLine3[]="\x1b[6;1H";

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
 
          lcdLabels("The Multiplier","N1:","N2:","N1 X N2=");  
         
         

/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
	         SCI0_TxString(clearAndHome);
	         SCI0_TxString(Prompt1); 
	       
              do{
                  RxData=SCI0_RxByte();
                  SCI0_TxByte(RxData);
                  srcString[0]=RxData;
                  strcat(destString,srcString);              
                     }while(RxData!=0x0d);
  
               x=atof(destString);
               
              
                  SCI0_TxString(startLine2); 
                 SCI0_TxString("Enter the second decimal number: "); 
            
 
                       do{
                  RxData=SCI0_RxByte();
                  SCI0_TxByte(RxData);
                  srcString[0]=RxData;
                  strcat(destStringTwo,srcString);              
                     }while(RxData!=0x0d);
  
               y=atof(destStringTwo);
               destString[0]='\0';                                      //clear the 
               
               //print N1
               
            //   if(sprintf(str,"N1: %6.3f",x)>0){
                  Set_R_C(1,5);
                  lcdString(destString);
          //     }
                    if(sprintf(str,"N2: %5.2f",y)>0){
                  Set_R_C(2,0);
                  lcdString(str);
               }
               
                        if(sprintf(str,"N1 X N2=: %8.3f",x*y)>0){
                  Set_R_C(3,0);
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
#include <hidef.h>      /* common defines and macros */






