=== File: totem/config.h ===
// Copyright 2022 GEIST @geigeigeist
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0   // USART TX pin
#define SERIAL_USART_RX_PIN GP1   // USART RX pin
#define SERIAL_USART_PIN_SWAP     // Swap TX and RX pins if keyboard is master halve.
#define EE_HANDS // Split handedness via eeprom

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
=== File: totem/keymaps/default/config.h ===
// Copyright 2022 GEIST @geigeigeist
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#define MATRIX_ROWS 8
#define MATRIX_COLS 5

#define SERIAL_USART_FULL_DUPLEX  // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN GP0   // USART TX pin
#define SERIAL_USART_RX_PIN GP1   // USART RX pin
#define SERIAL_USART_PIN_SWAP     // Swap TX and RX pins if keyboard is master halve.
#define EE_HANDS // Split handedness via eeprom

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 500U
=== File: totem/keymaps/default/keymap.c ===
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
    QWERTY
};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


    [0] = LAYOUT(
		          KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,      KC_I,    KC_O,      KC_P,
           	          KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,      KC_K,    KC_L,      KC_SCLN,
        LM(3,MOD_LSFT),   KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,      KC_N,     KC_M,      KC_COMM, KC_DOT,    KC_SLSH,   KC_ENT,
                                              KC_LCTL,  KC_LGUI,  KC_SPC,    KC_SPC,   _______,   _______
    ),
    [1] = LAYOUT(
		          KC_ESC,   KC_1,     KC_2,     KC_3,     KC_0,      KC_LPRN,  KC_RPRN,   KC_LBRC, KC_RBRC,   KC_BSPC,
           	          KC_TAB,   KC_4,     KC_5,     KC_6,     _______,   KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,  KC_QUOT,
        _______,          _______,  KC_7,     KC_8,     KC_9,     _______,   _______,  _______,   _______, _______,   _______,   KC_BSLS,
                                              _______,  _______,  _______,   _______,  _______,   _______
    ),
    [2] = LAYOUT(
		          KC_GRAVE, KC_F1,    KC_F2,    KC_F3,    KC_F10,    _______,  _______,   KC_MINUS,KC_EQUAL, KC_DEL,
           	          _______,  KC_F4,    KC_F5,    KC_F6,    KC_F11,    _______,  _______,   _______, _______,  _______,
        _______,          _______,  KC_F7,    KC_F8,    KC_F9,    KC_F12,    _______,  _______,   _______, _______,  _______,   _______,
                                              _______,  _______,  _______,   _______,  _______,   _______
    ),
    [3] = LAYOUT(
		          _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,
           	          _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,
        _______,          _______,  _______,  _______,  _______,  _______,    _______, _______,   _______, _______,  _______,   _______,
                                              _______,  KC_LALT,  KC_LGUI,    _______, _______,   _______
    ),

};

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ M A C R O S                                                                                                            │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
                                                            ██ ██▀▀██
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
=== File: totem/keymaps/default/rules.mk ===
DYNAMIC_MACRO_ENABLE = yes
=== File: totem/keyboard.json ===
{
    "keyboard_name": "TOTEM",
    "manufacturer": "GEIST",
    "url": "https://github.com/GEIGEIGEIST/TOTEM",
    "maintainer": "qmk",
    "usb": {
        "vid": "0x3A3C",
        "pid": "0x0002",
        "device_version": "0.3.0"
    },
    "processor": "RP2040",
    "bootloader": "rp2040",
    "matrix_pins": {
        "rows": [
            "GP26",
            "GP27",
            "GP28",
            "GP29"
        ],
        "cols": [
            "GP6",
            "GP7",
            "GP3",
            "GP4",
            "GP2"
        ]
    },
    "diode_direction": "COL2ROW",
    "debounce": 5,
    "features": {
        "swap_hands": true
    },
    "split": {
        "serial": {
            "driver": "vendor"
        }
    },
    "layouts": {
        "LAYOUT": {
            "layout": [
                {
                    "label": "L00",
                    "matrix": [
                        0,
                        0
                    ],
                    "x": 1,
                    "y": 1.4
                },
                {
                    "label": "L01",
                    "matrix": [
                        0,
                        1
                    ],
                    "x": 2,
                    "y": 0.6
                },
                {
                    "label": "L02",
                    "matrix": [
                        0,
                        2
                    ],
                    "x": 3,
                    "y": 0
                },
                {
                    "label": "L03",
                    "matrix": [
                        0,
                        3
                    ],
                    "x": 4,
                    "y": 0.5
                },
                {
                    "label": "L04",
                    "matrix": [
                        0,
                        4
                    ],
                    "x": 5,
                    "y": 0.65
                },
                {
                    "label": "R00",
                    "matrix": [
                        4,
                        4
                    ],
                    "x": 9,
                    "y": 0.65
                },
                {
                    "label": "R01",
                    "matrix": [
                        4,
                        3
                    ],
                    "x": 10,
                    "y": 0.5
                },
                {
                    "label": "R02",
                    "matrix": [
                        4,
                        2
                    ],
                    "x": 11,
                    "y": 0
                },
                {
                    "label": "R03",
                    "matrix": [
                        4,
                        1
                    ],
                    "x": 12,
                    "y": 0.6
                },
                {
                    "label": "R04",
                    "matrix": [
                        4,
                        0
                    ],
                    "x": 13,
                    "y": 1.4
                },
                {
                    "label": "L10",
                    "matrix": [
                        1,
                        0
                    ],
                    "x": 1,
                    "y": 2.4
                },
                {
                    "label": "L11",
                    "matrix": [
                        1,
                        1
                    ],
                    "x": 2,
                    "y": 1.6
                },
                {
                    "label": "L12",
                    "matrix": [
                        1,
                        2
                    ],
                    "x": 3,
                    "y": 1
                },
                {
                    "label": "L13",
                    "matrix": [
                        1,
                        3
                    ],
                    "x": 4,
                    "y": 1.5
                },
                {
                    "label": "L14",
                    "matrix": [
                        1,
                        4
                    ],
                    "x": 5,
                    "y": 1.65
                },
                {
                    "label": "R10",
                    "matrix": [
                        5,
                        4
                    ],
                    "x": 9,
                    "y": 1.65
                },
                {
                    "label": "R11",
                    "matrix": [
                        5,
                        3
                    ],
                    "x": 10,
                    "y": 1.5
                },
                {
                    "label": "R12",
                    "matrix": [
                        5,
                        2
                    ],
                    "x": 11,
                    "y": 1
                },
                {
                    "label": "R13",
                    "matrix": [
                        5,
                        1
                    ],
                    "x": 12,
                    "y": 1.6
                },
                {
                    "label": "R14",
                    "matrix": [
                        5,
                        0
                    ],
                    "x": 13,
                    "y": 2.4
                },
                {
                    "label": "L30",
                    "matrix": [
                        3,
                        0
                    ],
                    "x": 0,
                    "y": 2.9
                },
                {
                    "label": "L20",
                    "matrix": [
                        2,
                        0
                    ],
                    "x": 1,
                    "y": 3.4
                },
                {
                    "label": "L21",
                    "matrix": [
                        2,
                        1
                    ],
                    "x": 2,
                    "y": 2.6
                },
                {
                    "label": "L22",
                    "matrix": [
                        2,
                        2
                    ],
                    "x": 3,
                    "y": 2
                },
                {
                    "label": "L23",
                    "matrix": [
                        2,
                        3
                    ],
                    "x": 4,
                    "y": 2.5
                },
                {
                    "label": "L24",
                    "matrix": [
                        2,
                        4
                    ],
                    "x": 5,
                    "y": 2.65
                },
                {
                    "label": "R20",
                    "matrix": [
                        6,
                        4
                    ],
                    "x": 9,
                    "y": 2.65
                },
                {
                    "label": "R21",
                    "matrix": [
                        6,
                        3
                    ],
                    "x": 10,
                    "y": 2.5
                },
                {
                    "label": "R22",
                    "matrix": [
                        6,
                        2
                    ],
                    "x": 11,
                    "y": 2
                },
                {
                    "label": "R23",
                    "matrix": [
                        6,
                        1
                    ],
                    "x": 12,
                    "y": 2.6
                },
                {
                    "label": "R24",
                    "matrix": [
                        6,
                        0
                    ],
                    "x": 13,
                    "y": 3.4
                },
                {
                    "label": "R34",
                    "matrix": [
                        7,
                        0
                    ],
                    "x": 14,
                    "y": 2.9
                },
                {
                    "label": "L32",
                    "matrix": [
                        3,
                        2
                    ],
                    "x": 3.6,
                    "y": 3.5
                },
                {
                    "label": "L33",
                    "matrix": [
                        3,
                        3
                    ],
                    "x": 4.8,
                    "y": 3.65
                },
                {
                    "label": "L34",
                    "matrix": [
                        3,
                        4
                    ],
                    "x": 6,
                    "y": 3.85
                },
                {
                    "label": "R30",
                    "matrix": [
                        7,
                        4
                    ],
                    "x": 8,
                    "y": 3.85
                },
                {
                    "label": "R31",
                    "matrix": [
                        7,
                        3
                    ],
                    "x": 9.2,
                    "y": 3.65
                },
                {
                    "label": "R32",
                    "matrix": [
                        7,
                        2
                    ],
                    "x": 10.4,
                    "y": 3.5
                }
            ]
        }
    }
}
=== File: totem/totem.c ===
/* Copyright 2022
 * GEIST @geigeigeist
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"


#ifdef SWAP_HANDS_ENABLE

__attribute__ ((weak))
const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] =
    // The LAYOUT macro could work for this, but it was harder to figure out the
    // identity using it.

    // This is the identity layout.
/*
{ \
 { {0, 0}, {1, 0}, {2, 0}, {3, 0}, {4, 0} }, \
 { {0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1} }, \
 { {0, 2}, {1, 2}, {2, 2}, {3, 2}, {4, 2} }, \
 { {0, 3}, {2, 3}, {3, 3}, {4, 3} },         \
    \
 { {0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4} }, \
 { {0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5} }, \
 { {0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6} }, \
 { {0, 7}, {1, 7}, {2, 7}, {4, 7},           \
};
*/

    // This is the mirror, q <-> p, w <-> o, etc...
{ \
 { {4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4} }, \
 { {4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5} }, \
 { {4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6} }, \
 { {4, 7},         {2, 7}, {1, 7}, {0, 7} }, \
                                             \
 { {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0} }, \
 { {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1} }, \
 { {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2} }, \
 { {4, 3}, {3, 3}, {2, 3},         {0, 3} }, \
};

#endif //SWAP_HANDS_ENABLE
