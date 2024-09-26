/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "keymap_german.h"

// Definieren Sie zuerst Ihre Tap Dance Enums
enum {
    TD_Q_AT,
    TD_A_AE,
    TD_O_OE,
    TD_U_UE,
    TD_S_SS,
    TD_PLUS_MINUS,
    TD_DOT_COLON,
    TD_COMMA_SEMICOLON,
    TD_LEFT_ANGLE_RIGHT_ANGLE,
    TD_SLASH_BACKSLASH,
    TD_LEFT_BRACKET_RIGHT_BRACKET,
    TD_SLEFT_BRACKET_SRIGHT_BRACKET,
    TD_LEFT_PARENTHESIS_RIGHT_PARENTHESIS,
    TD_HASH_TILDE,
};

// Definieren Sie Ihre Tap Dance Aktionen
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_AT] = ACTION_TAP_DANCE_DOUBLE(KC_Q, 	RALT(KC_Q)),
    [TD_A_AE] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_QUOT),
    [TD_O_OE] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_SCLN),
    [TD_U_UE] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_LBRC),
    [TD_S_SS] = ACTION_TAP_DANCE_DOUBLE(KC_S, DE_SS),
    [TD_PLUS_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_SLSH),
    [TD_DOT_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_DOT)),
    [TD_COMMA_SEMICOLON] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),
    [TD_SLASH_BACKSLASH] = ACTION_TAP_DANCE_DOUBLE(S(KC_7), LCA(DE_SS)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    TD(TD_Q_AT)    , KC_W     , KC_E     , KC_R     , KC_T     ,                   DE_Z     , TD(TD_U_UE)     , KC_I     , TD(TD_O_OE)     , KC_P     ,
    TD(TD_A_AE)     , TD(TD_S_SS)     , KC_D     , LSFT_T(KC_F)     , KC_G     ,               KC_H     , LSFT_T(KC_J)     , KC_K     , LT(3, KC_L)     ,  S(DE_SS),
    LSFT_T(DE_Y)   , KC_X     , KC_C     , KC_V     , KC_B     ,                                         KC_N     , KC_M     , KC_BTN1 , KC_BTN2   , S(KC_1)  ,
    KC_LCTL  , KC_LEFT_GUI  , KC_NO  ,  LT(2,KC_DELETE ) ,MT(MOD_LALT,KC_SPC),LT(3,KC_TAB),         KC_BSPC,LT(1,KC_ENT),KC_NO,KC_NO,KC_NO, KC_ESC
  ),

  [1] = LAYOUT_universal(
    LSFT(KC_3) , KC_GRV , 	LSFT(KC_8) ,  LSFT(KC_9) , LSFT(KC_SLSH) ,               TD(TD_PLUS_MINUS)  , TD(TD_SLASH_BACKSLASH) , LSFT(KC_4) , LSFT(KC_RBRC) , LSFT(KC_5) ,
    KC_NO , KC_NO , RALT(KC_7) , RALT(KC_0) , 	LSFT(KC_2) ,                           TD(TD_COMMA_SEMICOLON) , TD(TD_DOT_COLON) , 	LSFT(KC_0) , 	LSFT(KC_6) , 	RALT(KC_NUBS) ,
    KC_LEFT_SHIFT , RALT(KC_RBRC) , RALT(KC_8) , RALT(KC_9) , LSFT(DE_HASH) ,            KC_NUBS ,S(KC_NUBS) , LSFT(KC_EQL), KC_NO , DE_HASH,
    KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,      KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO
  ),

  [2] = LAYOUT_universal(
    KC_F11 , KC_F12 , KC_NO , KC_NO , KC_NO ,                             KC_NO , KC_7 , KC_8 , KC_9 , KC_NO ,
    KC_F6 , KC_F7 , KC_F8 , KC_F9 , KC_F10 ,                            KC_NO , KC_4 , KC_5 , KC_6 , KC_NO ,
    KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                            KC_0 , KC_1 , KC_2 , KC_3 , KC_NO ,
    KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,      KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO
  ),

  [3] = LAYOUT_universal(
    KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                            KC_NO , KC_NO , KC_UP , KC_NO , KC_NO ,
    KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                            KC_NO , KC_LEFT , KC_DOWN , KC_RIGHT , KC_NO ,
    KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,                            KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,
    KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,      KC_NO , KC_LEFT_GUI , KC_NO , KC_NO , KC_NO , KC_NO
  ),
};


layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
