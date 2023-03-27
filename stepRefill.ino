void stepRefill(byte rf)
{
  if(rf == 0) //FA
  {
    tft.fillRoundRect(10, 100, 300, 60, 8, TFT_RED);
    tft.drawRoundRect(10, 100, 300, 60, 8, TFT_WHITE);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("LOAD : FIRST-AID", tft.width()/2, 125, 1);
    while(stepper.currentPosition() != 15)
    {
      stepper.setSpeed(20);
      stepper.runSpeed();
    }
    buzz1();
    delay(200);
  }
  
  if(rf == 1) //FV
  {
    tft.fillRoundRect(10, 100, 300, 60, 8, TFT_RED);
    tft.drawRoundRect(10, 100, 300, 60, 8, TFT_WHITE);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("LOAD : FEVER", tft.width()/2, 125, 1);
    while(stepper.currentPosition() != 49) 
    {
      stepper.setSpeed(20);
      stepper.runSpeed();
    }
    buzz1();
    delay(200);
  }

  if(rf == 2) //CC
  {
    tft.fillRoundRect(10, 100, 300, 60, 8, TFT_RED);
    tft.drawRoundRect(10, 100, 300, 60, 8, TFT_WHITE);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("LOAD : COLD/COUGH", tft.width()/2, 125, 1);
    while(stepper.currentPosition() != 82) 
    {
      stepper.setSpeed(20);
      stepper.runSpeed();
    }
    buzz1();
    delay(200);
  }

  if(rf == 3) //BP
  {
    tft.fillRoundRect(10, 100, 300, 60, 8, TFT_RED);
    tft.drawRoundRect(10, 100, 300, 60, 8, TFT_WHITE);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("LOAD : BODY-PAIN", tft.width()/2, 125, 1);
    while(stepper.currentPosition() != 115) 
    {
      stepper.setSpeed(20);
      stepper.runSpeed();
    }
    buzz1();
    delay(200);
  }

  if(rf == 4) //SA
  {
    tft.fillRoundRect(10, 100, 300, 60, 8, TFT_RED);
    tft.drawRoundRect(10, 100, 300, 60, 8, TFT_WHITE);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("LOAD : STOMACH-ACHE", tft.width()/2, 125, 1);
    while(stepper.currentPosition() != 148) 
    {
      stepper.setSpeed(20);
      stepper.runSpeed();
    }
    buzz1();
    delay(200);
  }

  if(rf == 5) //HA
  {
    tft.fillRoundRect(10, 100, 300, 60, 8, TFT_RED);
    tft.drawRoundRect(10, 100, 300, 60, 8, TFT_WHITE);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("LOAD : HEAD-ACHE", tft.width()/2, 125, 1);
    while(stepper.currentPosition() != 182) 
    {
      stepper.setSpeed(20);
      stepper.runSpeed();
    }
    buzz1();
    delay(200);
  }

  if(rf == 6) //bring back to home posn after full loading
  {
    tft.fillRoundRect(10, 100, 300, 60, 8, TFT_RED);
    tft.drawRoundRect(10, 100, 300, 60, 8, TFT_WHITE);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("-- SYSTEM FULLY LOADED --", tft.width()/2, 125, 1);
    homeLimit();
    currentPage = 0;
    cnt = 0;
  }
}
