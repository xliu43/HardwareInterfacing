#include "derivative.h"
#include "LEDS_7Seg_C.h"



//this is a set of instructions to cleat he memory of the 7 seg led digits-used prior to wrting anything to them 

void LEDS_7Seg_Init_C(void)

{
    signed char i=0;
    unsigned char Digit=0;
    
    DDRA=0x03; //0000 0011          A0:A1 output 
    DDRB=0xff; //1111 1111          all portB output
    
    PORTA= 0x03; //0000 0011        preset portA control line high
    
    for(i=8;i>=0;i--)
    {
       Digit=(0x70|i);
       PORTB =Digit;
       
       PORTA=0b00000010;           //mode high, strobe /write
       PORTA=0b00000011;           //resting state 
       
       PORTB=0b10000000;           //turn off all segments &dp 
       PORTA=0b00000000;           //mode low ,strobe /write
       PORTA=0b00000001;           //why not 11?
       
       Digit ++;
    
    }
   
}



//clears all segments of char in position Pos (has to be 0-7)
void Clear_7Seg(unsigned char Pos) 
{
   Pos |= 0x70; //0111 0000   
   
   PORTB= Pos;
   
   PORTA= 0x02;             //mode high, strobe /write
   PORTA= 0x03;               //resting state 
   
   PORTB=0x80;               //turn off all segments &dp 
   PORTA=0x00;                //mode low ,strobe /write
   PORTA=0x01;


}
  
// sends charcter to position Pos (pos has 0-7)  Only lower nibble has data value 
void Char_7Seg_C(unsigned char Pos, unsigned char Character)
{
     Pos|=0x50; //0101 0000     set up mode in higher 5bits 
     PORTB=Pos;
     
     PORTA= 0x02;             //mode high, strobe /write
     PORTA= 0x03;               //resting state 
   
    PORTB=(Character|=0x80);               // or with 10000000   sets no decimal point 
    PORTA=0x00;                //mode low ,strobe /write
    PORTA=0x01;

}
//places input data on pos 7 and 8 (4bits each)  uppper two digits of row are blanked; 
void Bot_8Out_C(unsigned char cIn)     //eg. Cin=oxA8
{

    unsigned char cVal;
    Clear_7Seg(0x04);
    Clear_7Seg(0x05);
    
    cVal=cIn>>4;       //get A
    Char_7Seg_C(6,cVal);  //print A at Pos6 
    
    cVal=cIn&0b00001111;  //get 8 
    Char_7Seg_C(7,cVal);  //print 8 at Pos7
    
    
    


}

void Bot_16Out_C(int iIn)
{
    
   
    int Temp;
    int firstTwoChar;
    unsigned char cVal;
    
    Temp=iIn&0b0000000011111111;
    Bot_8Out_C( ( unsigned char) Temp);   
    
    firstTwoChar= iIn& 0b1111111100000000;  //first two nibble
    
    firstTwoChar=firstTwoChar>>8;
    
  
    cVal=( unsigned char)firstTwoChar;     //eg. oxA8
    
    cVal=firstTwoChar>>4;       //get A
    Char_7Seg_C(4,cVal);  //print A at Pos4 
    
    cVal=( unsigned char)firstTwoChar&0b00001111;  //get 8 
    Char_7Seg_C(5,cVal);  //print 8 at Pos5  
    
}


void Top_8Out_C(unsigned char cIn)     //eg. Cin=oxA8
{

    unsigned char cVal;
    Clear_7Seg(0x00);
    Clear_7Seg(0x01);
    
    cVal=cIn>>4;       //get A
    Char_7Seg_C(2,cVal);  //print A at Pos2 
    
    cVal=cIn&0b00001111;  //get 8 
    Char_7Seg_C(3,cVal);  //print 8 at Pos3
    
    
    


}

void Top_16Out_C(int iIn)
{
    
   
    int Temp;
    int firstTwoChar;
    unsigned char cVal;
    
    Temp=iIn&0b0000000011111111;
    Top_8Out_C( ( unsigned char) Temp);   
    
    firstTwoChar= iIn& 0b1111111100000000;  //first two nibble
    
    firstTwoChar=firstTwoChar>>8;
    
  
    cVal=( unsigned char)firstTwoChar;     //eg. oxA8
    
    cVal=firstTwoChar>>4;       //get A
    Char_7Seg_C(0,cVal);  //print A at Pos0 
    
    cVal=( unsigned char)firstTwoChar&0b00001111;  //get 8 
    Char_7Seg_C(1,cVal);  //print 8 at Pos1 
    
}




