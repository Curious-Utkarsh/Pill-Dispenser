void refillMode()
{
  if(digitalRead(backPin) == LOW)
  {
    while(digitalRead(backPin) == LOW)
    {}
    
  }
  
}
