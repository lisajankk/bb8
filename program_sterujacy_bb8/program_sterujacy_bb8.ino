#include<SoftwareSerial.h>
SoftwareSerial bt(2, 3);
char inputByte;
#define mot11 7
#define mot12 8
#define mot21 12
#define mot22 13
#define m1s 10
#define m2s 11

void setup() {
// put your setup code here, to run once:
bt.begin(38400);
Serial.begin(38400);
Serial.write(bt.read());
pinMode(mot11, OUTPUT);
pinMode(mot12, OUTPUT);
pinMode(mot21, OUTPUT);
pinMode(mot22, OUTPUT);
pinMode(m1s, OUTPUT);
pinMode(m2s, OUTPUT);
analogWrite(m1s, 0);
analogWrite(m2s, 0);
}

void loop() {
// put your main code here, to run repeatedly:
if (bt.available()) /* If data is available on serial port */
{
inputByte = bt.read();
Serial.println(inputByte);
if (inputByte == 'w')
{
analogWrite(m1s, 255);
analogWrite(m2s, 255);
digitalWrite(mot11, LOW);
digitalWrite(mot12, HIGH);
digitalWrite(mot21, LOW);
digitalWrite(mot22, HIGH);
}
.
.
.
else if (inputByte == 'q')
{
analogWrite(m1s, 0);
analogWrite(m2s, 0);
digitalWrite(mot11, LOW);
digitalWrite(mot12, LOW);
digitalWrite(mot21, LOW);
digitalWrite(mot22, LOW);
}
}
if (Serial.available())
{
bt.write(Serial.read());
}
}
