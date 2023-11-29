/*
  IR Remote Emulator - Sending
  ir-remote-send.ino
  Emulates three buttons of remote control
  Uses TinySender Library packaged with Arduino-IRremote Library
  -- https://github.com/Arduino-IRremote/Arduino-IRremote --
  Uses pin-change interrupts for pushbuttons
  Use SimpleReceiver example to determine button codes
  
  DroneBot Workshop 2023
  https://dronebotworkshop.com
*/

// Include required libraries
#include <Arduino.h>
#include "TinyIRSender.hpp"

// Define IR LED pin
#define IR_SEND_PIN 3

// Define the pins for the buttons
const byte buttonPin1 = 10;
const byte buttonPin2 = 9;
const byte buttonPin3 = 8;

// Button code variables (change to match your remote control)
uint16_t codePower = 0x0A;
uint16_t codeMinus = 0x09;
uint16_t codePlus = 0x0B;

// Variables to hold complete send parameters
uint16_t sAddress = 0x00;
volatile uint16_t sCommand = 0x0A;
uint16_t sRepeats = 0;

// Button presed flag
volatile bool buttonPressed = false;

// Button pin-change service routine
ISR(PCINT0_vect) {
  // Port B Interrupt occured

  // Only run if buttonPressed is false, as a debounce technique
  if (!buttonPressed) {

    // Check if this was D10 (button 1)
    if (digitalRead(buttonPin1) == LOW) {
      //Pin D10 triggered the ISR on a Falling pulse
      sCommand = codePower;
    }
    // Check if this was D9 (button 2)
    if (digitalRead(buttonPin2) == LOW) {
      //Pin D9 triggered the ISR on a Falling pulse
      sCommand = codeMinus;
    }
    // Check if this was D8 (button 3)
    if (digitalRead(buttonPin3) == LOW) {
      //Pin D8 triggered the ISR on a Falling pulse
      sCommand = codePlus;
    }

    // Change button pressed flag
    buttonPressed = true;
  }
}

void setup() {

  // Serial monitor
  Serial.begin(115200);

  // Set switches as inputs with pullups
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  // Built-in LED setup for IR library
  pinMode(LED_BUILTIN, OUTPUT);

  // Setup pin-change interrupt masks for port B (pins 8 - 13)
  // Enable PCIE0 Bit0 = 1 (Port B)
  PCICR |= B00000001;
  // Enable PCINT0, PCINT1 & PCINT23 (Pins D8, D9 & D10)
  PCMSK0 |= B00000111;
}

void loop() {
  // See if a button has been pressed
  if (buttonPressed) {
    // Send IR code
    sendNEC(IR_SEND_PIN, sAddress, sCommand, sRepeats);
    // Print to serial monitor
    Serial.print("Sent command ");
    Serial.println(sCommand, HEX);
    // Short delay to debounce
    delay(100);
    // Reset the flag
    buttonPressed = false;
  }
  // Another short delay
  delay(100);
}