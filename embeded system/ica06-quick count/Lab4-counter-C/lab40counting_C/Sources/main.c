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
#include "LEDS_7Seg_C.h"



/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/

 //unsigned char Pos;
 unsigned char counter;
 signed pos;
 unsigned char sw;
 //int counterBottom;
 


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
  LEDS_7Seg_Init_C();
  
   Top_16Out_C(0x0000);
   //Bot_16Out_C(0x0000);
   counter=0;
   pos=0;
   
 // counterBottom=0;
   
 
  
  
   


/********************************************************************
*		Main Program Code
********************************************************************/
	 
	for (;;)		//endless program loop
  	{
                                sw=Get_Switches();
                              
                                 switch(sw){
                
                                                        case 0b00010000: //upswitch
                                                        counter++;
                                                      
                                                        break;
                                                        
                                                        case 0b00000100: //downswitch 
                                                        counter--;
                                                     
                                                        break; 
                                                        
                                                        case 0b00001000 :  //left switch 
                                                         pos--;
                                                        counter=0;
                                                        if(pos<0)
                                                          pos=3;
                                                        
                                                       
                                                         break;
                                                         
                                                        case 0b0000010 :  //right switch 
                                                            pos++;
                                                        counter=0;
                                                        if(pos>3)
                                                          pos=0;
                                                        
                                                        
                                                         break;    
                                                         
                                                        case 0b00000001:
                                                        Top_16Out_C(0x00);
                                                        break;
                                                        
                                                        }
                                                        
                             Char_7Seg_C(pos,counter);       
                         
                              
                                               
                             Bot_16Out_C(pos);
                             
                             Wait_For_Switch_Up(sw);
          
                
                
                
                
          
   
                 
       
         
    
         
         
         
         
         
         
    
         
         
     
        
      
     
      
      
      
      
      
      
      
      
      
      
                                
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
