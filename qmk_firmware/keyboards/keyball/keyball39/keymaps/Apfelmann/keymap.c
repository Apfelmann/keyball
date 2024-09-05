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
    TD_A_Ä,
    TD_O_Ö,
    TD_U_Ü,
    TD_S_SS,
    TD_PLUS_MINUS,
    TD_DOT_COLON,
    TD_COMMA_SEMICOLON,
    TD_LEFT_ANGLE_RIGHT_ANGLE,
    TD_SLASH_BACKSLASH,
    TD_LEFT_BRACKET_RIGHT_BRACKET,
    TD_SLEFT_BRACKET_SRIGHT_BRACKET,
    TD_LEFT_PARENTHESIS_RIGHT_PARENTHESIS
};

// Definieren Sie Ihre Tap Dance Aktionen
tap_dance_action_t tap_dance_actions[] = {
    [TD_Q_AT] = ACTION_TAP_DANCE_DOUBLE(KC_Q, LCTL(LALT(KC_Q))),
    [TD_A_Ä] = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_QUOT),
    [TD_O_Ö] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_SCLN),
    [TD_U_Ü] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_LBRC),
    [TD_S_SS] = ACTION_TAP_DANCE_DOUBLE(KC_S, DE_SS),
    [TD_PLUS_MINUS] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_SLSH),
    [TD_DOT_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, S(KC_DOT)),
    [TD_COMMA_SEMICOLON] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, S(KC_COMM)),
    [TD_LEFT_ANGLE_RIGHT_ANGLE] = ACTION_TAP_DANCE_DOUBLE(KC_NUBS, S(KC_NUBS)),
    [TD_SLASH_BACKSLASH] = ACTION_TAP_DANCE_DOUBLE(S(KC_7), LCA(DE_SS)),
    [TD_LEFT_BRACKET_RIGHT_BRACKET] = ACTION_TAP_DANCE_DOUBLE(LCA(KC_8), LCA(KC_9)),
    [TD_SLEFT_BRACKET_SRIGHT_BRACKET] = ACTION_TAP_DANCE_DOUBLE(LCA(KC_7), LCA(KC_0)),
    [TD_LEFT_PARENTHESIS_RIGHT_PARENTHESIS] = ACTION_TAP_DANCE_DOUBLE(S(KC_8), S(KC_9))
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [0] = LAYOUT_universal(
    TD(TD_Q_AT)    , KC_W     , KC_E     , KC_R     , KC_T     ,                   DE_Z     , TD(TD_U_Ü)     , KC_I     , TD(TD_O_Ö)     , KC_P     ,
    TD(TD_A_Ä)     , TD(TD_S_SS)     , KC_D     , LSFT_T(KC_F)     , KC_G     ,               KC_H     , LSFT_T(KC_J)     , KC_K     , LT(3, KC_L)     ,  S(DE_SS),
    LSFT_T(DE_Y)   , KC_X     , KC_C     , KC_V     , KC_B     ,                                         KC_N     , KC_M     , KC_BTN1 , KC_BTN2   , S(KC_1)  ,
    KC_LCTL  , KC_LEFT_GUI  , KC_NO  ,  MT(MOD_LALT,KC_DELETE ) ,LT(1,KC_SPC),LT(3,KC_TAB),         KC_BSPC,LT(2,KC_ENT),KC_NO,KC_NO,KC_NO, KC_ESC
  ),

  [1] = LAYOUT_universal(
    KC_NO , KC_NO , KC_NO , TD(TD_LEFT_PARENTHESIS_RIGHT_PARENTHESIS) , KC_NO ,                            S(KC_2) , S(KC_BSLS) , S(DE_HASH) , S(KC_4) , DE_CIRC ,
    KC_NO , KC_NO , KC_NO , TD(TD_SLEFT_BRACKET_SRIGHT_BRACKET) , KC_NO ,                            TD(TD_PLUS_MINUS) , S(KC_MINUS) , S(KC_0) , S(DE_PLUS) , S(KC_5) ,
    KC_LEFT_SHIFT , KC_NO , KC_NO , TD(TD_LEFT_BRACKET_RIGHT_BRACKET) , KC_NO ,                            TD(TD_DOT_COLON) ,TD(TD_COMMA_SEMICOLON) , TD(TD_LEFT_ANGLE_RIGHT_ANGLE) , TD(TD_SLASH_BACKSLASH) , LCA(DE_PLUS) ,
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
// clang-format on

/*
Textbasierte Darstellung der Keymap:

Layer 0 (Basis-Layer):
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
| Q/@    |   W    |   E    |   R    |   T    |                                        |   Z    |  U/Ü   |   I    |  O/Ö   |   P    |
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
| A/Ä    |  S/ß   |   D    |F(Shift)|   G    |                                        |   H    |J(Shift)|   K    |L(Lay3) |   ?    |  
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
  |Y(Shift)|   X    |   C    |   V    |   B    |                                         |   N    |   M    |MausBtn1|MausBtn2|   !    |
+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
|  Ctrl  |       GUI      |      Alt/Del      |Spc(L1)    |Tab(L3) |            | Bksp   |Ent(L2) |        |        |            |  Esc   |
+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+

Layer 1 (aktiviert durch Halten von Leertaste):
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
|        |        |        | ( / )  |        |                                               |   "    |   '    |   `    |   $    |   ^    |
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
|        |        |        | { / }  |        |                                               |  +/-   |   _    |   =    |   *    |   %    | 
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
| Shift  |        |        | [ / ]  |        |                                              |  ./:   |  ,/;   |  </>   |  /|\   |   ~    
+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
|        |        |        |        |        |        |  |        |        |        |        |        |        |
+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+

Layer 2 (aktiviert durch Halten von Enter):
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
|  F11   |  F12   |        |        |        |                    |                                  |   7        |       8    |    9         |           |
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
|   F6   |   F7   |   F8   |   F9   |  F10   |                |                                   |   4        |   5        |   6      |             |
+--------+--------+--------+--------+--------+                    +------+--------+--------+--------+--------+
|   F1   |   F2   |   F3   |   F4   |   F5   |                |                        |   0        |   1        |   2        |   3         |        |

+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
|        |        |        |        |        |        |  |        |        |        |        |        |        |
+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+

Layer 3 (aktiviert durch Halten von Tab oder L):
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
|        |        |        |        |        |                    |        |        |   Up   |        |        |
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
|        |        |        |        |        |                    |        |  Left  |  Down  | Right  |        |
+--------+--------+--------+--------+--------+                    +--------+--------+--------+--------+--------+
|        |        |        |        |        |                    |        |        |        |        |        |
+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
|        |        |        |        |        |        |  |        |  GUI   |        |        |        |        |
+--------+--------+--------+--------+--------+--------+  +--------+--------+--------+--------+--------+--------+
*/
// clang-format on

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
