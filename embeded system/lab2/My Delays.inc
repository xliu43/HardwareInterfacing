; library: My delays.inc 

;delay subroutine 
 ; details: this perfroms a delay of the number of ms specified by the X register 
 
 
 Delay: ldy #2665           ;insidie the loop counter 
 delay_2: dbne y, delay_2
          dbne x, Delay
          
          rts 