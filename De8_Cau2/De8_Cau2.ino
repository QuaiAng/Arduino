#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int pin_X = 10;
int pin_Y = 9;
int pre_stax = LOW;
int pre_stay = LOW;
int check  = 0; 
 int dem = 0; 
byte chuEE[8] = {
B00100,
B01010,
B01110,
B01000,
B01110,
B01000,
B01110,
B00000
  };
byte chuOO[8] = {
B00100,
B01010,
B00000,
B00100,
B01010,
B01010,
B00100,
B00000
  };
byte chuOW[8] = {
B00011,
B00001,
B00110,
B01010,
B01010,
B01010,
B00100,
B00000  
  };

void setup() {
  pinMode(pin_X,INPUT);
  pinMode(pin_Y,INPUT);
   
  lcd.begin(16,2);

  lcd.createChar(0,chuEE);
  lcd.createChar(1,chuOO);
  lcd.createChar(2,chuOW);
  
  lcd.clear();
  lcd.setCursor(0,0);

}

void loop() {
   int stax = digitalRead(pin_X);
   int stay = digitalRead(pin_Y);
 
  if(pre_stax == LOW && stax == HIGH){ // E: 1, F: 2, O: 3, T: 4
     dem ++; 
    if(dem == 1){
      lcd.setCursor(0,0);
      lcd.print("E");
      check  = 1; 
    }else if(dem == 2){
      lcd.setCursor(0,0);
      lcd.print("F");
      check  = 2;
    }else if(dem == 3){
      lcd.setCursor(0,0);
      lcd.print("O");
      check = 3;
    }else if(dem == 4){
      lcd.setCursor(0,0);
      lcd.print("T");
      check = 4;
      dem = 0;
    }
  }
   pre_stax = stax;
 // xử lý nút Y: 
if(pre_stay == LOW && stay == HIGH){ // E: 1, F:2, O: 3, T: 4, Ê: 5, Ô:6, Ơ: 7
 if(check == 1){
     lcd.setCursor(0,0);
     lcd.print(char(0)); // in ra chữ Ê
     delay(200);
     check = 5;
  }else if(check == 5){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("E");
    check = 1;     
  }else if(check == 2){
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("F");
    check = 2;
  }else if(check == 3 ){
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(char(1)); // từ O thành Ô
    check = 6;
  }else if(check == 6){
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(char(2)); // in ra chữ Ơ
    check = 7;
  }else if(check == 4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("T");
    check = 4;
  }else if(check == 7){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("O");
    check = 3;
  }
}
pre_stay = stay;

}
