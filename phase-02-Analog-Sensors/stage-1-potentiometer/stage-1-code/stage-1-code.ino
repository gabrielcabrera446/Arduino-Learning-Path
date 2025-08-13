// Project: Analog Reading with Potentiometer
// Author: Gabriel Cabrera
// Description: Reads analog value from potentiometer and prints it in volts and raw value

const int potenciometer = A0;  // Analog pin connected to potentiometer output

void setup() {
  Serial.begin(9600);  // Initialize serial communication at 9600 bps
}

void loop() {
  int analogValue = analogRead(potenciometer);          // Read analog value (0–1023)
  float voltage = analogValue * (5.0 / 1023.0);  // Convert to voltage (0.00–5.00V)

  Serial.print("Analog: ");
  Serial.print(analogValue);
  Serial.print("  |  Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  delay(500);  // Wait half a second
}
