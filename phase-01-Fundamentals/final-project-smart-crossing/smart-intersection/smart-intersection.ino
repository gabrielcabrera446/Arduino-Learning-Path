/*
  Smart Traffic Intersection with Pedestrian Button
  Author: Gabriel Cabrera
  Description:
  Simulates a two-way intersection with pedestrian crossing.
  Each street has its own traffic light (Red, Yellow, Green).
  A pedestrian button allows people to cross when safe.
  After 3 full cycles, pedestrian crossing is triggered even if button is not pressed.
*/

/* --- Traffic Light A (Street A) --- */
int redA = 12;
int yellowA = 11;
int greenA = 10;

/* --- Traffic Light B (Street B) --- */
int redB = 24;
int yellowB = 23;
int greenB = 22;

/* --- Pedestrian Light --- */
int redP = 9;
int greenP = 52;
int pedestrianButton = 7;

/* --- Timing Control --- */
unsigned long totalTime = 0;
int redGreenDelay = 1000; // Delay before switching to green after red (safety delay)

/* --- State Control --- */
int lightState = 0;        // Tracks current light phase
int trafficCicle = 0;      // Tracks full cycles (forces pedestrian crossing after 3)

void setup() {
  // Configure traffic light pins as outputs
  pinMode(redA, OUTPUT);
  pinMode(yellowA, OUTPUT);
  pinMode(greenA, OUTPUT);
  pinMode(redB, OUTPUT);
  pinMode(yellowB, OUTPUT);
  pinMode(greenB, OUTPUT);
  pinMode(redP, OUTPUT);
  pinMode(greenP, OUTPUT);

  // Configure button as input
  pinMode(pedestrianButton, INPUT);

  // Initial state: B green, A red, pedestrian red
  digitalWrite(redA, HIGH);
  digitalWrite(yellowA, LOW);
  digitalWrite(greenA, LOW);
  digitalWrite(redB, LOW);
  digitalWrite(yellowB, LOW);
  digitalWrite(greenB, HIGH);
  digitalWrite(redP, HIGH);
  digitalWrite(greenP, LOW);
}

void loop() {
  unsigned long currentTime = millis();

  // Detect button press to trigger pedestrian crossing after current cycle
  if (digitalRead(pedestrianButton) == HIGH) {
    trafficCicle = 2; // Force crossing after current phase ends
  }

  // Phase 0: Street B green for 8s
  if (currentTime - totalTime == 8000 && lightState == 0) {
    digitalWrite(greenB, LOW);
    digitalWrite(yellowB, HIGH);
    totalTime = currentTime;
    lightState++;
  }

  // Phase 1: Street B yellow for 3s
  if (currentTime - totalTime == 3000 && lightState == 1) {
    digitalWrite(yellowB, LOW);
    digitalWrite(redB, HIGH);
    totalTime = currentTime;
    lightState++;
  }

  // Phase 2: Safety delay (1s) before A turns green
  if (currentTime - totalTime == 1000 && lightState == 2) {
    digitalWrite(redA, LOW);
    digitalWrite(greenA, HIGH);
    totalTime = currentTime;
    lightState++;
  }

  // Phase 3: Street A green for 8s
  if (currentTime - totalTime == 8000 && lightState == 3) {
    digitalWrite(greenA, LOW);
    digitalWrite(yellowA, HIGH);
    totalTime = currentTime;
    lightState++;
  }

  // Phase 4: Street A yellow for 3s, then red
  if (currentTime - totalTime == 3000 && lightState == 4) {
    digitalWrite(yellowA, LOW);
    digitalWrite(redA, HIGH);
    totalTime = currentTime;
    lightState++;
    trafficCicle++;

    // Force pedestrian phase after 3 full cycles
    if (trafficCicle == 3) {
      lightState = -1; // Custom value to trigger pedestrian crossing
    }
  }

  // Pedestrian phase: turn greenP on for 7s
  if (currentTime - totalTime >= 1000 && trafficCicle == 3) {
    digitalWrite(redP, LOW);
    digitalWrite(greenP, HIGH);
    totalTime = currentTime;
    trafficCicle++;
  }

  // Turn pedestrian red back on
  if (currentTime - totalTime >= 7000 && trafficCicle == 4) {
    digitalWrite(greenP, LOW);
    digitalWrite(redP, HIGH);
    totalTime = currentTime;
    lightState = 5;
    trafficCicle = 0;
  }

  // Resume cycle with Street B green
  if (currentTime - totalTime >= 1000 && lightState == 5) {
    digitalWrite(redB, LOW);
    digitalWrite(greenB, HIGH);
    totalTime = currentTime;
    lightState = 0;
  }
}
