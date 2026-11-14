# IoT Lab – Embedded Systems Experiments (8051 and STM32)

Lab experiments for **25CS2741 Fundamentals of Internet of Things + Lab** (B.Tech CSE (IoT), Shiv Nadar University Chennai).

The experiments start with bare-metal register programming on the 8051, move to STM32 microcontrollers with STM32CubeMX and the HAL library, and finish with networked sensing: an STM32 talks to a Wemos (ESP8266) Wi-Fi modem with AT commands, serves data over HTTP and publishes it over MQTT. The final project (Cat 15) is a server rack monitor with a DHT11 sensor, MQTT and a Node-RED dashboard.

Each experiment folder (`CATn`) has a **README.md** index with the experiment details, date, overview, circuit diagram and a table of its tasks. Each task folder (`TASKnX`) contains the project and its own **README.md** with the hardware used, core logic, pseudocode, code base and inference.

## Experiments

### 8051 (AT89S52) – Bare-Metal Embedded C, Keil µVision

| # | Experiment | Key concepts | Tasks |
|---|---|---|---|
| [Cat 2](8051/CAT2/) | 8051 tool chain setup, LED blink and custom delay library | SFR bit access (`sbit`), software delay, `delay_ms()` library | [`TASK2B`](8051/CAT2/TASK2B/), [`TASK2C`](8051/CAT2/TASK2C/) |
| [Cat 3](8051/CAT3/) | Button-controlled LED pattern generator | Keypad row/column input, GPIO output | [`TASK3A`](8051/CAT3/TASK3A/) |
| [Cat 4](8051/CAT4/) | HMI with matrix keypad, LEDs and seven-segment display | Keypad scanning, debouncing, seven-segment codes, mode flags | [`TASK4A`](8051/CAT4/TASK4A/) |
| [Cat 5](8051/CAT5/) | Hardware timer-based LED blinking | Timer 0 mode 1, reload value, interrupt service routine | [`TASK5A`](8051/CAT5/TASK5A/) |
| [Cat 6](8051/CAT6/) | UART driver and serial debugging | `SCON` / `TMOD`, Timer 1 baud-rate generation, `TI` / `RI` flags, echo | [`TASK6A`](8051/CAT6/TASK6A/), [`TASK6B`](8051/CAT6/TASK6B/) |
| [Cat 7](8051/CAT7/) | 16×2 LCD driver and dynamic display control | HD44780 4-bit interface, DDRAM addressing, keypad scanning | [`TASK7A`](8051/CAT7/TASK7A/), [`TASK7B`](8051/CAT7/TASK7B/), [`TASK7C`](8051/CAT7/TASK7C/) |

### STM32 – STM32CubeMX + HAL, Keil MDK-ARM / STM32CubeIDE

| # | Experiment | Board | Key concepts | Tasks |
|---|---|---|---|---|
| [Cat 8](STM32/CAT8/) | GPIO bring-up and switch-controlled LED | Blue Pill (STM32F103C8) | GPIO input/output, pull-ups, debouncing | [`TASK8A`](STM32/CAT8/TASK8A/), [`TASK8B`](STM32/CAT8/TASK8B/), [`TASK8C`](STM32/CAT8/TASK8C/) |
| [Cat 9](STM32/CAT9/) | UART command-controlled LED | Blue Pill (STM32F103C8) | USART with HAL, echo, command parsing | [`TASK9A`](STM32/CAT9/TASK9A/), [`TASK9B`](STM32/CAT9/TASK9B/) |
| [Cat 10](STM32/CAT10/) | STM32–Wemos (ESP8266) Wi-Fi modem interface using AT commands | Blue Pill (STM32F103C8) | Two UARTs, ESP8266 AT commands, station mode, joining Wi-Fi | [`TASK10A`](STM32/CAT10/TASK10A/), [`TASK10B`](STM32/CAT10/TASK10B/), [`TASK10C`](STM32/CAT10/TASK10C/) |
| [Cat 11](STM32/CAT11/) | HTTP server on the STM32–Wemos Wi-Fi modem | Blue Pill | TCP server over AT commands, `+IPD` requests, HTTP response | [`TASK11A`](STM32/CAT11/TASK11A/), [`TASK11B`](STM32/CAT11/TASK11B/), [`TASK11C`](STM32/CAT11/TASK11C/) |
| [Cat 12](STM32/CAT12/) | Cortex-M4 GPIO and user input | NUCLEO-F401RE | F4 clock tree, on-board LED/button, short/long press | [`TASK12A`](STM32/CAT12/TASK12A/), [`TASK12B`](STM32/CAT12/TASK12B/), [`TASK12C`](STM32/CAT12/TASK12C/) |
| [Cat 13](STM32/CAT13/) | BME280 over I²C with the Bosch Sensor API | NUCLEO-F401RE | I²C, Bosch Sensor API, UART output, HTTP response | [`TASK13A`](STM32/CAT13/TASK13A/), [`TASK13B`](STM32/CAT13/TASK13B/), [`TASK13C`](STM32/CAT13/TASK13C/) |
| [Cat 14](STM32/CAT14/) | MQTT publishing of BME280 data | NUCLEO-F401RE | MQTT CONNECT/PUBLISH packets, public broker, custom ESP8266 API | [`TASK14`](STM32/CAT14/TASK14/) |
| [Cat 15](STM32/CAT15/) | IoT project: server rack monitor | Blue Pill (STM32F103C6) | DHT11 single-wire timing, MQTT publishing, local LED/buzzer alarm, Node-RED dashboard | [`TASK15`](STM32/CAT15/TASK15/) |

## Hardware

| Hardware | Used in | Notes |
|---|---|---|
| AT89S52 development kit | Cat 2 – Cat 7 | On-board LEDs, matrix keypad, seven-segment display and 16×2 LCD; programmed over ISP |
| STM32 Blue Pill (STM32F103C8 / C6) | Cat 8 – Cat 11, Cat 15 | Programmed with an ST-Link over SWD |
| NUCLEO-F401RE (STM32F401RE) | Cat 12 – Cat 14 | On-board ST-LINK |
| Wemos D1 Mini (ESP8266) | Cat 10 – Cat 15 | Wi-Fi modem running AT-command firmware |
| I²C sensor module | Cat 13 | Connected to the STM32 over I²C |
| DHT11 module, LED, buzzer | Cat 15 | Rack temperature/humidity sensor (single-wire) and local alarm |
| USB-to-TTL serial converter | Cat 6, Cat 9 – Cat 11 | PC terminal (PuTTY / Tera Term) |

## Tools

| Tool | Used for |
|---|---|
| **Keil µVision 5** with the C51 compiler | 8051 projects (`.uvproj`) |
| **STM32CubeMX** | STM32 pin, clock and peripheral configuration (`.ioc`) and code generation |
| **Keil MDK-ARM** / **STM32CubeIDE** | Building and flashing the STM32 projects |
| STM32Cube HAL | STM32 peripheral drivers (in each project's `Drivers/` folder) |
| Proteus | 8051 circuit simulation |
| Node-RED + Dashboard | MQTT dashboard and flows (Cat 15, `flows.json`) |
| MQTT broker (broker.emqx.io) | Public broker used in Cat 14 and Cat 15 |
| PuTTY / Tera Term | Serial terminal |

## Repository Layout

```
<platform>/CATn/
├── README.md                 experiment index: details, date, overview, circuit, task table
├── circuit.png               circuit diagram
└── TASKnX/                   one folder per task
    ├── README.md             task details: hardware, logic, pseudocode, code, inference
    ├── 8051:  *.c, *.uvproj, STARTUP.A51, Objects/*.hex
    └── STM32: *.ioc, Core/, Drivers/, MDK-ARM/*.uvprojx
```

Build output is not committed (see [.gitignore](.gitignore)): Keil's `Listings/` and the rest of `Objects/`, STM32CubeIDE's `Debug/` and `Release/`, and per-user IDE files. The 8051 projects keep their `.hex` file so they can be flashed without rebuilding.

## Building

**8051 (Keil µVision):** open the experiment's `.uvproj` file and choose **Project → Build Target (F7)**. The HEX file is written to the project's `Objects/` folder. Flash it to the AT89S52 with an ISP programmer.

**STM32 (STM32CubeIDE):** choose **File → Import → General → Existing Projects into Workspace**, select the project folder, then **Project → Build Project**. Flash and debug with **Run → Debug** through the ST-Link. For the Wi-Fi experiments (Cat 10 – Cat 15), set your own Wi-Fi network name and password in `main.c` first.
