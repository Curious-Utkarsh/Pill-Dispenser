void buttonState()
{
  nVal = digitalRead(nextPin);
  sVal = digitalRead(selPin);
  pVal = digitalRead(prevPin);
  bVal = digitalRead(backPin);

//  Serial.println(nVal);
//  Serial.println(sVal);
//  Serial.println(pVal);
//  Serial.println("\n");

  if(pVal == LOW && (cursorPosn > 0 || spritePosn > 1))
  {
    while(digitalRead(prevPin) == LOW)
    {}
    cursorPosn--;
    spritePosn--;
  }
  if(nVal == LOW && (cursorPosn < 2 || spritePosn < 6))
  {
    while(digitalRead(nextPin) == LOW)
    {}
    cursorPosn++;
    spritePosn++;
  }
  if(sVal == LOW)
  {
    while(digitalRead(selPin) == LOW)
    {}
    if(currentPage == -2) //homePage
    {
      if(cursorPosn == 0)
      {
        currentPage = 1;//Timer Mode
        cnt = 0;
      }
      if(cursorPosn == 1)
      {
        currentPage = 2;//Selection Mode
        cnt = 0;
      }
      if(cursorPosn == 2)
      {
        currentPage = 3;//Refill Mode
        cnt = 0;
      }
  }
  if(currentPage == 2)// Selection Page
  {
    stepperSelect(); //Stepper Motor for Selection Mode
  }
  }
}
