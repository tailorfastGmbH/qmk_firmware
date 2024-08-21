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
  TD_LSHIFT_CAPS = 0,
  TD_RSHIFT_CAPS,
  TD_ESC_NUMBERS
};
 
//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_LSHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_SHIFT, KC_CAPS),
  [TD_RSHIFT_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_SHIFT, KC_CAPS),
  [TD_ESC_NUMBERS]  = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_ESC, 5)
};


// 1 = LAYER 0, means MAC
const key_override_t ctrl_c_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_C, G(KC_C), 1);
const key_override_t ctrl_v_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_V, G(KC_V), 1);
const key_override_t ctrl_x_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_X, G(KC_X), 1);
const key_override_t ctrl_z_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_Z, G(KC_Z), 1);
const key_override_t ctrl_f_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_F, G(KC_F), 1);
const key_override_t ctrl_a_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_A, G(KC_A), 1);
const key_override_t ctrl_d_key_override = ko_make_with_layers(MOD_MASK_CTRL, KC_D, G(KC_D), 1); // duplicate line

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
	&ctrl_c_key_override,
	&ctrl_v_key_override,
	&ctrl_x_key_override,
	&ctrl_z_key_override,
	&ctrl_f_key_override,
	&ctrl_a_key_override,
	&ctrl_d_key_override,
	NULL // Null terminate the array of overrides!
};
 
//***************************************************
//CUSTOM
//***************************************************


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// layer Mac
[0] = LAYOUT_ansi_84(
	TD(TD_ESC_NUMBERS),	KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 		KC_F12, 	MAC_PRTA,	KC_INS,		KC_DEL,
	KC_GRV, 			KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,		KC_EQL, 				KC_BSPC,	KC_PGUP,
	KC_TAB, 			KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,		KC_RBRC, 				KC_BSLS,	KC_PGDN,
	KC_LCTL,			KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_HOME,
	TD(TD_LSHIFT_CAPS),	KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,  TD(TD_RSHIFT_CAPS),	KC_UP,		KC_END,
	KC_LALT,	KC_LGUI,	KC_RALT,										KC_SPC, 							KC_RALT,	MO(1),   		KC_RCTL,				KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer Mac Fn
[1] = LAYOUT_ansi_84(
	_______, 	KC_BRID,  	KC_BRIU,  	MAC_TASK, 	MAC_SEARCH, MAC_VOICE,  MAC_DND,    KC_MPRV,  	KC_MPLY,  	KC_MNXT, 	KC_MUTE, 	KC_VOLD, 	KC_VOLU, 	MAC_PRT,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(4), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(1),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer win
[2] = LAYOUT_ansi_84(
	TD(TD_ESC_NUMBERS), KC_F1,  	KC_F2,  	KC_F3, 		KC_F4,  	KC_F5,  	KC_F6,  	KC_F7,  	KC_F8,  	KC_F9, 		KC_F10, 	KC_F11, 	KC_F12, 	KC_PSCR,	KC_INS,		KC_DEL,
	KC_GRV, 			KC_1,   	KC_2,   	KC_3,  		KC_4,   	KC_5,   	KC_6,   	KC_7,   	KC_8,   	KC_9,  		KC_0,   	KC_MINS,	KC_EQL, 				KC_BSPC,	KC_PGUP,
	KC_TAB, 			KC_Q,   	KC_W,   	KC_E,  		KC_R,   	KC_T,   	KC_Y,   	KC_U,   	KC_I,   	KC_O,  		KC_P,   	KC_LBRC,	KC_RBRC, 				KC_BSLS,	KC_PGDN,
	KC_LCTL,			KC_A,   	KC_S,   	KC_D,  		KC_F,   	KC_G,   	KC_H,   	KC_J,   	KC_K,   	KC_L,  		KC_SCLN,	KC_QUOT, 	 						KC_ENT,		KC_HOME,
	TD(TD_LSHIFT_CAPS),	KC_Z,   	KC_X,   	KC_C,  		KC_V,   	KC_B,   	KC_N,   	KC_M,   	KC_COMM,	KC_DOT,		KC_SLSH,		TD(TD_RSHIFT_CAPS),	    KC_UP,	KC_END,
	KC_LALT,	KC_LGUI,	KC_RALT,										KC_SPC, 							KC_RALT,	MO(3),   	KC_RCTL,				KC_LEFT,	KC_DOWN,    KC_RGHT),

// layer win Fn
[3] = LAYOUT_ansi_84(
	_______, 	KC_BRID,   	KC_BRIU,    _______,  	_______,   	_______,   	_______,   	KC_MPRV,   	KC_MPLY,   	KC_MNXT,  	KC_MUTE, 	KC_VOLD, 	KC_VOLU,	_______,	_______,	_______,
	_______, 	LNK_BLE1,  	LNK_BLE2,  	LNK_BLE3,  	LNK_RF,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	DEV_RESET,	SLEEP_MODE, 			BAT_SHOW,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,	MO(4), 		RGB_SPD,	RGB_SPI,	_______,				_______,	RGB_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(3),   	_______,				RGB_MOD,	RGB_VAD,    RGB_HUI),

// layer 4
[4] = LAYOUT_ansi_84(
	_______, 	_______,  	_______,  	_______, 	_______,  	_______,  	_______,  	_______,  	_______,  	_______, 	_______, 	_______, 	_______, 	_______,	_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______, 	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,   	_______,	_______, 				_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	_______,   	_______,  	_______,	_______, 	 						_______,	_______,
	_______,				_______,   	_______,   	_______,  	_______,   	_______,   	_______,   	_______,   	SIDE_SPD,	SIDE_SPI,	_______,				_______,	SIDE_VAI,	_______,
	_______,	_______,	_______,										_______, 							_______,	MO(4),   	_______,				SIDE_MOD,	SIDE_VAD,   SIDE_HUI),


// layer 5 numbers
[5] = LAYOUT_ansi_84(
	TD(TD_ESC_NUMBERS), 	_______,  	_______,	_______, 	_______,  	_______,   	_______,  	_______,  	_______,	_______, 	_______,  	_______,   	_______, 	_______,	_______,	_______,
	_______, 	_______,  	_______,	_______, 	_______,  	_______,   	_______,	KC_7,   	KC_8,   	KC_9,  		_______,	_______,	_______, 				_______,	_______,
	_______, 	_______,  	_______,	_______, 	_______,  	_______,   	_______,   	KC_4,   	KC_5,   	KC_6,  		_______,   	_______, 	_______, 				_______,	_______,
	_______,	_______,   	_______,   	_______,  	_______,   	_______,  	_______,  	KC_1,   	KC_2,   	KC_3,  		_______, 	_______, 	 						_______,	_______,
	_______,			  	_______,   	_______,  	_______,   	_______,   	_______,	KC_0,      	_______,	_______, 	_______,	_______,			   	_______,	KC_UP,		_______,
	_______,	_______,	_______,										_______, 							_______,	_______, 	_______,				KC_LEFT,	KC_DOWN,    KC_RGHT),
};