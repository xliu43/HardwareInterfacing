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
#include "Switches_C.h"
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
 double VoltageMin=5.115;
 double VoltageMax=0;
 double temp;
 unsigned int sw;
 

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
           Sw_Init();
           LEDS_7Seg_Init_C();
 
  
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
                 ATDSample=  ATD0_Sample7();   
                 Top_16Out_C(ATDSample);                 
                // VoltageIn=ATDSample*0.005;                                                --can not do that becuase the int can not multiple 
                VoltageIn=(double)ATDSample*0.005;
                   sw=Get_Switches();
                              
                                 switch(sw){
                
                                                        case 0b00010000: //upswitch
                                                        VoltageMax=0;
                                                      
                                                        break;
                                                        
                                                        case 0b00000100: //downswitch 
                                                        VoltageMin=5.115;
                                                     
                                                        break; 
                                                        
                                                        case 0b00001000 :  //left switch 
                                                         break;
                                                         
                                                        case 0b0000010 :  //right switch 
                                                         break;    
                                                         
                                                        case 0b00000001:
                                                              VoltageMax=0;
                                                              VoltageMin=5.115;
                                                        break;
                                                        
                                                        }
                    //         Wait_For_Switch_Up(sw);
                 if (VoltageIn>VoltageMax) {
                      VoltageMax=VoltageIn;
                 }
                  if(VoltageIn<VoltageMin){
                     VoltageMin=VoltageIn;
                  }
                   if(sprintf(str,"SAMPLED A/D: %03X",ATDSample)>0){
                            Set_R_C(0,0);
                        lcdString(str);   
                 }
                  if(sprintf(str,"Voltage: %5.3f V",VoltageIn)>0){
                            Set_R_C(1,0);
                        lcdString(str); 
                  }
                  if(sprintf(str,"MAX VOLTAGE: %5.3f V",VoltageMax)>0){
                            Set_R_C(2,0);
                        lcdString(str); 
                  }
                   if(sprintf(str,"MIN VOLTAGE: %5.3f V",VoltageMin)>0){
                            Set_R_C(3,0);
                        lcdString(str); 
                  }
                          
                 Delay_C(2000);     

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
