#include "derivative.h"


             
             
void led_sw_init(void) 
{
   PT1AD1 &=0x1F;            //all the leds off at hte start no unpridicatbale behavior 
   DDR1AD1 |=0xE0;           //make all LEDs outputs, reset inputs
   ATD1DIEN |=0x1F;          //enable digital inputs for switches
}

void Red_On(void) 
{
   PT1AD1 |=0x80;

}

void Red_Off(void)
{
  PT1AD1 &=0x7F;

}

void Red_Toggle(void)
{
   PT1AD1 ^=0x80;
}


void Green_On(void){
   PT1AD1 |=0b00100000;

}
void Green_Off(void){
   PT1AD1 &=0b11011111;
}

void Green_Toggle(void){
  PT1AD1 ^=0b00100000; 
}


void Yellow_On(void){
   PT1AD1 |=0b01000000;
}

void Yellow_Off(void){
  PT1AD1 &=0b10111111;
}

void Yellow_Toggle(void){
  PT1AD1 ^=0b01000000; 
}