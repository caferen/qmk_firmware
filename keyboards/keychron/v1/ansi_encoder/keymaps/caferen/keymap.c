/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
    GAMING,
    GAMING_FN,
    COLEMAK,
    UTILS
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

// LAYOUT_ansi_82(
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
//     _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
//     _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
//     _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [GAMING] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            QK_AUTO_SHIFT_OFF,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_BSPC,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             RCS(KC_F12),
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LOPT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI,  MO(GAMING_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [GAMING_FN] = LAYOUT_ansi_82(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,             RM_TOGG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            MEH(KC_F1),
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [COLEMAK] = LAYOUT_ansi_82(
        KC_ESC,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_DEL,             RM_TOGG,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   CW_TOGG,            QK_AUTO_SHIFT_ON,
        KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_G,     KC_J,     KC_L,     KC_U,     KC_Y,     CW_TOGG,  KC_LBRC,    KC_RBRC,  KC_BSLS,            MEH(KC_F1),
        KC_BSPC,  LCTL_T(KC_A),       LGUI_T(KC_S),       LALT_T(KC_R),       LSFT_T(KC_T),     KC_D,     KC_H,     RSFT_T(KC_N),     RALT_T(KC_E),     RGUI_T(KC_I),     RCTL_T(KC_O),     KC_SCLN,              KC_ENT,             RCS(KC_F12),
        KC_MEH,   KC_Z,     KC_X,     KC_C,     HYPR_T(KC_V),     KC_B,     HYPR_T(KC_K),     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              LM(UTILS, MOD_LSFT),  KC_UP,
        KC_LCTL,  KC_LALT,  KC_LGUI,                                 LT(UTILS, KC_SPC),                                 KC_RGUI,  MO(UTILS), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [UTILS] = LAYOUT_ansi_82(
        KC_NO,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_NO,            RM_TOGG,
        KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,    KC_NO,  KC_NO,            KC_NO,
        KC_NO,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,    KC_NO,    KC_NO,  KC_NO,            KC_PGUP,
        KC_BSPC,  KC_ESC,   KC_LBRC,  KC_RBRC,  KC_TAB,   KC_GRV,   KC_BSLS,  KC_LEFT,  KC_DOWN,   KC_UP,   KC_RIGHT,  KC_MINS,              KC_NO,            KC_NO,
        KC_LSFT,            KC_NO,  KC_NO,  KC_NO,  KC_QUOT,  KC_NO,  KC_EQL,  KC_NO,  KC_NO,  KC_NO,  KC_NO,              KC_NO,  KC_NO,
        KC_LCTL,  KC_LALT,  KC_NO,                                KC_NO,                                KC_NO,  KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [GAMING] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [GAMING_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [COLEMAK]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [UTILS]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)}
};
#endif // ENCODER_MAP_ENABLE
