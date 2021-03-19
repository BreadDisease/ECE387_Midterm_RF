/*
  Aidan Quimby
  ECE 387
  3/18/2021
  Midterm Presentation 1
*/

#include <RH_ASK.h>
#include <SPI.h>

// Button pin to send message
const int btnPin = 8;

// Text to transmit wirelessly
const char *msg = "According to all known laws of aviation";

// Instance of RadioHead amplitude shift-keying
RH_ASK driver;

// Variable to store the button's state in
int btnState;

// Method to transmit message wirelessly
void sendMessage() {
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);
}

void setup() {
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");
  pinMode(btnPin, INPUT_PULLUP);
}

void loop() {
  // Read button state into btnState
  btnState = digitalRead(btnPin);

  // If the button is pressed then send message 
  if (btnState == 0)
    sendMessage();
}
