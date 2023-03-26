//for dispense mode
void stepDispense(int stepPosn)
{
  while(stepper.currentPosition() != (31*stepPosn))
  {
    stepper.setSpeed(stepSpeed);
    stepper.runSpeed();
  }
 
  delay(200);
}
