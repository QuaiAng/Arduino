int pin_tang = 13;
int pin_giam = 12;
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 6; 
int led5 = 5;
int led6 = 3;
int pre_sta_tang = LOW;
int pre_sta_giam = LOW;
int dosang = 150;
int previous  = 0;
int dl_time = 500;
int array[6] = {11,10,9,6,5,3};

bool kiemTraDenNhapNhay(){
  if(dosang > 0){
    return true;
  }
   return false;
}
 
void setup() {
  pinMode(pin_tang, INPUT);
  pinMode(pin_giam, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
 
}


void loop() {
    int sta_tang = digitalRead(pin_tang);
     int sta_giam = digitalRead(pin_giam);
      int sta = digitalRead(pin_btn);
     int currentmillis = millis();

// kiểm tra nút tăng độ sáng đèn 
       if(pre_sta_tang == LOW &&  sta_tang == HIGH){
          dosang += 30;
          if(dosang > 255){
            dosang  = 255;
          }
         }
          pre_sta_tang = sta_tang; 

// kiểm tra nút giảm độ sáng đèn      
         if(pre_sta_giam == LOW &&  sta_giam == HIGH){
            dosang -= 30;
          if(dosang <  0){
            dosang  = 0;
          }
         }
          pre_sta_giam = sta_giam;
// kiểm tra khi nhấn hai nút,
    if(pre_sta_tang  == LOW && sta_tang == HIGH){
       if(pre_sta_giam  == LOW && sta_giam == HIGH){
            if(kiemTraDenNhapNhay() == true){
              dosang  = 0;     // khi đèn nhấp nháy thì tắt hết đèn    
          }else{
            dosang  = 100; // khi đèn tắt hết thì nhấp nháy đèn 
          }
            }
            pre_sta_giam  = sta_giam;
    }
      pre_sta_tang = sta_tang;   
            
 // đèn sáng nhấp nháy 
         if(currentmillis - previous <= dl_time){
          analogWrite(array[0], dosang); // đèn 1 sáng 500
        }else if(currentmillis - previous <= dl_time*2){
            analogWrite(array[0], 0); // đèn 1  tắt  1000
        }else if(currentmillis - previous <= dl_time*3){
            analogWrite(array[1], dosang); // đèn 2 sáng 1500
        }else if(currentmillis - previous <= dl_time*4){
           analogWrite(array[1], 0);// đèn 2 tắt 2000
        }else if(currentmillis - previous <= dl_time*5){
           analogWrite(array[2], dosang);
        }else if(currentmillis - previous <= dl_time*6){
           analogWrite(array[2], 0);
        }else if(currentmillis - previous <= dl_time*7){
           analogWrite(array[3], dosang);
        }else if(currentmillis - previous <= dl_time*8){
           analogWrite(array[3], 0);
        }else if(currentmillis - previous <= dl_time*9){
           analogWrite(array[4], dosang);
        }else if(currentmillis - previous <= dl_time*10){
           analogWrite(array[4], 0);
        }else if(currentmillis - previous <= dl_time*11){
           analogWrite(array[5], dosang);
        }else if(currentmillis - previous <= dl_time*12){
           analogWrite(array[5], 0);
        }else if(currentmillis - previous <= dl_time*13){
            analogWrite(array[0], dosang); // sáng đèn 1
        }else if(currentmillis - previous <= dl_time*14){
            analogWrite(array[0], 0); // tắt đèn 1
        }else if(currentmillis - previous <= dl_time*15){
            analogWrite(array[2], dosang); // sáng đèn 3
        }else if(currentmillis - previous <= dl_time*16){
            analogWrite(array[2], 0); // tắt đèn 3
        }else if(currentmillis - previous <= dl_time*17){
            analogWrite(array[4], dosang); // sáng đèn 5
        }else if(currentmillis - previous <= dl_time*18){
            analogWrite(array[4], 0); // tắt đèn 5
        }else if(currentmillis - previous <= dl_time*19){
            analogWrite(array[1], dosang); // sáng đèn 2
        }else if(currentmillis - previous <= dl_time*20){
            analogWrite(array[1], 0); // tắt đèn 2
        }else if(currentmillis - previous <= dl_time*21){
            analogWrite(array[3], dosang); //  sáng đèn 4
        }else if(currentmillis - previous <= dl_time*22){
            analogWrite(array[3], 0); // tắt đèn 4
        }else if(currentmillis - previous <= dl_time*23){
            analogWrite(array[5], dosang); // sáng đèn 6
        }else if(currentmillis - previous <= dl_time*24){
            analogWrite(array[5], 0); // tắt đèn 6
        }else{
          previous  = currentmillis;
        }
          
}
               
     
   
