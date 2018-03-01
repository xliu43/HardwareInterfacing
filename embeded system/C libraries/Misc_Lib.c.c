 unsigned int HexToBCD (unsigned int iHexIn) {
        int iPow=1;
        int cCount;
      unsigned int iBCDOut=0;   
       if(iHexIn>0x270f)
          return 0;              //why if not initiate to 0 will have error???! 
      for(cCount=0;cCount<4;cCount++){
           iBCDOut+=(iHexIn%10)*iPow;
           iHexIn/=10;
           iPow*=16;
      }
    
        return iBCDOut; 
 
 }