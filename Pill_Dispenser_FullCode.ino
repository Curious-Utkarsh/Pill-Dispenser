#include <SPI.h>
#include <TFT_eSPI.h>
#include <NTPClient.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <SD.h>
#include <JPEGDecoder.h>
#include <ESP32Servo.h>
#include <AccelStepper.h>
#include <WiFiManager.h>

//Buttons
#define nextPin   16 //RX2 //INPUT_PULLUP
#define selPin    27 //D27 //INPUT_PULLUP
#define prevPin   32 //D32 //INPUT_PULLUP
#define backPin   25 //D25 //INPUT_PULLUP
#define wifiPin    3 //RX0 //INPUT_PULLUP

//Led cum buzz 
#define led       33 //D33 //ON when LOW

//Servo Pin
#define servoPin  26

//Stepper Pins
#define dirPin    14
#define stepPin   13
#define stepSpeed 20

//Limit Switch
#define limitSwitch    12 //D12 //ON when LOW 

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800);

Servo myServo;

AccelStepper stepper = AccelStepper(1, stepPin, dirPin);

TFT_eSPI tft = TFT_eSPI();

String currentTime = "";
String dispenseTime = "";
String currentDate = "";
byte Mode = 0;//to check if HH or MM

int currentPage = 0;
byte cursorPosn = 0; // for homePage
byte spritePosn = 1; // for selectionPage
byte sp = 0;
byte nVal = 0;
byte sVal = 0;
byte pVal = 0;
byte bVal = 0;
byte cnt = 0;
byte hh = 0;
byte mm = 0;
byte cc = 0;
byte lt = 0;
byte Lt = 1;
byte refill = 0;
byte bValue = 1;
byte fillCnt = 1;
  
void setup() 
{
  Serial.begin(115200);
  delay(1000);
  SPI.begin();
  delay(10);
  pinMode(wifiPin, INPUT_PULLUP);
  pinMode(backPin, INPUT_PULLUP);
  pinMode(prevPin, INPUT_PULLUP);
  pinMode(selPin,  INPUT_PULLUP);
  pinMode(nextPin, INPUT_PULLUP);
  pinMode(limitSwitch, INPUT_PULLUP);
  pinMode(led, OUTPUT);

  stepper.setMaxSpeed(1000);
  stepper.setSpeed(-stepSpeed);
  myServo.attach(servoPin);
  myServo.write(70);//home
  delay(1000);
  
  WiFi.mode(WIFI_STA);
  WiFiManager wm;
  if(digitalRead(wifiPin) == LOW)
  {
    wm.resetSettings();
    for(byte i = 0; i<20; i++)
    {
      digitalWrite(led, HIGH);
      delay(50);
      digitalWrite(led, LOW);
      delay(50);
    }
  }

  bool res;
  res = wm.autoConnect("AutoConnectAP");
  if(!res) 
  {
    //Serial.println("Failed to connect");
    digitalWrite(led, HIGH); //means not connected to wifi
  } 
  else 
  {
      //if you get here you have connected to the WiFi    
      //Serial.println("connected...yeey :)");
      digitalWrite(led, LOW); //means connected to wifi
  }
  timeClient.begin();

  tft.init();

  if (!SD.begin()) 
  {
    //Serial.println("Card Mount Failed");
    return;
  }
  uint8_t cardType = SD.cardType();

  if (cardType == CARD_NONE) 
  {
    //Serial.println("No SD card attached");
    return;
  }
  
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  tft.drawRoundRect(0, 0, 319, 240, 8, TFT_WHITE); //Page Border
  tft.setTextSize(3);
  tft.setTextColor(TFT_WHITE);
  tft.setCursor(50, 16);//(x,y)
  tft.print("SETTING UP...");
  tft.setTextColor(TFT_YELLOW);
  tft.setCursor(50, 70);
  tft.print("  AUTOMATED");
  tft.setCursor(40, 110);
  tft.print("PILL DISPENSER");
  tft.drawRect(80,165, 154, 18, TFT_WHITE);
  tft.setCursor(50, 200);
  tft.setTextColor(TFT_GREEN);
  tft.print(" LOADING...");
  for(byte i = 1; i<=148; i++)
  {
    tft.fillRect(83, 168, i, 13, TFT_RED);
    delay(20);
  }
  tft.fillRect(50, 200, 200, 25, TFT_BLACK);
  tft.setCursor(100, 200);
  tft.setTextColor(TFT_GREEN);
  tft.print(" DONE");
}

void loop() 
{ 
  while(digitalRead(limitSwitch) == HIGH && lt == 0) // Put this section in void loop with flag.
  {
    //Serial.println(digitalRead(limitSwitch));
    stepper.runSpeed();
  }
  lt = 1;
  if(lt == 1 && Lt == 1)
  {
    stepper.setSpeed(0);
    stepper.setCurrentPosition(0);
    lt = 2;
    Lt = 2;
  }
  
  //Home Page
  if(currentPage == 0)
  {
    if(cnt == 0)
    {
      tft.fillScreen(TFT_BLACK);
      cnt = 1;
    }
    homePage();//currentPage = 0
    currentPage = -2;
  }
  if(currentPage == -2)
  {
    buttonState();
    Cursor();
  }

  //Timer Mode
  if(currentPage == 1)
  {
    if(cnt == 0)
    {
      tft.fillScreen(TFT_BLACK);
      cnt = 1;
    }
    timerMode();
    if(digitalRead(backPin) == LOW && currentPage != -2)
    {
      while(digitalRead(backPin) == LOW)
      {}
      currentPage = 0;
      cnt = 0;
    }
  }

  //Selection Mode
  if(currentPage == 2)
  {
    if(cnt == 0)
    {
      tft.fillScreen(TFT_BLACK);
      cnt = 1;
    }
    selectionMode();
  }

  //Refill Mode
  if(currentPage == 3)
  {
    if(cnt == 0)
    {
      tft.fillScreen(TFT_BLACK);
      cnt = 1;
    }
    refillMode();
    if(digitalRead(backPin) == LOW && currentPage != -2)
    {
      while(digitalRead(backPin) == LOW)
      {}
      currentPage = 0;
      cnt = 0;
    }
  }
}
