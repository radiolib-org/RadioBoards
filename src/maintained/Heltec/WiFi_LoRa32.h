#if !defined(_RADIOBOARDS_MAINTAINED_HELTEC_WIFI_LORA32_H)
#define _RADIOBOARDS_MAINTAINED_HELTEC_WIFI_LORA32_H

// sources:
// https://github.com/espressif/arduino-esp32/blob/master/variants/heltec_*/pins_arduino.h

#define RADIO_BOARDS_NAME "Heltec WiFi LoRa32"

#define RADIO_NSS     (18)
#define RADIO_IRQ     (26)
#define RADIO_RST     (14)
#define RADIO_GPIO    (33)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1276
#endif

#endif
