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
                              
Main:        bclr PT1AD1, #$E0     ;make all leds low
             bset DDR1AD1, #$E0     ;make PAD13:15 outputs,reset inputs 
             bset ATD1DIEN1,#$1F  


LOOP:           LDD PT1AD1
             
             BRSET PT1AD1, #%00001000,RedOn              ;if left swith is held down bra to red on 
             BRCLR PT1AD1, #%00001000,RedOFF              ; if left switch is relesed bra to red off 
             
             BRSET PT1AD1, #%00000001,YellowOn 
             BRCLR PT1AD1, #%00000001,YellowOFF
             
             BRSET PT1AD1, #%00000010,GreenOn
             BRCLR PT1AD1, #%00000010,GreenOFF
             
             BRA LOOP
            
RedOn:       bset PT1AD1,#%10000000                       ;turn on red 
             rts
             
RedOFF:      bclr PT1AD1,#%10000000                        ;turn off red 
             rts 
  
YellowOn:    bset PT1AD1,#%01000000          
             rts
             
YellowOFF:   bclr PT1AD1,#%01000000 
             rts 
GreenOn:       bset PT1AD1,#%10000000          
             rts
             
GreenOFF:      bclr PT1AD1,#%10000000 
             rts 
  
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
