int leds[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
unsigned long preTime = 0;

void setup() {

  for (int i = 0; i < 10; i++) {

    pinMode(leds[i], OUTPUT);

  }
}

void loop() {

  unsigned long crrTime = millis();


  if (preTime == 0 || crrTime - preTime >= 500) {

    preTime = crrTime;

    for (int i = 0; i < 10; i++) {

      int randomNumber = random(1, 100);

      if (randomNumber % 2 != 0) {

        digitalWrite(leds[i], HIGH);

      } else {

        digitalWrite(leds[i], LOW);

      }
    }
  }
}
