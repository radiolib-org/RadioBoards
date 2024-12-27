#if !defined(_RADIOBOARDS_MAINTAINED_HELTEC_HT_CT62_H)
#define _RADIOBOARDS_MAINTAINED_HELTEC_HT_CT62_H

// sources:
// Seeed does not clearly label the pins from the ESP32S3
// to the Wio SX1262 through their B2B connector,
// so these pins are taken from their contribution to OCH:
// https://github.com/Seeed-Studio/one_channel_hub/blob/4cc771ac02da1bd18be67509f6b52d21bb0feabd/components/smtc_ral/bsp/sx126x/seeed_xiao_esp32s3_devkit_sx1262.c#L358-L369

#define RADIO_BOARDS_NAME "SeeedStudio XIAO ESP32S3 (using B2B connector)"

#define RADIO_NSS     (41)
#define RADIO_IRQ     (39)
#define RADIO_RST     (42)
#define RADIO_GPIO    (40)

#if RADIOLIB_SUPPORT_ENABLED
  #define Radio       SX1262
#endif

#endif
