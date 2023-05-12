#include <SPI.h>
#include <Servo.h>
#include <Wire.h>
#include <VL53L1X.h>
#include <MsTimer2.h>
#include "rgb_lcd.h"

#define PIN_SPI_MOSI 11
#define PIN_SPI_MISO 12
#define PIN_SPI_SCK 13
#define PIN_SPI_SS 10
#define PIN_BUSY 9
#define PIN_SERVO 8

float hand_pos;
float hand_pos_con;
float head_pos;
float th = 17;
const float width = 1100;
unsigned int sensor_val;
unsigned int loop_cnt = 0;

VL53L1X sensor;
rgb_lcd lcd;
Servo myservo;

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_SPI_MOSI, OUTPUT);
  pinMode(PIN_SPI_MISO, INPUT);
  pinMode(PIN_SPI_SCK, OUTPUT);
  pinMode(PIN_SPI_SS, OUTPUT);
  pinMode(PIN_BUSY, INPUT);
  pinMode(PIN_SERVO, OUTPUT);

  SPI.begin();
  SPI.setDataMode(SPI_MODE3);
  SPI.setBitOrder(MSBFIRST);
  digitalWrite(PIN_SPI_SS, HIGH);

  Wire.begin();
  Wire.setClock(400000);

  MsTimer2::set(50, flash);
  MsTimer2::start();

  sensor.setTimeout(10000);
  if (!sensor.init()) {
    Serial.println("Failed");
    while (1);
  }
  sensor.setDistanceMode(VL53L1X::Long);
  sensor.setMeasurementTimingBudget(50000);
  sensor.startContinuous(50);

  lcd.begin(16, 2);
  lcd.clear();

  myservo.attach(PIN_SERVO);
  myservo.write(0);

  L6470_resetdevice();
  L6470_setup();
}

void loop()
{
  //get loop count
  GetLoopCount();

  //get sensor value
  GetSensorValue();

  //get hand position
  GetHandPosition();

  //send Serial sign
  SendSignal();

  //control motors and judge in or out
  ControlMotors();

  //show the parm on display
  LcdShow();

  //judge get timeout
  TimeOut();

  Serial.println();
}


void GetLoopCount() {
  Serial.print(loop_cnt);
  Serial.print(":");

  loop_cnt++;
}


void GetSensorValue() {
  sensor_val = sensor.read();

  Serial.print("sensor_val = ");
  Serial.print(sensor_val);
  Serial.print(":");
}


void GetHandPosition() {
  if (InOut() == true) {
    hand_pos = sensor.read();
  }
  else {
    hand_pos = head_pos;
  }

  Serial.print("hand_pos = ");
  Serial.print(hand_pos);
  Serial.print(":");
}


boolean InOut() {
  if (sensor_val < width) {
    return true;
  }
  else {
    return false;
  }
}


boolean TimeOut() {
  if (sensor.timeoutOccurred()) {
    Serial.println("TIMEOUT");
    return true;
  }
  else {
    return false;
  }
}
