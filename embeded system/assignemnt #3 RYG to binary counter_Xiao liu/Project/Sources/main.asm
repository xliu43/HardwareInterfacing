;****************************************************************************
;* HC12 Program:  YourProg - MiniExplanation                                *
;* Processor:     mc9s12xdp512                                              *
;* Xtal Speed:    16 MHz                                                    *
;* Author:        Marc Anderson                                             *
;* Date:          16:00 May 19, 2010	                                      *
;*                                                                          *
;* Details: A more detailed explanation of the program is entered here      *
;*                                                                          * 
;*                                                                          *
;*                                                                          *
;*                                                                          *
;****************************************************************************

; export symbols
            XDEF Entry            ; export 'Entry' symbol
            ABSENTRY Entry        ; for absolute assembly: mark this as application entry point

; include derivative specific macros
            INCLUDE 'mc9s12xdp512.inc'
            
            
;**************************************************************
;*                  Equates Declared Here                     *
;**************************************************************
ROMStart    EQU  $4000  ; absolute address to place my code/constant data


            

;**************************************************************
;*                 Variables Declared Here                    *
;**************************************************************
            ORG RAMStart 			;Address $0400            
;Insert your variables here 




;**************************************************************
;*                 Constants Declared Here                    *
;**************************************************************
            
Constants	EQU $C000	
	ORG Constants 			;Address $C000

            
;Insert your constants here 




;**************************************************************
;*                 Code Section Here                          *
;**************************************************************
            ORG   ROMStart		  ;Address	$4000
Entry:
            LDS   #RAMEnd+1       ; initialize the stack pointer
                                  ; enable interrupts
                                  
                                  

;Place your code here starting at the Main label                                
                              
Main:
           bclr PT1AD1,#%11100000    ; clear top 3 bits of 16 bits PT1AD1 which are LED bits 
           bset DDR1AD1,#%11100000  ; set top 3bits as outputs(LED), reset inputs
           bset ATD1DIEN1,#%00011111    ;enable digital inputs for switches ATD1: 
           



Loop:      ldd  PT1AD1                        ;Accumulator D 
           adda #%00100000                          ; add one bit to positon 13 
            std PT1AD1                          ;store D value to PAD1 
            bra  Loop
           
          
 
  
  
  
;**************************************************************
;*                 SCI VT100 Strings Defined Here             *
;**************************************************************  
  
     
     
;**************************************************************
;*                 Look-Up Table Includes                     *
;**************************************************************

          ;INCLUDE "YourLookUp.inc" 

 
     
;**************************************************************
;*            Absolute DP128 Library Includes                 *
;************************************************************** 
      
         
         ;INCLUDE "A2D_LIB.inc"
         ;INCLUDE "DAC4822_LIB.inc"
         ;INCLUDE "Delays.inc"
         ;INCLUDE "My Delays.inc"
          
         ;INCLUDE "LCD_LIB.inc"
         ;INCLUDE "LEDS_RYG.inc"
         ;INCLUDE "LEDS_7Seg.inc"
         ;INCLUDE "SCI_LIB.inc"
                  
         ;INCLUDE "SPI_4822.inc"
         ;INCLUDE "STRING_LIB.inc"
         ;INCLUDE "HC12_Switches.inc"
                   
         ;INCLUDE "UTILITY_LIB.inc"
         ;INCLUDE "Math_Utility_Lib.inc"
         
         
;**************************************************************
;*           Absolute XDP512 Library Includes                 *
;************************************************************** 
         ; XDP512 Libs
         ;INCLUDE "IIC-24AA512_EEPROM.inc"
         ;INCLUDE "LCD_XDP512.inc"
         ;INCLUDE "LEDS_7Seg.inc"
         ;INCLUDE "LEDS_RYG_XDP512.inc"         
         ;INCLUDE "My Delays.inc"
         ;INCLUDE "Switches_XDP512.inc"
         
       
         

;**************************************************************
;*                 Interrupt Vectors                          *
;**************************************************************
            ORG   $FFFE
            DC.W  Entry           ; Reset Vector
