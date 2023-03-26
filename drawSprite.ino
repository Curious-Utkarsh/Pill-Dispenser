void drawSprite(int c)
{
  if(abs(c - cc) != 0)
  {
    tft.fillRoundRect(10, 215, 300, 22, 8, TFT_GREEN);
  }
  cc = c;

  if(c == 1)//Headache
  {
    byte x = 13;
    byte y = 30;
    tft.fillTriangle(x, y, x+20, y, x, y+20, TFT_BLUE);
    tft.fillTriangle(x+84, y+84, x+65, y+84, x+84, y+65, TFT_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("HEADACHE", tft.width()/2, 220, 1);
  }
  if(c == 2)//FirstAid
  {
    byte x = 117;
    byte y = 30;
    tft.fillTriangle(x, y, x+20, y, x, y+20, TFT_BLUE);
    tft.fillTriangle(x+84, y+84, x+65, y+84, x+84, y+65, TFT_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("FIRST-AID", tft.width()/2, 220, 1);
  }
  if(c == 3)//Fever
  {
    byte x = 223;
    byte y = 30;
    tft.fillTriangle(x, y, x+20, y, x, y+20, TFT_BLUE);
    tft.fillTriangle(x+84, y+84, x+65, y+84, x+84, y+65, TFT_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("FEVER", tft.width()/2, 220, 1);
  }
  if(c == 4)//Cold
  {
    byte x = 13;
    byte y = 124;
    tft.fillTriangle(x, y, x+20, y, x, y+20, TFT_BLUE);
    tft.fillTriangle(x+84, y+84, x+65, y+84, x+84, y+65, TFT_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("COLD/COUGH", tft.width()/2, 220, 1);
  }
  if(c == 5)//BodyPain
  {
    byte x = 115;
    byte y = 124;
    tft.fillTriangle(x, y, x+20, y, x, y+20, TFT_BLUE);
    tft.fillTriangle(x+84, y+84, x+65, y+84, x+84, y+65, TFT_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("BODY-PAIN", tft.width()/2, 220, 1);
  }
  if(c == 6)//StomachAche
  {
    byte x = 223;
    byte y = 124;
    tft.fillTriangle(x, y, x+20, y, x, y+20, TFT_BLUE);
    tft.fillTriangle(x+84, y+84, x+65, y+84, x+84, y+65, TFT_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("STOMACH-ACHE", tft.width()/2, 220, 1);
  }
}
