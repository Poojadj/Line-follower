#define SLeft 4
#define SRight 2
#define SMiddle 3
#define I1 6
#define I2 9
#define I3 10
#define I4 11
void left()
{
  analogWrite(I1,0);
  analogWrite(I2,120);
  analogWrite(I3,120);
  analogWrite(I4,0);
}
void right()
{
   analogWrite(I1,120);
  analogWrite(I4,120);
  analogWrite(I3,0);
  analogWrite(I2,0);
}
void forward()
{
   analogWrite(I1,120);
  analogWrite(I4,0);
  analogWrite(I3,120);
  analogWrite(I2,0);
}
void brake()
{
   analogWrite(I1,0);
  analogWrite(I4,0);
  analogWrite(I3,0);
  analogWrite(I2,0);
}
void setup()
{
  pinMode(SLeft,INPUT);
  pinMode(SRight,INPUT);
  pinMode(SMiddle,INPUT);
  pinMode(I1,OUTPUT);
  pinMode(I2,OUTPUT);
  pinMode(I3,OUTPUT);
  pinMode(I4,OUTPUT);

  analogWrite(I1,0);
  analogWrite(I4,0);
  analogWrite(I3,0);
  analogWrite(I2,0);
}
void loop(){
  int xr,xm,xl;
  xl=digitalRead(SLeft);
  xm=digitalRead(SMiddle);
  xr=digitalRead(SRight);

  
  if(xl==1 )
    {
      while(xl==1)
      {
        left(); 
        xl=digitalRead(SLeft);
      }
  }
  if(xr==1 )
  {
    while(xr==1)
    {
      right();
      xr=digitalRead(SRight);
    }
  }


  if(xl==0 && xr ==0 && xm == 1)
  {
   forward();
  }


}
