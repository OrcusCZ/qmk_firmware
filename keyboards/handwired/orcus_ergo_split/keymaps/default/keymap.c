/* Copyright 2021 Orcus
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
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    // _FN
};

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     QMKBEST = SAFE_RANGE,
//     QMKURL
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_SCLN, BL_TOGG, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_KP_SLASH,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_QUOT, BL_STEP, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_KP_ASTERISK,
        _______, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_GRV,  BL_BRTG, KC_H,    KC_J,    KC_K,    KC_L,    KC_QUOT, KC_KP_MINUS,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,  KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_KP_PLUS,
        KC_LCTL, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,                                     KC_LALT, KC_SLSH, KC_MINS, KC_LGUI, KC_KP_ENTER,
                          KC_HOME, KC_PGUP,                                                       KC_BSPC, KC_UP,
                          KC_END,  KC_PGDN,                                                       KC_DEL,  KC_DOWN,
        KC_LSFT, KC_SPC,  _______, KC_INS,                                                        KC_LEFT, KC_RGHT, KC_SPC,  KC_ENTER
    ),
    // [_FN] = LAYOUT(
    //     QMKBEST, QMKURL,  _______,
    //         RESET,    XXXXXXX
    // )
};

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case QMKBEST:
//             if (record->event.pressed) {
//                 // when keycode QMKBEST is pressed
//                 SEND_STRING("QMK is the best thing ever!");
//             } else {
//                 // when keycode QMKBEST is released
//             }
//             break;
//         case QMKURL:
//             if (record->event.pressed) {
//                 // when keycode QMKURL is pressed
//                 SEND_STRING("https://qmk.fm/\n");
//             } else {
//                 // when keycode QMKURL is released
//             }
//             break;
//     }
//     return true;
// }

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { // left encoder
        if (clockwise) {
            tap_code(KC_RIGHT);
        } else {
            tap_code(KC_LEFT);
        }
    } else if (index == 1) { // right encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
}

#ifdef MULTI_OLED_DRIVER_ENABLE
void oled_task_user(int id) {
    if (id == 0) {
        oled_write_P(PSTR("test LEFT"), false, id);
    }
    else {
        oled_write_P(PSTR("test RIGHT"), false, id);
    }
    oled_scroll_left(id);
}
#endif