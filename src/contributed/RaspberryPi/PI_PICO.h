#if !defined(_RADIOBOARDS_CONTRIBUTED_RASPBERRYPI_PICO_H)
#define _RADIOBOARDS_CONTRIBUTED_RASPBERRYPI_PICO_H

// sources:
// https://datasheets.raspberrypi.com/pico/Pico-R3-A4-Pinout.pdf
// https://github.com/jgromes/RadioLib/issues/729

#define RADIO_BOARDS_NAME "Raspberry Pi Pico"

#define RADIO_NSS     (3)   // i.e., SX1262 radio = new Module(3, 20, 15, 2, SPI1, RADIOLIB_DEFAULT_SPI_SETTINGS);
#define RADIO_IRQ     (20)
#define RADIO_RST     (15)
#define RADIO_GPIO    (2)

// this board uses custom SPI to interface with the module
#define RADIO_SPI     SPI1
#define RADIO_MISO    (12)
#define RADIO_MOSI    (11)
#define RADIO_SCK     (10)

#define RADIO_SPI_INIT                                    \
SPI1.setSCK(10);         \       // from https://github.com/jgromes/RadioLib/issues/729
SPI1.setTX(11);          \       // ~
SPI1.setRX(12);          \       // ~  
pinMode(3, OUTPUT);      \       // ~
digitalWrite(3, HIGH);   \       // ~
RADIO_SPI1.begin(false);         // from https://github.com/jgromes/RadioLib/issues/729

#endif
