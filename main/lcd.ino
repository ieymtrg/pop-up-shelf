void LcdShow() {
  lcd.setCursor(0, 0);//00
  lcd.print("ToF = ");
  if (hand_pos < 10000 && hand_pos >= 1000) {
    lcd.print("0");
  }
  else if (hand_pos < 1000 && hand_pos >= 100) {
    lcd.print("00");
  }
  else if (hand_pos < 100 && hand_pos >= 10) {
    lcd.print("000");
  }
  else if (hand_pos < 10 && hand_pos >= 0) {
    lcd.print("0000");
  }
  else {
    lcd.print("00000");
  }
  lcd.print(sensor_val);

  lcd.setCursor(0, 1);//01
  lcd.print("sign : ");
  lcd.print(SendSignal());
}
