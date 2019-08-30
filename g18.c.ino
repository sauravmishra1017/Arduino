#include<SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
int state;
char send()
{
  return('s');
  }
void setup() {
  Serial.begin(9600);
 mySerial.begin(9600);
 delay(100);
 pinMode(2,INPUT);
 int state;
  // put your setup code here, to run once:

}

void loop() {
  state=digitalRead(2);
  if(state==HIGH)
  {
  if(Serial.available()>0)
   switch(send())
   {
    case 's':
    mySerial.println("AT+CMGF=1");
    delay(1000);
    mySerial.println("AT+CMGS=\"+918618473120\"\r");
    delay(1000);
    mySerial.println("High water leakage is detected");
    delay(100);
    mySerial.println((char)26);
    delay(1000);
   break;
   }
   
   if(mySerial.available()>0)
    Serial.write(mySerial.read());
    
   
  }
  // put your main code here, to run repeatedly:

}
