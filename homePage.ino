void homePage()
{
  tft.drawRoundRect(0, 0, 319, 240, 8, TFT_WHITE); //Page Border

  tft.fillRoundRect(60, 180, 200, 40, 8, TFT_RED);
  tft.drawRoundRect(60, 180, 200, 40, 8, TFT_WHITE);

  tft.fillRoundRect(60, 130, 200, 40, 8, TFT_RED);
  tft.drawRoundRect(60, 130, 200, 40, 8, TFT_WHITE);

  tft.fillRoundRect(60, 80, 200, 40, 8, TFT_RED);
  tft.drawRoundRect(60, 80, 200, 40, 8, TFT_WHITE);

  tft.setCursor(60, 20);
  tft.setTextSize(2);

  tft.setTextColor(TFT_WHITE);
  tft.print(" --SELECT MODE--");
  tft.setCursor(4, 50);
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLUE);
  tft.print("   -- SPENCER-PRO 370 --   ");

  tft.setTextColor(TFT_BLACK);
  tft.setCursor(63, 195);
  tft.print("   REFILL-MODE");

  tft.setCursor(78, 145);
  tft.print("SELECTION-MODE");

  tft.setCursor(80, 95);
  tft.print("  TIMER-MODE");
}
