#if !defined(_RADIOBOARDS_H)
#define _RADIOBOARDS_H

// try to resolve the board automatically
#if defined(RADIO_BOARD_AUTO)
  #if defined(NRF52840_XXAA) && defined(LR11XX)
    #define RADIO_BOARD_WM1110

  #elif defined(ARDUINO_HELTEC_WIFI_LORA_32)
    #define RADIO_BOARD_WIFI_LORA32

  #elif defined(NUCLEO_L476RG_SEMTECH_LR1110)
    #define RADIO_BOARD_NUCLEO_L476RG_SEMTECH_LR1110

  #else
    #error "Unable to resolve board type automatically, please select one from the supported list"

  #endif

#endif

// check RadioLib support
#if defined(_RADIOLIB_H)
  #define RADIOLIB_SUPPORT_ENABLED  (1)
#endif

// select the appropriate header
#if defined(RADIO_BOARD_WM1110)
  #include "maintained/SeeedStudio/WM1110.h"
#elif defined(RADIO_BOARD_WIFI_LORA32)
  #include "maintained/Heltec/WiFi_LoRa32.h"
#elif defined(RADIO_BOARD_NUCLEO_L476RG_SEMTECH_LR1110)
  #include "contributed/Semtech/LR1110.h"  

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
