#include <Servo.h>

const int servoPin1 = 5;
int angle = 0;

Servo myservo1;

void setup()
{
  myservo1.attach(servoPin1);
  myservo1.write(160);
  Serial.begin(9600);
}

void loop()
{
  char val;
  
  if (Serial.available() > 0) {
    val = Serial.read();
    if (val == 'a') {
      angle = 160;
      Serial.println("160");
    } else if (val == 's') {
      angle = 0;
      Serial.println("0");
    } else if (val == 'd') {
      angle = 60;
      Serial.println("60");
    }
  }
  
  myservo1.write(angle);
}
