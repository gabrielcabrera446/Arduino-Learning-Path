## 🔹 Project 1: Analog Reading with Potentiometer
**⏱️ Estimated Time:** 1 hour  
**📌 Issue Registered**

**Problem Description:** Needed to identify and wire the potentiometer correctly. Initial confusion with rotary encoder and orientation.  
**How It Was Detected:** Through physical inspection and pin verification on breadboard.  
**Solution Applied:** Verified the WH148 10kΩ model, explained terminal mapping in text. Connected to 5V, GND, and A0.  
**Key Learning:** Introduction to analog inputs, ADC resolution, use of Serial Monitor, converting analog values to voltage.  

## 🔹 Project 2: LED control with threshold and potentiometer 
**⏱️ Estimated Time:** 2 hours  
**📌 Issue Registered**

**Problem Description:** The LED flickered near the threshold value due to signal noise, and Serial Monitor was printing repeated messages.  
**How It Was Detected:** Observed LED rapid ON/OFF transitions when the potentiometer was near the decision point, and redundant "LED ON/OFF" messages.  
**Solution Applied:**  
- Implemented a moving average over 16 samples (sampled every ~5 ms) to smooth out signal noise.  
- Applied hysteresis with ±2% tolerance around a base threshold at 70% of ADC range.  
- Used `millis()` for non-blocking timing of sampling and printing, replacing any `delay()` usage.  
- Introduced `prevState`/`currentState` logic to print status messages only on state transitions.  
**Key Learning:**  
- Hysteresis is a standard good practice to stabilize ON/OFF decisions in noisy analog signals.  
- Combining averaging and hysteresis yields a more robust and stable control.  
- Non-blocking design with `millis()` allows independent timing for multiple tasks in the loop.
