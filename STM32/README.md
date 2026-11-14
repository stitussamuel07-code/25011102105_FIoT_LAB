# STM32 Experiments

Platform: STM32CubeMX + STM32 HAL · Keil MDK-ARM / STM32CubeIDE · flashed with an ST-Link

| # | Experiment | Board | Tasks |
|---|---|---|---|
| [Cat 8](CAT8/) | STM32 GPIO Bring-Up and Switch-Controlled LED | Blue Pill (STM32F103C8) | [`TASK8A`](CAT8/TASK8A/) · [`TASK8B`](CAT8/TASK8B/) · [`TASK8C`](CAT8/TASK8C/) |
| [Cat 9](CAT9/) | STM32 UART Command Controlled LED | Blue Pill (STM32F103C8) | [`TASK9A`](CAT9/TASK9A/) · [`TASK9B`](CAT9/TASK9B/) |
| [Cat 10](CAT10/) | STM32–Wemos Wi-Fi Modem Interface Using AT Commands | Blue Pill (STM32F103C8) | [`TASK10A`](CAT10/TASK10A/) · [`TASK10B`](CAT10/TASK10B/) · [`TASK10C`](CAT10/TASK10C/) |
| [Cat 11](CAT11/) | HTTP Server – STM32–Wemos Wi-Fi Modem Using AT Commands | Blue Pill | [`TASK11A`](CAT11/TASK11A/) · [`TASK11B`](CAT11/TASK11B/) · [`TASK11C`](CAT11/TASK11C/) |
| [Cat 12](CAT12/) | STM32F401RE Cortex-M4: GPIO and User Input Programming | NUCLEO-F401RE | [`TASK12A`](CAT12/TASK12A/) · [`TASK12B`](CAT12/TASK12B/) · [`TASK12C`](CAT12/TASK12C/) |
| [Cat 13](CAT13/) | BME280 Sensor Interfacing Using I²C and Bosch Sensor API | NUCLEO-F401RE | [`TASK13A`](CAT13/TASK13A/) · [`TASK13B`](CAT13/TASK13B/) · [`TASK13C`](CAT13/TASK13C/) |
| [Cat 14](CAT14/) | BME280 over I²C with MQTT using a custom-built ESP8266 API | NUCLEO-F401RE | [`TASK14`](CAT14/TASK14/) |
| [Cat 15](CAT15/) | Server Rack Monitor – STM32, DHT11, ESP8266 (MQTT) and Node-RED Dashboard | Blue Pill (STM32F103C6) | [`TASK15`](CAT15/TASK15/) |

Each `CATn/` folder has a `README.md` with the experiment details, overview, circuit diagram and task table, plus `circuit.png`. Each `TASKnX/` folder has the CubeMX / Keil / CubeIDE project (`.ioc`, `Core/`, `Drivers/`, `MDK-ARM/`) and its own `README.md`.
