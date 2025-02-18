#pragma once

// April 2023 update: QMK supports GMMK Pro by emulating EEPROM through its onboard flash and using a wear-leveling algorithm to spread out writes. Recent QMK changes require me to now explicitly specify a larger EEPROM
// size to properly fit my firmware (which requires 1195 bytes as of April 10, 2023). In the future, I may need to increase this if firmware grows further. Also, I don't currently explicitly call out EEPROM_DRIVER = wear_leveling and
// WEAR_LEVELING_DRIVER = embedded_flash in rules.mk but may need to in the future if defaults change -- QMK should eventually support writing to my MCU's actual EEPROM.
#define WEAR_LEVELING_LOGICAL_SIZE 1280             //default 1024    Number of bytes “exposed” to the rest of QMK and denotes the size of the usable EEPROM.
#define WEAR_LEVELING_BACKING_SIZE 2560             //default 2048    Number of bytes used by the wear-leveling algorithm for its underlying storage, and needs to be a multiple of the logical size.

// Force n-key rollover
#define FORCE_NKRO

// Set keyboard debounce time (originally 5ms, now 8ms to combat touchy switches)
#define DEBOUNCE 8
// Set TT to two taps
#define TAPPING_TOGGLE 2

// Caps Word configuration
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
#define CAPS_WORD_IDLE_TIMEOUT 10000      // Automatically turn off after x milliseconds of idle. 0 to never timeout.

// #define TAPPING_TERM 180
#define TAPPING_TERM 300
#define TAPPING_TERM_PER_KEY
