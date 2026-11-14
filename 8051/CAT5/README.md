# EXPERIMENT DETAILS

**EXP:** CONTINUOUS ASSESSMENT 5

**DATE:** _fill in_

**NAME OF EXP:** Hardware Timer-Based LED Blinking

**HARDWARE SETUP / PLATFORM:** AT89S52 Development Kit (11.0952 MHz crystal) + Keil µVision (C51) + 1 LED

---

## Overview

Blink an LED using the 8051's hardware Timer 0 and its interrupt instead of a software delay loop, so the timing is accurate and the main loop is free.

**Expected outcome:** The LED on P1.1 toggles about once per second, driven entirely from the Timer 0 interrupt; `main()` only sets up the timer.

## Circuit Diagram

- **Microcontroller:** AT89S52 (8051 core) on the AT89S52 development kit
- **LED:** P1.1 (active-high, through 330 Ω to GND)
- **Timer:** Timer 0 in mode 1 (16-bit), reload 0xF199 ≈ 4 ms per overflow
- **Power Supply:** 5V DC

![Circuit Diagram](circuit.png)

## Tasks

| Task | What it does | Outcome |
|---|---|---|
| [TASK 5A Timer 0 Interrupt LED Blink](TASK5A/) | Configures Timer 0 mode 1 with interrupt; the ISR reloads the timer, counts 250 overflows and toggles the LED | ≈ 1 s LED toggle from the timer interrupt |

Each task folder contains its Keil µVision project (`.uvproj`, C source, `STARTUP.A51`, `Objects/*.hex`) and a README with the task's hardware, core logic, pseudocode, code base and inference.
