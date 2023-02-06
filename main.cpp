#include "Arduino.h"

// Declaring the pins
const int BottomLeft_L = 13;
const int Down_L = 12;
const int Decimal_L = 11;
const int BottomRight_L = 10;
const int Middle_L = 9;
const int UpRight_L = 8;
const int UpLeft_L = 7;
const int Up_L = 6;

// Declaring the input buttons
const int ResetButton = 3;
const int DecrementButton = 4;
const int IncrementButton = 5;

// Declaring the three different segments
const int FirstLed = 1;
const int SecondLed = 2;
const int ThirdLed = 0;

// Declaring Global Variables
int counter = 0;
int buttonState1;           // the current reading from the input pin
int lastbuttonState1 = LOW; // the previous reading from the input pin
int buttonState2;
int lastbuttonState2 = LOW;
unsigned long lastDebounceTime1 = 0; // the last time the output pin was toggled
unsigned long lastDebounceTime2 = 0;
unsigned long debounceDelay = 1; // the debounce time; increase if the output flickers

void setup()
{
  pinMode(BottomLeft_L, OUTPUT);
  pinMode(Down_L, OUTPUT);
  pinMode(Decimal_L, OUTPUT);
  pinMode(BottomRight_L, OUTPUT);
  pinMode(Middle_L, OUTPUT);
  pinMode(UpRight_L, OUTPUT);
  pinMode(UpLeft_L, OUTPUT);
  pinMode(Up_L, OUTPUT);
  //----------------------------------------------------------------------
  pinMode(FirstLed, OUTPUT);
  pinMode(SecondLed, OUTPUT);
  pinMode(ThirdLed, OUTPUT);

  digitalWrite(FirstLed, LOW);
  digitalWrite(SecondLed, LOW);
  digitalWrite(ThirdLed, LOW);
  //-----------------------------------------------------------------------
  pinMode(ResetButton, INPUT);
  pinMode(DecrementButton, INPUT);
  pinMode(IncrementButton, INPUT);

  digitalWrite(ResetButton, LOW);
  digitalWrite(DecrementButton, LOW);
  digitalWrite(IncrementButton, LOW);
}

//------------------------------Functions------------------------------
void nine()
{
  digitalWrite(BottomLeft_L, HIGH);
  digitalWrite(Down_L, HIGH);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, LOW);
  digitalWrite(UpRight_L, LOW);
  digitalWrite(UpLeft_L, LOW);
  digitalWrite(Up_L, LOW);
}

void eight()
{
  digitalWrite(BottomLeft_L, LOW);
  digitalWrite(Down_L, LOW);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, LOW);
  digitalWrite(UpRight_L, LOW);
  digitalWrite(UpLeft_L, LOW);
  digitalWrite(Up_L, LOW);
}

void seven()
{
  digitalWrite(BottomLeft_L, HIGH);
  digitalWrite(Down_L, HIGH);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, HIGH);
  digitalWrite(UpRight_L, LOW);
  digitalWrite(UpLeft_L, HIGH);
  digitalWrite(Up_L, LOW);
}

void six()
{
  digitalWrite(BottomLeft_L, LOW);
  digitalWrite(Down_L, LOW);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, LOW);
  digitalWrite(UpRight_L, HIGH);
  digitalWrite(UpLeft_L, LOW);
  digitalWrite(Up_L, LOW);
}

void five()
{
  digitalWrite(BottomLeft_L, HIGH);
  digitalWrite(Down_L, LOW);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, LOW);
  digitalWrite(UpRight_L, HIGH);
  digitalWrite(UpLeft_L, LOW);
  digitalWrite(Up_L, LOW);
}

void four()
{
  digitalWrite(BottomLeft_L, HIGH);
  digitalWrite(Down_L, HIGH);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, LOW);
  digitalWrite(UpRight_L, LOW);
  digitalWrite(UpLeft_L, LOW);
  digitalWrite(Up_L, HIGH);
}

void three()
{
  digitalWrite(BottomLeft_L, HIGH);
  digitalWrite(Down_L, LOW);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, LOW);
  digitalWrite(UpRight_L, LOW);
  digitalWrite(UpLeft_L, HIGH);
  digitalWrite(Up_L, LOW);
}

void two()
{
  digitalWrite(BottomLeft_L, LOW);
  digitalWrite(Down_L, LOW);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, HIGH);
  digitalWrite(Middle_L, LOW);
  digitalWrite(UpRight_L, LOW);
  digitalWrite(UpLeft_L, HIGH);
  digitalWrite(Up_L, LOW);
}

void one()
{
  digitalWrite(BottomLeft_L, HIGH);
  digitalWrite(Down_L, HIGH);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, HIGH);
  digitalWrite(UpRight_L, LOW);
  digitalWrite(UpLeft_L, HIGH);
  digitalWrite(Up_L, HIGH);
}

void zero()
{
  digitalWrite(BottomLeft_L, LOW);
  digitalWrite(Down_L, LOW);
  digitalWrite(Decimal_L, HIGH);
  digitalWrite(BottomRight_L, LOW);
  digitalWrite(Middle_L, HIGH);
  digitalWrite(UpRight_L, LOW);
  digitalWrite(UpLeft_L, LOW);
  digitalWrite(Up_L, LOW);
}

void displayer(int num)
{
  if (num == 0)
  {
    zero();
  }
  else if (num == 1)
  {
    one();
  }
  else if (num == 2)
  {
    two();
  }
  else if (num == 3)
  {
    three();
  }
  else if (num == 4)
  {
    four();
  }
  else if (num == 5)
  {
    five();
  }
  else if (num == 6)
  {
    six();
  }
  else if (num == 7)
  {
    seven();
  }
  else if (num == 8)
  {
    eight();
  }
  else if (num == 9)
  {
    nine();
  }
}

void ThreeDigitDisplayer(int FirstDigit, int SecondDigit, int ThirdDigit)
{
  digitalWrite(FirstLed, HIGH);
  displayer(FirstDigit);
  delay(8);
  digitalWrite(FirstLed, LOW);

  digitalWrite(SecondLed, HIGH);
  displayer(SecondDigit);
  delay(8);
  digitalWrite(SecondLed, LOW);

  digitalWrite(ThirdLed, HIGH);
  displayer(ThirdDigit);
  delay(8);
  digitalWrite(ThirdLed, LOW);
}

void TwoDigitDisplayer(int FirstDigit, int SecondDigit)
{
  digitalWrite(SecondLed, HIGH);
  displayer(FirstDigit);
  delay(10);
  digitalWrite(SecondLed, LOW);

  digitalWrite(ThirdLed, HIGH);
  displayer(SecondDigit);
  delay(10);
  digitalWrite(ThirdLed, LOW);
}

void Breaker(int counter)
{
  int FirstDigit, SecondDigit, ThirdDigit;
  if (counter < 10)
  {
    digitalWrite(ThirdLed, HIGH);
    displayer(counter);
  }
  else if (counter > 9 && counter < 100)
  {
    SecondDigit = counter % 10;
    FirstDigit = (counter / 10) % 10;
    TwoDigitDisplayer(FirstDigit, SecondDigit);
  }
  else if (counter < 1000 && counter > 99)
  {
    ThirdDigit = counter % 10;
    counter = counter / 10;
    SecondDigit = counter % 10;
    counter = counter / 10;
    FirstDigit = counter % 10;
    ThreeDigitDisplayer(FirstDigit, SecondDigit, ThirdDigit);
  }
}

//------------------------------------------------------------------------
void loop()
{
  Breaker(counter);

  if (digitalRead(ResetButton) == HIGH)
  {
    counter = 0;
  }

  int reading = digitalRead(DecrementButton);
  int reading2 = digitalRead(IncrementButton);

  if (reading != lastbuttonState1)
  {
    lastDebounceTime1 = millis();
  }

  if (reading2 != lastbuttonState2)
  {
    lastDebounceTime2 = millis();
  }

  if ((millis() - lastDebounceTime1) > debounceDelay)
  {

    if (reading != buttonState1)
    {
      buttonState1 = reading;
      if (buttonState1 == HIGH)
      {
        counter--;
        if (counter < 0)
        {
          counter = 999;
        }
      }
    }
  }

  if ((millis() - lastDebounceTime2) > debounceDelay)
  {
    if (reading2 != buttonState2)
    {
      buttonState2 = reading2;
      if (buttonState2 == HIGH)
      {
        counter++;
        if (counter > 999)
        {
          counter = 0;
        }
      }
    }
  }
  
  lastbuttonState1 = reading;
  lastbuttonState2 = reading2;
}
