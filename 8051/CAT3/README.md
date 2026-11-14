# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 3

**DATE:** _fill in_

**NAME OF EXP:** Button-Controlled LED Pattern Generator

**HARDWARE SETUP / PLATFORM:** AT89S52 Development Kit (11.0952 MHz crystal) + Keil µVision (C51) + 4 LEDs + 1 push-button (keypad key)

---

## Overview

Read a push-button on the AT89S52 and use it to drive an LED pattern: while the key is held, four LEDs light one after another as a running light.

**Expected outcome:** Nothing happens while the key is released; while it is pressed, LED1 → LED2 → LED3 → LED4 light in turn, repeatedly.

## Circuit Diagram

- **Microcontroller:** AT89S52 (8051 core) on the AT89S52 development kit
- **LEDs:** 4 external LEDs on P1.1, P1.3, P1.5, P1.7 (active-high, through 330 Ω to GND)
- **Button:** One key of the built-in matrix keypad – row P2.5 driven low, column P2.0 read as input
- **Power Supply:** 5V DC

![Circuit Diagram](circuit.png)

## Tasks

| Task | What it does | Outcome |
|---|---|---|
| [TASK 3A Key-Controlled LED Chaser](TASK3A/) | Holds the keypad row low, reads the column and runs the four-LED running light while the key is pressed | Button-driven running LED |

Each task folder contains its Keil µVision project (`.uvproj`, C source, `STARTUP.A51`, `Objects/*.hex`) and a README with the task's hardware, core logic, pseudocode, code base and inference.
