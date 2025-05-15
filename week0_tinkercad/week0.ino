const int pot1Pin = A0;
const int pot2Pin = A1;

const int buzzer1 = 2;
const int buzzer2 = 3;
const int buzzer3 = 4;

const int ledPins[5] = {5, 6, 7, 8, 9};

void setup() {
  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);

  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int pot1Value = analogRead(pot1Pin);

  digitalWrite(buzzer1, LOW);
  digitalWrite(buzzer2, LOW);
  digitalWrite(buzzer3, LOW);

  if (pot1Value >= 0 && pot1Value <= 341) {
    digitalWrite(buzzer1, HIGH);
  } else if (pot1Value >= 342 && pot1Value <= 682) {
    digitalWrite(buzzer2, HIGH);
  } else if (pot1Value >= 683) {
    digitalWrite(buzzer3, HIGH);
  }

  int pot2Value = analogRead(pot2Pin);
  int ledDelay = map(pot2Value, 0, 1023, 100, 1000);

  for (int i = 0; i < 5; i++) {
    turnOffAllLEDs();
    digitalWrite(ledPins[i], HIGH);
    delay(ledDelay);
  }
}

void turnOffAllLEDs() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

// tinkercad link
// https://www.tinkercad.com/things/iQ55O2KYLtJ-dazzling-blad?sharecode=mNDz_0bIvVMG8y2-V3ZsZs3MbVa4V18aLq5FBAgAgv8