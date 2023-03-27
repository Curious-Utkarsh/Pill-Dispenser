void refillMode()
{
  tft.drawRoundRect(1, 1, 318, 238, 8, TFT_BLUE); //Page Border
  
  tft.setCursor(60, 10);
  tft.setTextSize(2);

  if(cnt == 1)
  {
    cnt = 3;
    tft.fillRoundRect(10, 5, 300, 22, 8, TFT_YELLOW);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("--REFILL MODE--", tft.width()/2, 10, 1);
    tft.setTextColor(TFT_GREEN);
    tft.drawCentreString("--LOAD PILLS--", tft.width()/2, 50, 1);
    tft.drawCentreString("-- AS INSTRUCTED BELOW --", tft.width()/2, 70, 1);

    stepRefill(0);

    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("*** NOTE ***", tft.width()/2, 180, 1);
    tft.drawCentreString("LOAD PILLS FOR TIMER MODE", tft.width()/2, 200, 1);
    tft.drawCentreString("-- NORMALLY --", tft.width()/2, 220, 1);
  }

  if(digitalRead(selPin) == LOW)
  {
    while(digitalRead(selPin) == LOW)
    {}
    stepRefill(fillCnt);
    if(fillCnt < 6)
    {
      fillCnt++;
    }
    else
    {
      fillCnt = 0;
    } 
  }
}
