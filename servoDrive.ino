void servoDrive()
{
  myServo.write(0);
  delay(1000);
  myServo.write(110);
  delay(1000);
  myServo.write(70);//home
  delay(1000);
}
