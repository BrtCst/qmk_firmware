/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2000

#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000

//#define COMBO_COUNT 32

#define PERMISSIVE_HOLD_PER_KEYs

/* custom */
#define COMBO_SHOULD_TRIGGER
#define COMBO_STRICT_TIMER
#define COMBO_TERM 28
#define COMBO_TERM_SHORT 16
#define COMBO_TERM_PER_COMBO

#define LEADER_TIMEOUT 300
#define LEADER_NO_TIMEOUT

// pour avoir les indicator leds en custom
#define MOONLANDER_USER_LEDS

#undef CAPS_LOCK_STATUS
