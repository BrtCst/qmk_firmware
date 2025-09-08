#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_bepo.h"

// pour que la méthode send_string utilise le layout bépo et pas l’ascii
#include "sendstring_bepo.h"

#include "common_brtcst.h"
#include "transactions.h"



/*
const key_override_t next_track_override = 
	ko_make_with_layers_negmods_and_options(
   		MOD_MASK_CTRL,       // Trigger modifiers: ctrl
    	KC_MPLY,             // Trigger key: play/pause
    	KC_MNXT,             // Replacement key
    	~0,                  // Activate on all layers
    	MOD_MASK_SA,         // Do not activate when shift or alt are pressed
    	ko_option_no_reregister_trigger); // Specifies that the play key is not registered again after lifting ctrl
      */
     
/*const key_override_t number_1_override = 
	ko_make_with_layers_negmods_and_options(
   		MOD_MASK_SHIFT,       // Trigger modifiers
    	KC_KP_1,             // Trigger key
    	KC_1,             // Replacement key
    	NUMPAD,                  // Activate on all layers
    	MOD_MASK_CTRL,         // Do not activate when *** are pressed
    	ko_option_no_reregister_trigger);*/

      const key_override_t number_1_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_1,KC_1);
      const key_override_t number_1b_override =ko_make_basic(MOD_MASK_SA,KC_KP_1,LSFT(RALT(KC_1)));
      const key_override_t number_1c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_1,RALT(KC_1));
      const key_override_t number_2_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_2,KC_2);
      const key_override_t number_2b_override =ko_make_basic(MOD_MASK_SA,KC_KP_2,LSFT(RALT(KC_2)));
      const key_override_t number_2c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_2,RALT(KC_2));
      const key_override_t number_3_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_3,KC_3);
      const key_override_t number_3b_override =ko_make_basic(MOD_MASK_SA,KC_KP_3,LSFT(RALT(KC_3)));
      const key_override_t number_3c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_3,RALT(KC_3));
      const key_override_t number_4_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_4,KC_4);
      const key_override_t number_4b_override =ko_make_basic(MOD_MASK_SA,KC_KP_4,LSFT(RALT(KC_4)));
      const key_override_t number_4c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_4,RALT(KC_4));
      const key_override_t number_5_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_5,KC_5);
      const key_override_t number_5b_override =ko_make_basic(MOD_MASK_SA,KC_KP_5,LSFT(RALT(KC_5)));
      const key_override_t number_5c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_5,RALT(KC_5));
      const key_override_t number_6_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_6,KC_6);
      const key_override_t number_6b_override =ko_make_basic(MOD_MASK_SA,KC_KP_6,LSFT(RALT(KC_6)));
      const key_override_t number_6c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_6,RALT(KC_6));
      const key_override_t number_7_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_7,KC_7);
      const key_override_t number_7b_override =ko_make_basic(MOD_MASK_SA,KC_KP_7,LSFT(RALT(KC_7)));
      const key_override_t number_7c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_7,RALT(KC_7));
      const key_override_t number_8_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_8,KC_8);
      const key_override_t number_8b_override =ko_make_basic(MOD_MASK_SA,KC_KP_8,LSFT(RALT(KC_8)));
      const key_override_t number_8c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_8,RALT(KC_8));
      const key_override_t number_9_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_9,KC_9);
      const key_override_t number_9b_override =ko_make_basic(MOD_MASK_SA,KC_KP_9,LSFT(RALT(KC_9)));
      const key_override_t number_9c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_9,RALT(KC_9));
      const key_override_t number_0_override =ko_make_basic(MOD_MASK_SHIFT,KC_KP_0,KC_0);
      const key_override_t number_0b_override =ko_make_basic(MOD_MASK_SA,KC_KP_0,LSFT(RALT(KC_0)));
      const key_override_t number_0c_override =ko_make_basic(MOD_BIT(KC_RALT),KC_KP_0,RALT(KC_0));
      

const key_override_t *key_overrides[] = {
  &number_0c_override,
  &number_0b_override,
  &number_0_override,
  &number_1c_override,
  &number_1b_override,
  &number_1_override,
  &number_2c_override,
  &number_2b_override,
  &number_2_override,
  &number_3c_override,
  &number_3b_override,
  &number_3_override,
  &number_4c_override,
  &number_4b_override,
  &number_4_override,
  &number_5c_override,
  &number_5b_override,
  &number_5_override,
  &number_6c_override,
  &number_6b_override,
  &number_6_override,
  &number_7c_override,
  &number_7b_override,
  &number_7_override,
  &number_8c_override,
  &number_8b_override,
  &number_8_override,
  &number_9c_override,
  &number_9b_override,
  &number_9_override
};

// pour les dictionnaires de combos (combos.def)
#include "g/keymap_combo.h"

char chordal_hold_handedness(keypos_t key) {
    //if (key.col == 0 || key.col == MATRIX_COLS - 1) {
    //    return '*';  // Exempt the outer columns.
    //}
    // On split keyboards, typically, the first half of the rows are on the
    // left, and the other half are on the right.
    return key.row < MATRIX_ROWS / 2 ? 'L' : 'R';
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_split_3x6_3_ex2(
        //,-----------------------------------------------------.
        //,-----------------------------------------------------.
        top_row[0], top_row[1], top_row[2], top_row[3], top_row[4], top_row[5], top_row[6],                top_row[7], top_row[8], top_row[9], top_row[10], top_row[11], top_row[12], top_row[13],
        //|--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------|
        mid_row[0], mid_row[1], mid_row[2], mid_row[3], mid_row[4], mid_row[5], mid_row[6],                mid_row[7], mid_row[8], mid_row[9], mid_row[10], mid_row[11], mid_row[12], mid_row[13],
        //|--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------|
        bot_row[0], bot_row[1], bot_row[2], bot_row[3], bot_row[4], bot_row[5],                                        bot_row[6], bot_row[7], bot_row[8], bot_row[9], bot_row[10], bot_row[11],
        //|--------+--------+--------+--------+--------+--------+--------|
        //|--------+--------+--------+--------+--------+--------+--------|
        thumb_row[0], thumb_row[1], thumb_row[2], thumb_row[3], thumb_row[4], thumb_row[5]
        //`--------------------------'  `--------------------------'

        ),
  [GAMING] = LAYOUT_split_3x6_3_ex2( // Gaming layer
    // Left Hand                                                                   // Right Hand
    BP_W, _______, _______, _______, _______, _______, BP_DCIR,              TD(D_4),  _______, _______, _______, _______, _______, _______,
    BP_CCED, BP_A,    BP_U,    BP_I,    BP_E,     _______, KC_ENTER,                      _______, _______, _______, _______, _______, _______, _______,
    KC_LSFT, BP_AGRV, BP_Y,    BP_X,    BP_DOT,  BP_K,                                     _______, _______, _______, _______, _______, _______,
    _______,    _______, _______, _______, _______,    _______
  ),
  [NUMPAD] = LAYOUT_split_3x6_3_ex2( // Numpad layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    TD(D_F1_F13),   TD(D_F2_F14),   TD(D_F3_F15),   TD(D_F4_F16), XXXXXXX,  XXXXXXX,              QK_LLCK, KC_NUM, KC_KP_7, KC_KP_8, KC_KP_9, BP_EQL, BP_PERC,
    XXXXXXX,    TD(D_F5_F17),   TD(D_F6_F18),   TD(D_F7_F19),   TD(D_F8_F20), XXXXXXX,  XXXXXXX,              XXXXXXX, KC_PPLS, KC_KP_4,KC_KP_5, KC_KP_6, KC_PAST, BP_DLR,
    XXXXXXX,   TD(D_F9_F21),   TD(D_F10_F22),  TD(D_F11_F23),  TD(D_F12_F24), XXXXXXX,                                        KC_PMNS, KC_KP_1, KC_KP_2, KC_KP_3, BP_DOT, BP_COMM,
    _______,    _______, MO(CONFIG), _______,     _______,    KC_KP_0
  ),
  [FXARROWS] = LAYOUT_split_3x6_3_ex2( // Functions & Arrows layer
    // Left Hand                                                                       // Right Hand
    XXXXXXX,    XXXXXXX,    KC_MPRV,        TD(D_PLAY_STOP),     KC_MNXT,          KC_MUTE,   XXXXXXX,              XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_PGUP,    XXXXXXX,    XXXXXXX,
    _______,    KC_RALT,    KC_LALT,         TD(D_COPY_CUT),     TD(D_PASTE_LSFT), KC_VOLU,  KC_CAPS,              XXXXXXX,    KC_BSPC,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_DEL,     XXXXXXX,
    XXXXXXX,    XXXXXXX,   XXXXXXX,            XXXXXXX, CMC_6,       KC_VOLD,                                      XXXXXXX,    KC_END,     XXXXXXX,    KC_PGDN,    XXXXXXX,    _______,
    _______,   _______ , _______,  MO(CONFIG), _______,    KC_DEL
  ),
  [CONFIG] = LAYOUT_split_3x6_3_ex2( // CONFIG
    // Left Hand                                                                       // Right Hand
    QK_BOOT,    XXXXXXX,    DM_REC1,    DM_RSTP,    DM_PLY1,    XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    DM_REC2,    DM_RSTP,    DM_PLY2,    RM_VALU,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    RM_VALD,                                      XXXXXXX,    XXXXXXX,    XXXXXXX,      XXXXXXX,    XXXXXXX,    XXXXXXX,
    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX
  )
      };


bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
  if (layer_state_is(GAMING))
    switch(combo_index) {
      case YX_ENTER:
      case GH_ENTER:
      case XDOT_W:
      case QG_Ç:
        return true;
      default:
        return false;
    }
  return true;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // decide by combo->keycode
    /*switch (combo->keycode) {
        case BP_LCBR:
        case BP_RCBR:
            return COMBO_TERM_SHORT;
    }*/

    // or with combo index, i.e. its name from enum.
    switch (index) {
        case ST_HYPHEN:
        case SR_ASTERISK:
        case UI_HASSH:
        case SL_AROBASE:
            return COMBO_TERM_SHORT;
    }
    return COMBO_TERM;
}

// Combos plus complexe, code si besoin

// enum combo_events {
//   EM_EMAIL,
//   BSPC_LSFT_CLEAR,
// };

// const uint16_t PROGMEM email_combo[] = {KC_E, KC_M, COMBO_END};
// const uint16_t PROGMEM clear_line_combo[] = {KC_BSPC, KC_LSFT, COMBO_END};

// combo_t key_combos[] = {
//   [EM_EMAIL] = COMBO_ACTION(email_combo),
//   [BSPC_LSFT_CLEAR] = COMBO_ACTION(clear_line_combo),
// };
// /* COMBO_ACTION(x) is same as COMBO(x, XXXXXXX) */

// void process_combo_event(uint16_t combo_index, bool pressed) {
//   switch(combo_index) {
//     case EM_EMAIL:
//       if (pressed) {
//         SEND_STRING("john.doe@example.com");
//       }
//       break;
//     case BSPC_LSFT_CLEAR:
//       if (pressed) {
//         tap_code16(KC_END);
//         tap_code16(S(KC_HOME));
//         tap_code16(KC_BSPC);
//       }
//       break;
//   }
// }

// Handler pour la synchro de l’état de caps_word entre les deux moitiés, qui ne fonctionne pas par défaut
void caps_word_sync(uint8_t initiator2target_buffer_size, const void *initiator2target_buffer, uint8_t target2initiator_buffer_size, void *target2initiator_buffer) {
       bool caps_word_active = *(bool*)initiator2target_buffer;
       if (caps_word_active) {
        caps_word_on();
       } else {
        caps_word_off();
       }
  }

void keyboard_post_init_user(void) {
    //rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    // enregistrement de la synchro de caps_word, qui ne fonctionne pas par défaut
    transaction_register_rpc(RPC_ID_USER_CAPS_WORD_SYNC, caps_word_sync);


}


tap_dance_action_t tap_dance_actions[] = TAP_DANCE_LIST;

/* custom */


// The number of per-key LEDs on each side of a 5-column Corne.
#define NUM_LEDS_PER_SIDE 24

// keyboards/crkbd/rev1/rev1.c has a hard-coded g_led_config with 27 LEDs, so we
// have to work around this.
#define NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE 27

// This is a thin wrapper around rgb_matrix_set_color which allows you to put
// the same firmware on both halves of the keyboard (other than a #define for
// `MASTER_LEFT` or `MASTER_RIGHT`) and still have the correct LEDs light up
// regardless of which half has the USB cable in it.
//
// This complexity behind this logic is explained in the comments within the
// function itself.
/*void set_color_split(uint8_t key_code, uint8_t r, uint8_t g, uint8_t b) {
    // When using defines for MASTER_LEFT and MASTER_RIGHT, is_keyboard_left()
    // will be inaccurate. For example, (is_keyboard_left() &&
    // !is_keyboard_master()) can NEVER be true.
#ifdef MASTER_LEFT
    bool is_left = true;
#endif
#ifdef MASTER_RIGHT
    bool is_left = false;
#endif

    bool left_is_master = (is_keyboard_master() && is_left) || (!is_keyboard_master() && !is_left);

    // Note on constants: 23 is the number of LEDs on each side (24) minus 1.
    // 27 is the number of LEDs that the Corne normally has with six columns.

    // Rule #1: you must set the LED based on what the master's range is. So if
    // the USB cable is in the left half, then the range is 0-23, otherwise it's
    // 27-50.

    // Rule #2: each half of the keyboard can only set its own LEDs, it's just
    // that the codes change according to Rule #1.

    // Rule #2
    if ((is_left && key_code >= NUM_LEDS_PER_SIDE) || (!is_left && key_code < NUM_LEDS_PER_SIDE)) {
        return;
    }

    // Rule #1
    if (left_is_master && key_code >= NUM_LEDS_PER_SIDE)
        key_code -= NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE;
    else if (!left_is_master && key_code < NUM_LEDS_PER_SIDE)
        key_code += NUM_LEDS_PER_SIDE_ON_NORMAL_CORNE;
    rgb_matrix_set_color(key_code, r, g, b);
}*/



void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(BP_M, BP_B)) {
        SEND_STRING("- [ ]");
        //tap_code16(KC_LEFT);
    } else if (leader_sequence_one_key(BP_AT)) {
        SEND_STRING("@brtcst.net");
    } else if (leader_sequence_one_key(BP_D)) {
        // utilisé avec Autohotkey pour insérer la date du jour
        tap_code16(KC_F13);
    }
    
    /* else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
    }*/
}

/* Gestion des leds */
/*void led_update_ports(led_t led_state) {
    //ML_LED_5(led_state.num_lock);
    ML_LED_6(led_state.caps_lock);
}*/

/*bool led_update_user(led_t led_state) {
    ML_LED_5(led_state.num_lock);
    ML_LED_6(led_state.caps_lock);
    return false;
}*/
#define MAX_LEDS 46
static hsv_t color_table[MAX_LEDS] = {[0 ... MAX_LEDS-1] = {HSV_BLACK}};

void set_key_color(uint8_t index, uint8_t h, uint8_t s, uint8_t v) {
    color_table[index] = (hsv_t){h, s, v};
}

bool rgb_matrix_indicators_user() {
  // Sens des leds : début moitité gauche, espace 0, puis serpentin vers la gauche. Les deux touches supplémentaires sont 21 (haut) et 22 (bas).
  // ajouter 23 pour avoir la touche correspondante à droite

  // NOTE IMPORTANTE : suite à bug ou mauvaise conf du firmware, les leds de la moitié gauche sont mirrorées à droite. Il faut
  // donc les réinitialiser après avoir déclaré la moitié gauche

  // NOTE : il faut flasher les deux moitiés du clavier pour que les leds fonctionnent correctement
  
  for (int i = 0; i < MAX_LEDS; i++)
  {
    set_key_color(i, HSV_BLACK);
  }

  if (!host_keyboard_led_state().num_lock) {
    set_key_color(26, HSV_GREEN);
  } else {
     set_key_color(26, HSV_BLACK);
  }

    hsv_t caps_color = {0, 0, 0};
    if (is_caps_word_on()) {
        caps_color = host_keyboard_led_state().caps_lock ? (hsv_t){HSV_PURPLE} : (hsv_t){HSV_BLUE};
    } else if (host_keyboard_led_state().caps_lock) {
        caps_color = (hsv_t){HSV_RED};
    }
    if (caps_color.h || caps_color.s || caps_color.v) {
        set_key_color(22, caps_color.h, caps_color.s, caps_color.v);
        set_key_color(45, caps_color.h, caps_color.s, caps_color.v);
    }

    switch(get_highest_layer(layer_state)) {
            case GAMING:
                set_key_color(44, HSV_RED);
                break;
            case NUMPAD:
              set_key_color(27, HSV_GREEN); //numpad
              set_key_color(28, HSV_GREEN);
              set_key_color(29, HSV_GREEN);
              set_key_color(31, HSV_GREEN);
              set_key_color(32, HSV_GREEN );
              set_key_color(33, HSV_GREEN);
              set_key_color(34, HSV_GREEN);
              set_key_color(35, HSV_GREEN );
              set_key_color(36, HSV_GREEN);
              set_key_color(37, HSV_GREEN);
              set_key_color(26, HSV_RED ); //numlock
              // fn
              set_key_color(4, HSV_BLUE);
              set_key_color(5, HSV_BLUE);
              set_key_color(6, HSV_BLUE);
              set_key_color(9, HSV_BLUE);
              set_key_color(10, HSV_BLUE);
              set_key_color(11, HSV_BLUE);
              set_key_color(12, HSV_BLUE);
              set_key_color(13, HSV_BLUE);
              set_key_color(14, HSV_BLUE);
              set_key_color(15, HSV_BLUE);
              set_key_color(16, HSV_BLUE);
              set_key_color(17, HSV_BLUE);
              
              set_key_color(44, HSV_PURPLE); // layer lock
              break;
            case FXARROWS:
              set_key_color(28, HSV_RED); // arrows
              set_key_color(33, HSV_RED);
              set_key_color(34, HSV_RED);
              set_key_color(36, HSV_RED );
              set_key_color(27, HSV_YELLOW ); // home
              set_key_color(29, HSV_YELLOW ); // end
              set_key_color(35, HSV_YELLOW ); // pgup
              set_key_color(37, HSV_YELLOW ); // pgdn
              set_key_color(25, HSV_CYAN); // backspace
              set_key_color(39, HSV_CYAN); // del

              set_key_color(1, HSV_GREEN);
              set_key_color(2, HSV_GREEN);
              set_key_color(3, HSV_GREEN);
              set_key_color(4, HSV_GREEN);
              set_key_color(11, HSV_GREEN);
              set_key_color(12, HSV_GREEN);
              set_key_color(5, HSV_CYAN);
              set_key_color(10, HSV_CYAN);

              set_key_color(22, HSV_RED);
              break;
            case CONFIG:
               set_key_color(12, HSV_RED); // bootloader
               set_key_color(13, HSV_RED);
               set_key_color(18, HSV_RED);
               set_key_color(10, HSV_ORANGE);
               set_key_color(11, HSV_ORANGE);
               set_key_color(4, HSV_GREEN);
               set_key_color(5, HSV_GREEN);
               // brightness
               set_key_color(1, HSV_YELLOW);
               set_key_color(2, HSV_YELLOW);
        }

  for (size_t i = 0; i < MAX_LEDS; i++) {
    hsv_t hsv = color_table[i];
    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    rgb_t rgb = hsv_to_rgb(hsv);
    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
  }

	return false;
}

// Gestion de l’état du caps_word, notamment la synchro des deux moitiés
void caps_word_set_user(bool active) {
      if (is_keyboard_master()) {
          // Synchroniser l'état vers l'autre moitié
          transaction_rpc_send(RPC_ID_USER_CAPS_WORD_SYNC, 1, &active);
      }
  }

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case BASE:
        //ML_LED_1(false);
        //ML_LED_2(false);
        //ML_LED_3(false);
        //ML_LED_4(false);
        break;
    case GAMING:
       // ML_LED_1(false);
        //ML_LED_2(false);
        //ML_LED_3(true);
       // ML_LED_4(false);
        
        break;
    default: //  for any other layers, or the default layer
        break;
    }
  return state;
}

// pour stockage de l’état des modificateurs (shift, alt, ctrl…)
uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // Stockage de l'état des modificateurs
  mod_state = get_mods();

  
  switch (keycode) {
    case OS_RSFT:
      if (mod_state & MOD_MASK_SHIFT){
        clear_oneshot_mods();
      }
      break;
    case KC_RSFT:
      if (mod_state & MOD_MASK_SHIFT){
        clear_oneshot_mods();
      }
      break;
    
    case CMC_CCED:
      if (record->event.pressed) {
        // 'ça'
        
      }
      break;
    case CMC_0:
      if (record->event.pressed) {
        // '« '
        SEND_STRING(SS_TAP(X_2) SS_DELAY(5) SS_LSFT(SS_RALT(SS_TAP(X_SPACE))));
      }
      break;
    case CMC_1:
      if (record->event.pressed) {
        // ' »'
        SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_SPACE))) SS_DELAY(5) SS_TAP(X_3));
      }
      break;
    case CMC_6:
      // ' :'
      if (record->event.pressed) {
        SEND_STRING(SS_LSFT(SS_RALT(SS_TAP(X_SPACE))) SS_DELAY(5) SS_LSFT(SS_TAP(X_V)));
      }
      break;
    case CMC_END_RETURN:
      // END puis enter
      if (record->event.pressed) {
        SEND_STRING(SS_TAP(X_END) SS_TAP(X_ENTER));
      }
      break;
    case CMC_SLASH:
      // / si pas de modifier
      // \ si altGr
      static bool agrav_registered;
      static bool slash_registered;
      if (record->event.pressed) {
        
        if (mod_state == MOD_BIT(KC_RALT)) {
          // le backslash est sur altgr+à, on s’évite de désactiver un modifier altGr inutilement
          // puisqu’il est activé ici
          register_code(BP_AGRV);
          agrav_registered = true;
        } else if (mod_state & MOD_MASK_SHIFT) {
          del_mods(MOD_MASK_SHIFT);
          set_mods(MOD_RALT);
          register_code(BP_AGRV);
          del_mods(MOD_RALT);
          agrav_registered = true;
        } else if (mod_state == 0 ) {
          register_code(BP_SLSH);
          slash_registered = true;
        }
        return false;
      } else {
        if (agrav_registered) {
          unregister_code(BP_AGRV);
          agrav_registered = false;
        }
        if (slash_registered) {
          unregister_code(BP_SLSH);
          slash_registered = false;
        }
      }
      break;
    /*case RGB_SLD:
        if (rawhid_state.rgb_control) {
            return false;
        }
        if (record->event.pressed) {
            rgblight_mode(1);
        }
        return false;*/
  }
  return true;
}

