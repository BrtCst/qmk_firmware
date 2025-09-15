# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
MOUSEKEY_ENABLE = no
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes
SPACE_CADET_ENABLE = no
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
LEADER_ENABLE = yes
USER_NAME = brtcst

DYNAMIC_TAPPING_TERM_ENABLE = yes

# pour gérer les dictionnaires de combos (combos.def)
VPATH += keyboards/gboards

KEY_OVERRIDE_ENABLE = yes
LAYER_LOCK_ENABLE = yes
CONSOLE_ENABLE = yes

SWAP_HANDS_ENABLE = yes
