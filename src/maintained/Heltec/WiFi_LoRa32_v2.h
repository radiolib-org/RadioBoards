#if !defined(_RADIOBOARDS_MAINTAINED_HELTEC_WIFI_LORA32_V2_H)
#define _RADIOBOARDS_MAINTAINED_HELTEC_WIFI_LORA32_V2_H

// sources:
// https://github.com/espressif/arduino-esp32/blob/master/variants/heltec_*/pins_arduino.h

#define RADIO_BOARDS_NAME "Heltec WiFi LoRa32 v2"

#define RADIO_NSS     (14)
#define RADIO_IRQ     (4)
#define RADIO_RST     (12)
#define RADIO_GPIO    (16)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1278
#endif

#endif
