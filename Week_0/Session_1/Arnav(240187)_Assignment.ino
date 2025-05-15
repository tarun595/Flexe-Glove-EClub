const int pot1Pin = A0;  
const int pot2Pin = A1;  

const int buzzerPins[3] = {4, 5, 6};  
const int ledPins[5] = {7, 8, 9, 10, 11};  

int currentLed = 0;
unsigned long lastLedChangeTime = 0;

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(buzzerPins[i], OUTPUT);
    digitalWrite(buzzerPins[i], LOW);
  }
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
  Serial.begin(9600);
}

void loop() {
  int pot1Value = analogRead(pot1Pin);  
  int pot2Value = analogRead(pot2Pin);  

  Serial.print(pot1Value);
  Serial.print(",");
  Serial.println(pot2Value);

  controlBuzzers(pot1Value);

  int delayTime = map(pot2Value, 0, 1023, 50, 1000);
  updateLEDs(delayTime);
}

void controlBuzzers(int pot1Value) {
  int activeBuzzer;
  if (pot1Value <= 341) {
    activeBuzzer = 0;  
  } else if (pot1Value <= 682) {
    activeBuzzer = 1;  
  } else {
    activeBuzzer = 2;  
  }
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPins[i], (i == activeBuzzer) ? HIGH : LOW);
  }
}

void updateLEDs(int delayTime) {
  unsigned long currentTime = millis();
  if (currentTime - lastLedChangeTime >= delayTime) {
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    currentLed = (currentLed + 1) % 5;
    digitalWrite(ledPins[currentLed], HIGH);
    lastLedChangeTime = currentTime;
  }
}
// Link to the Tinkercad Project: https://www.tinkercad.com/things/cpiQNzYMcWo-week0assignment?sharecode=CvjnGVE5qRCdxBiNBzZTE_X2ofrmtSnMM71U3hEG3a4