#if !defined(_RADIOBOARDS_MAINTAINED_LILYGO_TTGO_T_BEAM_H)
#define _RADIOBOARDS_MAINTAINED_LILYGO_TTGO_T_BEAM_H

// sources:

#define RADIO_BOARDS_NAME "LilyGo TTGO T-Beam"

#define RADIO_NSS     (18)
#define RADIO_IRQ     (26)
#define RADIO_RST     (23)
#define RADIO_GPIO    (33)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1276
#endif

#endif
