//C library for delay 

void Delay_C(int mSec) 
{
   asm ldx mSec
   asm Delay:  ldy#2665  //inside the loop counter 
   asm delay_2: dbne y,delay_2
   asm dbne x,Delay
   
}


void Short_Delay(void) {

    asm ldy#10
    asm dbne y,*

}


void Long_Delay(void){

  asm ldy#0
  asm dbne y,*
}
