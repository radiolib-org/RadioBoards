#if !defined(_RADIOBOARDS_MAINTAINED_HELTEC_HT_CT62_H)
#define _RADIOBOARDS_MAINTAINED_HELTEC_HT_CT62_H

// sources:
// https://resource.heltec.cn/download/HT-CT62/HT-CT62(Rev1.1).pdf

// warning: this board cannot be selected, so you must define 
// RADIO_BOARD_HT_CT62 yourself instead of RADIO_BOARD_AUTO

#define RADIO_BOARDS_NAME "Heltec HT-CT62"

#define RADIO_NSS     (8)
#define RADIO_IRQ     (3)
#define RADIO_RST     (5)
#define RADIO_GPIO    (4)

// there is no default selector for this board, so add custom SPI
#define RADIO_SPI     SPI
#define RADIO_MISO    (6)
#define RADIO_MOSI    (7)
#define RADIO_SCK     (10)

#define RADIO_SPI_INIT                                      \
  RADIO_SPI.begin(RADIO_SCK, RADIO_MISO, RADIO_MOSI);

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1262
#endif

#endif
