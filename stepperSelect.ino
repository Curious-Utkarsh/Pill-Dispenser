void stepperSelect()
{
  if(spritePosn == 1)
  {
    Serial.println("HeadAche");  //HA
    stepDispense(1);
    servoDrive();
    homePosn();
  }
  if(spritePosn == 2)
  {
    Serial.println("FirstAid");  //FA
    stepDispense(2);
    servoDrive();
    homePosn();
  }
  if(spritePosn == 3)
  {
    Serial.println("Fever"); //FV
    stepDispense(3);
    servoDrive();
    homePosn();
  }
  if(spritePosn == 4)
  {
    Serial.println("ColdCough"); //CC
    stepDispense(4);
    servoDrive();
    homePosn();
  }
  if(spritePosn == 5)
  {
    Serial.println("BodyPain");  //BP
    stepDispense(5);
    servoDrive();
    homePosn();
  }
  if(spritePosn == 6)
  {
    Serial.println("StomachAche"); //SA
    stepDispense(0);
    servoDrive();
    homePosn();
  }
}
