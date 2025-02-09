#if !defined(_RADIOBOARDS_CONTRIBUTED_LILYGO_T3S3_H)
#define _RADIOBOARDS_CONTRIBUTED_LILYGO_T3S3_H

// Source:
// Schematic    - https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series/blob/master/schematic/T3_S3_V1.2.pdf
//                https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series/issues/213
// Code example - https://github.com/Xinyuan-LilyGO/LilyGo-LoRa-Series/blob/master/examples/T3S3Factory/T3S3Factory.ino#L381

#define RADIO_BOARDS_NAME "LilyGo T3-S3"

#define RADIO_NSS     (LORA_CS)
#define RADIO_IRQ     (LORA_IRQ)
#define RADIO_RST     (LORA_RST)
#define RADIO_GPIO    (LORA_BUSY)

// this board uses custom SPI to interface with the module
#define RADIO_SPI     SPI
#define RADIO_MISO    (LORA_MISO)
#define RADIO_MOSI    (LORA_MOSI)
#define RADIO_SCK     (LORA_SCK)

#define RADIO_SPI_INIT          \
RADIO_SPI.begin(RADIO_SCK, LORA_MISO, LORA_MOSI, LORA_CS);

#endif


#if RADIOLIB_SUPPORT_ENABLED
  #if defined(ARDUINO_LILYGO_T3S3_SX1262)
    #define Radio       SX1262

  #elif defined(ARDUINO_LILYGO_T3S3_LR1121)
    #define Radio       LR1121

    // it also has custom RF switching
    #define RADIO_RF_SWITCH

    #define RADIO_RF_SWITCH_PINS                              \
        static const uint32_t RadioBoards_rfswitch_pins[] = { \
            RADIOLIB_LR11X0_DIO5, RADIOLIB_LR11X0_DIO6,       \
            RADIOLIB_NC, RADIOLIB_NC, RADIOLIB_NC             \
        };

    #define RADIO_RF_SWITCH_TABLE \
    static const Module::RfSwitchMode_t RadioBoards_rfswitch_table[] = {  \
        /* mode                  DIO5  DIO6 */   \
        { LR11x0::MODE_STBY,   { LOW,  LOW  } }, \
        { LR11x0::MODE_RX,     { HIGH, LOW  } }, \
        { LR11x0::MODE_TX,     { LOW,  HIGH } }, \
        { LR11x0::MODE_TX_HP,  { LOW,  HIGH } }, \
        { LR11x0::MODE_TX_HF,  { LOW,  LOW  } }, \
        { LR11x0::MODE_GNSS,   { LOW,  LOW  } }, \
        { LR11x0::MODE_WIFI,   { LOW,  LOW  } }, \
        END_OF_MODE_TABLE,                       \
    };

  #elif defined(ARDUINO_LILYGO_T3S3_SX1276)
    #define Radio       SX1276
  #endif
#endif