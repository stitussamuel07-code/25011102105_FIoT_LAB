# 8051 Experiments

Platform: AT89S52 development kit (11.0952 MHz crystal) · Keil µVision (C51) · flashed over ISP

| # | Experiment | Tasks |
|---|---|---|
| [Cat 2](CAT2/) | 8051 Tool Chain Setup – Development Board – AT89S52 | [`TASK2B`](CAT2/TASK2B/) LED blink · [`TASK2C`](CAT2/TASK2C/) delay library |
| [Cat 3](CAT3/) | Button-Controlled LED Pattern Generator | [`TASK3A`](CAT3/TASK3A/) |
| [Cat 4](CAT4/) | Human-Machine Interface using Matrix Keypad, LEDs, and Seven-Segment Display | [`TASK4A`](CAT4/TASK4A/) |
| [Cat 5](CAT5/) | Hardware Timer-Based LED Blinking | [`TASK5A`](CAT5/TASK5A/) |
| [Cat 6](CAT6/) | UART Driver and Serial Debugging | [`TASK6A`](CAT6/TASK6A/) transmit · [`TASK6B`](CAT6/TASK6B/) echo |
| [Cat 7](CAT7/) | 16×2 LCD Driver Development and Dynamic Display Control | [`TASK7A`](CAT7/TASK7A/) · [`TASK7B`](CAT7/TASK7B/) · [`TASK7C`](CAT7/TASK7C/) |

Each `CATn/` folder has a `README.md` with the experiment details, overview, circuit diagram and task table, plus `circuit.png`. Each `TASKnX/` folder has the Keil project (`.uvproj`, C source, `STARTUP.A51`, `Objects/*.hex`) and its own `README.md`.
