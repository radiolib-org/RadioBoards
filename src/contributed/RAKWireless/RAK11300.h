#if !defined(_RADIOBOARDS_CONTRIBUTED_RAK11300_H)
#define _RADIOBOARDS_CONTRIBUTED_RAK11300_H

// Pin definitions taken from:
//    RAK definition: https://github.com/RAKWireless/RAK-RP-Arduino/
//    RAK datasheet: https://docs.rakwireless.com/Product-Categories/WisDuo/RAK11300-Module/Datasheet/#overview
//    Internal wiring of SX1262 module: https://forum.rakwireless.com/t/rak11300-pinout-rp2040-to-sx1262/8414/
//    Arduino-Pico: https://github.com/earlephilhower/arduino-pico/blob/5bd1a3a0f6f4df55053daf2c13c853f233501c81/variants/rakwireless_rak11300/pins_arduino.h#L6
// Based on: https://www.nico-maas.de/?p=2607

#define RADIO_BOARDS_NAME "RAKWireless RAK11300"

#define RADIO_NSS     (PIN_SPI1_SS)
#define RADIO_IRQ     (PIN_SX1262_DIO1)
#define RADIO_RST     (PIN_SX1262_NRESET)
#define RADIO_GPIO    (PIN_SX1262_BUSY)

// this board uses custom SPI to interface with the module
// SPI pins are configured in Arduino-Pico
#define RADIO_SPI     SPI1

#define RADIO_PIN_SX1262_ANT_PWR PIN_SX1262_ANT_PWR

#define RADIO_SPI_INIT                                      \
  RADIO_SPI.begin(RADIO_NSS);

#endif


#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1262

  // it also has custom RF switching
  #define RADIO_RF_SWITCH

  #define RADIO_RF_SWITCH_PINS                              \
  static const uint32_t RadioBoards_rfswitch_pins[] = {     \
      RADIO_PIN_SX1262_ANT_PWR,                             \
      RADIOLIB_NC, RADIOLIB_NC, RADIOLIB_NC, RADIOLIB_NC    \
    };

  #define RADIO_RF_SWITCH_TABLE \
  static const Module::RfSwitchMode_t RadioBoards_rfswitch_table[] = {  \
    /* mode              ANT_PWR */                         \
    {Module::MODE_IDLE,  {LOW}},                            \
    {Module::MODE_RX,    {HIGH}},                           \
    {Module::MODE_TX,    {HIGH}},                           \
    END_OF_MODE_TABLE,                                      \
  };
#endif