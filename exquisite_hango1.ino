
#include <Servo.h>

#define temperature A0;
#define ledIndicator 9;

Servo mainServo;
int position = 0;
int previousPosition;

void setup() {
 
  pinMode(temperature, INPUT);
  pinMode(ledIndicator, OUTPUT);
  mainServo.attach(6);
 
  Serial.begin(9600);

}

void loop() {
 
 
  int tempReading = analogRead(temperature);
 
  float voltage = tempReading * 3.0;
 
 
  voltage /= 1024.0;
 
  float tempC = (voltage - 0.3) * 100;
 
 
  int position = map(tempC, 0, 30, 0, 90);
  Serial.println(position);
  if(previousPosition != position){
     mainServo.write(position);
  digitalWrite(ledIndicator, HIGH);
     delay(1000);
  }
     
  digitalWrite(ledIndicator, LOW);
  previousPosition = position;
}

