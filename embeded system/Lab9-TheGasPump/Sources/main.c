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
#include "LEDS_7Seg_C_Revised.h"
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
	float regularPrice=1;                                                    //atof only works on float 
	float midPrice=0;
	float preminumPrice=0;
	float liters=0;
	float price=1;
	unsigned char sw=0;
	int GradeSelect=1;
	
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
          Sw_Init();
          LEDS_7Seg_Init_C();
 
          Set_R_C(0,4);
          lcdString("The Gas Pump");
          Set_R_C(1,0);
          lcdString("Enter Todays prices");
          
          
            //input the Regular 
	         SCI0_TxString(clearAndHome);
	         SCI0_TxString("Enter Regular Price: "); 
	       
                  do{
                  
                   RxData=SCI0_RxByte();
                   if(RxData!=0x0d) {
                       SCI0_TxByte(RxData);
                  srcString[0]=RxData;
                  strcat(destString,srcString);  
                   }
                     }while(RxData!=0x0d);
          
               regularPrice=atof(destString);
               destString[0]='\0';
                  
            //input mid-Range price  
                  SCI0_TxString("\x1b[2;1H"); 
                 SCI0_TxString("Enter Mid-Grade Price:  "); 
            
 
                      do{
                  
                   RxData=SCI0_RxByte();
                   if(RxData!=0x0d) {
                       SCI0_TxByte(RxData);
                  srcString[0]=RxData;
                  strcat(destString,srcString);  
                   }
                     }while(RxData!=0x0d);
          
  
               midPrice=atof(destString);
               
                     destString[0]='\0';                                  //clear the  destString array 
                     
               //input Preminum price          
                     SCI0_TxString("\x1b[3;1H"); 
                 SCI0_TxString("Enter  Preminum Price:  "); 
            
 
                      do{
                  
                   RxData=SCI0_RxByte();
                   if(RxData!=0x0d) {
                       SCI0_TxByte(RxData);
                  srcString[0]=RxData;
                  strcat(destString,srcString);  
                   }
                     }while(RxData!=0x0d);
  
               preminumPrice=atof(destString);
               
                     destString[0]='\0';                                  //clear the  destString array 
          
         
         

/********************************************************************
*		Main Program Code
********************************************************************/
	
	for (;;)		//endless program loop
	{
	     lcdClear();
	     GradeSelect=1;
	     if(sprintf(str,"Regular: %05.1f", regularPrice) >0) {
                   Set_R_C(0,0);
                   lcdString(str);
          }   
                     
                     
         if(sprintf(str,"Mid-Grade: %05.1f", midPrice) >0) {
                   Set_R_C(1,0);
                   lcdString(str);
          }   
                            
                          
               
           if(sprintf(str,"Preminum: %05.1f", preminumPrice) >0) {
                   Set_R_C(2,0);
                   lcdString(str);
          }  
          
           //select Grade 
        
            SCI0_TxString(clearAndHome);
	         SCI0_TxString("Select your Grade use Switches: "); 
	           
               
           while(GradeSelect) {
                    
                    sw=Get_Switches();
           
                    switch(sw){
                
                                                        case 0b00010000: //upswitch
                                                         lcdClear();
                                                         Set_R_C(0,5);
                                                         lcdString("The Gas Pump");
                                                         Set_R_C(2,0);
                                                          if(sprintf(str,"regular Price: %5.1f", regularPrice) >0) {
                                                                     Set_R_C(1,0);
                                                                     lcdString(str);
                                                            }   
                                                          Set_R_C(3,0); 
                                                          lcdString("Liters?"); 
                                                          
                                                          price=regularPrice;
                                                          GradeSelect=0;                                              
                                                      
                                                        break;
                                                        
                                                        case 0b00000100: //downswitch 
                                                            lcdClear();
                                                         Set_R_C(0,5);
                                                         lcdString("The Gas Pump");
                                                         Set_R_C(2,0);
                                                          if(sprintf(str,"Premium Price: %5.1f", preminumPrice) >0) {
                                                                     Set_R_C(1,0);
                                                                     lcdString(str);
                                                            }   
                                                          Set_R_C(3,0); 
                                                          lcdString("Liters?"); 
                                                          
                                                          price=preminumPrice;
                                                          GradeSelect=0;         
                                                        break; 
                                                        
                                                        case 0b00001000 :  //left switch 
                                                         break;
                                                         
                                                        case 0b0000010 :  //right switch 
                                                         break;    
                                                         
                                                        case 0b00000001:  //center switch 
                                                           lcdClear();
                                                         Set_R_C(0,5);
                                                         lcdString("The Gas Pump");
                                                         Set_R_C(2,0);
                                                          if(sprintf(str,"Mid-Grade: %5.1f", midPrice) >0) {
                                                                     Set_R_C(1,0);
                                                                     lcdString(str);
                                                            }   
                                                          Set_R_C(3,0); 
                                                          lcdString("Liters?"); 
                                                          
                                                          price=midPrice;
                                                          GradeSelect=0;      
                                                         
                                                        break;
                                                        
                                 }
                   Wait_For_Switch_Up(sw);     
           
           
           }
           
           
             SCI0_TxString(clearAndHome);
	         SCI0_TxString("Enter Liters: "); 
	       
                  do{
                  
                   RxData=SCI0_RxByte();
                   if(RxData!=0x0d) {
                       SCI0_TxByte(RxData);
                  srcString[0]=RxData;
                  strcat(destString,srcString);  
                   }
                     }while(RxData!=0x0d);
          
               liters=atof(destString);
               destString[0]='\0';     
       //Pump the fuel   
                lcdClear();
                Set_R_C(0,4);
          lcdString("The Gas Pump");
         if(sprintf(str,"Price: %05.1f", price ) >0) {
                                                                     Set_R_C(1,0);
                                                                     lcdString(str);
                                                            }   
          
         
           if(sprintf(str,"Liters: %05.1f", liters ) >0) {
                                                                     Set_R_C(2,0);
                                                                     lcdString(str);
                                                            }  
                                                            
           if(sprintf(str,"Your Cost: %05.1f", (liters*price)/100.0 ) >0) {
                                                                     Set_R_C(3,0);
                                                                     lcdString(str);
                                                            }        
               
               
         while( (sw=Get_Switches())!=0b00000001){
         
               
               Bot_8Out_C(sw);
         }
               
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








