#if !defined(RADIOBOARDS_MAINTAINED_RADIOHAT_REV_E_H)
#define RADIOBOARDS_MAINTAINED_RADIOHAT_REV_E_H

// sources:
// https://github.com/radiolib-org/RadioHAT

// warning: this board cannot be selected, so you must define 
// RADIO_BOARD_RADIOHAT_REV_E yourself instead of RADIO_BOARD_AUTO

#define RADIO_BOARDS_NAME "RadioHAT Rev. E"

#define RADIOHAT_IRQ0     (16)
#define RADIOHAT_RST0     (18)
#define RADIOHAT_GPIO0    (20)
#define RADIOHAT_IRQ1     (24)
#define RADIOHAT_RST1     (25)
#define RADIOHAT_GPIO1    (23)

// chip select is controlled by the SPI channel selection (0 for CE0, 1 for CE1)
#define RADIO_NSS         (RADIOLIB_NC)
#define RADIO_IRQ         (RADIOHAT_IRQ0)
#define RADIO_RST         (RADIOHAT_RST0)
#define RADIO_GPIO        (RADIOHAT_GPIO0)

// extra pins for some modules
#define RADIOHAT_GNICERF_SX1280_TCXOEN    (RADIOHAT_GPIO1)

#if RADIOLIB_SUPPORT_ENABLED

// G-Nice RF LR1120 switch
#define RADIO_RF_SWITCH_PINS                              \
  static const uint32_t RadioBoards_rfswitch_pins[] = {   \
  RADIOLIB_LR11X0_DIO5, RADIOLIB_LR11X0_DIO6,             \
  RADIOLIB_LR11X0_DIO7, RADIOLIB_NC, RADIOLIB_NC          \
};

#define RADIO_RF_SWITCH_TABLE \
static const Module::RfSwitchMode_t RadioBoards_rfswitch_table[] = {                       \
  /* mode                  DIO5                DIO6                DIO7 */                 \
  { LR11x0::MODE_STBY,   { hal->GpioLevelLow,  hal->GpioLevelLow,  hal->GpioLevelLow  } }, \
  { LR11x0::MODE_RX,     { hal->GpioLevelHigh, hal->GpioLevelLow,  hal->GpioLevelLow  } }, \
  { LR11x0::MODE_TX,     { hal->GpioLevelLow,  hal->GpioLevelHigh, hal->GpioLevelLow  } }, \
  { LR11x0::MODE_TX_HP,  { hal->GpioLevelLow,  hal->GpioLevelHigh, hal->GpioLevelLow  } }, \
  { LR11x0::MODE_TX_HF,  { hal->GpioLevelLow,  hal->GpioLevelLow,  hal->GpioLevelLow  } }, \
  { LR11x0::MODE_GNSS,   { hal->GpioLevelLow,  hal->GpioLevelLow,  hal->GpioLevelHigh } }, \
  { LR11x0::MODE_WIFI,   { hal->GpioLevelLow,  hal->GpioLevelLow,  hal->GpioLevelLow  } }, \
  END_OF_MODE_TABLE, \
};

#endif

#endif
