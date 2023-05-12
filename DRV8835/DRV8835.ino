int APHASE  = 4;
int AENBL   = 5;
int BPHASE  = 6;
int BENBL   = 7;
int VR_PIN  = A0;
int SW_PIN  = 2;

unsigned long VR_VALUE = 0;
int sw_value = 0;

void setup()
{
  Serial.begin(9600);

  pinMode(APHASE, OUTPUT);
  pinMode(AENBL, OUTPUT);
  pinMode(BPHASE, OUTPUT);
  pinMode(BENBL, OUTPUT);
  digitalWrite(AENBL, HIGH);
  digitalWrite(BENBL, HIGH);

  pinMode(SW_PIN, INPUT);
  digitalWrite(SW_PIN, HIGH);

  delay(100);
}

void READ_VR(void) {
  VR_VALUE = analogRead(VR_PIN);
}

void READ_SW(void) {
  sw_value = digitalRead(SW_PIN);
}

void DELAY_WAIT(void) {
  for (int i = 0; i < (VR_VALUE / 10 + 7) ; i++) delayMicroseconds(100);
}

void MOTOR_FORWARD() {
  digitalWrite(APHASE, HIGH);
  DELAY_WAIT();
  digitalWrite(BPHASE, HIGH);
  DELAY_WAIT();
  digitalWrite(APHASE, LOW);
  DELAY_WAIT();
  digitalWrite(BPHASE, LOW);
  DELAY_WAIT();
}

void MOTOR_REVERSE() {
  digitalWrite(APHASE, HIGH);
  DELAY_WAIT();
  digitalWrite(BPHASE, LOW);
  DELAY_WAIT();
  digitalWrite(APHASE, LOW);
  DELAY_WAIT();
  digitalWrite(BPHASE, HIGH);
  DELAY_WAIT();
}

void MOTOR_STOP() {
  DELAY_WAIT();
}

void loop()
{
  char val;
  READ_VR();
  READ_SW();
  MOTOR_FORWARD();
}
