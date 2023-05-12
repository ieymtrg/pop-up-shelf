void L6470_setup() {
  L6470_setparam_acc(0x40);
  L6470_setparam_dec(0x40);
  L6470_setparam_maxspeed(0x40);
  L6470_setparam_minspeed(0x01);
  L6470_setparam_fsspd(0x3ff);
  L6470_setparam_kvalhold(0x50);
  L6470_setparam_kvalrun(0x50);
  L6470_setparam_kvalacc(0x50);
  L6470_setparam_kvaldec(0x50);
  L6470_setparam_stepmood(0x03);
}


void flash() {
  Serial.print("abs = ");
  Serial.print( L6470_getparam_abspos());
  Serial.print(":");
  Serial.print("spd = ");
  Serial.print( L6470_getparam_speed());
  Serial.println();
}


void L6470_setparam_abspos(long val) {
  L6470_transfer(0x01, 3, val);
}


void L6470_setparam_elpos(long val) {
  L6470_transfer(0x02, 2, val);
}


void L6470_setparam_mark(long val)
{
  L6470_transfer(0x03, 3, val);
}


void L6470_setparam_acc(long val) {
  L6470_transfer(0x05, 2, val);
}


void L6470_setparam_dec(long val) {
  L6470_transfer(0x06, 2, val);
}


void L6470_setparam_maxspeed(long val) {
  L6470_transfer(0x07, 2, val);
}


void L6470_setparam_minspeed(long val) {
  L6470_transfer(0x08, 2, val);
}


void L6470_setparam_fsspd(long val) {
  L6470_transfer(0x15, 2, val);
}


void L6470_setparam_kvalhold(long val) {
  L6470_transfer(0x09, 1, val);
}


void L6470_setparam_kvalrun(long val) {
  L6470_transfer(0x0a, 1, val);
}


void L6470_setparam_kvalacc(long val) {
  L6470_transfer(0x0b, 1, val);
}


void L6470_setparam_kvaldec(long val) {
  L6470_transfer(0x0c, 1, val);
}


void L6470_setparam_intspd(long val) {
  L6470_transfer(0x0d, 2, val);
}


void L6470_setparam_stslp(long val) {
  L6470_transfer(0x0e, 1, val);
}


void L6470_setparam_fnslpacc(long val) {
  L6470_transfer(0x0f, 1, val);
}


void L6470_setparam_fnslpdec(long val) {
  L6470_transfer(0x10, 1, val);
}


void L6470_setparam_ktherm(long val) {
  L6470_transfer(0x11, 1, val);
}


void L6470_setparam_ocdth(long val) {
  L6470_transfer(0x13, 1, val);
}


void L6470_setparam_stallth(long val) {
  L6470_transfer(0x14, 1, val);
}


void L6470_setparam_stepmood(long val)
{
  L6470_transfer(0x16, 1, val);
}


void L6470_setparam_alareen(long val) {
  L6470_transfer(0x17, 1, val);
}


void L6470_setparam_config(long val) {
  L6470_transfer(0x18, 2, val);
}

long L6470_getparam_abspos() {
  return L6470_getparam(0x01, 3);
}


long L6470_getparam_elpos() {
  return L6470_getparam(0x02, 2);
}


long L6470_getparam_mark() {
  return L6470_getparam(0x03, 3);
}


long L6470_getparam_speed() {
  return L6470_getparam(0x04, 3);
}


long L6470_getparam_acc() {
  return L6470_getparam(0x05, 2);
}


long L6470_getparam_dec() {
  return L6470_getparam(0x06, 2);
}


long L6470_getparam_maxspeed() {
  return L6470_getparam(0x07, 2);
}


long L6470_getparam_minspeed() {
  return L6470_getparam(0x08, 2);
}


long L6470_getparam_fsspd() {
  return L6470_getparam(0x15, 2);
}


long L6470_getparam_kvalhold() {
  return L6470_getparam(0x09, 1);
}


long L6470_getparam_kvalrun() {
  return L6470_getparam(0x0a, 1);
}


long L6470_getparam_kvalacc() {
  return L6470_getparam(0x0b, 1);
}


long L6470_getparam_kvaldec() {
  return L6470_getparam(0x0c, 1);
}


long L6470_getparam_intspd() {
  return L6470_getparam(0x0d, 2);
}


long L6470_getparam_stslp() {
  return L6470_getparam(0x0e, 1);
}


long L6470_getparam_fnslpacc() {
  return L6470_getparam(0x0f, 1);
}


long L6470_getparam_fnslpdec() {
  return L6470_getparam(0x10, 1);
}


long L6470_getparam_ktherm() {
  return L6470_getparam(0x11, 1);
}


long L6470_getparam_adcout() {
  return L6470_getparam(0x12, 1);
}


long L6470_getparam_ocdth() {
  return L6470_getparam(0x13, 1);
}


long L6470_getparam_stallth() {
  return L6470_getparam(0x14, 1);
}


long L6470_getparam_stepmood() {
  return L6470_getparam(0x16, 1);
}


long L6470_getparam_alareen() {
  return L6470_getparam(0x17, 1);
}


long L6470_getparam_config() {
  return L6470_getparam(0x18, 2);
}


long L6470_getparam_status() {
  return L6470_getparam(0x19, 2);
}


void L6470_run(int dia, long spd) {
  if (dia == 1)
    L6470_transfer(0x51, 3, spd);
  else
    L6470_transfer(0x50, 3, spd);
}


void L6470_stepclock(int dia) {
  if (dia == 1)
    L6470_transfer(0x59, 0, 0);
  else
    L6470_transfer(0x58, 0, 0);
}


void L6470_move(int dia, long n_step) {
  if (dia == 1)
    L6470_transfer(0x41, 3, n_step);
  else
    L6470_transfer(0x40, 3, n_step);
}
void L6470_goto(long pos) {
  L6470_transfer(0x60, 3, pos);
}


void L6470_gotodia(int dia, int pos) {
  if (dia == 1)
    L6470_transfer(0x69, 3, pos);
  else
    L6470_transfer(0x68, 3, pos);
}


void L6470_gountil(int act, int dia, long spd) {
  if (act == 1)
    if (dia == 1)
      L6470_transfer(0x8b, 3, spd);
    else
      L6470_transfer(0x8a, 3, spd);
  else if (dia == 1)
    L6470_transfer(0x83, 3, spd);
  else
    L6470_transfer(0x82, 3, spd);
}


void L6470_relesesw(int act, int dia) {
  if (act == 1)
    if (dia == 1)
      L6470_transfer(0x9b, 0, 0);
    else
      L6470_transfer(0x9a, 0, 0);
  else if (dia == 1)
    L6470_transfer(0x93, 0, 0);
  else
    L6470_transfer(0x92, 0, 0);
}


void L6470_gohome() {
  L6470_transfer(0x70, 0, 0);
}


void L6470_gomark() {
  L6470_transfer(0x78, 0, 0);
}


void L6470_resetpos() {
  L6470_transfer(0xd8, 0, 0);
}


void L6470_resetdevice() {
  L6470_send_u(0x00);
  L6470_send_u(0x00);
  L6470_send_u(0x00);
  L6470_send_u(0x00);
  L6470_send_u(0xc0);
}


void L6470_softstop() {
  L6470_transfer(0xb0, 0, 0);
}


void L6470_hardstop() {
  L6470_transfer(0xb8, 0, 0);
}


void L6470_softhiz() {
  L6470_transfer(0xa0, 0, 0);
}


void L6470_hardhiz() {
  L6470_transfer(0xa8, 0, 0);
}


long L6470_getstatus() {
  long val = 0;
  L6470_send_u(0xd0);
  for (int i = 0; i <= 1; i++) {
    val = val << 8;
    digitalWrite(PIN_SPI_SS, LOW);
    val = val | SPI.transfer(0x00);
    digitalWrite(PIN_SPI_SS, HIGH);
  }
  return val;
}


void L6470_transfer(int add, int bytes, long val) {
  int data[3];
  L6470_send(add);
  for (int i = 0; i <= bytes - 1; i++) {
    data[i] = val & 0xff;
    val = val >> 8;
  }
  if (bytes == 3) {
    L6470_send(data[2]);
  }
  if (bytes >= 2) {
    L6470_send(data[1]);
  }
  if (bytes >= 1) {
    L6470_send(data[0]);
  }
}


void L6470_send(unsigned char add_or_val) {
  while (!digitalRead(PIN_BUSY)) {
  }
  digitalWrite(PIN_SPI_SS, LOW);
  SPI.transfer(add_or_val);
  digitalWrite(PIN_SPI_SS, HIGH);
}


void L6470_send_u(unsigned char add_or_val) {
  digitalWrite(PIN_SPI_SS, LOW);
  SPI.transfer(add_or_val);
  digitalWrite(PIN_SPI_SS, HIGH);
}


void L6470_busydelay(long time) {
  while (!digitalRead(PIN_BUSY)) {
  }
  delay(time);
}


long L6470_getparam(int add, int bytes) {
  long val = 0;
  int send_add = add | 0x20;
  L6470_send_u(send_add);
  for (int i = 0; i <= bytes - 1; i++) {
    val = val << 8;
    digitalWrite(PIN_SPI_SS, LOW);
    val = val | SPI.transfer(0x00);
    digitalWrite(PIN_SPI_SS, HIGH);
  }
  return val;
}

/*
  L6470 comands
  ---------------------------
  dia    1 : order / 0 : reverse
  spd    (20bit)(0.015*spd[step/s])
  pos    (22bit)
  n_step (22bit)
  act    1 : mark / 0 : reset
  mssec
  val
  ---------------------------
  L6470_run(dia,spd);
  L6470_stepclock(dia);
  L6470_move(dia,n_step);
  L6470_goto(pos);
  L6470_gotodia(dia,pos);
  L6470_gountil(act,dia,spd);
  L6470_relesesw(act,dia);
  L6470_gohome();
  L6470_gomark();
  L6470_resetpos();
  L6470_resetdevice();
  L6470_softstop();
  L6470_hardstop();
  L6470_softhiz();
  L6470_hardhiz();
  L6470_getstatus();
*/
