/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR


#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000
#define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // Sets the default mode, if none has been set

//#define FIRMWARE_VERSION u8"VWLEe/9KbzN"
//#define RAW_USAGE_PAGE 0xFF60
//#define RAW_USAGE_ID 0x61
//#define LAYER_STATE_8BIT
//#define COMBO_COUNT 32

//#define RGB_MATRIX_STARTUP_SPD 60

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY
//#define HOLD_ON_OTHER_KEY_PRESS

/* custom */
#define COMBO_SHOULD_TRIGGER
#define COMBO_STRICT_TIMER
#define COMBO_TERM 28
#define COMBO_TERM_SHORT 16
#define COMBO_TERM_PER_COMBO

#define LEADER_TIMEOUT 300
#define LEADER_NO_TIMEOUT
#define RGB_MATRIX_VAL_STEP 10
// pour avoir les indicator leds en custom

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 120

#define CHORDAL_HOLD
// https://docs.qmk.fm/tap_hold#flow-tap
#define FLOW_TAP_TERM 40
#define CAPS_WORD_INVERT_ON_SHIFT

// pour la synchro du caps_word qui ne fonctionne pas par défaut
#define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_CAPS_WORD_SYNC

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 250

