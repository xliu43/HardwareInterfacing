//header file for switches library 

void Sw_Init(void);


void Wait_For_Switches_Up(void); 

unsigned char Get_Switches(void); 

void Wait_For_UpSwitch_Up(void) ;

void Wait_For_DownSwitch_Up(void);

void Wait_For_Switch_Up(unsigned char sw);


/*
   sw=Get_Switches();
                switch(sw){
                
                                                        case 0b00010000: //upswitch
                                                        VoltageMax=0;
                                                      
                                                        break;
                                                        
                                                        case 0b00000100: //downswitch 
                                                        VoltageMin=5.115;
                                                     
                                                        break; 
                                                        
                                                        case 0b00001000 :  //left switch 
                                                         break;
                                                         
                                                        case 0b0000010 :  //right switch 
                                                         break;    
                                                         
                                                        case 0b00000001:
                                                              VoltageMax=0;
                                                              VoltageMin=5.115;
                                                        break;
                                                        
                                                        }
                    //         Wait_For_Switch_Up(sw);

*/