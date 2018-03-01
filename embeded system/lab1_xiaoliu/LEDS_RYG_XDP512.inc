;Library: LEDS_RYG_XDP512.inc
;Contains:
   ;Red_On
   ;Red_Off
   ;Red_Toggle
   
   ;Yellow_ON
   ;Yellow_Off
   ;Yellow_Toggle
   
   ;Green_On
   ;Green_Off
   ;Green_Toggle
   
   ;led_sw_init    ;subroutine for initialzing the uppper half of PORTAD for the RYG leds and the switches
   
 
led_sw_inint:  bclr PT1AD1, #$E0     ;make all leds low
               bset DDR1AD1, #$E0     ;make PAD13:15 outputs,reset inputs 
               bset ATD1DIEN1,#$1F    ;enable digital inputs for switches ATD1:
               rts 
               
               
               
;Red On-Off-Toggle subroutines 

Red_On:  psha
         pshb 
         
         ldd PT1AD1 
         oraa #%10000000
         std PT1AD1 
         
         pulb
         pula
         rts 
         
Red_OFF: psha
         pshb 
         
         ldd PT1AD1 
         anda #%01111111
         std PT1AD1 
         
         pulb
         pula
         rts 
        
Red_Togglel: psha 
             pshb
             ldd PT1AD1 
             eora #%10000000
             std PT1AD1
             
             pulb
             pula 
             rts 
             

Yellow_On:    psha
              pshb 
          
              ldd PT1AD1 
              oraa #%01000000
              std PT1AD1 
         
              pulb
              pula
              rts 
Yellow_Off:   psha
              pshb 
          
              ldd PT1AD1 
              anda #%10111111
              std PT1AD1 
         
              pulb
              pula
              rts 
              
Yellow_Toggle:psha
              pshb 
          
              ldd PT1AD1 
              eora #%01000000
              std PT1AD1 
         
              pulb
              pula
              rts 

Green_On:    psha
             pshb 
         
             ldd PT1AD1 
             oraa #%00100000
             std PT1AD1 
         
             pulb
             pula
             rts      
             
Green_Off:    psha
              pshb 
              
              ldd PT1AD1 
              anda #%11011111
              std PT1AD1 
              
              pulb
              pula
              rts 
              
Green_Toggle: psha 
              pshb
              ldd PT1AD1 
              eora #%00100000
              std PT1AD1
             
              pulb
              pula 
              rts 
          
              
              
              
              