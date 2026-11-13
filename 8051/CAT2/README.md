# CAT2 – Key-Controlled LED Chaser

| Field | Details |
|---|---|
| **EXP** | CAT2 |
| **DATE** | _fill in (from questions PDF)_ |
| **NAME OF EXP** | _copy exact title from questions PDF_ (working title: Key-Controlled LED Chaser) |
| **HARDWARE SETUP / PLATFORM** | AT89S52 (8051) · 11.0592 MHz crystal · Keil µVision (C51) · Proteus · 4 LEDs (P1.1, P1.3, P1.5, P1.7) · 1 push button (row P2.5, column P2.0) |
| **TASK NO** | _fill in (from questions PDF)_ |

## Circuit Diagram

![Circuit Diagram](circuit.png)

## Core Logic

```
loop forever:
    drive row P2.5 low
    if column P2.0 reads 0 (button pressed):
        light LED1 -> delay -> LED2 -> delay -> LED3 -> delay -> LED4 -> delay
```

- Only one LED is on at a time, so it looks like a running light.
- Nothing happens while the button is not pressed.

## INFERENCE

A key matrix works by driving a row low and reading a column. A low column means the key at that crossing is pressed. This is used to start the LED chaser.

## Files

- `Ex3.c` – source code
- `Ex3.uvproj` – Keil µVision project
- `Objects/Ex3.hex` – compiled firmware (load into Proteus / flash to the chip)
- `circuit.png` / `circuit.svg` – circuit diagram
