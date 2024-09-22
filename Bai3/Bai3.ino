int leds[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int currentLed = 0;
bool right = true;
unsigned long previousMillis = 0;  // Biến lưu trữ thời điểm trước đó
void setup() {
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
}


// Hàm thay thế delay()
bool skipTime(unsigned long interval) {
  unsigned long currentMillis = millis();  // Lấy thời gian hiện tại
  
  // Nếu thời gian chênh lệch đã vượt quá khoảng thời gian mong muốn
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Cập nhật thời điểm trước đó
    return true;  // Đã hoàn thành khoảng thời gian
  }
  
  return false;  // Chưa đủ thời gian
}

void loop() {
  if (right) {
    // Nếu đã đủ thời gian (500ms), thực hiện bật LED
    if (skipTime(500)) {
      digitalWrite(leds[currentLed], HIGH);  // Bật LED hiện tại
      currentLed++;  // Chuyển sang LED tiếp theo

      if (currentLed >= 10) {
        right = false;  // Đã bật hết, chuyển hướng
        currentLed = 9;  // Bắt đầu từ LED 10
      }
    }
  } else {
    // Nếu đã đủ thời gian (500ms), thực hiện tắt LED
    if (skipTime(500)) {
      digitalWrite(leds[currentLed], LOW);  // Tắt LED hiện tại
      currentLed--;  // Chuyển về LED trước đó

      if (currentLed < 0) {
        right = true;  // Quay lại bật từ LED 1
        currentLed = 0;
      }
    }
  }
}
