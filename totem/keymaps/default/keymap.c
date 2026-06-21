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
#include "gpio.h"

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   k e y c o d e s                   │
// └─────────────────────────────────────────────────┘

enum custom_keycodes {
	QWERTY = SAFE_RANGE,
	VER_ALT,
	VER_ALT_MOD,
	VER_LSFT_L3,
	VER_SPACE,
	GAME_MO1,
	GAME_MO2,
	GAME_CTRL,
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
        // On Windows/Linux this helper starts as GUI, but some combos below
        // temporarily swap it to Ctrl so one thumb key can cover both roles.
        return KC_LGUI;
    }
    return KC_LALT;
}

#ifdef RGBLIGHT_ENABLE
void keyboard_pre_init_user(void) {
    // The Seeed XIAO RP2040 onboard NeoPixel needs its power pin enabled.
    gpio_set_pin_output(GP11);
    gpio_write_pin_high(GP11);
}

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv_noeeprom(HSV_OFF);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, 4)) {
        rgblight_sethsv_noeeprom(HSV_RED);
    } else {
        rgblight_sethsv_noeeprom(HSV_OFF);
    }

    return state;
}
#endif


// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

enum combo_events {
   GAMING_LAYER_TOGGLE,
};

const uint16_t PROGMEM gaming_layer_combo[] = {KC_COMM, KC_DOT, KC_SLSH, COMBO_END};

combo_t key_combos[] = {
   // comma+dot+slash toggles the gaming layer on/off.
   [GAMING_LAYER_TOGGLE] = COMBO(gaming_layer_combo, TG(4)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT(
                   KC_Q, KC_W,    KC_E,    KC_R,     KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
                   KC_A, KC_S,    KC_D,    KC_F,     KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      VER_LSFT_L3, KC_Z, KC_X,    KC_C,    KC_V,     KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                         KC_LCTL, VER_ALT, VER_SPACE,                KC_SPC,  MO(1),   MO(2)
   ),

   [1] = LAYOUT(
                   KC_ESC,  KC_1,    KC_2,    KC_3,    KC_0,               KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,  KC_BSPC,
                   KC_TAB,  KC_4,    KC_5,    KC_6,    _______,            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOT,
          _______, _______, KC_7,    KC_8,    KC_9,    _______,            _______, _______, _______, _______,  _______, KC_BSLS,
                            _______, _______, _______,                     _______, _______, _______
   ),

   [2] = LAYOUT(
                   KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F10,             KC_BRID, KC_BRIU, KC_MINUS, KC_EQL,  KC_DEL,
                   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,             KC_HOME, KC_PGDN, KC_PGUP,  KC_END,  _______,
          _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,             KC_MPLY, KC_VOLD, KC_VOLU,  KC_MPRV, KC_MNXT, _______,
                                     _______, _______, _______,            _______, _______, _______
   ),
   [3] = LAYOUT(
                   _______,  _______,  _______,  _______,     _______,    _______, _______,   _______, _______,  _______,
                   _______,  _______,  _______,  _______,     _______,    _______, _______,   _______, _______,  _______,
          _______, _______,  _______,  _______,  _______,     _______,    _______, _______,   _______, _______,  _______, _______,
                                       _______,  VER_ALT_MOD,  VER_ALT,   _______, _______,   _______
   ),
   [4] = LAYOUT(
               KC_GRV, KC_Q,    KC_W,    KC_E,   KC_R,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
               KC_TAB, KC_A,    KC_S,    KC_D,   KC_F,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_LSFT, KC_Z,   KC_X,    KC_C,    KC_V,   KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                       GAME_CTRL, KC_LALT, KC_SPC,               KC_SPC,  GAME_MO1, GAME_MO2
   ),
   [5] = LAYOUT(
               KC_ESC, KC_1,    KC_2,    KC_3,   KC_T,           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
               KC_TAB, KC_4,    KC_5,    KC_6,   KC_G,           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_LSFT, KC_Z,   KC_7,    KC_8,    KC_9,   KC_B,           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                       KC_LCTL, KC_LALT, KC_SPC,                 KC_SPC,  GAME_MO1, GAME_MO2
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
static bool ver_alt_mod_active = false;
static bool ver_alt_mod_ctrl_swapped = false;
static uint16_t ver_space_timer = 0;
static uint16_t game_ctrl_timer = 0;
static bool game_ctrl_down = false;
static bool game_ctrl_interrupted = false;
static bool game_ctrl_held = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   // If a layer-5 key is pressed while GAME_CTRL is held but Ctrl hasn't engaged
   // yet, treat GAME_CTRL purely as a layer key and cancel its pending Ctrl.
   if (record->event.pressed && keycode != GAME_CTRL && game_ctrl_down && !game_ctrl_held) {
      game_ctrl_interrupted = true;
   }

   switch (keycode) {
      case GAME_MO1:
      case GAME_MO2:
         if (record->event.pressed) {
            layer_off(5);
            layer_off(4);
            layer_on(keycode == GAME_MO1 ? 1 : 2);
         } else {
            layer_off(keycode == GAME_MO1 ? 1 : 2);
            layer_on(4);
         }
         return false;
   }

   if (ver_alt_mod_active && is_win_or_linux()) {
      // While VER_ALT_MOD is held on Windows/Linux, re-map a few keys to the
      // Ctrl-based editing shortcuts that are commonly used there.
      switch (keycode) {
          case KC_LEFT:
          case KC_RIGHT:
             if (record->event.pressed) {
                if (!ver_alt_mod_ctrl_swapped) {
                   // VER_ALT_MOD started as GUI on Windows/Linux. Swap that held
                   // modifier to Ctrl once so left/right becomes Ctrl+Arrow.
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
                // Same modifier swap as above, but for Ctrl+Backspace to delete
                // the previous word on Windows/Linux.
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
      // While VER_ALT is held on Windows/Linux, emulate the navigation and app
      // management shortcuts that would normally live under Command on macOS.
      switch (keycode) {
          case KC_LEFT:
          case KC_RIGHT: {
             // Left/Right jump to start/end of line by converting the held
             // Ctrl modifier into Home/End.
             uint16_t nav_key = (keycode == KC_LEFT) ? KC_HOME : KC_END;
             if (record->event.pressed) {
                if (ver_alt_tab_swapped) {
                   // If we were in Alt+Tab mode, leave it before switching to
                   // line navigation to avoid mixing modifiers.
                   unregister_code(KC_LALT);
                   ver_alt_tab_swapped = false;
                }
                if (!ver_alt_home_end_swapped) {
                   // VER_ALT starts as Ctrl on Windows/Linux. Home/End should be
                   // sent without Ctrl, so release it until this navigation mode
                   // is over.
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
          case KC_UP:
          case KC_DOWN: {
             // Up/Down also map to Home/End here. Unlike left/right, this path
             // restores Ctrl if it had been released earlier.
             uint16_t nav_key = (keycode == KC_UP) ? KC_HOME : KC_END;
             if (record->event.pressed) {
                if (ver_alt_tab_swapped) {
                   unregister_code(KC_LALT);
                   ver_alt_tab_swapped = false;
                }
                if (ver_alt_home_end_swapped) {
                   // Put Ctrl back before sending the key so the held modifier
                   // returns to its default VER_ALT state after home/end usage.
                   register_code(KC_LCTL);
                   wait_ms(10);
                   ver_alt_home_end_swapped = false;
                }
               wait_ms(10);
               register_code(nav_key);
            } else {
               unregister_code(nav_key);
            }
             return false;
          }
          case KC_TAB:
          case KC_Q: {
             // VER_ALT+Tab becomes Alt+Tab, and VER_ALT+Q becomes Alt+F4.
             // Both are Windows-style window switching / closing shortcuts.
             uint16_t alt_remap = (keycode == KC_TAB) ? KC_TAB : KC_F4;
             if (record->event.pressed) {
                if (!ver_alt_tab_swapped) {
                   if (!ver_alt_home_end_swapped) unregister_code(KC_LCTL);
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
          case KC_BSPC: {
             if (record->event.pressed) {
                if (ver_alt_tab_swapped) {
                  unregister_code(KC_LALT);
                  ver_alt_tab_swapped = false;
                }
                if (!ver_alt_home_end_swapped) unregister_code(KC_LCTL);
                wait_ms(10);
                // Shift+Home selects from the cursor to the start of the line,
                // then Backspace deletes that selection.
                register_code(KC_LSFT);
                tap_code(KC_HOME);
                unregister_code(KC_LSFT);
                wait_ms(10);
                tap_code(KC_BSPC);
               if (!ver_alt_home_end_swapped) {
                  wait_ms(10);
                  register_code(KC_LCTL);
               }
            }
             return false;
          }
          case KC_SPC: {
             if (record->event.pressed) {
                if (ver_alt_tab_swapped) {
                  unregister_code(KC_LALT);
                  ver_alt_tab_swapped = false;
                }
                if (!ver_alt_home_end_swapped) unregister_code(KC_LCTL);
                wait_ms(10);
                // Open Windows search/start search with Win+S.
                register_code(KC_LGUI);
                tap_code(KC_S);
                unregister_code(KC_LGUI);
                if (!ver_alt_home_end_swapped) {
                  wait_ms(10);
                  register_code(KC_LCTL);
               }
            }
            return false;
          }
          case KC_LBRC:
          case KC_RBRC: {
             bool is_shift = get_mods() & MOD_MASK_SHIFT;
             if (is_shift) {
                if (record->event.pressed) {
                  if (ver_alt_tab_swapped) {
                     unregister_code(KC_LALT);
                     ver_alt_tab_swapped = false;
                  }
                  if (ver_alt_home_end_swapped) {
                     register_code(KC_LCTL);
                     ver_alt_home_end_swapped = false;
                     wait_ms(10);
                   }
                   if (keycode == KC_RBRC) { // Ctrl + Tab (Next Tab)
                      // If Shift is physically held, clear it temporarily so the
                      // sent shortcut stays Ctrl+Tab instead of Ctrl+Shift+Tab.
                      uint8_t saved_mods = get_mods();
                      del_mods(MOD_MASK_SHIFT);
                      send_keyboard_report();
                      wait_ms(10);
                      tap_code(KC_TAB);
                      set_mods(saved_mods);
                      send_keyboard_report();
                   } else { // Ctrl + Shift + Tab (Prev Tab)
                      // Here we keep Shift so the same gesture moves to the
                      // previous browser/editor tab.
                      tap_code(KC_TAB);
                   }
                }
                return false;
             } else {
                // Without Shift, [ and ] act like browser history back/forward
                // by switching the held modifier to Alt and sending arrows.
                uint16_t alt_remap = (keycode == KC_LBRC) ? KC_LEFT : KC_RIGHT;
                if (record->event.pressed) {
                   if (!ver_alt_tab_swapped) {
                      if (!ver_alt_home_end_swapped) unregister_code(KC_LCTL);
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
   }

   switch (keycode) {
       case VER_ALT:
          if (record->event.pressed) {
             // Pressing VER_ALT starts the platform-specific primary modifier:
             // Ctrl on Windows/Linux, Command on macOS.
             ver_alt_active = true;
             ver_alt_tab_swapped = false;
             ver_alt_home_end_swapped = false;
             wait_ms(10);
             register_code(ver_alt_keycode());
          } else {
             ver_alt_active = false;
             if (ver_alt_tab_swapped) {
                // After Alt+Tab on Windows, send a harmless key before releasing
                // Alt so the OS reliably exits the app switcher state.
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
             // Secondary modifier thumb key: Alt on macOS, GUI on Windows/Linux,
             // with special Ctrl-based edits handled in the block above.
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
       case VER_SPACE:
          if (record->event.pressed) {
             // Hold for Left Alt, tap for Space. The quick-tap behavior below has
             // one extra Windows/Linux shortcut when VER_ALT is also held.
             ver_space_timer = timer_read();
             register_code(KC_LALT);
          } else {
             unregister_code(KC_LALT);
             if (timer_elapsed(ver_space_timer) < 300) {
                if (ver_alt_active && is_win_or_linux()) {
                  if (ver_alt_tab_swapped) {
                     unregister_code(KC_LALT);
                     ver_alt_tab_swapped = false;
                   }
                   if (!ver_alt_home_end_swapped) unregister_code(KC_LCTL);
                   wait_ms(10);
                   // VER_ALT + VER_SPACE quick-tap also opens Win+S on
                   // Windows/Linux, matching the dedicated SPC case above.
                   register_code(KC_LGUI);
                   tap_code(KC_S);
                   unregister_code(KC_LGUI);
                   if (!ver_alt_home_end_swapped) {
                     wait_ms(10);
                     register_code(KC_LCTL);
                  }
               } else {
                  tap_code(KC_SPC);
               }
            }
         }
         return false;
      case GAME_CTRL:
         // Tap (<400ms, no layer-5 key) = Ctrl tap. Hold alone >=400ms = hold
         // Ctrl (engaged in housekeeping_task_user). Press a layer-5 key while
         // held = layer access, Ctrl dismissed.
         if (record->event.pressed) {
            game_ctrl_timer = timer_read();
            game_ctrl_down = true;
            game_ctrl_interrupted = false;
            game_ctrl_held = false;
            layer_on(5);
         } else {
            game_ctrl_down = false;
            layer_off(5);
            if (game_ctrl_held) {
               unregister_code(KC_LCTL);
               game_ctrl_held = false;
            } else if (!game_ctrl_interrupted && timer_elapsed(game_ctrl_timer) < 400) {
               tap_code(KC_LCTL);
            }
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

void housekeeping_task_user(void) {
   // Engage a real held Ctrl once GAME_CTRL has been held alone for >=400ms.
   if (game_ctrl_down && !game_ctrl_held && !game_ctrl_interrupted
       && timer_elapsed(game_ctrl_timer) >= 400) {
      register_code(KC_LCTL);
      game_ctrl_held = true;
   }
}
