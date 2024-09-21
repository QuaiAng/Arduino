int ledXanh = 7;
int ledDo = 8;
int demXanh = 0;
int demDo = 0;
unsigned long preTimes = 0;  

void setup() {
  pinMode(ledXanh, OUTPUT);
  pinMode(ledDo, OUTPUT);
}

bool denChopNMiligiay(int n, int led){
  if(n < 100){
    n = 100;  
  }
  
  unsigned long currentTimes = millis(); 

  if(currentTimes - preTimes <= n) {
    digitalWrite(led, HIGH);  
  }
  else if(currentTimes - preTimes <= n * 2) {
    digitalWrite(led, LOW);  
  }
  else {
    preTimes = currentTimes;  
    return true;
  }
  return false;
}

void loop() {
 if (demXanh < 2) {
    if (denChopNMiligiay(500, ledXanh)) {  // Nếu hoàn thành một chu kỳ sáng-tắt của đèn xanh
      demXanh++;  // Tăng số lần chớp của đèn xanh
    }
  }
  // Sau khi đèn xanh chớp 2 lần, đèn đỏ chớp 1 lần
  else if (demDo < 1) {
    if (denChopNMiligiay(500, ledDo)) {  // Nếu hoàn thành một chu kỳ sáng-tắt của đèn đỏ
      demDo++;  // Tăng số lần chớp của đèn đỏ
    }
  }
  else {
    demXanh = 0;  // Reset lại số lần chớp của đèn xanh
    demDo = 0;    // Reset lại số lần chớp của đèn đỏ
  }
}


