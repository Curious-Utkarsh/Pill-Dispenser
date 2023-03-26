void homePosn() // limit switch posn
{
  while(stepper.currentPosition() != 0)
  {
    stepper.setSpeed(-stepSpeed);
    stepper.runSpeed();
  }
 
  delay(200);
}
