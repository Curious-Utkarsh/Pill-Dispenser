void homePosn() // limit switch posn
{
  while(stepper.currentPosition() != 0)
  {
    stepper.setSpeed(-stepSpeed);
    stepper.runSpeed();
  }
  delay(200);
}

void homeLimit() // limit switch posn
{
  while(digitalRead(limitSwitch) == HIGH) 
  {
    stepper.setSpeed(-stepSpeed);
    stepper.runSpeed();
  }
  stepper.setSpeed(0);
  stepper.setCurrentPosition(0);
}
