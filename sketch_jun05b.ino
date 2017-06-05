#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 7, 5, 4, 3, 2);
#include <Ultrasonic.h>
#define TRIGGER_PIN 11
#define ECHO_PIN 10

const byte intPin=8; //interrupt pin
volatile boolean state=LOW; //initial value of 

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() {
Serial.begin(9600);
 lcd.begin(20,2);
 pinMode(intPin, INPUT_PULLUP); 
 attachInterrupt(0, int0, LOW);
 
}
void loop(){
  

}
void int0() { 
  lcd.home();
  state=!state; 
float cmMsec, inMsec;
long microsec = ultrasonic.timing();
cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM); // 計算距離，單位: 公分
inMsec = ultrasonic.convert(microsec, Ultrasonic::IN); // 計算距離，單位: 英吋
Serial.print("MS: "); Serial.print(microsec);
Serial.print(", CM: "); Serial.print(cmMsec);
Serial.print(", IN: "); Serial.println(inMsec);
lcd.print("CM:");
lcd.print(cmMsec);
delay(1000);

}

