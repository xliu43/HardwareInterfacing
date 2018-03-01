//library for switches 

#include "derivative.h"
#include "Delay_C.h"
 

//this funciton initiziliaze the port lines associated with the swithces by plcaing 1 in the approiate bit postions of atd1dien1 

void Sw_Init(void) {
  ATD1DIEN1 |=0x1F;
}

//this function returns an unsigned char that contains ones in the bit positions of the swiches that are down, after deboucing. If the swithces are not stable, the function just return zero 

unsigned char Get_Switches(void) {          //have to includ void in pareameter 

     unsigned char Switches=0;
     
     Switches=PT1AD1&0x1F;            //get clean sw state
     
     Delay_C(10);
     
     if((PT1AD1&0x1F)!=Switches)
         Switches=0;
     
     return Switches;

}


//this function hangs in a loop waiting for all hte switches to be in the up state 

void Wait_For_Switches_Up(void){

     unsigned char Switches=0;
     Switches=PT1AD1 & 0x1F;
     while (Switches) {
     
         Switches= PT1AD1 &0x1F;
     }
      return; 
}

void Wait_For_Switch_Up(unsigned char sw) 
{
     while(sw) 
     {
      sw=PT1AD1&sw;
     }
      
     return;

}

//this function hangs in a loop waiting for upswitch to be in the upstate 

void Wait_For_UpSwitch_Up(void)
{
     unsigned char Switches=0;
     Switches=PT1AD1 & 0x1F;
     while (Switches) {
     
         Switches= PT1AD1 &0b00010000;
     }
      return; 
}

//this function hangs in a loop waiting for Downswitch to be in the upstate 

 void Wait_For_DownSwitch_Up(void) 
 {
        unsigned char Switches=0;
     Switches=PT1AD1 & 0x1F;
     while (Switches) {
     
         Switches= PT1AD1 &0b00000100;
     }
      return; 
 
 
 }