/********************************************************
 * File Name : Otto_App.ino
 * Author    : Bibek Poodar
 * Company    :Curiosta Innovation Labs 
 ********************************************************/



#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // CONNECT BT RX PIN TO ARDUINO 11 PIN | CONNECT BT TX PIN TO ARDUINO 10 PIN

#include "Otto.h"

Otto Otto;

  #define PIN_YL 2 //servo[2]
  #define PIN_YR 3 //servo[3]
  #define PIN_RL 4 //servo[4]
  #define PIN_RR 5 //servo[5]


  
//-- Movement parameters
int T=1000;              //Initial duration of movement
int moveId=0;            //Number of movement
int modeId=0;            //Number of mode
int moveSize=15;         //Asociated with the height of some movements

//---------------------------------------------------------

void setup() 
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH); 
  Serial.begin(9600);
  
  BTSerial.begin(38400);  // HC-05 default speed in AT command more

Otto.init(PIN_YL,PIN_YR,PIN_RL,PIN_RR,true);
        Otto.home();
}

void loop()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
if (BTSerial.available())
    
   {   
     
    int x =  BTSerial.read();
     Serial.println(x);

  switch (x){
    case 1: Serial.println("UP");
            Otto.walk(1,1000,1); 
            break;
            
       case 2: Serial.println("Down");
               Otto.walk(2,1300,-1); 
               break;
               
       case 3: Serial.println("Left");
               Otto.turn(1,1000,-1);  
               break;
               
       case 4: Serial.println("Right");
               Otto.turn(1,1000,-1);  
               break;
               
       case 5: Serial.println("Pause");
               Otto.home();
               break;
               
      case 6: Serial.println("Ascending turn");
              Otto.ascendingTurn(1,T,moveSize);
              break;
              
      case 7: Serial.println("bend");
              Otto.bend(1,T,1);
              break;
              
      case 8: Serial.println("Cursaito");
              Otto.crusaito(1,T,moveSize,1);     
              break;
              
      case 9: Serial.println("Flapping");
              Otto.flapping(1,T,moveSize,1);
              break;
              
      case 10: Serial.println("Jitter");
               Otto.jitter(1,T,moveSize);
               break;
               
      case 11: Serial.println("Jump");
               Otto.jump(1,T);
               break;
               
      case 12: Serial.println("Shake Leg");
               Otto.shakeLeg(1,T,1);
               break;
               
      case 13: Serial.println("Swing");
               Otto.swing(1,T,moveSize);
               break;
               
      case 14: Serial.println("Tip Toe Swing");
               Otto.tiptoeSwing(1,T,moveSize);
               break;
               
      case 15: Serial.println("Up Down");
               Otto.updown(1,T,moveSize);
               break;
               
      case 16: Serial.println("Moon Walker");
               Otto.moonwalker(1,T,moveSize,1);
               break;
      
     
      default: Serial.println("Invalid");
               break;
    
     }//end switch

  } //end if
    
}//end loop
  
