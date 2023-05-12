void ControlMotors() {
  while (InOut() == true) {
    GetSensorValue();
    GetHandPosition();
    hand_pos_con = hand_pos * th * -1;
    head_pos = hand_pos;
    L6470_goto(hand_pos_con);
    PushServo();
    delay(100);
  }

  while (InOut() == false) {
    GetSensorValue();
    GetHandPosition();
    L6470_hardstop();
    PullServo();
    delay(100);
  }
}
