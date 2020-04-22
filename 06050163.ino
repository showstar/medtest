#include<SevSeg.h>
SevSeg sevseg;
const byte bb=6;
int i;
void setup()
{
  byte numDigits = 1;
  byte digitPins[] = {5};
  byte segmentPins[] = {8,9,10,11,12,13,14};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);

  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(bb,INPUT);
  
}

void loop()
{
  
      
  bool val=digitalRead(bb);
    if(val)
    {
      digitalWrite(7,HIGH);
      delay(500);
      digitalWrite(7,LOW);
      delay(500);
    }
    else
    {
      static unsigned long timer=millis();
      if(millis()>=timer)
      {
        timer+=500;
        sevseg.setNumber(i);
        i=i+1;
        if(i==10)
        {
          i=0;  
        }
      }
    
    }
    sevseg.refreshDisplay();
}
