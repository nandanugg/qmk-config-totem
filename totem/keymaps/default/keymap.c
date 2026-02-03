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
	// MAC_CTRL,
	// MAC_CMD,
	// MAC_ALT,
};

// Track tab state for alt-tab functionality
// static bool alt_tab_active = false;
//
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     static os_variant_t detected_os = OS_UNSURE;
//
//     // Detect OS only once
//     if (detected_os == OS_UNSURE) {
//         detected_os = detected_host_os();
//     }
//
//     bool is_mac = (detected_os == OS_MACOS || detected_os == OS_IOS);
//
//     // Handle Tab key for Alt+Tab functionality on Windows/Linux
//     if (keycode == KC_TAB) {
//         if (!is_mac && get_mods() & MOD_BIT(KC_LCTL)) { // Check if LCTRL (our remapped CMD) is pressed
//             if (record->event.pressed) {
//                 // Start Alt+Tab
//                 alt_tab_active = true;
//                 del_mods(MOD_BIT(KC_LCTL));  // Remove LCTL temporarily
//                 register_code(KC_LALT);      // Press Alt instead
//                 register_code(KC_TAB);       // Press Tab
//                 return false;
//             } else if (alt_tab_active) {
//                 // End Alt+Tab
//                 unregister_code(KC_TAB);
//                 unregister_code(KC_LALT);
//                 alt_tab_active = false;
//
//                 // Restore LCTL if the key is still physically held
//                 if (get_mods() & MOD_BIT(KC_LCTL)) {
//                     add_mods(MOD_BIT(KC_LCTL));
//                 }
//                 return false;
//             }
//         }
//     }
//
//     // Process custom keycodes
//     switch (keycode) {
//         case MAC_CTRL: {
//             // MAC_CTRL maps to CTRL on Mac, ALT on Windows/Linux
//             uint16_t target_key = is_mac ? KC_LCTL : KC_LALT;
//
//             if (record->event.pressed) {
//                 register_code(target_key);
//             } else {
//                 unregister_code(target_key);
//             }
//             return false;
//         }
//
//         case MAC_CMD: {
//             // MAC_CMD maps to GUI on Mac, CTRL on Windows/Linux
//             if (record->event.pressed) {
//                 if (is_mac) {
//                     register_code(KC_LGUI);
//                 } else if (!alt_tab_active) {
//                     register_code(KC_LCTL);
//                 }
//             } else {
//                 if (is_mac) {
//                     unregister_code(KC_LGUI);
//                 } else if (!alt_tab_active) {
//                     unregister_code(KC_LCTL);
//                 } else if (!(get_mods() & MOD_BIT(KC_TAB))) {
//                     // If we're in Alt+Tab mode and Tab is not pressed
//                     unregister_code(KC_LALT);
//                     alt_tab_active = false;
//                 }
//             }
//             return false;
//         }
//
//         case MAC_ALT: {
//             // MAC_ALT maps to ALT on Mac, GUI on Windows/Linux
//             uint16_t target_key = is_mac ? KC_LALT : KC_LGUI;
//
//             if (record->event.pressed) {
//                 register_code(target_key);
//             } else {
//                 unregister_code(target_key);
//             }
//             return false;
//         }
//     }
//
//     return true;
// }

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(
              KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
              KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    MT(MOD_LGUI, KC_B),       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
                                 KC_LCTL, KC_LALT, KC_SPC,            KC_SPC,  MO(1),   MO(2)
    ),

    [1] = LAYOUT(
              KC_ESC,  KC_1,    KC_2,    KC_3,    KC_0,                      KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, KC_BSPC,
              KC_TAB,  KC_4,    KC_5,    KC_6,    _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOT,
      _______, _______, KC_7,    KC_8,    KC_9,    _______,                   _______, _______, _______, _______, _______, KC_BSLS,
                                 _______, _______, _______,           _______, _______, _______
    ),

    [2] = LAYOUT(
              KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F10,                    KC_MPLY, KC_MSTP, KC_MINUS, KC_EQL,  KC_DEL,
              _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,                    KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
      _______, _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,                    _______, _______ _______,  _______, _______, _______,
                                 _______, _______, _______,           _______, _______, _______
    )
    // [3] = LAYOUT(
    //         _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,
    //        	          _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,
    //     _______,          _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,   _______,
    //                                           _______,  KC_LALT,  KC_LGUI,   _______,  _______,   _______
    // ),
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
 _                                                           ██ ██▀▀██
                                                            ▀▀ ██▄▄██
                                                        ██████  ▀▀▀▀
                                                          ██ ▄▄▄▄▄▄
                                                          ██ ██▀▀▀▀
                                                          ██ ██████
                                                             ██▄▄▄▄
                                                             ▀▀▀▀▀▀
                                                           ████████
                                                           ██ ██ ██
                                                           ██ ██ ██
                                                           ▀▀ ▀▀ ▀▀
                                                          ████████

*/
