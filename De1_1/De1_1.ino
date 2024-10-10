int led1 = 3;
int led2 = 5;
int led3 = 6;
int led4 = 9;
int led5 = 10;
int led6 = 11;
int btn = 13;
int preSttBtn = LOW;
int preTime = 0;
int preTimeLe = 0;
int preTimeChan = 0;
int cheDoHienTai = 0;
int count = 0;
void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(btn, INPUT);
}

void tatTatCaDen() {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
}


bool sangLanLuot6Den(int n) {

  unsigned int time = millis();

  if (preTime == 0) {
    if (time - preTime > n) {
      preTime = time;
    }
  }

  if (time - preTime < n) {
    digitalWrite(led1, HIGH);

  } else if (time - preTime < n * 2) {

    digitalWrite(led2, HIGH);

  } else if (time - preTime < n * 3) {

    digitalWrite(led3, HIGH);

  } else if (time - preTime < n * 4) {

    digitalWrite(led4, HIGH);

  } else if (time - preTime < n * 5) {

    digitalWrite(led5, HIGH);

  } else if (time - preTime < n * 6) {

    digitalWrite(led6, HIGH);

  } else if (time - preTime < n * 7) {
    tatTatCaDen();
  } else {

    preTime = time;
    return true;
  }
  return false;
}


bool sangDenLe(int n) {

  unsigned int time = millis();

  if (preTimeLe == 0) {
    if (time - preTimeLe > n) {
      preTimeLe = time;
    }
  }

  if (time - preTimeLe < n) {

    digitalWrite(led1, HIGH);

  } else if (time - preTimeLe < n * 2) {

    digitalWrite(led3, HIGH);

  } else if (time - preTimeLe < n * 3) {

    digitalWrite(led5, HIGH);

  } else if (time - preTimeLe < n * 4) {

    tatTatCaDen();

  } else {
    preTimeLe = time;
    return true;
  }
  return false;
}


bool sangDenChan(int n) {

  unsigned int time = millis();

  if (preTimeChan == 0) {
    if (time - preTimeChan > n) {
      preTimeChan = time;
    }
  }

  if (time - preTimeChan < n) {

    digitalWrite(led2, HIGH);

  } else if (time - preTimeChan < n * 2) {

    digitalWrite(led4, HIGH);

  } else if (time - preTimeChan < n * 3) {

    digitalWrite(led6, HIGH);

  } else if (time - preTimeChan < n * 4) {

    tatTatCaDen();

  } else {
    preTimeChan = time;
    return true;
  }
  return false;
}


void loop() {

  int sttBtn = digitalRead(btn);
  if (preSttBtn == LOW && sttBtn == HIGH) {
    count++;
    tatTatCaDen();
    cheDoHienTai = 0;
  }
  preSttBtn = sttBtn;

  if (count == 1) {

    sangLanLuot6Den(500);

  } else if (count == 2) {

    sangDenLe(500);

  } else if (count == 3) {

    sangDenChan(500);

  } else if (count == 4) {

    if (cheDoHienTai == 0) {
      if (sangLanLuot6Den(500))
        cheDoHienTai++;
    } else if (cheDoHienTai == 1) {
      if (sangDenLe(500))
        cheDoHienTai++;
    } else if (cheDoHienTai == 2) {
      if (sangDenChan(500))
        cheDoHienTai = 0;
    }

  } else {
    count = 0;
  }
}
