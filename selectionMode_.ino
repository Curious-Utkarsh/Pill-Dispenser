void selectionMode()
{
  tft.drawRoundRect(1, 1, 318, 238, 8, TFT_BLACK); //Page Border
  
  tft.setCursor(60, 10);
  tft.setTextSize(2);

  if(cnt == 1)
  {
    cnt = 3;
    tft.fillRoundRect(10, 5, 300, 22, 8, TFT_RED);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("--SELECTION MODE--", tft.width()/2, 10, 1);
  }

  drawSdJpeg("/HeadAcheSM.jpg", 13, 30);    //HA 

  drawSdJpeg("/FirstAidSM.jpg", 117, 30);   //FA 

  drawSdJpeg("/FeverSM.jpg", 223, 30);     //FV

  drawSdJpeg("/ColdCoughSM.jpg", 13, 124);     //CC

  drawSdJpeg("/BodyPainSM.jpg", 115, 124);     //BP

  drawSdJpeg("/StomachAcheSM.jpg", 223, 124);    //SA

  buttonState();
  drawSprite(spritePosn);
}
