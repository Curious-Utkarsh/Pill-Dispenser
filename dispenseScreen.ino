void dispenseScreen1()
{
  tft.fillScreen(TFT_BLACK);
  tft.drawRoundRect(1, 1, 318, 238, 8, TFT_RED); //Page Border
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
  tft.drawCentreString("-- DISPENSING PILL --", tft.width()/2, 80, 1);
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(50, 200);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(3);
  tft.drawCentreString("PLEASE WAIT...", tft.width()/2, 130, 1);
}

void dispenseScreen2()
{
  tft.fillRect(15, 125, 290, 60, TFT_BLACK);
  tft.setCursor(100, 200);
  tft.setTextColor(TFT_GREEN);
  tft.setTextSize(3);
  tft.drawCentreString("DONE", tft.width()/2, 130, 1);
  
}
void dispenseScreen3()
{
  tft.fillScreen(TFT_BLACK);
  tft.drawRoundRect(0, 0, 319, 240, 8, TFT_WHITE); //Page Border
  tft.fillRoundRect(10, 5, 300, 22, 8, TFT_RED);
  tft.setTextColor(TFT_WHITE);
  tft.drawRoundRect(0, 0, 319, 240, 8, TFT_BLACK); //Page Border
  tft.setTextSize(2);
  tft.drawCentreString("--SELECTION MODE--", tft.width()/2, 10, 1);
}
void dispenseScreen4()
{
  tft.fillRoundRect(90, 90, 130, 30, 8, TFT_RED);
  tft.drawRoundRect(90, 90, 130, 30, 8, TFT_WHITE);
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(80, 100);
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK);
  tft.print("  SET ALARM");
  cnt = 1;
}
