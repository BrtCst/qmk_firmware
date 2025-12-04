[1mdiff --git a/keyboards/zsa/moonlander/keymaps/brtcst/keymap.c b/keyboards/zsa/moonlander/keymaps/brtcst/keymap.c[m
[1mindex eca9bb46d7..33f41383be 100644[m
[1m--- a/keyboards/zsa/moonlander/keymaps/brtcst/keymap.c[m
[1m+++ b/keyboards/zsa/moonlander/keymaps/brtcst/keymap.c[m
[36m@@ -96,7 +96,7 @@[m [mconst uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[m
     // Left Hand                                                                       // Right Hand[m
     XXXXXXX,      XXXXXXX,    XXXXXXX,            XXXXXXX,            XXXXXXX,        XXXXXXX,    XXXXXXX,              XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,[m
     XXXXXXX,   XXXXXXX,  KC_MEDIA_PREV_TRACK,  TD(D_PLAY_STOP) ,KC_MEDIA_NEXT_TRACK,    KC_MUTE,  TG(LOCK),                  XXXXXXX,    XXXXXXX,    KC_HOME,    KC_UP,      KC_PGUP,    XXXXXXX,    XXXXXXX,[m
[31m-    XXXXXXX,   XXXXXXX,  XXXXXXX,  TD(D_COPY_CUT),LCTL(BP_V), KC_VOLU,  KC_CAPS,            XXXXXXX,    KC_BSPC,    RALT_T(KC_LEFT),    RSFT_T(KC_DOWN),    RCTL_T(KC_RIGHT),   LALT_T(KC_DEL),     XXXXXXX,[m
[32m+[m[32m    XXXXXXX,   XXXXXXX,  XXXXXXX,  RSFT_T(TD(D_COPY_CUT)),RALT_T(LCTL(BP_V)), KC_VOLU,  KC_CAPS,            XXXXXXX,    KC_BSPC,    RALT_T(KC_LEFT),    RSFT_T(KC_DOWN),    RCTL_T(KC_RIGHT),   LALT_T(KC_DEL),     XXXXXXX,[m
     XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,XXXXXXX,    KC_VOLD,                                   XXXXXXX,    KC_END,     XXXXXXX,    KC_PGDN,    XXXXXXX,    XXXXXXX,[m
     XXXXXXX,    XXXXXXX,    XXXXXXX,            XXXXXXX,            XXXXXXX,                    XXXXXXX,              XXXXXXX,                XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,[m
                                                                     XXXXXXX,        XXXXXXX,   XXXXXXX,              XXXXXXX, TD(D_20),MO(CONFIG)[m
