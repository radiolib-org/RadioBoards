#if !defined(_RADIOBOARDS_MAINTAINED_SEEEDSTUDIO_WM1110_H)
#define _RADIOBOARDS_MAINTAINED_SEEEDSTUDIO_WM1110_H

// sources:
// https://github.com/SeeedJP/LBM_WM1110/blob/8adaddb00ccd59f37ed083c9990561ebd7883f38/src/internal/Wm1110Hardware.hpp
// https://github.com/Seeed-Studio/Adafruit_nRF52_Arduino/blob/5aa3573913449410fd60f76b75673c53855ff2ec/variants/Seeed_Wio_Tracker_1110/variant.h

#define RADIO_BOARDS_NAME "SeeedStudio WM1110"

#define RADIO_NSS     (44)
#define RADIO_IRQ     (2)
#define RADIO_RST     (42)
#define RADIO_GPIO    (43)

// this board uses custom SPI to interface with the module
#define RADIO_SPI     SPI
#define RADIO_MISO    (47)
#define RADIO_MOSI    (46)
#define RADIO_SCK     (45)

#define RADIO_SPI_INIT                                      \
  RADIO_SPI.setPins(RADIO_MISO, RADIO_SCK, RADIO_MOSI);     \
  RADIO_SPI.begin();

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       LR1110

  // it also has custom RF switching
  #define RADIO_RF_SWITCH

  #define RADIO_RF_SWITCH_PINS                              \
    static const uint32_t RadioBoards_rfswitch_pins[] = {   \
    RADIOLIB_LR11X0_DIO5, RADIOLIB_LR11X0_DIO6,             \
    RADIOLIB_NC, RADIOLIB_NC, RADIOLIB_NC                   \
  };

  #define RADIO_RF_SWITCH_TABLE \
  static const Module::RfSwitchMode_t RadioBoards_rfswitch_table[] = {  \
    /* mode                  DIO5  DIO6 */                  \
    { LR11x0::MODE_STBY,   { LOW,  LOW  } },                \
    { LR11x0::MODE_RX,     { HIGH, LOW  } },                \
    { LR11x0::MODE_TX,     { HIGH, HIGH } },                \
    { LR11x0::MODE_TX_HP,  { LOW,  HIGH } },                \
    { LR11x0::MODE_TX_HF,  { LOW,  LOW  } },                \
    { LR11x0::MODE_GNSS,   { LOW,  LOW  } },                \
    { LR11x0::MODE_WIFI,   { LOW,  LOW  } },                \
    END_OF_MODE_TABLE,                                      \
  };

#endif

#endif
