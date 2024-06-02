#if !defined(_RADIOBOARDS_CONTRIBUTED_SEMTECH_LR1100_H)
#define _RADIOBOARDS_CONTRIBUTED_SEMTECH_LR1100_H

// sources:
// K4KDR hands-on testing w/ this hardware

#define RADIO_BOARDS_NAME "Semtech LR1110"  // ** pin #'s when used w/ vendor recommended MCU: Nucleo L476RG

#define RADIO_NSS     (D7)
#define RADIO_IRQ     (D5)
#define RADIO_RST     (A0)
#define RADIO_GPIO    (D3)

// this board does NOT use custom SPI to interface with the module
// #define RADIO_SPI     SPI
// #define RADIO_MISO    (xx)
// #define RADIO_MOSI    (xx)
// #define RADIO_SCK     (xx)

// #define RADIO_SPI_INIT                                      \
//   RADIO_SPI.setPins(RADIO_MISO, RADIO_SCK, RADIO_MOSI);     \
//   RADIO_SPI.begin();

// it also does NOT have custom RF switching
// #if RADIOLIB_SUPPORT_ENABLED
//   #define RADIO_RF_SWITCH

/*  #define RADIO_RF_SWITCH_PINS                            \
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

#endif */
