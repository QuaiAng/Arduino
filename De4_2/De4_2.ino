#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


const int btnE = 10;
const int btnY = 9;
const int btnF = 8;
const int btnS = 7;
int preSttbtnE = LOW;
int preSttbtnY = LOW;
int preSttBtnF = LOW;
int preSttBtnS = LOW;

byte chuE_E[8] = {
  B00100,
  B01010,
  B01110,
  B01000,
  B01110,
  B01000,
  B01110,
  B00000
};

byte chuE_F[8] = {
  B01000,
  B00100,
  B00010,
  B01110,
  B01000,
  B01110,
  B01000,
  B01110
};

byte chuE_S[8] = {
  B00010,
  B00100,
  B01000,
  B01110,
  B01000,
  B01110,
  B01000,
  B01110
};

byte chuY_S[8] = {
  B01000,
  B00100,
  B00010,
  B10001,
  B01010,
  B00100,
  B00100,
  B00100
};

byte chuY_F[8] = {
  B00010,
  B00100,
  B01000,
  B10001,
  B01010,
  B00100,
  B00100,
  B00100
};

int preChar = -1;

void setup() {
  // Khởi tạo LCD với 16 cột, 2 hàng
  lcd.begin(16, 2);


  lcd.createChar(0, chuE_E);
  lcd.createChar(1, chuE_F);
  lcd.createChar(2, chuE_S);
  lcd.createChar(3, chuY_S);
  lcd.createChar(4, chuY_F);


  pinMode(btnE, INPUT);
  pinMode(btnY, INPUT);
  pinMode(btnF, INPUT);
  pinMode(btnS, INPUT);

  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);

  int stateE = digitalRead(btnE);
  int stateY = digitalRead(btnY);
  int stateF = digitalRead(btnF);
  int stateS = digitalRead(btnS);


  if (stateE == HIGH && preSttbtnE == LOW) {

    //Neu truoc do la chu A
    if (preChar == 1) {
      lcd.write(byte(0));
      preChar = 0;
    } else {
      lcd.print("E");
      preChar = 1;
    }
  }
  preSttbtnE = stateE;



  if (stateY == HIGH && preSttbtnY == LOW) {
    preChar = 2;
    lcd.print("Y");
  }
  preSttbtnY = stateY;



  if (stateF == HIGH && preSttBtnF == LOW) {
    //Neu truoc do la E
    if (preChar == 1) {
      lcd.write(byte(1));
    }
    //Neu truoc do la Y
    else if (preChar == 2) {
      lcd.write(byte(3));
    } else {
      lcd.print("F");
    }
    preChar = 0;
  }
  preSttBtnF = stateF;



  if (stateS == HIGH && preSttBtnS == LOW) {
    //Neu truoc do la E
    if (preChar == 1) {
      lcd.write(byte(2));
    }
    //Neu truoc do la Y
    else if (preChar == 2) {
      lcd.write(byte(4));
    } else {
      lcd.print("S");
    }
    preChar = 0;
  }
  preSttBtnS = stateS;
}
