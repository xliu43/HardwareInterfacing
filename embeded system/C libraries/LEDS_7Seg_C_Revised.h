

//this is a set of instructions to cleat he memory of the 7 seg led digits-used prior to wrting anything to them 
void LEDS_7Seg_Init_C(void);
//clears all segments of char in position Pos (has to be 0-7)
void Clear_7Seg(unsigned char Pos); 

// sends charcter to position Pos (pos has 0-7)  Only lower nibble has data value 
void Char_7Seg_C(unsigned char Pos, unsigned char Character);

//places input data on pos 7 and 8 (4bits each)  uppper two digits of row are blanked; 
void Bot_8Out_C(unsigned char cIn);     //eg. Cin=oxA8


void Bot_16Out_C(int iIn);

void Top_8Out_C(unsigned char cIn);     //eg. Cin=oxA8

void Top_16Out_C(int iIn);

