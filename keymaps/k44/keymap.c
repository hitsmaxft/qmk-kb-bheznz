// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "quantum.h"
#include "bheznz.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ A │ S │ D │ F │
     * ├───┼───┼───┼───┤
     * │ Z │ X │ C │ V │
     * └───┴───┴───┴───┘
     */
    [0] = LAYOUT_ortho_4x4(
        _______,    KC_UP  ,    KC_SPC,         KC_A,
        KC_LEFT,    KC_ENTER,   KC_RIGHT,       KC_B,
        KC_LEFT_CTRL,    KC_DOWN,    KC_LEFT_SHIFT,        KC_C,
        LT(1, KC_Z),    KC_BACKSPACE,   LT(2, KC_C),    KC_D
    ),
    [1] = LAYOUT_ortho_4x4(
        RGB_SPI,    RGB_VAI,    RGB_HUI,    _______,
        RGB_SPD,    RGB_VAD,    RGB_HUD,    _______,
        RGB_MOD,    RGB_TOG,    _______,    KC_ZNZ_DEBUG,
        KC_NO,      QK_BOOT,    _______,   QK_DEBUG_TOGGLE
    ),
    [2] = LAYOUT_ortho_4x4(
        KC_1,    KC_2,    KC_3,    KC_A,
        KC_4,    KC_5,    KC_6,    KC_B,
        KC_7,    KC_8,    KC_9,    KC_C,
        _______, KC_0,    KC_NO,   KC_D
    ),
};
