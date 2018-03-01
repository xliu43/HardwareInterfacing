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
#include "Misc_Lib.c.h"
#include "LEDS_7Seg_C_Revised.h"
#include "Switches_C.h"
#include "LCD_4Line_C.h"




/********************************************************************
*		Prototypes
********************************************************************/



/********************************************************************
*		Variables
********************************************************************/

 //unsigned char Pos;
 unsigned int hexValue;
 unsigned int output;
  
 unsigned char sw; 
 unsigned char counter;
 char pos;
 unsigned int valueToDisplay=0;
 unsigned int BCDValue;
 char str1[13]="input number";
 char str2[10]="too high!";
           

 
/********************************************************************
*		Lookups
********************************************************************/



void main(void) 	// main entry point
{
	_DISABLE_COP();
   

  
       
  

/********************************************************************
*		Initializations
********************************************************************/
    hexValue=0x271f;
    LEDS_7Seg_Init_C();  
    Sw_Init(); 
  
    lcdInit();
     
     
  
 


/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
      	                                    
       
                                 sw=Get_Switches();
                              
                                 switch(sw){
                
                                                        case 0b00010000: //upswitch
                                                        switch(pos){
                                                          case 0:
                                                          valueToDisplay+=0x1000;
                                                          break;
                                                          case 1:
                                                          valueToDisplay+=0x0100;
                                                          break;
                                                          case 2:
                                                          valueToDisplay+=0x0010;
                                                          break;
                                                          case 3:
                                                          valueToDisplay+=0x0001;
                                                          break;
                                                          
                                                          
                                                                   }
                                                      
                                                        break;
                                                        
                                                        case 0b00000100: //downswitch 
                                                           switch(pos){
                                                          case 0:
                                                          valueToDisplay-=0x1000;
                                                          break;
                                                          case 1:
                                                          valueToDisplay-=0x0100;
                                                          break;
                                                          case 2:
                                                          valueToDisplay-=0x0010;
                                                          break;
                                                          case 3:
                                                          valueToDisplay-=0x0001;
                                                          break;
                                                          
                                                          
                                                                      }
                                                     
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
                                                         
                                                        case 0b00000001:     //center switch 
                                                        BCDValue=HexToBCD(valueToDisplay);
                                                        Bot_16Out_C(BCDValue);
                                                        break;
                                                        
                                           }
                             Top_16Out_C(valueToDisplay);  
                             Wait_For_Switch_Up(sw);
                             
                                                              
                            
                             if(valueToDisplay>0x270f)//flashing the top 
                               {LEDS_7Seg_Init_C();
                                Delay_C(50);
                                Top_16Out_C(valueToDisplay);
                                Delay_C(50);
                               

                                Set_R_C(1,5);
                                lcdString(str1);
                                Set_R_C(2,5);
                                lcdString(str2);
                                
                               }  else
                                 lcdClear();

                                  
 
                              
                                          
          
    

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
