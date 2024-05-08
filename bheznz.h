#pragma once
#include "quantum.h"
#include <stdint.h>

void pre_kb_init_user(void);
void setup_znz_usb(void);
void add_keycode_to_history(uint16_t keycode);
void print_recent_keycodes(void);
void sprint_recent_keycodes(char * buffer, uint8_t size);

char* keycode_to_ascii(uint16_t keycode);

enum ZNZKeyCodes {
    KC_ZNZ_DEBUG = QK_KB_0
};
