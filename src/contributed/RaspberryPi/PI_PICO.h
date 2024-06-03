#if !defined(_RADIOBOARDS_CONTRIBUTED_RASPBERRYPI_PICO_H)
#define _RADIOBOARDS_CONTRIBUTED_RASPBERRYPI_PICO_H

// sources:
// https://datasheets.raspberrypi.com/pico/Pico-R3-A4-Pinout.pdf

#define RADIO_BOARDS_NAME "Raspberry Pi Pico"

#define RADIO_NSS     (3)   // i.e., SX1262 radio = new Module(3, 20, 15, 2, SPI1, RADIOLIB_DEFAULT_SPI_SETTINGS);
#define RADIO_IRQ     (20)
#define RADIO_RST     (15)
#define RADIO_GPIO    (2)

#endif
