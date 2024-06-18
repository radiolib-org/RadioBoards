#if !defined(_RADIOBOARDS_MAINTAINED_LILYGO_TTGO_LORA32_V2_H)
#define _RADIOBOARDS_MAINTAINED_LILYGO_TTGO_LORA32_V2_H

// sources:

#define RADIO_BOARDS_NAME "LilyGo TTGO LoRa32 v2"

#define RADIO_NSS     (18)
#define RADIO_IRQ     (26)
#define RADIO_RST     (12)
#define RADIO_GPIO    (RADIOLIB_NC)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1276
#endif

#endif
