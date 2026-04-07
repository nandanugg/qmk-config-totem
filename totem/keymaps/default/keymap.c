/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀
                                                           ▀  ▀  ▀  D E F A U L T

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	VER_ALT,
	VER_ALT_MOD,
	VER_LSFT_L3,
	VER_CTRL,
};

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   O S   d e t e c t i o n           │
// └─────────────────────────────────────────────────┘

#include "os_detection.h"

static bool is_win_or_linux(void) {
    return detected_host_os() == OS_WINDOWS || detected_host_os() == OS_LINUX;
}

static uint16_t ver_alt_keycode(void) {
    if (is_win_or_linux()) {
        return KC_LCTL;
    }
    return KC_LGUI;
}

static uint16_t ver_alt_mod_keycode(void) {
    if (is_win_or_linux()) {
        return KC_LGUI;
    }
    return KC_LALT;
}


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
              KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
              KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      VER_LSFT_L3, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                 VER_CTRL, VER_ALT, KC_SPC,         KC_SPC,  MO(1),   MO(2)
    ),

    [1] = LAYOUT(
              KC_ESC,  KC_1,    KC_2,    KC_3,    KC_0,                      KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_BSPC,
              KC_TAB,  KC_4,    KC_5,    KC_6,    _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOT,
      _______, _______, KC_7,    KC_8,    KC_9,    _______,                   _______, _______, _______, _______, _______, KC_BSLS,
                                 _______, _______, _______,           _______, _______, _______
    ),

    [2] = LAYOUT(
              KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F10,                     KC_MPLY, KC_MSTP, KC_MINUS, KC_EQL,  KC_DEL,
              _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,                     KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  _______,
      _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,                     _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______,            _______, _______, _______
    ),
    [3] = LAYOUT(
            _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,
                      _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,
        _______,          _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,   _______,
                                              _______,  VER_ALT_MOD,  VER_ALT,   _______,  _______,   _______
    ),
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

static bool lsft_active = false;
static bool ver_alt_active = false;
static bool ver_alt_tab_swapped = false;
static bool ver_alt_home_end_swapped = false;
static bool ver_ctrl_active = false;
static bool ver_alt_mod_active = false;
static bool ver_alt_mod_ctrl_swapped = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   if (ver_alt_mod_active && is_win_or_linux()) {
      switch (keycode) {
         case KC_LEFT:
         case KC_RIGHT:
            if (record->event.pressed) {
               if (!ver_alt_mod_ctrl_swapped) {
                  unregister_code(ver_alt_mod_keycode());
                  wait_ms(10);
                  register_code(KC_LCTL);
                  ver_alt_mod_ctrl_swapped = true;
               }
               wait_ms(10);
               register_code(keycode);
            } else {
               unregister_code(keycode);
            }
            return false;
      }
      if (keycode == KC_BSPC) {
         if (record->event.pressed) {
            if (!ver_alt_mod_ctrl_swapped) {
               unregister_code(ver_alt_mod_keycode());
               wait_ms(10);
               register_code(KC_LCTL);
               ver_alt_mod_ctrl_swapped = true;
            }
            wait_ms(10);
            register_code(KC_BSPC);
         } else {
            unregister_code(KC_BSPC);
         }
         return false;
      }
   }

   if (ver_alt_active && is_win_or_linux()) {
      switch (keycode) {
         case KC_LEFT:
         case KC_RIGHT: {
            uint16_t nav_key = (keycode == KC_LEFT) ? KC_HOME : KC_END;
            if (record->event.pressed) {
               if (ver_alt_tab_swapped) {
                  unregister_code(KC_LALT);
                  ver_alt_tab_swapped = false;
               }
               if (!ver_alt_home_end_swapped) {
                  unregister_code(KC_LCTL);
                  wait_ms(10);
                  ver_alt_home_end_swapped = true;
               }
               wait_ms(10);
               register_code(nav_key);
            } else {
               unregister_code(nav_key);
            }
            return false;
         }
         case KC_TAB:
         case KC_Q:
         case KC_UP:
         case KC_DOWN: {
            uint16_t alt_remap = KC_NO;
            switch (keycode) {
               case KC_TAB: alt_remap = KC_TAB; break;
               case KC_Q:   alt_remap = KC_F4;  break;
               case KC_UP:  alt_remap = KC_UP;  break;
               case KC_DOWN: alt_remap = KC_DOWN; break;
            }
            if (record->event.pressed) {
               if (!ver_alt_tab_swapped) {
                  unregister_code(KC_LCTL);
                  wait_ms(10);
                  register_code(KC_LALT);
                  ver_alt_tab_swapped = true;
               }
               wait_ms(10);
               register_code(alt_remap);
            } else {
               unregister_code(alt_remap);
            }
            return false;
         }
      }
   }

   switch (keycode) {
      case VER_ALT:
         if (ver_ctrl_active) {
            if (record->event.pressed) {
               register_code(KC_LALT);
            } else {
               unregister_code(KC_LALT);
            }
            return false;
         }
         if (record->event.pressed) {
            ver_alt_active = true;
            ver_alt_tab_swapped = false;
            ver_alt_home_end_swapped = false;
            wait_ms(10);
            register_code(ver_alt_keycode());
         } else {
            ver_alt_active = false;
            if (ver_alt_tab_swapped) {
               register_code(KC_F24);
               unregister_code(KC_F24);
               unregister_code(KC_LALT);
               ver_alt_tab_swapped = false;
            } else if (!ver_alt_home_end_swapped) {
               unregister_code(ver_alt_keycode());
            }
            ver_alt_home_end_swapped = false;
         }
         return false;
      case VER_ALT_MOD:
         if (record->event.pressed) {
            ver_alt_mod_active = true;
            ver_alt_mod_ctrl_swapped = false;
            wait_ms(10);
            register_code(ver_alt_mod_keycode());
         } else {
            ver_alt_mod_active = false;
            if (ver_alt_mod_ctrl_swapped) {
               unregister_code(KC_LCTL);
               ver_alt_mod_ctrl_swapped = false;
            } else {
               unregister_code(ver_alt_mod_keycode());
            }
         }
         return false;
      case VER_CTRL:
         if (record->event.pressed) {
            ver_ctrl_active = true;
            register_code(KC_LCTL);
         } else {
            ver_ctrl_active = false;
            unregister_code(KC_LCTL);
         }
         return false;
      case VER_LSFT_L3:
         if (record->event.pressed) {
            lsft_active = true;
            wait_ms(10);
            register_code(KC_LSFT);
            layer_on(3);
         } else {
            layer_off(3);
            lsft_active = false;
            unregister_code(KC_LSFT);
         }
         return false;
   }
   return true;
}
