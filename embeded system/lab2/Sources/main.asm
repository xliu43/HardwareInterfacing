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
                              
Main:      bclr PT1AD1, #$E0     ;make all leds low
           bset DDR1AD1, #$E0     ;make PAD13:15 outputs,reset inputs 
           bset ATD1DIEN1,#$1F    ;enable digital inputs for switches ATD1:
           
LOOP:               LDD  PT1AD1          ;load port state 
                    ANDA #%00011111    ;clear first three bits so has clean switch 
            
                    CMPA #0              ;compare accA with 0;
                    BEQ LOOP             ;if equal to 0 No SW is pressed go back to loop
                                ; else continue 
CheckCenterKeyPress:    BRSET PT1AD1,%00000001,OnCenterKeyPress
CheckLeftKeyPress:      BRSET PT1AD1,%00001000,OnLeftKeyPress             
                        BRA LOOP 


OnLeftKeyPress:     BRSET PT1AD1,%00010000,OnUpKeyPress    ;checkUpkeypress 
                    BRSET PT1AD1,%00000100,OnDownKeyPress  ;checkDownKeyPress
                    BRA  LOOP      
                        

OnUpKeyPress:        LDX #10                                 ;check debouncing 
                     JSR Delay  
                     BRSET PT1AD1,%00010000,UpKeyPressed 
                     BRA LOOP 

UpKeyPressed:       LDD PT1AD1
                    ADDA #%0010000
                    STD PT1AD1                             ;add counter1 
UpKeyRelease:       BRCLR PT1AD1,%00010000,LOOP 
                    BRA UpKeyRelease                       ;keep checking if upkey is released before proceeding
                    
                    
OnDownKeyPress:      LDX #10                                 ;check debouncing 
                     JSR Delay  
                     BRSET PT1AD1,%00000100,DownKeyPressed 
                     BRA LOOP                    

DownKeyPressed       LDD PT1AD1
                     SUBA #%0010000
                     STD PT1AD1   
DownKeyReleased:     BRCLR PT1AD1,%00000100,LOOP 
                     BRA DownKeyReleased  


OnCenterKeyPress:    LDX #10                            
                     JSR Delay  
                     BRSET PT1AD1,%00000001,CenterKeyPressed 
                     BRA CheckLeftKeyPress                         ;center key is not pressed
CenterKeyPressed:                                                  ;check if other key is pressed
                     BRSET PT1AD1,%00001000,CheckLeftKeyPress
                     BRSET PT1AD1,%00010000,CheckLeftKeyPress
                     BRSET PT1AD1,%00000100,CheckLeftKeyPress
                     BRSET PT1AD1,%00000010,CheckLeftKeyPress
                     
                     bclr PT1AD1,%11100000
                     BRA LOOP


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
         INCLUDE "My Delays.inc"
          
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
