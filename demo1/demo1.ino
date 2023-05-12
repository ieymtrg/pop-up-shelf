#include <SPI.h>
#include <MsTimer2.h>
#include <Servo.h>
#include <Wire.h>

#define PIN_SPI_MOSI 11
#define PIN_SPI_MISO 12
#define PIN_SPI_SCK 13
#define PIN_SPI_SS 10
#define PIN_BUSY 9

const int servopin = 5;
Servo myservo;

void setup()
{
  Serial.begin(9600);

  pinMode(PIN_SPI_MOSI, OUTPUT);
  pinMode(PIN_SPI_MISO, INPUT);
  pinMode(PIN_SPI_SCK, OUTPUT);
  pinMode(PIN_SPI_SS, OUTPUT);
  pinMode(PIN_BUSY, INPUT);

  SPI.begin();
  SPI.setDataMode(SPI_MODE3);
  SPI.setBitOrder(MSBFIRST);
  digitalWrite(PIN_SPI_SS, HIGH);

  Wire.begin();
  Wire.setClock(400000);

  L6470_resetdevice();
  L6470_setup();

  myservo.attach(servopin);
  myservo.write(160);

  MsTimer2::set(50, flash);
  MsTimer2::start();
}

void loop()
{
  myservo.write(0);
  delay(3000);
  L6470_goto(-1600 * 10);
  delay(5000);
  L6470_gohome();
  delay(4000);
  myservo.write(160);
  delay(3000);
  myservo.write(0);
  delay(3000);
  L6470_goto(-1600 * 4);
  delay(3000);
  myservo.write(160);
  delay(3000);
  L6470_gohome();
}
