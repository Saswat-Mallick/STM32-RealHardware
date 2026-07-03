# STM32F103C8 Embedded Systems Learning Lab

A hands-on collection of embedded systems experiments built on the **STM32F103C8 (Blue Pill)** microcontroller, developed using the **Arduino Framework**. Every project in this repository has been written with the assistance of Claude AI, then physically implemented, wired, tested, and verified on real hardware.

## About This Repository

This repository serves as a practical learning journal for embedded systems development. Rather than being a purely theoretical exercise, every experiment listed here has been:

- **Physically built** — corresponding hardware circuits were designed and assembled for each experiment
- **Functionally verified** — each program was flashed to the STM32F103C8 and confirmed to produce the desired output
- **Debugged and refined** — errors encountered during implementation were diagnosed and resolved, reinforcing core embedded systems concepts along the way

The goal is to build a solid foundation in microcontroller programming, peripheral interfacing, and hardware-software integration through direct, verified experimentation.

## Hardware & Software Specifications

| Component | Detail |
|---|---|
| Microcontroller | STM32F103C8 (Generic "Blue Pill" board) |
| Framework | Arduino Framework |
| Serial Baud Rate | 9600 bps (for all serial communication projects) |
| Upload Protocol | STLink |

## Experiments

| # | Experiment | Description |
|---|---|---|
| 01 | Blink-LED | Simple Blinking of onboard LED of STM32 (PC13 port)  |
| 02 | RBG-LED | A setup for knowing the possibilities about how RGB Led can be used in different ways |
| 03 | Interrupts on Real Hardware | Simple Button detection experiment with a onboard led glow |
| 04 | Buzzer Melody | A failed attempt to play rickroll but a successful attempt to make a buzzer work |
| 05 | UART Experiment via CP2102 | It is a experiment where I tried to install serial data converter to my setup (the led glows in CP2102 indicating serial in out is working) |
| 06 | UART Experiment debouncing | It is a more catchy experiment than the previous one. A button enables serial data in and out from the microcontroller to the PC (clearly visible in Serial Monitor) |
| 07 | Serial Monitor | It is experiment to check the whether Serial Monitor is working or not |
| 08 | DHT11 sensor experiment | A sensor is used to know about surrounding Temp and humidity (visible in serial monitor) |
| 09 | OLED Experiment | This experiment explains how to use the Oled board and possibilities of how we can use it |

## How to Use This Repository

1. Clone the repository to your local machine.
2. Open the desired experiment folder and load the `.ino` file using the Arduino IDE (with STM32 board support installed) or PlatformIO.
3. Wire the corresponding hardware circuit as described in the experiment's comments/documentation.
4. Flash the code to the STM32F103C8 board.
5. Observe the output and refer to the code comments for an explanation of each step.

## Learning Outcomes

Working through these experiments has provided practical experience in:

- Reading, understanding, and modifying microcontroller code
- Mapping code logic to physical hardware connections
- Diagnosing and resolving hardware-software integration issues
- Building confidence in embedded systems fundamentals through iterative, verified experimentation

## Disclaimer

The code in this repository was generated with the assistance of Claude AI. All code has been independently tested and verified on physical STM32F103C8 hardware to confirm correct functionality.
