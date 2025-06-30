#if !defined(_RADIOBOARDS_CONTRIBUTED_WAVESHARE_RP2040_LORA_H)
#define _RADIOBOARDS_CONTRIBUTED_WAVESHARE_RP2040_LORA_H

/*
 * This is a variant of the Waveshare RP2040 One module with integrated SX1262 
 *
 * notes:
 * - it uses custom SPI pins --> must call RadioBeginSPI() before use
 * - it has an antenna switch --> to enable/use call RadioEnableRfSwitch(radio)
 * - it has an XTAL (crystal oscillator that is not temperature compensated),
 *   which is not the default of RadioLib. The SPI initialization will correct
 *   this setting (could not find a better place for that)
 *
 * Tested with the EU (868 Mhz) model but should work for others as well
 * 
 * sources:
 *   https://www.waveshare.com/wiki/RP2040-LoRa
 *   https://nwgat.ninja/rp2040-lora/
 *   https://github.com/jgromes/RadioLib/wiki/Troubleshooting-Guide#sx126xsx128xlr11x0-incorrect-oscillator
 */

#define RADIO_BOARDS_NAME "Waveshare RP2040-Lora"

// pins connected to the SX1262 on this board
#define RADIO_NSS     (13)  // GP9
#define RADIO_IRQ     (16)  // GP16
#define RADIO_RST     (23)  // GP23
#define RADIO_GPIO    (18)  // GP18

// this board uses custom SPI to interface with the module
#define RADIO_SPI     SPI1
#define RADIO_MISO    (24)  // GP8
#define RADIO_MOSI    (15)  // GP11
#define RADIO_SCK     (14)  // GP10

// this board has a TX/RX antenna switch 
#define RADIO_ANT_SW  (17)  // GP17


// SPI pins are custom and requires calling RadioBeginSPI() before use
#define RADIO_SPI_INIT              \
    RADIO_SPI.setSCK(RADIO_SCK);    \
    RADIO_SPI.setTX(RADIO_MOSI);    \
    RADIO_SPI.setRX(RADIO_MISO);    \
    RADIO_SPI.begin(false);         \
    radio.XTAL = true;


#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1262

  // Antenna /  RF switching is supported but seems optional
  #define RADIO_RF_SWITCH

  // antenna switch uses only 1 pin
  #define RADIO_RF_SWITCH_PINS \
  static const uint32_t RadioBoards_rfswitch_pins[Module::RFSWITCH_MAX_PINS] = {    \
      RADIO_ANT_SW, RADIOLIB_NC, RADIOLIB_NC, RADIOLIB_NC, RADIOLIB_NC              \
    }

  // Antenna switch must be LOW when sending, HIGH when receiving
  #define RADIO_RF_SWITCH_TABLE \
  static const Module::RfSwitchMode_t RadioBoards_rfswitch_table[] = {  \
    /* mode              ANT_SW */  \
    {Module::MODE_IDLE,  {HIGH}},   \
    {Module::MODE_RX,    {HIGH}},    \
    {Module::MODE_TX,    {LOW}},    \
    END_OF_MODE_TABLE,              \
  }

#endif // RADIOLIB_SUPPORT_ENABLED

#endif // _RADIOBOARDS_CONTRIBUTED_WAVESHARE_RP2040_LORA_H
