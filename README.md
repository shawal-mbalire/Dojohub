# Dojohub

AVR microcontroller projects using bare-metal C programming and Arduino.

## Projects

9 projects covering:
- LED blinking with direct port manipulation
- GPIO input/output control
- IR remote signal sending
- Direct register access on ATmega chips

## Tech Stack

- C (AVR-GCC)
- Arduino (.ino)
- AVR libc
- avrdude

## Prerequisites

```bash
# Arch Linux
sudo pacman -S avr-libc avrdude gcc-avr binutils-avr
```

## Build & Upload

```bash
# Arduino
arduino-cli compile --fqbn arduino:avr:mega project1/
arduino-cli upload --fqbn arduino:avr:mega project1/

# Bare metal C
avr-gcc -mmcu=atmega2560 -Os -o output.elf project1.c
```
