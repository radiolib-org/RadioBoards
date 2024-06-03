/*
  Custom SPI module example.

  This example shows how to set up a board with
  non-default SPI pins and custom RF switching.

  The board used as example here is SeeedStudio
  Wio Tracker 1110 Dev Board, which uses the
  LR1110 LoRa radio module. It does not use the
  default SPI pins, and it also has an RF switch.

  This example assumes RadioLib is being used
  as the radio driver:
  https://github.com/jgromes/RadioLib
*/

// include RadioLib
#include <RadioLib.h>

// instead of defining RADIO_BOARD_AUTO,
// board can be specified manually
#define RADIO_BOARD_WM1110

// now include RadioBoards
// this must be included AFTER RadioLib!
#include <RadioBoards.h>

// create a new RadioLib module
// "Radio" will be set to the correct module type,
// and "RadioModule" will have the correct pins
Radio radio = new RadioModule();

void setup() {
  Serial.begin(9600);

  // start SPI on the appropriate pins,
  // configure and enable RF switching
  // both of these have to be called before radio.begin()!
  RadioBeginSPI();
  RadioEnableRfSwitch(radio);

  // initialize the radio
  Serial.print(F("[Radio] Initializing ... "));
  int state = radio.begin();
  if (state == RADIOLIB_ERR_NONE) {
    Serial.println(F("success!"));
  } else {
    Serial.print(F("failed, code "));
    Serial.println(state);
    while (true);
  }
}

void loop() {
  // whatever else here - transmitting, receiving etc.
}
