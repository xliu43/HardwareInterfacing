 void lcdRWUp(void);
void lcdRWDown(void);
void lcdEUp(void);

void lcdEDown(void);
void lcdRSUp(void);
void lcdRSDown(void);
 
void lcdSDelay(void);
void lcdLDelay(void);
void lcdInit(void);

void lcdData(char);
void lcdBusy(void);
void lcdInst(char);

void lcdAddr(char);
void lcdString(char*);
void lcdClear(void);

void Set_R_C(char,char);
void lcdLabels(char*,char*,char*,char*);  


/*
 hwo to use sprintf 
 declare str variable 
 char str [20];
 sprintf(str,"%3X", value variable)      3 chars wide uppercase hex  if x lowercase hex 
 %5.3f  5 chars wide 3 decimals floating point 
 %03X - pad with zeros in front 
 %010.4f  pad with zeors 10chars wide 4 decimals 

   if(sprintf(str,"%02u", iMinutes) >0) {
                   Set_R_C(1,5);
                   lcdString(str);
          }
          if(sprintf(str,":%02u", iSeconds) >0) {
                   Set_R_C(1,8);
                  lcdString(str);

          }


*/