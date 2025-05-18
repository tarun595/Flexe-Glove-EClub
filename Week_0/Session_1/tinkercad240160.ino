// C++ code
//
const int pot1Pin = A0;
const int pot2Pin = A1;

const int buzzerPins[3] = {2, 3, 4};
const int ledPins[5] = {5, 6, 7, 8, 9};

int currentLED = 0;

void setup() {
  for (int i = 0; i < 3; i++)
    pinMode(buzzerPins[i], OUTPUT);

  for (int i = 0; i < 5; i++)
    pinMode(ledPins[i], OUTPUT);
}

void loop() {
  int pot1Value = analogRead(pot1Pin); // 0 to 1023
  int pot2Value = analogRead(pot2Pin); // 0 to 1023

  // Buzzer logic
  int activeBuzzer = pot1Value / 342;
  if (activeBuzzer > 2) activeBuzzer = 2;

  for (int i = 0; i < 3; i++)
    digitalWrite(buzzerPins[i], i == activeBuzzer ? HIGH : LOW);

  // LED Chaser logic
  for (int i = 0; i < 5; i++)
    digitalWrite(ledPins[i], LOW);

  digitalWrite(ledPins[currentLED], HIGH);
  currentLED = (currentLED + 1) % 5;

  int delayTime = map(pot2Value, 0, 1023, 50, 1000);
  delay(delayTime);
}

/*
TinkerCAD Simulation Link:
https://www.tinkercad.com/things/5hmrNbvKAk9/editel?returnTo=%2Fdashboard&sharecode=Y2dUkVKaSrpxesXk_TD_Qf_XbazfNixGkpoa7o7zswM

*/
