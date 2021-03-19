/*
  Aidan Quimby
  ECE 387
  3/18/2021
  Midterm Presentation 1
*/

#include <RH_ASK.h>
#include <SPI.h>

// Instance of RadioHead amplitude shift-keying
RH_ASK driver;

// String to compare message to, not currently implemented
String sentMsg;

// Method to print ASCII text of message to Serial monitor
void printASCII(const uint8_t* buf, uint8_t buflen) {
  uint8_t i;
  sentMsg = "";
  for (i = 0; i < buflen; i++) {
    Serial.write(buf[i]);
    // Forms string from decimal values received and stores in sentMsg
    sentMsg = sentMsg + char(buf[i]);
  }
  Serial.println("");
}

void setup() {
  Serial.begin(9600);
  if (!driver.init())
    Serial.println("init failed");
}

void loop() {
  // Data storage of message
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  // Data received, called method to print
  if (driver.recv(buf, &buflen))
    printASCII(buf, buflen);
}
