#include "keycodes.h"
#include "quantum.h"
#include "bheznz.h"

char* keycode_to_ascii(uint16_t keycode) {
    static char str[5];

    switch (keycode) {
        case 0x0000: return "NO";
        case 0x0001: return "____";
        case 0x0004: return "A";
        case 0x0005: return "B";
        case 0x0006: return "C";
        case 0x0007: return "D";
        case 0x0008: return "E";
        case 0x0009: return "F";
        case 0x000A: return "G";
        case 0x000B: return "H";
        case 0x000C: return "I";
        case 0x000D: return "J";
        case 0x000E: return "K";
        case 0x000F: return "L";
        case 0x0010: return "M";
        case 0x0011: return "N";
        case 0x0012: return "O";
        case 0x0013: return "P";
        case 0x0014: return "Q";
        case 0x0015: return "R";
        case 0x0016: return "S";
        case 0x0017: return "T";
        case 0x0018: return "U";
        case 0x0019: return "V";
        case 0x001A: return "W";
        case 0x001B: return "X";
        case 0x001C: return "Y";
        case 0x001D: return "Z";
        case 0x001E: return "1";
        case 0x001F: return "2";
        case 0x0020: return "3";
        case 0x0021: return "4";
        case 0x0022: return "5";
        case 0x0023: return "6";
        case 0x0024: return "7";
        case 0x0025: return "8";
        case 0x0026: return "9";
        case 0x0027: return "0";
        case 0x0028: return "ENT";
        case 0x0029: return "ESC";
        case 0x002A: return "BSPC";
        case 0x002B: return "TAB";
        case 0x002C: return "SPC";
        case 0x002D: return "-";
        case 0x002E: return "=";
        case 0x002F: return "[";
        case 0x0030: return "]";
        case 0x0031: return "\\";
        case 0x0032: return "#";
        case 0x0033: return ";";
        case 0x0034: return "'";
        case 0x0035: return "`";
        case 0x0036: return ",";
        case 0x0037: return ".";
        case 0x0038: return "/";
        case 0x0039: return "CAPS";
        case 0x003A: return "F1";
        case 0x003B: return "F2";
        case 0x003C: return "F3";
        case 0x003D: return "F4";
        case 0x003E: return "F5";
        case 0x003F: return "F6";
        case 0x0040: return "F7";
        case 0x0041: return "F8";
        case 0x0042: return "F9";
        case 0x0043: return "F10";
        case 0x0044: return "F11";
        case 0x0045: return "F12";
        case 0x0046: return "PSCR";
        case 0x0047: return "SLCK";
        case 0x0048: return "PAUS";
        case 0x0049: return "INS";
        case 0x004A: return "HOME";
        case 0x004B: return "PGUP";
        case 0x004C: return "DEL";
        case 0x004D: return "END";
        case 0x004E: return "PGDN";
        case 0x004F: return "RGT";
        case 0x0050: return "LFT";
        case 0x0051: return "DWN";
        case 0x0052: return "UP";
        case 0x7820: return "rTG";
        case 0x7821: return "rMdF";
        case 0x7822: return "rMdR";
        case 0x7823: return "rHUI";
        case 0x7824: return "rHUD";
        case 0x7825: return "rSAI";
        case 0x7826: return "rSAD";
        case 0x7827: return "rVAI";
        case 0x7828: return "rVAD";
        case 0x7829: return "rSPI";
        case 0x782A: return "rSPD";
        case 0x782B: return "rPLN";
        case 0x782C: return "rBTH";
        case 0x782D: return "rRBW";
        case 0x782E: return "rSWL";
        case 0x782F: return "rSNK";
        case 0x7830: return "rKNI";
        case 0x7831: return "rXMS";
        case 0x7832: return "rGRD";
        case 0x7833: return "rTST";
        case 0x7834: return "rTWN";
        case 0x7C00: return "BLD";
        case 0x7C01: return "RBOOT";
        case 0x7C02: return "DBGTL";
        case 0x7C03: return "CLRERP";
        case 0x00CD: return "MUP";
        case 0x00CE: return "MDWN";
        case 0x00CF: return "MLFT";
        case 0x00D0: return "MRGT";
        case 0x00D1: return "MB1";
        case 0x00D2: return "MB2";
        case 0x00D3: return "MB3";
        case 0x00D4: return "MB4";
        case 0x00D5: return "MB5";
        case 0x00D6: return "MB6";
        case 0x00D7: return "MB7";
        case 0x00D8: return "MB8";
        case 0x00D9: return "MWU";
        case 0x00DA: return "MWD";
        case 0x00DB: return "MWL";
        case 0x00DC: return "MWR";
        case 0x00DD: return "MA0";
        case 0x00DE: return "MA1";
        case 0x00DF: return "MA2";
        case 0x00E0: return "LCTL";
        case 0x00E1: return "LSFT";
        case 0x00E2: return "LALT";
        case 0x00E3: return "LGUI";
        case 0x00E4: return "RCTL";
        case 0x00E5: return "RSFT";
        case 0x00E6: return "RALT";
        case 0x00E7: return "RGUI";
        default: str[0] = ' '; str[1] = ' '; return str; // Unknown keycode
    }
}

/** a simple keycode to ascii converter **/

char* keycode_to_ascii2(uint16_t keycode) {

    //reuse char array
    static char ascii[4] = { ' ', ' ', '\0'}; // 初始化为全空字符串
    if (keycode >= KC_A && keycode <= KC_Z) {
        ascii[1] = 'A' + ((keycode - KC_A) % 26);
    } else if (keycode >= KC_1 && keycode <= KC_9) {
        ascii[1] = '1' + ((keycode - KC_1) % 9);
    } else {
        switch (keycode) {
            case KC_0:
                ascii[1] = '0';
                break;
            case KC_ENTER:
            case KC_ESCAPE:
            case KC_BACKSPACE:
            case KC_TAB:
            case KC_SPACE:
            case KC_MINUS:
            case KC_EQUAL:
            case KC_LEFT_BRACKET:
            case KC_RIGHT_BRACKET:
            case KC_BACKSLASH:
            case KC_NONUS_HASH:
            case KC_SEMICOLON:
            case KC_QUOTE:
            case KC_GRAVE:
            case KC_COMMA:
            case KC_DOT:
            case KC_SLASH:
            case KC_CAPS_LOCK:
                ascii[1] = (char[]){'n', 'E', 'S', 't', ' ', '-', '=', '[', ']', '\\', '#', ';', '\'', '`', ',', '.', '/'}[keycode - KC_ENTER];
                break;
            case RGB_TOG:
                return "RGBT";
                break;
            case RGB_MOD:
                return "RM+";
                break;
            case RGB_RMOD:
                return "RM-";
                break;
            case RGB_VAI :
                return "RV+";
                break;
            case RGB_VAD :
                return "RV-";
                break;
            case RGB_HUI :
                return "RH+";
                break;
            case RGB_HUD :
                return "RH-";
                break;
            case RGB_SPI :
                return "RS+";
                break;
            case RGB_SPD :
                return "RS-";
                break;
            case QK_BOOT :
                return "BOOT";
                break;
            case QK_DEBUG_TOGGLE:
                return "DEBG";
                break;
            case KC_UP:
                return "UP";
                break;
            case KC_DOWN:
                return "DWN";
                break;
            case KC_LEFT:
                return "<-";
                break;
            case KC_RIGHT:
                return "->";
                break;
            case KC_LEFT_CTRL:
                return "CTL";
                break;
            case KC_LEFT_SHIFT:
                return "SHT";
                break;
            default:
                ascii[0] = '-'; // 对于不表示打印字符的按键，返回空字符串
                ascii[1] = '-'; // 对于不表示打印字符的按键，返回空字符串
                break;
        }
    }

    return ascii;
}


// 定义一个足够大的数组来存储按键代码
// QMK 中，一个 keycode 通常定义为 uint16_t 类型
#define KEYCODE_HISTORY_SIZE 3
static uint16_t keycode_history[KEYCODE_HISTORY_SIZE] = {KC_NO, KC_NO, KC_NO};

// 更新存储的按键代码历史
void add_keycode_to_history(uint16_t keycode) {
    // 将历史记录中的每个键码往后移动一个位置
    for (int i = KEYCODE_HISTORY_SIZE - 1; i > 0; i--) {
        keycode_history[i] = keycode_history[i - 1];
    }
    // 在数组的起始位置插入新的键码
    keycode_history[0] = keycode;
}


// 打印最近的三个按键代码
// TODO limit buffer size
void sprint_recent_keycodes(char * buffer, uint8_t size) {
    char *buff_ptr = buffer;
    *buff_ptr = '\0';

    for (int i = 0; i < KEYCODE_HISTORY_SIZE; i++) {
        // 获取键码对应的字符
        char *key_char = keycode_to_ascii(keycode_history[i]);
        // move pointer
        buff_ptr += snprintf(buff_ptr, 6, "%4s ", key_char);
    }
    if( buff_ptr != buffer ) {
        //remove last space
        *(buff_ptr-1) = '\0';
    }
}

// 打印最近的三个按键代码
void print_recent_keycodes(void) {
    // 输出存储的按键代码到控制台
    dprint("Recent keycodes: ");
    for (int i = 0; i < KEYCODE_HISTORY_SIZE; i++) {
        uprintf("%s ", keycode_to_ascii(keycode_history[i]));
    }
    dprint("\n");
}

