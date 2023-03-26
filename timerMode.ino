void timerMode()
{
  tft.drawRoundRect(0, 0, 319, 240, 8, TFT_WHITE); //Page Border
  
  tft.setTextSize(2);


  if(cnt == 1)
  {
    cnt = 3;
    tft.fillRoundRect(10, 15, 300, 22, 8, TFT_GREEN);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("--TIMER MODE--", tft.width()/2, 20, 1);
  }


  String strTime = currentTime;
  String strDate = currentDate;
  getTime_Date();
  if(strTime != currentTime)
  tft.fillRect(245, 55, 65,15, TFT_BLACK);//time
  if(strDate != currentDate)
  tft.fillRect(70, 55, 80,15, TFT_BLACK);//date

  //Set Date_Time
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(8, 55);
  tft.print("Date:");
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(70, 55);
  tft.print(currentDate);
  tft.setCursor(185, 55);
  tft.setTextColor(TFT_YELLOW);
  tft.print("Time:");
  tft.setCursor(248, 55);
  tft.setTextColor(TFT_WHITE);
  tft.print(currentTime);

  //Set Alarm
  if(fil == 0)
  {
    tft.fillRoundRect(90, 90, 130, 30, 8, TFT_RED);
    tft.drawRoundRect(90, 90, 130, 30, 8, TFT_WHITE);
    fil = 1;
  }
  tft.setCursor(80, 100);
  tft.setTextSize(2);
  tft.setTextColor(TFT_BLACK);
  tft.print("  SET ALARM");

  tft.drawRoundRect(5, 130, 308, 100, 8, TFT_BLUE);
  tft.drawLine(159, 130, 159, 229, TFT_BLUE);
  tft.setCursor(70, 145);
  tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
  tft.print("HH");
  tft.setCursor(220, 145);
  tft.print("MM");
  tft.setTextSize(4);
  tft.setTextColor(TFT_GREEN);
  tft.setCursor(60, 185);
  if(hh<=9)
  tft.print("0"+String(hh));
  else
  tft.print(String(hh));
  tft.setCursor(210, 185);
  if(mm<=9)
  tft.print("0"+String(mm));
  else
  tft.print(String(mm));

  if(Mode == 0)//in HH
  {
    tft.setCursor(70, 145);
    tft.setTextSize(2);
    tft.setTextColor(TFT_RED);
    tft.print("HH");
    if(digitalRead(selPin) == LOW)
    {
      while(digitalRead(selPin) == LOW)
      {}
      dispenseTime = dispenseTime + String(hh);
      Mode = 1;
    }
    if(digitalRead(nextPin) == LOW && hh<23)
    {
      while(digitalRead(nextPin) == LOW)
      {}
      tft.fillRect(50, 185, 80, 40, TFT_BLACK);
      hh++;
    }
    if(digitalRead(prevPin) == LOW && hh>0)
    {
      while(digitalRead(prevPin) == LOW)
      {}
      tft.fillRect(50, 185, 80, 40, TFT_BLACK);
      hh--;
    }
  }

  if(Mode == 1)//in MM
  {
    tft.setCursor(220, 145);
    tft.setTextSize(2);
    tft.setTextColor(TFT_RED);
    tft.print("MM");
    if(digitalRead(selPin) == LOW)
    {
      while(digitalRead(selPin) == LOW)
      {}
      dispenseTime = dispenseTime +":"+ String(mm);
      Mode = 2;
    }
    if(digitalRead(nextPin) == LOW && mm<59)
    {
      while(digitalRead(nextPin) == LOW)
      {}
      tft.fillRect(210, 185, 80, 40, TFT_BLACK);
      mm++;
    }
    if(digitalRead(prevPin) == LOW && mm>0)
    {
      while(digitalRead(prevPin) == LOW)
      {}
      tft.fillRect(210, 185, 80, 40, TFT_BLACK);
      mm--;
    }
  }
  if(Mode == 2)//checks alarm time
  {
    if(dispenseTime == currentTime)
    {
      digitalWrite(2, HIGH);
      Serial.println("ON");
      delay(3000);
      Mode = 3;
      digitalWrite(2, LOW);
      Serial.println("OFF");
    }
  }
  if(Mode == 3 && digitalRead(selPin) == LOW)
  {
    while(digitalRead(selPin) == LOW)
    {}
    Mode = 0;
    dispenseTime = "";
  }
}
