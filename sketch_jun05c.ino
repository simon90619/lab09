#include <Ultrasonic.h>
#include <LiquidCrystal.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 13
LiquidCrystal lcd(11, 10 , 5, 4, 3, 7);
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
const byte intPin=2; //interrupt pin
volatile boolean state=LOW; //initial value of switch pin
volatile boolean a=LOW;
void setup() 
{
Serial.begin(9600);
lcd.begin(20, 2);
pinMode(intPin, INPUT_PULLUP);
pinMode(6, INPUT_PULLUP);
attachInterrupt(0, int0, LOW);
}
void loop() 
{

a = digitalRead(6);
if(a==1)
 interrupts();
else
  noInterrupts();
}
void int0() 
{
 lcd.home();
float cmMsec, inMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
Serial.print("MS: "); Serial.print(microsec);
Serial.print(", CM: "); Serial.print(cmMsec);
Serial.print(", IN: "); Serial.println(inMsec);
lcd.print("CM:"); lcd.print(cmMsec);
delay(100);


 
 
 
  
}

