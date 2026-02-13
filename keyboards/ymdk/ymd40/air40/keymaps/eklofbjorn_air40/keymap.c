/* Copyright 2022 Dennis Kruyt (dennis@kruyt.org)
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

#define FLOW_TAP_TERM 150
#define TAPPING_TERM 300
//#define BILATERAL_COMBINATIONS

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layer_names {
  _QWERTY,
  _LOWER,
  _RAISE,
  _NAVIG,
  _ADJUST
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NAVSPC LT(_NAVIG, KC_SPC)
#define MT_ENT MT(MOD_LSFT, KC_ENT)
#define MT_S MT(MOD_LALT, SE_S)
#define MT_D MT(MOD_LGUI, SE_D)
#define MT_F MT(MOD_LCTL, SE_F)
#define MT_G MT(MOD_LSFT, SE_G)
#define MT_H MT(MOD_RSFT, SE_H)
#define MT_J MT(MOD_RCTL, SE_J)
#define MT_K MT(MOD_RGUI, SE_K)
#define MT_L MT(MOD_RALT, SE_L)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_ortho_4x12(
    KC_ESC,  SE_Q,    SE_W,    SE_E,    SE_R,   SE_T,      SE_Y,    SE_U,   SE_I,    SE_O,    SE_P,      SE_ARNG,
    KC_TAB,  SE_A,    MT_S,    MT_D,    MT_F,   MT_G,      MT_H,    MT_J,   MT_K,    MT_L,    SE_ODIA,   SE_ADIA,
    KC_DEL,  SE_Z,    SE_X,    SE_C,    SE_V,   SE_B,      SE_N,    SE_M,   SE_COMM, SE_DOT,  SE_MINS,   SE_QUOT,
    KC_BSPC, KC_NO,   KC_NO,   LOWER,   NAVSPC, NAVSPC,    MT_ENT,  MT_ENT, RAISE,   KC_NO,   SE_BSLS,   SE_ASTR
),

[_RAISE] = LAYOUT_ortho_4x12(
    SE_CIRC, SE_EXLM, SE_DQUO, SE_HASH, SE_CURR, SE_PERC, SE_AMPR, SE_SLSH, SE_LPRN, SE_RPRN, SE_EQL,  SE_QUES,
    SE_DIAE, SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_7,    SE_8,    SE_9,    SE_0,    SE_PLUS,
    SE_TILD, SE_PIPE, SE_AT,   SE_PND,  SE_DLR,  SE_EURO, SE_LABK, SE_LCBR, SE_LBRC, SE_RBRC, SE_RCBR, SE_RABK,
    SE_CIRC, KC_NO,   KC_NO,   KC_NO,   LOWER,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   SE_GRV,   SE_ACUT
),

[_LOWER] = LAYOUT_ortho_4x12(
    KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,   SE_SLSH,   SE_MINS,  SE_7,    SE_8,    SE_9,
    KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_NO,   SE_ASTR,   SE_PLUS,  SE_4,    SE_5,    SE_6,
    KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_NO,     SE_0,     SE_1,    SE_2,    SE_3,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RAISE,     KC_NO,    KC_NO,   KC_NO,   KC_NO
),

[_NAVIG] = LAYOUT_ortho_4x12(
    KC_NO,   KC_NO,   KC_NO,     KC_UP,     KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_PGUP,   KC_NO,    KC_NO,    KC_NO,
    KC_NO,   KC_NO,   KC_LEFT,   KC_DOWN,   KC_RIGHT,   KC_NO,   KC_NO,   KC_HOME, KC_PGDN,   KC_END,   KC_NO,    KC_NO,
    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,
    KC_NO,   KC_NO,   KC_NO,     KC_NO,     KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO
),
/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    KC_NO,   QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
)

};
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
