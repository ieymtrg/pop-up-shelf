#include <SPI.h>
#include <MsTimer2.h>

#define PIN_SPI_MOSI 11
#define PIN_SPI_MISO 12
#define PIN_SPI_SCK 13
#define PIN_SPI_SS 10
#define PIN_BUSY 9

void setup()
{
  pinMode(PIN_SPI_MOSI, OUTPUT);
  pinMode(PIN_SPI_MISO, INPUT);
  pinMode(PIN_SPI_SCK, OUTPUT);
  pinMode(PIN_SPI_SS, OUTPUT);
  pinMode(PIN_BUSY, INPUT);

  SPI.begin();
  SPI.setDataMode(SPI_MODE3);
  SPI.setBitOrder(MSBFIRST);
  Serial.begin(9600);
  digitalWrite(PIN_SPI_SS, HIGH);

  L6470_resetdevice();
  L6470_setup();

  MsTimer2::set(50, flash);
  MsTimer2::start();
}

void loop()
{
  L6470_move(0, 1600);
  delay(3000);

  L6470_move(1, 1600);
  delay(3000);

  for (int i = 0; i < 4; i++) {
    L6470_goto((i + 1) * 400);
    delay(3000);
  }
}
