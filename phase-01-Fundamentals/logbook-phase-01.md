# 📘 Arduino Learning Log Phase 01 – Gabriel Cabrera

This file documents technical challenges, solutions, and key takeaways for each Arduino project completed.

---

## 🔹 Project 1: Basic LED Control
**⏱️ Estimated Time:** 1 hour  
**📌 Issue Registered**

**Problem Description:** First-time use of pin 13, confusion about GND and current flow.  
**How It Was Detected:** Basic code test using the Arduino IDE.  
**Solution Applied:** Explained GND as reference ground; verified LED polarity and correct connection.  
**Key Learning:** Understanding current flow, use of internal LED on pin 13, groundwork for future circuits.

---

## 🔹 Project 2: LED + Resistor on Breadboard
**⏱️ Estimated Time:** 1 hour  
**📌 Issue Registered**

**Problem Description:** Confusion about resistor value and connection, unfamiliarity with breadboard layout.  
**How It Was Detected:** While assembling the circuit physically.  
**Solution Applied:** Reviewed common resistor values (1kΩ–10kΩ); explained breadboard row continuity.  
**Key Learning:** Reading color codes, horizontal flow in breadboard, LED protection principle.

---

## 🔹 Project 3: Button with Pull-Down Resistor
**⏱️ Estimated Time:** 1 hour  
**📌 Issue Registered**

**Problem Description:** Erratic behavior of the button, unclear wiring to 5V and GND.  
**How It Was Detected:** LED turned on without pressing the button.  
**Solution Applied:** Introduced pull-down resistor concept; proper diagonal button connection.  
**Key Learning:** Floating states, input stabilization using pull-down logic.

---

## 🔹 Project 4: Toggle Button Logic (Switch Behavior)
**⏱️ Estimated Time:** 1 hour  
**📌 Issue Registered**

**Problem Description:** LED did not toggle properly when pressing the button.  
**How It Was Detected:** Counter logic inside loop didn't behave as expected.  
**Solution Applied:** Improved state control using boolean logic and external toggle variable.  
**Key Learning:** Boolean toggling, proper use of digitalRead(), edge-triggered thinking.

---

## 🔹 Project 5: Blinking LED with millis()
**⏱️ Estimated Time:** 1 hour  
**📌 Issue Registered**

**Problem Description:** Needed blinking LED behavior without blocking the loop.  
**How It Was Detected:** `delay()` blocked other actions in the program.  
**Solution Applied:** Switched to `millis()` comparison-based timing.  
**Key Learning:** Non-blocking timing, how `millis()` works, state vs elapsed time.

---

## 🔹 Project 6: Multiple LEDs with Different Intervals
**⏱️ Estimated Time:** 1 hour  
**📌 Issue Registered**

**Problem Description:** Managing 3 LEDs blinking at different intervals.  
**How It Was Detected:** One LED was fast, another slow, third even slower.  
**Solution Applied:** Used independent time counters per LED.  
**Key Learning:** Simulating multitasking with multiple timers and independent states.

---

## 🚦 Project 7: Basic Automatic Traffic Light
**⏱️ Estimated Time:** 1 hour  
**📌 Issue Registered**

**Problem Description:** Traffic light phases did not change correctly with `millis()`.  
**How It Was Detected:** No state transitions after first green.  
**Solution Applied:** Changed equality check `==` to `>=`; added state+timestamp structure.  
**Key Learning:** Simple state machine design, phase transitions using time checks.

---

## 🚦🧠 Final Project: Smart Traffic Intersection with Pedestrian Button
**⏱️ Estimated Time:** 4 hours  
• Circuit design + assembly: 1 hour  
• Code + debugging: 3 hours  
**📌 Issue Registered**

**Problem Description:** System must alternate traffic lights with proper delays and allow pedestrians to cross safely with a button.  
**How It Was Detected:** During real-time testing, the button had no effect; later needed logic to force pedestrian crossing every 3 cycles.  
**Solution Applied:** 
- Fixed button logic using `digitalRead()`
- Implemented lightState logic using `millis()`
- Tracked traffic cycles and forced crossing on every third cycle
- Added 1s delay before switching to green (safety buffer)
**Key Learning:**
- Complex state machine logic
- Safety timing coordination
- Button-triggered vs auto-triggered events
- Pedestrian phase integration with normal cycle

🏷️ Tags: #millis #stateMachine #pedestrianButton #nonBlockingTiming #interruptLogic

---
