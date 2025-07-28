# 🧭 Arduino Learning Path – Gabriel Edition

Welcome to my Arduino learning repository! This space documents my journey into embedded systems and electronics through a structured, progressive path. The goal: to build practical projects while mastering key electronics and programming concepts step by step.

This repository is developed with the support of **ChatGPT**, acting as my instructor and documentation assistant throughout this learning process.

---

## 📘 Learning Structure
The path is divided into **5 progressive levels**, each focused on new core skills and capped with a final project ("mini-boss") that integrates everything learned up to that point.

| Level | Objective                   | Core Concepts                                         | Final Project (Mini-Boss)                     |
|-------|-----------------------------|--------------------------------------------------------|-----------------------------------------------|
| 1     | Control LEDs and buttons    | Voltage, current, Ohm’s Law, digital I/O               | 🚦 Smart traffic light with pedestrian button  |
| 2     | Read analog sensors         | Analog inputs, variable resistors, signal mapping      | 🌡️ Thermometer with LED warning                |
| 3     | Control active outputs      | Servos, DC motors, transistors                         | 🚪 Automatic door with distance sensor         |
| 4     | Combine sensing + logic     | Nested ifs, boolean logic, decision algorithms         | 💧 Smart irrigation system                     |
| 5     | Integrate and optimize      | Modularity, functions, debugging, system efficiency    | 📊 Interactive environmental station with display |

Each level includes:
- 🎯 Conceptual explanation
- 🧪 Practical experiments
- 🧠 Troubleshooting logs (see `logbook.md`)
- ✅ Final project with full documentation

---

## 📁 Repository Structure

```plaintext
arduino-learning/
├── phase-01-fundamentals/
│   ├── final-project-smart-crossing/
│   └── logbook.md ← all 8 early projects documented in text only
├── phase-02-analog-sensors/
│   ├── stage-1-temperature-test/
│   ├── stage-2-threshold-led/
│   └── ...
├── phase-03-actuators/
├── ...
├── logbook.md
├── README.md         ← (this file)
└── README_project.md ← detailed README inside each project folder
```

**Note:** In **Phase 1**, only the final project (Smart Traffic Light with Pedestrian Button) is fully documented with code and photos. The first 7 foundational projects are summarized in the logbook only. From **Phase 2 onward**, all projects include source code, photos, and detailed documentation in their respective folders (named `stage-X`).

---

## 🧠 Why this format?
I’m using GitHub not only as version control, but also to demonstrate:
- Technical growth over time
- Project planning and debugging process
- Structured documentation of learning

This repo acts as both a portfolio and a personal study log.

---

## ✨ How to Navigate
- For **learning logs**, see [`logbook.md`](./logbook.md)
- For **Phase 1**, explore `phase-01-fundamentals/final-project-smart-crossing`
- For **ongoing projects**, browse `phase-02-*` folders and their `stage-*` subfolders
- For **code and logic**, check each `.ino` file and its comments

---

## 👨‍💻 About Me
My name is **Gabriel Cabrera**. I'm a student of **Applied Mathematics and Computer Science Engineering** at the **Universidad San Francisco de Quito**. This project represents my structured and hands-on introduction to the world of electronics and embedded systems.

With the help of ChatGPT as my personal tutor and documentation assistant, I'm documenting each project in a way that reflects my learning process and technical growth.

Stay tuned for more as I level up! 🚀

