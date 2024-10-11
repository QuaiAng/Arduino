#include <LiquidCrystal.h>

// Khởi tạo LCD (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Khai báo nút
const int btnA = 10;
const int btnU = 9;
const int btnF = 8;
const int btnS = 7;
int preSttBtnA = LOW;
int preSttBtnU = LOW;
int preSttBtnF = LOW;
int preSttBtnS = LOW;
// Định nghĩa các ký tự Unicode
byte chuA_A[8] = {
  B00100,
  B01010,
  B00000,
  B00100,
  B01010,
  B01110,
  B01010,
  B01010
};

byte chuA_F[8] = {
  B01000,
  B00100,
  B00010,
  B00100,
  B01010,
  B01110,
  B01010,
  B01010
};

byte chuA_S[8] = {
  B00010,
  B00100,
  B01000,
  B00100,
  B01010,
  B01110,
  B01010,
  B01010
};

byte chuU_S[8] = {
  B00010,
  B00100,
  B00000,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000
};

byte chuU_F[8] = {
  B01000,
  B00100,
  B00000,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000
};

int preChar = -1;

void setup() {
  // Khởi tạo LCD với 16 cột, 2 hàng
  lcd.begin(16, 2);


  lcd.createChar(0, chuA_A);
  lcd.createChar(1, chuA_F);
  lcd.createChar(2, chuA_S);
  lcd.createChar(3, chuU_S);
  lcd.createChar(4, chuU_F);


  pinMode(btnA, INPUT);
  pinMode(btnU, INPUT);
  pinMode(btnF, INPUT);
  pinMode(btnS, INPUT);

  lcd.clear();
}

void loop() {
  lcd.setCursor(0, 0);

  int stateA = digitalRead(btnA);
  int stateU = digitalRead(btnU);
  int stateF = digitalRead(btnF);
  int stateS = digitalRead(btnS);


  if (stateA == HIGH && preSttBtnA == LOW) {

    //Neu truoc do la chu A
    if (preChar == 1) {
      lcd.write(byte(0));
      preChar = 0;
    } else {
      lcd.print("A");
      preChar = 1;
    }
    
  }
  preSttBtnA = stateA;



  if (stateU == HIGH && preSttBtnU == LOW) {
    preChar = 2;
    lcd.print("U");
  }
  preSttBtnU = stateU;



  if (stateF == HIGH && preSttBtnF == LOW) {
    //Neu truoc do la A
    if (preChar == 1) {
      lcd.write(byte(1));
    }
    //Neu truoc do la U
    else if (preChar == 2) {
      lcd.write(byte(4));
    } else {
      lcd.print("F");
    }
    preChar = 0;
  }
  preSttBtnF = stateF;



  if (stateS == HIGH && preSttBtnS == LOW) {
    //Neu truoc do la A
    if (preChar == 1) {
      lcd.write(byte(2));
    }
    //Neu truoc do la U
    else if (preChar == 2) {
      lcd.write(byte(3));
    } else {
      lcd.print("S");
    }
    preChar = 0;
  }
  preSttBtnS = stateS;
}
