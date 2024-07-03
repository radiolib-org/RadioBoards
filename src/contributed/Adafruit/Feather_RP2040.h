#if !defined(_RADIOBOARDS_MAINTAINED_ADAFRUIT_FEATHER_RP2040_H)
#define _RADIOBOARDS_MAINTAINED_ADAFRUIT_FEATHER_RP2040_H

// Source:
// Schematic - https://learn.adafruit.com/assets/120813

#define RADIO_BOARDS_NAME "Adafruit Feather RP2040 RFM"

#define RADIO_NSS     (16)
#define RADIO_IRQ     (21)
#define RADIO_RST     (17)
#define RADIO_GPIO    (RADIOLIB_NC)

// this board uses custom SPI to interface with the module
#define RADIO_SPI     SPI
#define RADIO_MISO    (8)
#define RADIO_MOSI    (15)
#define RADIO_SCK     (14)

#define RADIO_SPI_INIT          \
RADIO_SPI.setSCK(RADIO_SCK);    \
RADIO_SPI.setTX(RADIO_MOSI);    \
RADIO_SPI.setRX(RADIO_MISO);    \
RADIO_SPI.begin(false);

#endif


#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1276
#endif

