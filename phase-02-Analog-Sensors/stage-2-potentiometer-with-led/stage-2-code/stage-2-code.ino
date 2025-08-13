//Project: Phase 2 – Project 2: LED Control with Potentiometer (Non-blocking + Hysteresis + Averaging)
//Author: Gabriel Cabrera (Learning Log)
//Description: Reads analog value from potentiometer and turns on a led if it reaches a threshold
// --- Pin assignments and configuration constants ---
const int potentiometer = A0;
int ledPin = 23;
float threshold = 1023*0.7;
float tolerance = threshold*0.02;
// --- Timing variables for non-blocking printing and sampling ---
unsigned long lastPrint = 0;
unsigned long lastStamp = 0;
// --- Variables for averaging 16 analog samples ---
int counter = 0;
long averageSum = 0;
float averageValue = 0;
// --- Variables to track LED state changes ---
int prevState = LOW;
int currentState = LOW;

// --- Arduino setup: configure serial and initial LED state ---
void setup() {
  Serial.begin (9600);
  pinMode (ledPin, OUTPUT);
  digitalWrite (ledPin, currentState);
}

// --- Main loop: handle sampling, printing, and LED control ---
void loop() {
  unsigned long totalTime = millis(); 
  int analogValue = analogRead (potentiometer);
  // --- Sampling every 5 ms and accumulating for averaging ---
  if (totalTime - lastStamp >=5) {
    averageSum += analogValue;
    counter++;
    // --- Once 16 samples collected: calculate average and reset counters ---
    if (counter == 16) {
      averageValue = averageSum / 16.0;
      counter = 0;
      averageSum = 0;
    }
    lastStamp = totalTime;
  }
  // --- Debug print to Serial Monitor every 250 ms ---
  if (totalTime - lastPrint >= 250) {
    Serial.println (analogValue);
    lastPrint = totalTime;
  }
  // --- LED ON condition: above (threshold + tolerance) ---
  if (averageValue >= threshold + tolerance) {
    currentState = HIGH;
    digitalWrite (ledPin, currentState);
      // --- Print LED status only once per state change ---
    if (currentState != prevState) {
      Serial.println ("Led = ON");
      Serial.print ("Threshold = ");
      Serial.println (threshold);
      prevState = currentState;
    }
  }
  // --- LED OFF condition: below (threshold - tolerance) ---
  if (averageValue <= threshold - tolerance) {
    currentState = LOW;
    digitalWrite (ledPin, currentState);
      // --- Print LED status only once per state change ---
    if (currentState != prevState) {
      Serial.println ("Led = OFF");
      Serial.print ("Threshold = ");
      Serial.println (threshold);
      prevState = currentState;
    }
  }
}
