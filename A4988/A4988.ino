const int DIR  = 4;
const int STEP = 3;

void setup()
{
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  digitalWrite(DIR, HIGH);

  for (int i = 0; i < 200; i++) {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP, LOW);
    delayMicroseconds(500);
  }

  delay(1000);

  digitalWrite(DIR, LOW);

  for (int i = 0; i < 400; i++) {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(500);
    digitalWrite(STEP, LOW);
    delayMicroseconds(500);
  }

  delay(1000);
}
