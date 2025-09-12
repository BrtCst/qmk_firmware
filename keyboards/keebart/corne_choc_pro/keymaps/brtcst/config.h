/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#include "config_brtcst.h"

//#define FIRMWARE_VERSION u8"VWLEe/9KbzN"
//#define RAW_USAGE_PAGE 0xFF60
//#define RAW_USAGE_ID 0x61
//#define LAYER_STATE_8BIT
//#define COMBO_COUNT 32

//#define RGB_MATRIX_STARTUP_SPD 60

// pour la synchro du caps_word qui ne fonctionne pas par défaut
#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_CAPS_WORD_SYNC

