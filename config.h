#pragma once

/**
 * pb7
 * TIM4_CH2 Channel 4
 * TIM4_UP channel 7
 */

/**
 *
 * 24C02/24C04
 * Two-Wire Serial EEPROM
 * Preliminary datasheet 2K (256 X 8)
 * 1/15 MRD
 * Internally Organized 256 X 8 (2K)
 * Write Protect Pin for Hardware Data Protection
 * 8-byte Page (2K)
 *
 * Modes
 *
 * Self-timed Write Cycle (5 ms max)
 * – Endurance: 1 Million Write Cycles
 * – Data Retention: 100 Years
 *
 * The 24C02 / 24C04 provides 2048/4096 bits of
 * serial electrically erasable and programmable
 * read-only memory (EEPROM) organized as
 * 256/512 words of 8 bits each The device is
 * optimized for use in many industrial
 */

/*
#define STM32_ONBOARD_EEPROM_SIZE  256
#    define EXTERNAL_EEPROM_I2C_BASE_ADDRESS 0b10100000
#    define EXTERNAL_EEPROM_BYTE_COUNT 256 //words
#    define EXTERNAL_EEPROM_PAGE_SIZE 8
#    define EXTERNAL_EEPROM_ADDRESS_SIZE 1
#    define EXTERNAL_EEPROM_WRITE_TIME 5 //ms
*/

#define DEBUG_EEPROM_OUTPUT

// ouput on pb0 tim3ch3
#define WS2812_PWM_DRIVER        PWMD3

#define ZNZ_DMA_CHN_TIM3_CH3 2
#define ZNZ_DMA_CHN_TIM3_UP 3

#define WS2812_PWM_CHANNEL      3    // default: 2

//noused in gpiov1
//#define WS2812_PWM_PAL_MODE      2                    // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 2
#define WS2812_PWM_DMA_STREAM        STM32_DMA1_STREAM3     // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
                                                            // always map to zero under dmav1
#define WS2812_PWM_DMA_CHANNEL       3                      // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
//use af_pp
#undef  WS2812_EXTERNAL_PULLUP

//#define WS2812_PWM_DMAMUX_ID         STM32_DMAMUX1_TIM3_UP  // DMAMUX configuration for TIMx_UP -- only required if your MCU has a DMAMUX peripheral, see the respective reference manual for the appropriate values for your MCU.

#define RGBLIGHT_LED_COUNT 16
#define RGB_MATRIX_LED_COUNT 16



// for oled display
#define OLED_IC  OLED_IC_SSD1306

#define OLED_CS_PIN B6
#define OLED_DC_PIN B7
#define OLED_DISPLAY_128X64 TRUE

