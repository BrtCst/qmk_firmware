/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2000

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000

#define USB_SUSPEND_WAKEUP_DELAY 0
#define CAPS_LOCK_STATUS
#define FIRMWARE_VERSION u8"VWLEe/9KbzN"
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define LAYER_STATE_8BIT
//#define COMBO_COUNT 32

#define RGB_MATRIX_STARTUP_SPD 60

#define PERMISSIVE_HOLD_PER_KEY

/* custom */
#define COMBO_SHOULD_TRIGGER
#define COMBO_STRICT_TIMER
#define COMBO_TERM 28
#define COMBO_TERM_SHORT 16
#define COMBO_TERM_PER_COMBO

#define LEADER_TIMEOUT 300
#define LEADER_NO_TIMEOUT
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
// pour avoir les indicator leds en custom
#define MOONLANDER_USER_LEDS

