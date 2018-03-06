 #include <hidef.h>
 #include "derivative.h"
 #include "A2D_Lib_C.h"
 #include "Delay_C.h"
 
 void ATD0_Init(void){
  //   DDR1AD0= 0b00000000;   //enable all chanel as inputs 
   //  ATD0DIEN=0b00000000; //ensure they are Analog
     
     ATD0CTL2=0b11100000; 
   //  asm LDX #134;               //need a 50us delay 
   //  asm DBNE X, *;    
     
     ATD0CTL3=0b00001010;  //1 conversion per sequence    
     ATD0CTL4=0b00100110;   //4 A/D conversion clock per sample, 10 bit resolution
     Delay_C(100);  //delay 100 ms         
 }
 
 unsigned int  ATD0_Sample7(void) {
  
        unsigned int uiResult=0;
    ATD0CTL5=0b10000111;
     while((ATD0STAT0&0x80)==0 );
     
     uiResult=ATD0DR0;
     return uiResult;
      
 
 }