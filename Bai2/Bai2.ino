unsigned long preTimes[10] = {0};  // Mảng lưu thời gian riêng cho từng đèn
int leds[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

bool denChopNMiligiay(int n, int led, int index) {
  if (n < 100) {
    n = 100;  // Đảm bảo thời gian chớp tối thiểu là 100ms
  }

  unsigned long currentTimes = millis();  // Lấy thời gian hiện tại

  if (currentTimes - preTimes[index] <= n) {
    digitalWrite(led, HIGH);  // Bật đèn LED
  }
  else if (currentTimes - preTimes[index] <= n * 2) {
    digitalWrite(led, LOW);  // Tắt đèn LED
  }
  else {
    preTimes[index] = currentTimes;  // Cập nhật thời gian cho đèn này
    return true;  // Hoàn thành một chu kỳ
  }

  return false;
}

void loop() {
  for (int i = 0; i < 10; i++) {
    denChopNMiligiay(1000, leds[i], i);  // Mỗi đèn có một `preTimes` riêng
  }
}

