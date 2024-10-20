#if !defined(_RADIOBOARDS_MAINTAINED_HELTEC_CUBECELL_H)
#define _RADIOBOARDS_MAINTAINED_HELTEC_CUBECELL_H

// sources:
// https://resource.heltec.cn/download/HT-CT62/HT-CT62(Rev1.1).pdf

// warning: this board cannot be selected, so you must define 
// RADIO_BOARD_HT_CT62 yourself instead of RADIO_BOARD_AUTO

#define RADIO_BOARDS_NAME "Heltec CubeCell"

#include "board-config.h"

//#define RADIO_NSS     (RADIO_NSS) // CubeCell actually uses the same macro name here
#define RADIO_IRQ     (RADIO_DIO_1)
#define RADIO_RST     (RADIO_RESET)
#define RADIO_GPIO    (RADIO_BUSY)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1262
#endif

#endif
