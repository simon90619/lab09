#include <LiquidCrystal.h>
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);
#include <Ultrasonic.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 13
Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);
void setup() {
Serial.begin(9600);
 lcd.begin(20,2);
}
void loop(){
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
lcd.clear();
}
