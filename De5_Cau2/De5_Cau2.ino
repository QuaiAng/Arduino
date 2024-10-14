#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int btn_O = 10;
int btn_U = 9;
int btn_W = 8;
int btn_S = 7;
int pre_sta1 = LOW;
int pre_sta2 = LOW;
int pre_sta3 = LOW;
int pre_sta4 = LOW;
int dem  = 0; 
int check  = 0;
int cot = 0;
int hang = 0; 
// khai báo byte chữ Ô
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
byte chuOS[8] = {
B00010,
B00100,
B00000,
B00100,
B01010,
B01010,
B00100,
B00000
  };
byte chuUW[8]= {
B00011,
B00001,
B01011,
B01010,
B01010,
B01010,
B01110,
B00000
  };
byte chuUS[8] = {
B00010,
B00100,
B00000,
B01010,
B01010,
B01010,
B01110,
B00000
  };

void setup() {
pinMode(btn_O,INPUT);
pinMode(btn_W,INPUT);
pinMode(btn_S,INPUT);
pinMode(btn_U,INPUT);

lcd.begin(16,2);

lcd.createChar(0,chuOO);
lcd.createChar(1,chuOW);
lcd.createChar(2,chuOS);
lcd.createChar(3,chuUW);
lcd.createChar(4,chuUS);

lcd.clear();
lcd.setCursor(0,0);


}

void loop() {
  int sta1 = digitalRead(btn_O);
  int sta2 = digitalRead(btn_U);
  int sta3 = digitalRead(btn_W);
  int sta4 = digitalRead(btn_S);

// kiểm tra nút nhấn chữ O và in ra các chữ O, Ô
  if(pre_sta1 == LOW && sta1 == HIGH){
     if(check == 1 ){ // chữ O: 1, Ô: 1
      cot--;
      lcd.setCursor(cot,hang);
      lcd.print(char(0)); // in ra chữ Ô
      check  = 0;  
     }else{
      lcd.print("O");
      check = 1; // gán cho chữ O có check = 1;
  }
  cot++;
  }
    pre_sta1= sta1; 

   if(pre_sta2 == LOW && sta2 == HIGH){ // chữ U
      lcd.print("U"); // gán cho chữ U có check = 2
      check = 2;
       cot++;  
   }
    pre_sta2 = sta2;
    
    
   if(pre_sta3 == LOW && sta3 == HIGH){ // chữ W
    if(check == 1){ // khi nhấn vào, kiểm tra trước đó là chữ O thì in Ơ, còn chữ U thì in Ư
      cot--;
      lcd.setCursor(cot,hang);
      lcd.print(char(1));
      check = 0; 
    }else if(check  == 2){ // in ra chữ ư
      cot--;
      lcd.setCursor(cot,hang);
      lcd.print(char(3));
      check = 0;  
    }else{
      lcd.print("W");
    }
    cot++;  
   }
    pre_sta3 = sta3; // in ra chữ Ơ 

  if(pre_sta4 == LOW && sta4 == HIGH){ // chữ S
    if(check == 1){ // khi nhấn vào, kiểm tra trước đó là chữ O thì in Ó, còn chữ U thì in Ú
      cot--;
      lcd.setCursor(cot,hang);
      lcd.print(char(2)); // in ra chữ Ó
      check = 0; 
    }else if(check  == 2){ // in ra chữ Ú
      cot--;
      lcd.setCursor(cot,hang);
      lcd.print(char(4));
      check = 0;
    }else{
      lcd.print("S");
    }
    cot++;  
   }
    pre_sta4 = sta4;

  


    
}
