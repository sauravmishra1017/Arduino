#define rma 8 //right motor a
#define rmb 9 //right motor b
#define lma 10 //left motor a
#define lmb 11 //left motor b
char data=0;
int bijli=255;
void setup() 
{
Serial.begin(9600); //Default communication rate of the bluetooth module
pinMode(rma,OUTPUT);
pinMode(rmb,OUTPUT);
pinMode(lma,OUTPUT);
pinMode(lmb,OUTPUT);
}

void forward()
{
analogWrite(rma,bijli);
analogWrite(rmb,LOW);
analogWrite(lma,bijli);
analogWrite(lmb,LOW);
}
void stop()
{

analogWrite(rma,LOW);
analogWrite(rmb,LOW);
analogWrite(lma,LOW);
analogWrite(lmb,LOW);
}
void right()
{

analogWrite(rma,LOW);
analogWrite(rmb,bijli);
analogWrite(lma,bijli);
analogWrite(lmb,LOW);
}
void sright()
{

analogWrite(rma,bijli);
analogWrite(rmb,bijli);
analogWrite(lma,bijli);
analogWrite(lmb,LOW);
}
void left()
{

analogWrite(rma,bijli);
analogWrite(rmb,LOW);
analogWrite(lma,LOW);
analogWrite(lmb,bijli);
}
void sleft()
{

analogWrite(rma,bijli);
analogWrite(rmb,LOW);
analogWrite(lma,bijli);
analogWrite(lmb,bijli);
}
void rev()
{

analogWrite(rma,LOW);
analogWrite(rmb,bijli);
analogWrite(lma,LOW);
analogWrite(lmb,bijli);
}
void rightrev()
{

analogWrite(rma,bijli);
analogWrite(rmb,LOW);
analogWrite(lma,LOW);
analogWrite(lmb,bijli);
}
void leftrev()
{

analogWrite(rma,LOW);
analogWrite(rmb,bijli);
analogWrite(lma,bijli);
analogWrite(lmb,LOW);
}
void loop() 
{
if(Serial.available()>0) //Checks whether data is coming from the serial port
{
data=Serial.read(); //Reads the data from the serial port
if(data=='F')
{
forward();
}
if(data=='B')
{
rev();
}
if(data=='S')
{
stop();
}
if(data=='L')
{
left();
}
if(data=='R')
{
right();
}
if(data=='k')
{
sleft();
}
if(data=='l')
{
sright();
}
if(data=='h')
{
rightrev();
}
if(data=='i')
{
leftrev();
}
}
}
