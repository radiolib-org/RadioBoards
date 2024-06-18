#if !defined(_RADIOBOARDS_H)
#define _RADIOBOARDS_H

// try to resolve the board automatically
#if defined(RADIO_BOARD_AUTO)
  // maintained boards
  #if defined(NRF52840_XXAA) && defined(LR11XX)
    #define RADIO_BOARD_WM1110
  
  #elif defined(ARDUINO_SAMD_FEATHER_M0)
    #define RADIO_BOARD_FEATHER_M0

  #elif defined(ARDUINO_HELTEC_WIFI_LORA_32)
    #define RADIO_BOARD_WIFI_LORA32

  #elif defined(ARDUINO_heltec_wifi_lora_32_V2)
    #define RADIO_BOARD_WIFI_LORA32_V2

  #elif defined(ARDUINO_heltec_wifi_lora_32_V3)
    #define RADIO_BOARD_WIFI_LORA32_V3
  
  #elif defined(ARDUINO_TTGO_LORA32_V1) || defined(ARDUINO_TTGO_LoRa32_v21new)
    #define RADIO_BOARD_TTGO_LORA32_V1_V21

  #elif defined(ARDUINO_TTGO_LORA32_V2)
    #define RADIO_BOARD_TTGO_LORA32_V2

  #elif defined(ARDUINO_TBEAM_USE_RADIO_SX1276)
    #define RADIO_BOARD_TTGO_T_BEAM
  
  // contributed boards
  #elif defined(ARDUINO_ARCH_MBED_RP2040) || defined(ARDUINO_ARCH_RP2040)
    #define RADIO_BOARD_RASPBERRYPI_PICO

  #else
    #error "Unable to resolve board type automatically, please select one from the supported list"

  #endif

#endif

// check RadioLib support
#if defined(_RADIOLIB_H)
  #define RADIOLIB_SUPPORT_ENABLED  (1)
#endif

// select the appropriate header
// maintained boards
#if defined(RADIO_BOARD_WM1110)
  #include "maintained/SeeedStudio/WM1110.h"

#elif defined(RADIO_BOARD_FEATHER_M0)
  #include "maintained/Adafruit/Feather_M0.h"

#elif defined(RADIO_BOARD_WIFI_LORA32)
  #include "maintained/Heltec/WiFi_LoRa32.h"

#elif defined(RADIO_BOARD_WIFI_LORA32_V2)
  #include "maintained/Heltec/WiFi_LoRa32_v2.h"

#elif defined(RADIO_BOARD_WIFI_LORA32_V3)
  #include "maintained/Heltec/WiFi_LoRa32_v3.h"

#elif defined(RADIO_BOARD_TTGO_LORA32_V1_V21)
  #include "maintained/LilyGo/TTGO_LoRa32_v1_v21.h"

#elif defined(RADIO_BOARD_TTGO_LORA32_V2)
  #include "maintained/LilyGo/TTGO_LoRa32_v2.h"

#elif defined(RADIO_BOARD_TTGO_LORA32_V21)
  #include "maintained/LilyGo/TTGO_LoRa32_v21.h"

#elif defined(RADIO_BOARD_TTGO_T_BEAM)
  #include "maintained/LilyGo/TTGO_TBeam.h"

// contributed boards
#elif defined(RADIO_BOARD_RASPBERRYPI_PICO)
  #include "contributed/RaspberryPi/PI_PICO.h"

#else
  #error "Unsupported or unknown radio board!"

#endif

#if RADIO_BOARDS_DEBUG
  #pragma message "RadioBoards using board: " RADIO_BOARDS_NAME
#endif

// setup SPI
#if defined(RADIO_SPI)
  #define RadioBeginSPI()  RADIO_SPI_INIT
#else
  #define RadioBeginSPI()  {}
#endif

// setup RadioLib stuff
#if RADIOLIB_SUPPORT_ENABLED
  // Module constructor
  #if defined(RADIO_SPI)
    #define RadioModule() Module(RADIO_NSS, RADIO_IRQ, RADIO_RST, RADIO_GPIO, RADIO_SPI)
  #else
    #define RadioModule() Module(RADIO_NSS, RADIO_IRQ, RADIO_RST, RADIO_GPIO)
  #endif

  // RF switching
  #if defined(RADIO_RF_SWITCH)
    RADIO_RF_SWITCH_PINS;
    RADIO_RF_SWITCH_TABLE;
    #define RadioEnableRfSwitch(radio)    radio.setRfSwitchTable(RadioBoards_rfswitch_pins, RadioBoards_rfswitch_table)
  #else
    #define RadioEnableRfSwitch(radio)    {}
  #endif

#endif

#endif
