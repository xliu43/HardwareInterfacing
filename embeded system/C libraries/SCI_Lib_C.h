 /*
       Key_hit subroutine 
  return value:routine returns SCi0SR1&0x20
             this is checking RDRF 
             =0x20  if a character is wating      (0010 0000)
             =0x00 if no character is in 
             
             calling program needs to look at hte return 
             value and run Rx_Byte if return value is non-zero
 */
unsigned char SCI0_Key_hit(void) ;
 
 
 /*
    Rx_Byte Subroutine
    Description: This routine polls the RDRF (Receive Data Register Full Flag) of SCI0SR1until 
    character is received 
 */
unsigned char SCI0_RxByte(void);


 /*
    SCI_19200 subroutine 
    initialzie the sci baud rate for 19200
 */

 void SCI0_Init19200(void);
 
  /*
    Tx_byte subroutine
    charcter to be sent is passed into the fucntion 
    as an unsigned char.The transmit register is checked until 
    it is empty prior to writing the character into it 
 */
 void SCI0_TxByte(unsigned char cVal);
 
  /*
    Tx_String subroutine 
    the routine calls the Tx_Byte to transmit each element
    of hte string. It also checks for end of string char 00(null)
 */
 
 void SCI0_TxString(char* cString) ;
 
 
 
 
 
 
 