# IoT Lab – Embedded Systems Experiments (8051 and STM32)

Lab experiments for **25CS2741 Fundamentals of Internet of Things + Lab** (B.Tech CSE (IoT), Shiv Nadar University Chennai).

The experiments start with bare-metal register programming on the 8051, move to STM32 microcontrollers with STM32CubeMX and the HAL library, and finish with networked sensing: an STM32 talks to a Wemos (ESP8266) Wi-Fi modem with AT commands, serves data over HTTP and publishes it over MQTT.

Each experiment folder (`CATn`) has its own **README.md** with the hardware used, circuit diagram, core logic, pseudocode and inference. The 8051 folders also contain the source code, the Keil project and the compiled `.hex`.

## Experiments

### 8051 (AT89S52) – Bare-Metal Embedded C, Keil µVision

| # | Experiment | Key concepts | Folder |
|---|---|---|---|
| Cat 2 | LED blinking | SFR bit access (`sbit`), software delay | [`CAT2`](8051/CAT2/) |
| Cat 3 | Key-controlled LED chaser | Keypad row/column reading, GPIO input and output | [`CAT3`](8051/CAT3/) |
| Cat 4 | Keypad, seven-segment display and LED patterns | Keypad scanning, debouncing, seven-segment codes, mode flags | [`CAT4`](8051/CAT4/) |
| Cat 5 | Timer 0 interrupt LED blink | Timer 0 mode 1, reload value, interrupt service routine | [`CAT5`](8051/CAT5/) |
| Cat 6 | UART driver and serial debugging | `SCON`, `TMOD`, Timer 1 baud-rate generation, `TI` / `RI` flags | [`CAT6`](8051/CAT6/) |
| Cat 7 | 16×2 LCD interfacing | HD44780 4-bit interface, command and data nibbles | [`CAT7`](8051/CAT7/) |

### STM32 – STM32CubeMX + HAL, Keil MDK-ARM / STM32CubeIDE

| # | Experiment | MCU | Key concepts | Folder |
|---|---|---|---|---|
| Cat 8A | LED blink | STM32F103C8 | GPIO output, `HAL_Delay()` | [`CAT8A`](STM32/CAT8A/) |
| Cat 8B | Switch-controlled LED | STM32F103C8 | GPIO input, pull-ups, debouncing | [`CAT8B`](STM32/CAT8B/) |
| Cat 9 | UART configuration | STM32F103C8 | USART with HAL, serial terminal | [`CAT9`](STM32/CAT9/) |
| Cat 10 | STM32–Wemos Wi-Fi modem interface using AT commands | STM32F103C8 | Two UARTs, ESP8266 AT commands, station mode | [`CAT10`](STM32/CAT10/) |
| Cat 11 | HTTP server on the Wi-Fi modem | STM32F410RB | TCP server over AT commands, HTTP response | [`CAT11`](STM32/CAT11/) |
| Cat 12 | Wi-Fi server and LED blink | STM32F401RE | Cortex-M4 GPIO, UART to Wemos | [`CAT12`](STM32/CAT12/) |
| Cat 13 | Sensor interface over I²C | STM32F401RE | I²C, sensor data over UART and Wi-Fi | [`CAT13`](STM32/CAT13/) |
| Cat 14 | MQTT publishing | STM32F401RE | MQTT over the Wi-Fi modem, public broker | [`CAT14`](STM32/CAT14/) |

## Hardware

| Hardware | Used in | Notes |
|---|---|---|
| AT89S52 development kit | Cat 2 – Cat 7 | On-board LEDs, matrix keypad, seven-segment display and 16×2 LCD; programmed over ISP |
| STM32F103C8 board | Cat 8A – Cat 10 | Programmed with an ST-Link over SWD |
| STM32F410RB board | Cat 11 | Programmed through the on-board ST-LINK |
| NUCLEO-F401RE (STM32F401RE) | Cat 12 – Cat 14 | On-board ST-LINK |
| Wemos D1 Mini (ESP8266) | Cat 10 – Cat 14 | Wi-Fi modem running AT-command firmware |
| I²C sensor module | Cat 13 | Connected to the STM32 over I²C |
| USB-to-TTL serial converter | Cat 6, Cat 9 – Cat 11 | PC terminal (PuTTY / Tera Term) |

## Tools

| Tool | Used for |
|---|---|
| **Keil µVision 5** with the C51 compiler | 8051 projects (`.uvproj`) |
| **STM32CubeMX** | STM32 pin, clock and peripheral configuration (`.ioc`) and code generation |
| **Keil MDK-ARM** / **STM32CubeIDE** | Building and flashing the STM32 projects |
| STM32Cube HAL | STM32 peripheral drivers (in each project's `Drivers/` folder) |
| Proteus | 8051 circuit simulation |
| PuTTY / Tera Term | Serial terminal |

## Repository Layout

```
IOT_LAB/
├── README.md                   this file
├── 8051/
│   ├── README.md
│   └── CATn/                   README.md, circuit.png, *.c, *.uvproj, STARTUP.A51, Objects/*.hex
└── STM32/
    ├── README.md
    └── CATn/                   README.md, project folder(s): *.ioc, Core/, Drivers/
```

Build output is not committed (see [.gitignore](.gitignore)): Keil's `Listings/` and the rest of `Objects/`, STM32CubeIDE's `Debug/` and `Release/`, and per-user IDE files. The 8051 projects keep their `.hex` file so they can be flashed without rebuilding.

## Building

**8051 (Keil µVision):** open the experiment's `.uvproj` file and choose **Project → Build Target (F7)**. The HEX file is written to the project's `Objects/` folder. Flash it to the AT89S52 with an ISP programmer.

**STM32 (STM32CubeIDE):** choose **File → Import → General → Existing Projects into Workspace**, select the project folder, then **Project → Build Project**. Flash and debug with **Run → Debug** through the ST-Link. For the Wi-Fi experiments (Cat 10 – Cat 14), set your own Wi-Fi network name and password in `main.c` first.
