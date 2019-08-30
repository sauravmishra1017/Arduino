#include <Servo.h>
Servo myservo;
int x,y,z;

int pos=0;
int enable1=3;
int mot1=8;
int mot2=7;
int enable2=6;
int mot3=5;
int mot4=4; 
int sp1=150;
int sp2=150;
void setup() 
{
  pinMode(enable1,OUTPUT);
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(enable2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(19200);
  myservo.attach(9);
  myservo.write(0);
}

void loop()
{
// dont touch *************	
  if (Serial.available() > 0) 
    {
     	if (Serial.read() == 'X') 
        {
         	x = Serial.parseInt();
               if (Serial.read() == 'Y') 
            {
               	y = Serial.parseInt();
                if (Serial.read() == 'Z') 
                {
                	z = Serial.parseInt();
                }
            }
         }
    
  //  ********************
    
 
 
     
if (x>0 && x<200)
{
  //move right
  digitalWrite(mot1,HIGH);  
  digitalWrite(mot2,LOW);
  analogWrite(enable1,sp1);
  digitalWrite(mot3,LOW);
  digitalWrite(mot4,LOW);
  analogWrite(enable2,sp2);
}



if (x>300 && x<500)
{
  //move left
    digitalWrite(mot1,LOW);  
  digitalWrite(mot2,LOW);
  analogWrite(enable1,sp1);
  digitalWrite(mot3,HIGH);
  digitalWrite(mot4,LOW);
  analogWrite(enable2,sp2);
}




if ((x>200) && (x<300))
{

  // move staright 
  
  digitalWrite(mot1,HIGH);  
  digitalWrite(mot2,LOW);
  analogWrite(enable1,sp1);
  digitalWrite(mot3,HIGH);
  digitalWrite(mot4,LOW);
  analogWrite(enable2,sp2);
}
  //required zone
  if(z>95 && z <190)
  {
  digitalWrite(mot1,LOW);  
  digitalWrite(mot2,LOW);
  analogWrite(enable1,sp1);
  digitalWrite(mot3,LOW);
  digitalWrite(mot4,LOW);  
  analogWrite(enable2,sp2);
  delay(2000);
  myservo.attach(9);
 while(1){
  for(int pos = 0; pos < 45; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(9);                       // waits 15ms for the servo to reach the position 
  }
  
 break;
 }
  }

        
	while (Serial.available() > 0)
     {
      	Serial.read();
      }        
     
     } 

}
