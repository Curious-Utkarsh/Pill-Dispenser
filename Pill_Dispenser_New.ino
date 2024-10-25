#include <U8g2lib.h>
#include <SPI.h>
#include <AccelStepper.h>
#include <Servo.h>

#define dirPin 2
#define stepPin 5
#define motorInterfaceType 1

#define limitSwitch 7
#define button1 3
#define button2 4
#define button3 9
#define button4 12
#define servoPin 6
#define stepSpeed 20.0

int lt = 0;
int curPosn = 0;
int targetPosn = 0;

Servo myServo;

AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

U8G2_ST7920_128X64_F_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /* CS=*/ 10, /* reset=*/ 8);

void setup()
{
  Serial.begin(115200);

  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(60);
  stepper.setSpeed(stepSpeed);
  
  u8g2.begin(/*Select=*/ button2, /*Right/Next=*/ button3, /*Left/Prev=*/ button1, /*Up=*/ button1, /*Down=*/ button3, /*Home/Cancel=*/ button4);
  u8g2.setFont(u8g2_font_6x12_tr);
  
  myServo.attach(servoPin);
  myServo.write(70); // home
  delay(1000);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode(button4, INPUT_PULLUP);
  pinMode(limitSwitch, INPUT_PULLUP);
}

const char *string_list = 
  "Fever\n"
  "Pain Killer\n"
  "Stomach Ache\n"
  "Head Ache\n"
  "Band Aid\n"
  "Allergy";

uint8_t current_selection = 0;

void loop() 
{ 
  while(digitalRead(limitSwitch) == HIGH && lt == 0)
  {
    //Serial.println(digitalRead(limitSwitch));
    stepper.runSpeed();
  }
  lt = 1;
  if(lt == 1)
  {
    stepper.setSpeed(0);
    stepper.setCurrentPosition(0);
    lt = 2;
  }

  // Selection Mode
  if(lt == 2)
  {
    current_selection = u8g2.userInterfaceSelectionList(
      "Symptoms",
      current_selection, 
      string_list);

    if (current_selection == 0) {
      u8g2.userInterfaceMessage(
        "Nothing selected.", 
        "",
        "",
        " ok ");
    } else {
      uint8_t response = u8g2.userInterfaceMessage(
        "Selection:", 
        u8x8_GetStringLineStart(current_selection-1, string_list),
        "",
        " ok \n cancel ");

      // If "ok" is selected (response == 1), move stepper
      if (response == 1) {
        Serial.println(current_selection);
        stepDispense(current_selection);
        servoDrive();
        homePosn();
        response = 0;
      }
    }
  }
}

//for dispense mode
void stepDispense(uint8_t stepPosn)
{
  if(stepPosn == 1) //SA
  {
    targetPosn = 0;
  }
  if(stepPosn == 2) //HA
  {
    targetPosn = 30;
  }
  if(stepPosn == 3)  //FA
  {
    targetPosn = 65;
  }
  if(stepPosn == 4)  //FV
  {
    targetPosn = 97;
  }
  if(stepPosn == 5)  //CC
  {
    targetPosn = 132;
  }
  if(stepPosn == 6)  //BP
  {
    targetPosn = 165;
  }
  Serial.println(targetPosn);
  stepper.setSpeed(-stepSpeed);
  while (abs(stepper.currentPosition()) != targetPosn) 
  {
    Serial.println(abs(stepper.currentPosition()));
    stepper.runSpeed();
  }
}

void servoDrive()
{
  myServo.write(0);
  delay(1000);
  myServo.write(110);
  delay(1000);
  myServo.write(70);//home
  delay(1000);
}

void homePosn() // limit switch posn
{
  stepper.setSpeed(stepSpeed);
  while(abs(stepper.currentPosition()) != 0)
  {
    stepper.runSpeed();
  }
  delay(200);
}


