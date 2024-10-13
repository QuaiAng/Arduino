#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int pin_X = 10;
int pin_Y = 9;
int pre_stax = LOW;
int pre_stay = LOW;
int check  = 0; 
 int dem = 0; 
byte chuAW[8] = {
B01010,
B00100,
B00100,
B01010,
B01110,
B01010,
B01010,
B00000
  };
byte chuAA[8] = {
B00100,
B01010,
B00100,
B01010,
B01110,
B01010,
B01010,
B00000
  };
byte chuDD[8] = {
B00000,
B01111,
B01001,
B11101,
B01001,
B01001,
B01111,
B00000
  };

void setup() {
  pinMode(pin_X,INPUT);
  pinMode(pin_Y,INPUT);
   
  lcd.begin(16,2);

  lcd.createChar(0,chuAW);
  lcd.createChar(1,chuAA);
  lcd.createChar(2,chuDD);
  
  lcd.clear();
  lcd.setCursor(0,0);

}

void loop() {
   int stax = digitalRead(pin_X);
   int stay = digitalRead(pin_Y);
 
  if(pre_stax == LOW && stax == HIGH){ // A: 1, B: 2, C: 3, D: 4
     dem ++; 
    if(dem == 1){
      lcd.setCursor(0,0);
      lcd.print("A");
      check  = 1; 
    }else if(dem == 2){
      lcd.setCursor(0,0);
      lcd.print("B");
      check  = 2;
    }else if(dem == 3){
      lcd.setCursor(0,0);
      lcd.print("C");
      check = 3;
    }else if(dem == 4){
      lcd.setCursor(0,0);
      lcd.print("D");
      check = 4;
      dem = 0;
    }
  }
   pre_stax = stax;
 // xử lý nút Y: 
if(pre_stay == LOW && stay == HIGH){ // A: 1, B: 2, C: 3, D: 4, Â: 5, Ă: 6, Đ: 7
 if(check == 1){
     lcd.setCursor(0,0);
     lcd.print(char(0)); // in ra chữ Ă
     check = 6;
  }else if(check == 6){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(char(1));// in ra chữ Â
    check = 5;     
  }else if(check == 5){
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("A");
    check = 1;
  }else if(check == 2 ){
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("B"); 
    check = 2;
  }else if(check == 4){
     lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(char(2)); // in ra chữ Đ
    check = 7;
  }else if(check == 7){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("D");
    check = 4;
  }
}
pre_stay = stay;

}
