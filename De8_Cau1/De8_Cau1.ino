int pin_btn  = 13;
int led_red = 5;
int led_yellow = 3;
int pre_sta = LOW;
int dem  = 0; 
void setup() {
  pinMode(pin_btn, INPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_yellow, OUTPUT);

}

void loop() {
  int sta  = digitalRead(pin_btn);
  if(pre_sta == LOW && sta == HIGH){
    dem++;
    
  }
   if(dem == 1){
    digitalWrite(led_red,HIGH);
    digitalWrite(led_yellow,HIGH);
   }else if(dem == 2){
    digitalWrite(led_red,LOW);
    digitalWrite(led_yellow,LOW);
   }else if(dem == 3){
     digitalWrite(led_red,LOW);
    digitalWrite(led_yellow,HIGH);
   }else if(dem == 4){
    digitalWrite(led_red,HIGH);
    digitalWrite(led_yellow,LOW);
    dem = 0;
   }
   pre_sta = sta;

}
