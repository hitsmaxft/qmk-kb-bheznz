#include "bheznz.h"
#include <stdint.h>
#include <stdio.h>

#include "action_layer.h"
#include "info_config.h"
#include "bootloader.h"
#include "config.h"

#include "ws2812.h"
#include "debug.h"
#include "print.h"
#include "rgb_matrix.h"


extern const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS];

void _znz_eeconfig_debug_rgb_matrix(void) {
    dprintf("rgb_matrix_config EEPROM\n");
    dprintf("rgb_matrix_config.enable = %d\n", rgb_matrix_config.enable);
    dprintf("rgb_matrix_config.mode = %d\n", rgb_matrix_config.mode);
    dprintf("rgb_matrix_config.hsv.h = %d\n", rgb_matrix_config.hsv.h);
    dprintf("rgb_matrix_config.hsv.s = %d\n", rgb_matrix_config.hsv.s);
    dprintf("rgb_matrix_config.hsv.v = %d\n", rgb_matrix_config.hsv.v);
    dprintf("rgb_matrix_config.speed = %d\n", rgb_matrix_config.speed);
    dprintf("rgb_matrix_config.flags = %d\n", rgb_matrix_config.flags);
}

// show debug
rgb_led_t leds[16] = {
    [0 ... 15] = {
        .g=255,
        .r=0,
        .b=0,
    }
};

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable=false;
    debug_matrix=false;
    //debug_keyboard=true;
    //debug_mouse=true;
    rgb_matrix_set_color_all(0,0,0);
    rgb_matrix_set_color_all(0,0,0);
}


void bootloader_jump(void) {
    //写入 bootloader 标记, 下次重启自动进入bootloader
    BKP->DR10 = RTC_BOOTLOADER_FLAG;
    NVIC_SystemReset();
}

void mcu_reset(void) {
    BKP->DR10 = RTC_BOOTLOADER_FLAG;
    NVIC_SystemReset();
}

 bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_ZNZ_DEBUG:
            if (record->event.pressed) {
                _znz_eeconfig_debug_rgb_matrix();
                print_recent_keycodes();
            }
            debug_enable=!debug_enable;
            return false;
        default:
            print_recent_keycodes();
            return true; // Process all other keycodes normally
    }
    return true;
}

void snprintf_keymap(uint16_t layer, char* buffer, uint8_t size) {
    char* output = buffer;

    for (int r = 0; r < MATRIX_ROWS; r++) {
        for (int c=0 ; c < MATRIX_COLS; c++) {
            uint16_t kc = keymaps[layer][r][c];
            char* str = keycode_to_ascii(kc);
            output += snprintf(output, size , "%4s|", str);
        }
        *(output-1)  = '\n';

    }
}


#ifdef OLED_ENABLE
bool oled_task_user(void) {


    // MATRIX_COLS
    // MATRIX_ROWS
    //
    //
    oled_write_P(PSTR("Layer: "), false);


    char buffer[200];
    uint16_t layer_id = get_highest_layer(layer_state);
    switch (layer_id) {
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("1\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("2\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_P(PSTR("Undefined\n"), false);
    }

    snprintf_keymap(layer_id, buffer, 200);

    oled_write_P(PSTR(buffer), false);

    sprintf(buffer, "RgbMode %d\n", rgb_matrix_config.mode);
    oled_write_P(PSTR(buffer), false);
    sprint_recent_keycodes(buffer, 24);
    dprintf("oled history string '%s'\n" ,  buffer);
    oled_write_P(PSTR(buffer), false);
    //   oled_write_ln_P(PSTR("\n"), false);
    // Host Keyboard LED Status
    //led_t led_state = host_keyboard_led_state();
    //oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    //oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    //oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif
