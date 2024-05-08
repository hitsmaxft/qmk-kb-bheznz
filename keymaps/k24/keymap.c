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
    [0] = LAYOUT_ortho_2x4(
        LT(2, KC_A),    KC_S,    KC_D,    KC_F,
        LT(1, KC_Z),    KC_X,    KC_C,    KC_V
    ),
    [1] = LAYOUT_ortho_2x4(
        _______,    RGB_VAI,    RGB_HUI,    RGB_HUD,
        _______,    RGB_VAD,    RGB_MOD,    RGB_RMOD
    ),
    [2] = LAYOUT_ortho_2x4(
        _______,    RGB_TOG,    _______,    KC_ZNZ_DEBUG,
        QK_BOOT,    QK_DEBUG_TOGGLE,    RGB_SPI,   RGB_SPD
    ),
};
