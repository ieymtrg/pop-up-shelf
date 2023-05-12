int SendSignal() {
  char sign;
  if (Serial.available() > 0) {
    sign = Serial.read();
    if (sign == 'e') {
      while (1) {};
      return 1;
    }
    else if (sign == 'h') {
      L6470_gohome();
      exit(0);
      return 2;
    }
    else if (sign == 'r') {
      L6470_resetpos();
      L6470_resetdevice();
      return 3;
    }
    else if (sign == 's') {
      L6470_hardhiz();
      return 4;
    }
    else {
      return 0;
    }
  }
}

/*
   e : stop program (into infinity loop)
   h : go to home position
   r : reset motor axis and device
   s : emergence stop motor
*/
