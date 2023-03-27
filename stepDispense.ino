//for dispense mode
void stepDispense(int stepPosn)
{
  if(stepPosn == 0) //SA
  {
    while(stepper.currentPosition() != 0)
    {
      stepper.setSpeed(stepSpeed);
      stepper.runSpeed();
    }
    delay(200);
  }
  if(stepPosn == 1) //HA
  {
    while(stepper.currentPosition() != 30)
    {
      stepper.setSpeed(stepSpeed);
      stepper.runSpeed();
    }
    delay(200);
  }
  if(stepPosn == 2)  //FA
  {
    while(stepper.currentPosition() != 65)
    {
      stepper.setSpeed(stepSpeed);
      stepper.runSpeed();
    }
    delay(200);
  }
  if(stepPosn == 3)  //FV
  {
    while(stepper.currentPosition() != 97)
    {
      stepper.setSpeed(stepSpeed);
      stepper.runSpeed();
    }
    delay(200);
  }
  if(stepPosn == 4)  //CC
  {
    while(stepper.currentPosition() != 132)
    {
      stepper.setSpeed(stepSpeed);
      stepper.runSpeed();
    }
    delay(200);
  }
  if(stepPosn == 5)  //BP
  {
    while(stepper.currentPosition() != 165)
    {
      stepper.setSpeed(stepSpeed);
      stepper.runSpeed();
    }
    delay(200);
  }
}
