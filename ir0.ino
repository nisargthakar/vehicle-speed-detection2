#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int ir_a=8;
int ir_b=9;
int buzzer=10;
  
void setup() 
{
  lcd.begin(16,2);
  pinMode(ir_a,INPUT);
  pinMode(ir_b,INPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop() 
{
  int ir1,ir2,t=0,dist=25,speed1,c=0;
  L1:
  ir1=digitalRead(ir_a);
  ir2=digitalRead(ir_b);

  //Serial.println(a);
  //Serial.println(b);


if(ir1==0 && ir2==1)
{
  while(digitalRead(ir_b)!=0)
  {
    delay(100);
    c++;
    Serial.println(c);
  }
  t=c/10;
  Serial.println(t);
  speed1=dist/t;

  if(speed1>5)
  {
    digitalWrite(buzzer,HIGH);
    lcd.setCursor(0,0);
    lcd.print("over speed");
    lcd.setCursor(0,1);
    lcd.print("speed= ");
    lcd.print(speed1);
    lcd.print("cm/s");
  }
  else
  {
    lcd.setCursor(0,0);
    lcd.print("normal speed");
    lcd.setCursor(0,1);
    lcd.print("speed= ");
    lcd.print(speed1);
    lcd.print("cm/s");
  }
}


else if(ir1==1)
{
 //lcd.print("no vehicle");
  //lcd.setCursor(0,1);
  //lcd.print("detected");
  c==0;
  goto L1;
}
delay(100); 



}


