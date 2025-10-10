#undef RGB_DISABLE_TIMEOUT
#define RGB_DISABLE_TIMEOUT 300000
#define RGB_MATRIX_DEFAULT_ON true // Sets the default enabled state, if none has been set
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR // Sets the default mode, if none has been set

#define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY

#undef ONESHOT_TIMEOUT
#define ONESHOT_TIMEOUT 2000
#define COMBO_SHOULD_TRIGGER
#define COMBO_STRICT_TIMER
#define COMBO_TERM 28
#define COMBO_TERM_SHORT 16
#define COMBO_TERM_PER_COMBO

#define LEADER_TIMEOUT 300
#define LEADER_NO_TIMEOUT
#define RGB_MATRIX_VAL_STEP 10

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 160
#define TAPPING_TERM_HOMEROW_MODS TAPPING_TERM
#define TAPPING_TERM_PER_KEY

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 120

#define CHORDAL_HOLD
// https://docs.qmk.fm/tap_hold#flow-tap
#define FLOW_TAP_TERM TAPPING_TERM - 30
#define FLOW_TAP_TERM_SHORT FLOW_TAP_TERM
#define CAPS_WORD_INVERT_ON_SHIFT
