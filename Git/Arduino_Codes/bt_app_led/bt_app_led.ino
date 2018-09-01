#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // CONNECT BT RX PIN TO ARDUINO 11 PIN | CONNECT BT TX PIN TO ARDUINO 10 PIN


void setup() 
{
  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
  digitalWrite(9, HIGH); 
  Serial.begin(9600);
  
  BTSerial.begin(38400);  // HC-05 default speed in AT command more
pinMode(12,OUTPUT);

}

void loop(){
   if (BTSerial.available())
    
   {   
     
    int x =  BTSerial.read();
     Serial.println(x);

     switch(x){
      case 48: Serial.println("ON");
      digitalWrite(12,HIGH);
            break;

       case 49: Serial.println("OFF");
       digitalWrite(12,LOW);
       break;
     }
   }
}

