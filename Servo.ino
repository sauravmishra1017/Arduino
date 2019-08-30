#include<Servo.h>
Servo st;
int angle=0;
void setup() {
  st.attach(11);
}

void loop() {
  while(true)
  {
    for(angle=0;angle<180;angle+=1)
    {
      st.write(angle);
    }
    delay(10);
    for(angle=180;angle>0;angle-=1)
    {
      st.write(angle);
    }
    delay(10);  
  }
}
