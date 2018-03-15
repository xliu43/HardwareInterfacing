  #include "derivative.h"
  /*
       Key_hit subroutine 
  return value:routine returns SCi0SR1&0x20
             this is checking RDRF 
             =0x20  if a character is wating      (0010 0000)
             =0x00 if no character is in 
             
             calling program needs to look at hte return 
             value and run Rx_Byte if return value is non-zero
 */
 
 unsigned char SCI0_Key_hit(void) {
     unsigned char ucKey_In=0;
     ucKey_In=SCI0SR1&0x20;
     return ucKey_In;
 }
 
 /*
    Rx_Byte Subroutine
    Description: This routine polls the RDRF (Receive Data Register Full Flag) of SCI0SR1until 
    character is received 
 */
 unsigned char SCI0_RxByte(void){
    unsigned char ucKey=0;
    while((SCI0SR1&0x20)==0);
    return SCI0DRL;
 }
 
 /*
    SCI_19200 subroutine 
    initialzie the sci baud rate for 19200
 */
 void SCI0_Init19200(void) {
      SCI0BDH=0;
      SCI0BDL=26;
      SCI0CR1=0x00;
      SCI0CR2=0x0C; 
 }
 
 /*
    Tx_byte subroutine
    charcter to be sent is passed into the fucntion 
    as an unsigned char.The transmit register is checked until 
    it is empty prior to writing the character into it 
 */
 void SCI0_TxByte(unsigned char cVal){
     while((SCI0SR1&0x80)==0) {
     }//wait until transmit register is empty prior to wiring the char to the trasmit register 
     SCI0DRL=cVal;
 }
 
 /*
    Tx_String subroutine 
    the routine calls the Tx_Byte to transmit each element
    of hte string. It also checks for end of string char 00(null)
 */
 
 void SCI0_TxString(char* cString) //pointer to chars 
 {
        while(*cString!=0){
            SCI0_TxByte(*cString++); //walk the pointer
        }
 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
  