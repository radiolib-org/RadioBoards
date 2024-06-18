#if !defined(_RADIOBOARDS_MAINTAINED_LILYGO_TTGO_LORA32_V1_H)
#define _RADIOBOARDS_MAINTAINED_LILYGO_TTGO_LORA32_V1_H

// sources:

#define RADIO_BOARDS_NAME "LilyGo TTGO LoRa32 v1/v2.1"

#define RADIO_NSS     (18)
#define RADIO_IRQ     (26)
#define RADIO_RST     (14)
#define RADIO_GPIO    (33)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1276
#endif

#endif
