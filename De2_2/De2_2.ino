#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int btnOff = 10;
const int btnOn = 9;
const int btnLeft = 8;
const int btnRight = 7;

int preSttOff = LOW;
int preSttOn = LOW;
int preSttLeft = LOW;
int preSttRight = LOW;

int cursorPos = 0;

String message = "HELLO";

void setup() {

  lcd.begin(16, 2);
  lcd.print(message);

  pinMode(btnOff, INPUT);
  pinMode(btnOn, INPUT);
  pinMode(btnLeft, INPUT);
  pinMode(btnRight, INPUT);
}

void loop() {

  int sttOff = digitalRead(btnOff);
  if (preSttOff == LOW && sttOff == HIGH) {
    lcd.noDisplay();
  }
  preSttOff = sttOff;

  int sttOn = digitalRead(btnOn);
  if (preSttOn == LOW && sttOn == HIGH) {
    lcd.display();
  }
  preSttOn = sttOn;

  int sttLeft = digitalRead(btnLeft);
  if (preSttLeft == LOW && sttLeft == HIGH) {

    cursorPos -= 2;  

    if (cursorPos < 0)
      cursorPos = 0;  

    lcd.clear();
    lcd.setCursor(cursorPos, 0);
    lcd.print(message);
  }
  preSttLeft = sttLeft;

  int sttRight = digitalRead(btnRight);
  if (preSttRight == LOW && sttRight == HIGH) {
    cursorPos += 2;                                                        
    if (cursorPos > 16 - message.length()) cursorPos = 16 - message.length();  
    lcd.clear();
    lcd.setCursor(cursorPos, 0);
    lcd.print(message);
  }
  preSttRight = sttRight;
}
