void stepperSelect()
{
  if(sp == 1)
  {
    if(spritePosn == 1)
    {
      Serial.println("HeadAche");  //HA
      dispenseScreen1();
      stepDispense(1);
      servoDrive();
      dispenseScreen2();
      buzz();
      homePosn();
      dispenseScreen3();
    }
    if(spritePosn == 2)
    {
      Serial.println("FirstAid");  //FA
      dispenseScreen1();
      stepDispense(2);
      servoDrive();
      dispenseScreen2();
      buzz();
      homePosn();
      dispenseScreen3();
    }
    if(spritePosn == 3)
    {
      Serial.println("Fever"); //FV
      dispenseScreen1();
      stepDispense(3);
      servoDrive();
      dispenseScreen2();
      buzz();
      homePosn();
      dispenseScreen3();
    }
    if(spritePosn == 4)
    {
      Serial.println("ColdCough"); //CC
      dispenseScreen1();
      stepDispense(4);
      servoDrive();
      dispenseScreen2();
      buzz();
      homePosn();
      dispenseScreen3();
    }
    if(spritePosn == 5)
    {
      Serial.println("BodyPain");  //BP
      dispenseScreen1();
      stepDispense(5);
      servoDrive();
      dispenseScreen2();
      buzz();
      homePosn();
      dispenseScreen3();
    }
    if(spritePosn == 6)
    {
      Serial.println("StomachAche"); //SA
      dispenseScreen1();
      stepDispense(0);
      servoDrive();
      dispenseScreen2();
      buzz();
      homePosn();
      dispenseScreen3();
    }
  }
  else
  {
    sp = 1;
  }
}
