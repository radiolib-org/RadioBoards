#if !defined(_RADIOBOARDS_MAINTAINED_RADIO_SHIELD_A_H)
#define _RADIOBOARDS_MAINTAINED_RADIO_SHIELD_A_H

// sources:
// https://github.com/jgromes/RadioShield

// warning: this board cannot be selected, so you must define 
// RADIO_BOARD_RADIO_SHIELD yourself instead of RADIO_BOARD_AUTO

#define RADIO_BOARDS_NAME "RadioShield"

#define RADIOSHIELD_CS_A    (10)
#define RADIOSHIELD_IRQ_A   (2)
#define RADIOSHIELD_RST_A   (9)
#define RADIOSHIELD_GPIO_A  (8)
#define RADIOSHIELD_CS_B    (5)
#define RADIOSHIELD_IRQ_B   (3)
#define RADIOSHIELD_RST_B   (7)
#define RADIOSHIELD_GPIO_B  (6)

#define RADIO_NSS     (RADIOSHIELD_CS_A)
#define RADIO_IRQ     (RADIOSHIELD_IRQ_A)
#define RADIO_RST     (RADIOSHIELD_RST_A)
#define RADIO_GPIO    (RADIOSHIELD_GPIO_A)

#if RADIOLIB_SUPPORT_ENABLED
class Radio {
  public:
    Module* ModuleA;
    Module* ModuleB;

    Radio() {
      ModuleA = new Module(RADIOSHIELD_CS_A, RADIOSHIELD_IRQ_A, RADIOSHIELD_RST_A, RADIOSHIELD_GPIO_A);
      ModuleB = new Module(RADIOSHIELD_CS_B, RADIOSHIELD_IRQ_B, RADIOSHIELD_RST_B, RADIOSHIELD_GPIO_B);
    }
};

Radio RadioShield;

#endif

#endif
