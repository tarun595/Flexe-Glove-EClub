const int pot1 = A0;   
const int pot2 = A1;

const int buzzer3 = 11;
const int buzzer2 = 12;
const int buzzer1 = 13;

const int totalLEDs = 5;
int leds[totalLEDs] = {2, 3, 4, 5, 6};

void setup() {
  Serial.begin(9600);
  pinMode(pot1, INPUT);
  pinMode(pot2, INPUT);

  for (int i = 0; i < totalLEDs; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }

  pinMode(buzzer1, OUTPUT);
  pinMode(buzzer2, OUTPUT);
  pinMode(buzzer3, OUTPUT);
}

void loop() {
  int x = analogRead(pot1);
  int y = analogRead(pot2);
  int delayTime = map(y, 0, 1023, 100, 1000);  

  digitalWrite(buzzer1, LOW);
  digitalWrite(buzzer2, LOW);
  digitalWrite(buzzer3, LOW);
  
  if (x <= 341) {
    digitalWrite(buzzer1, HIGH);
  } else if (x > 341 && x <= 682) {
    digitalWrite(buzzer2, HIGH);
  } else {
    digitalWrite(buzzer3, HIGH);
  }

  // LEDs turn on one by one based on pot2 delay
  for (int i = 0; i < totalLEDs; i++) {
    digitalWrite(leds[i], LOW);
    delay(delayTime);
    digitalWrite(leds[i], HIGH);
  }

 Serial.print(x);
Serial.print(", ");
Serial.println(delayTime);

}

// tinkercad link
// https://www.tinkercad.com/things/j5trZLtm81t-week0?sharecode=iYZD00gPWFY6jUGcZivyv-C-PW_xl_zDgzlVuDVzodQ
