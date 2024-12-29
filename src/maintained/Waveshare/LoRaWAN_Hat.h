#if !defined(_RADIOBOARDS_MAINTAINED_WAVESHARE_LORAWAN_HAT_H)
#define _RADIOBOARDS_MAINTAINED_WAVESHARE_LORAWAN_HAT_H

// sources:
// https://www.waveshare.com/wiki/SX1262_XXXM_LoRaWAN/GNSS_HAT

#define RADIO_BOARDS_NAME "Waveshare LoRaWAN Hat"

#define RADIO_NSS     (21)
#define RADIO_IRQ     (16)
#define RADIO_RST     (18)
#define RADIO_GPIO    (20)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1262

#endif

#endif
