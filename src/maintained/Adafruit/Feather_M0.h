#if !defined(_RADIOBOARDS_MAINTAINED_ADAFRUIT_FEATHER_M0_H)
#define _RADIOBOARDS_MAINTAINED_ADAFRUIT_FEATHER_M0_H

// sources:
// https://learn.adafruit.com/adafruit-feather-m0-radio-with-lora-radio-module/downloads

#define RADIO_BOARDS_NAME "Adafruit Feather M0 LoRa"

#define RADIO_NSS     (8)
#define RADIO_IRQ     (3)
#define RADIO_RST     (4)
#define RADIO_GPIO    (RADIOLIB_NC)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1276
#endif

#endif
