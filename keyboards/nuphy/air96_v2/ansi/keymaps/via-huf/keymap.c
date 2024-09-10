/*
Copyright 2023 @ Nuphy <https://nuphy.com/>

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

//***************************************************
//CUSTOM
//***************************************************

//Tap Dance Declarations
enum {
  TD_LEFT_SHIFT_CAPS = 0,
  TD_RIGHT_SHIFT_CAPS = 1,
  TD_D = 2
};

//---------------
//ctrl+d -->  ctrl+d
//ctrl+dd --> ctrl+y
void dance_d_each(tap_dance_state_t *state, void *user_data) {
  if (!(get_mods() & MOD_MASK_CTRL) || state->count > 2) {
    register_code(KC_D);
  }
}
void dance_d_finished(tap_dance_state_t *state, void *user_data) {
  if(get_mods() & MOD_MASK_CTRL){
    if (state->count == 1){
      register_code(KC_D);
    } else if (state->count == 2){
      register_code(KC_Y);
    }
  }
}
void dance_d_reset(tap_dance_state_t *state, void *user_data) {
  if(get_mods() & MOD_MASK_CTRL && state->count == 2){
    unregister_code(KC_Y);
  } else {
    unregister_code(KC_D);
  }
}
//---------------

tap_dance_action_t tap_dance_actions[] = {
  [TD_LEFT_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_SHIFT, KC_CAPS),
  [TD_RIGHT_SHIFT_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_SHIFT, KC_CAPS),
  [TD_D] = ACTION_TAP_DANCE_FN_ADVANCED(dance_d_each, dance_d_finished, dance_d_reset)
};

//map shortcuts for mac
// 1 = LAYER 0, means MAC
const key_override_t ctrl_c_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_C, G(KC_C), 1);
const key_override_t ctrl_x_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_X, G(KC_X), 1);
const key_override_t ctrl_v_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_V, G(KC_V), 1);
const key_override_t ctrl_z_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_Z, G(KC_Z), 1);
const key_override_t ctrl_f_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_F, G(KC_F), 1);
const key_override_t ctrl_a_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_A, G(KC_A), 1);
const key_override_t ctrl_d_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_D, G(KC_D), 1);
const key_override_t ctrl_y_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_Y, G(KC_Y), 1);
const key_override_t ctrl_slash_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_SLSH, G(KC_SLSH), 1); // comment line


// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
  &ctrl_c_key_override,
  &ctrl_x_key_override,
  &ctrl_v_key_override,
  &ctrl_z_key_override,
  &ctrl_f_key_override,
  &ctrl_a_key_override,
  &ctrl_d_key_override,
  &ctrl_slash_key_override,
  NULL // Null terminate the array of overrides!
};

//Keep num lock always on
bool led_update_user(led_t led_state) {
    if (!led_state.num_lock) {
		tap_code(KC_NUM_LOCK); //enable num lock
	}
	return true;
}
//***************************************************
//CUSTOM
//***************************************************
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer 0 Mac
[0] = LAYOUT(
	KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6, 		KC_F7,  	KC_F8,  	KC_F9,      KC_PSCR,    KC_DEL,		KC_HOME,	KC_END,		KC_PGUP,	                KC_PGDN, 	KC_F10, 	KC_F11, 	KC_F12,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 	KC_BSPC,	        	                KC_INS, 	KC_PSLS,    KC_PAST,	KC_PMNS,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 	KC_BSLS,	                            KC_P7,		KC_P8,		KC_P9,		KC_PPLS,
	KC_LALT,	KC_A,   	KC_S,   	TD(TD_D), KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	KC_ENT,							                        KC_P4,		KC_P5,		KC_P6,
	TD(TD_LEFT_SHIFT_CAPS),				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,	TD(TD_RIGHT_SHIFT_CAPS),    KC_UP,		KC_P1,		KC_P2,		KC_P3,		KC_PENT,
	KC_LCTL,	KC_LGUI,	KC_RALT,										KC_SPC, 							KC_RALT,	MO(1),   	KC_RCTL,							    KC_LEFT,    KC_DOWN,    KC_RGHT,	KC_P0,		KC_PDOT),
// layer 1 Mac Fn
[1] = LAYOUT(
	_______, 	KC_BRID,  	KC_BRIU,  	MAC_TASK, 	MAC_SEARCH, MAC_VOICE,  MAC_DND,  	KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	_______,	_______,	_______, 	_______,	_______,    MAC_PRT,	KC_MUTE, 	KC_VOLD, 	KC_VOLU,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,				_______,	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, BAT_SHOW,				_______,	_______,	_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	_______,							_______,	_______,	_______,
	MO(4),				    _______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(4), 		RGB_SPD,	RGB_SPI,	_______,	MO(4),				    RGB_VAI,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______,   	_______,							RGB_MOD,	RGB_VAD,    RGB_HUI,	_______,	_______),
// layer 2 win
[2] = LAYOUT(
	KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6, 		KC_F7,  	KC_F8,  	KC_F9,      KC_PSCR,    KC_DEL,		KC_HOME,	KC_END,		KC_PGUP,	                KC_PGDN, 	KC_F10, 	KC_F11, 	KC_F12,
	KC_GRV, 	KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 	KC_BSPC,	        	                KC_INS,	    KC_PSLS,    KC_PAST,	KC_PMNS,
	KC_TAB, 	KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 	KC_BSLS,	                            KC_P7,		KC_P8,		KC_P9,		KC_PPLS,
	KC_LALT,	KC_A,   	KC_S,   	TD(TD_D), KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	KC_ENT,							                        KC_P4,		KC_P5,		KC_P6,
	TD(TD_LEFT_SHIFT_CAPS),				KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,	TD(TD_RIGHT_SHIFT_CAPS),  KC_UP,	    KC_P1,		KC_P2,		KC_P3,		KC_PENT,
	KC_LCTL,	KC_LGUI,	KC_RALT,										KC_SPC, 							KC_RALT,	MO(3),   	KC_RCTL,							    KC_LEFT,  KC_DOWN,      KC_RGHT,	KC_P0,		KC_PDOT),
// layer 3 win Fn
[3] = LAYOUT(
	_______, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,   	KC_MPLY,   	KC_MNXT,  	_______,	_______,	_______,	_______,	_______,	MAC_PRTA,	KC_MUTE, 	KC_VOLD, 	KC_VOLU,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,				_______,	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, BAT_SHOW,				_______,	_______,	_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______,  	_______,							_______,	_______,	_______,
	MO(4),				    _______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(4), 		RGB_SPD,	RGB_SPI,	_______, 	MO(4),				    RGB_VAI,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	_______, 	_______,							RGB_MOD,	RGB_VAD,    RGB_HUI,	_______,	_______),
// layer 4 function
[4] = LAYOUT(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,				_______,	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 	_______,				_______,	_______,	_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,	_______, 	_______,							_______,	_______,	_______,
	_______,				_______,   	_______,   	RGB_TEST,  	_______,   	_______,   	_______,   	_______,   	SIDE_SPD,	SIDE_SPI,	_______,	_______,				SIDE_VAI,	_______,	_______,	_______,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(4),   	_______,							SIDE_MOD,	SIDE_VAD,   SIDE_HUI,	_______,	_______)
};


const is31_led PROGMEM g_is31_leds[RGB_MATRIX_LED_COUNT] = {
    {0, A_16,   B_16,   C_16},
    {0, A_15,   B_15,   C_15},
    {0, A_14,   B_14,   C_14},
    {0, A_13,   B_13,   C_13},
    {0, A_12,   B_12,   C_12},
    {0, D_16,   E_16,   F_16},
    {0, D_15,   E_15,   F_15},
    {0, D_14,   E_14,   F_14},
    {0, D_13,   E_13,   F_13},
    {0, D_12,   E_12,   F_12},
    {1, D_16,   E_16,   F_16},
    {1, D_15,   E_15,   F_15},
    {1, D_14,   E_14,   F_14},
    {1, D_13,   E_13,   F_13},
    {1, G_4,    H_4,    I_4},
    {1, D_5,    E_5,    F_5},
    {1, G_5,    H_5,    I_5},
    {1, D_6,    E_6,    F_6},
    {1, G_6,    H_6,    I_6},
    {0, A_1,    B_1,    C_1},
    {0, A_2,    B_2,    C_2},
    {0, A_3,    B_3,    C_3},
    {0, A_4,    B_4,    C_4},
    {0, A_5,    B_5,    C_5},
    {0, A_6,    B_6,    C_6},
    {0, A_7,    B_7,    C_7},
    {0, A_8,    B_8,    C_8},
    {0, A_9,    B_9,    C_9},
    {0, A_10,   B_10,   C_10},
    {0, A_11,   B_11,   C_11},
    {1, D_1,    E_1,    F_1},
    {1, D_2,    E_2,    F_2},
    {1, D_3,    E_3,    F_3},
    {1, D_7,    E_7,    F_7},
    {1, D_8,    E_8,    F_8},
    {1, D_9,    E_9,    F_9},
    {1, D_10,   E_10,   F_10},
    {0, D_1,    E_1,    F_1},
    {0, D_2,    E_2,    F_2},
    {0, D_3,    E_3,    F_3},
    {0, D_4,    E_4,    F_4},
    {0, D_5,    E_5,    F_5},
    {0, D_6,    E_6,    F_6},
    {0, D_7,    E_7,    F_7},
    {0, D_8,    E_8,    F_8},
    {0, D_9,    E_9,    F_9},
    {0, D_10,   E_10,   F_10},
    {0, D_11,   E_11,   F_11},
    {1, G_1,    H_1,    I_1},
    {1, G_2,    H_2,    I_2},
    {1, G_3,    H_3,    I_3},
    {1, G_7,    H_7,    I_7},
    {1, G_8,    H_8,    I_8},
    {1, G_9,    H_9,    I_9},
    {1, G_10,   H_10,   I_10},
    {0, G_1,    H_1,    I_1},
    {0, G_2,    H_2,    I_2},
    {0, G_3,    H_3,    I_3},
    {0, G_4,    H_4,    I_4},
    {0, G_5,    H_5,    I_5},
    {0, G_6,    H_6,    I_6},
    {0, G_7,    H_7,    I_7},
    {0, G_8,    H_8,    I_8},
    {0, G_9,    H_9,    I_9},
    {0, G_10,   H_10,   I_10},
    {0, G_11,   H_11,   I_11},
    {1, G_16,   H_16,   I_16},
    {1, G_14,   H_14,   I_14},
    {1, G_13,   H_13,   I_13},
    {1, G_12,   H_12,   I_12},
    {1, G_11,   H_11,   I_11},
    {0, J_1,    K_1,    L_1},
    {0, J_3,    K_3,    L_3},
    {0, J_4,    K_4,    L_4},
    {0, J_5,    K_5,    L_5},
    {0, J_6,    K_6,    L_6},
    {0, J_7,    K_7,    L_7},
    {0, J_8,    K_8,    L_8},
    {0, J_9,    K_9,    L_9},
    {0, J_10,   K_10,   L_10},
    {0, J_11,   K_11,   L_11},
    {1, J_1,    K_1,    L_1},
    {1, J_3,    K_3,    L_3},
    {1, J_4,    K_4,    L_4},
    {1, J_5,    K_5,    L_5},
    {1, J_6,    K_6,    L_6},
    {1, J_7,    K_7,    L_7},
    {1, J_8,    K_8,    L_8},
    {0, J_16,   K_16,   L_16},
    {0, J_15,   K_15,   L_15},
    {0, J_14,   K_14,   L_14},
    {0, J_13,   K_13,   L_13},
    {0, J_12,   K_12,   L_12},
    {1, J_16,   K_16,   L_16},
    {1, J_14,   K_14,   L_14},
    {1, J_13,   K_13,   L_13},
    {1, J_12,   K_12,   L_12},
    {1, J_11,   K_11,   L_11},
    {1, J_10,   K_10,   L_10},
    {1, J_9,    K_9,    L_9},

    {1, A_5,    B_5,    C_5},
    {1, A_4,    B_4,    C_4},
    {1, A_3,    B_3,    C_3},
    {1, A_2,    B_2,    C_2},
    {1, A_1,    B_1,    C_1},

    {1, A_6,    B_6,    C_6},
    {1, A_7,    B_7,    C_7},
    {1, A_8,    B_8,    C_8},
    {1, A_9,    B_9,    C_9},
    {1, A_10,   B_10,   C_10}
};
