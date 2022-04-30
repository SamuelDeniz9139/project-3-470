#include <CapacitiveSensor.h>
int ledPin = 3;
CapacitiveSensor cs = CapacitiveSensor(10,8);
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  long start = millis();
  long total = cs.capacitiveSensor(30);
  Serial.print(millis() - start);
  Serial.print("\t");
  if(total < 1000){
      Serial.println("Aaah, that feels good.");
  } else if (total < 10000){
      Serial.println("Oh? Do you need something from me?");
  } else {
      Serial.println("Too hard, man!");
  }
  delay(10); // arbitrary delay to limit data to serial port
  int scaled = map(total, 0, 90000, 0, 255);
  analogWrite(ledPin, scaled);
}
