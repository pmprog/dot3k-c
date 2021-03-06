#include <stdint.h>
#include <poll.h>

typedef struct {
    int i2c_fd;
    int spi_fd;

    // Backlight
    uint8_t backlight_level[18];
    uint32_t backlight_enable;
    uint8_t backlight_level_map[18][256];
    // Input
    uint8_t input_state;
    // LCD
    int lcd_register_select_gpio_pin;
    int lcd_width;
    int lcd_height;
} DOTHAT;

int rpi_gpio_open(void);
void rpi_gpio_setup_pin(int gpio,int direction,int pud);
int rpi_gpio_function(int gpio);
void rpi_gpio_output(int gpio,int value);
int rpi_gpio_input(int gpio);
void rpi_gpio_close(void);

#define GPIO_IN 1
#define GPIO_OUT 0
#define GPIO_PUD_OFF 0
#define GPIO_PUD_DOWN 1
#define GPIO_PUD_UP 2


#define R_LED_BEHAVIOUR_1   0x81 # For LEDs 1-4
#define R_LED_BEHAVIOUR_2   0x82 # For LEDs 5-8
#define R_LED_PULSE_1_PER   0x84
#define R_LED_PULSE_2_PER   0x85
#define R_LED_BREATHE_PER   0x86
#define R_LED_CONFIG        0x88
#define R_LED_PULSE_1_DUT   0x90
#define R_LED_PULSE_2_DUT   0x91
#define R_LED_BREATHE_DUT   0x92
#define R_LED_DIRECT_DUT    0x93
#define R_LED_DIRECT_RAMP   0x94
#define R_LED_OFF_DELAY     0x95


#define R_LED_OUTPUT_TYPE		0x71
#define R_LED_LINKING				0x72
#define R_LED_POLARITY			0x73
#define R_LED_OUTPUT_CON		0x74
#define R_LED_LTRANS_CON		0x77
#define R_LED_MIRROR_CON		0x79

#define R_INPUT_STATUS      0x03
#define R_INPUT_1_THRESH    0x30
#define R_INPUT_1_DELTA     0x10
#define R_INPUT_ENABLE      0x21

#define R_SAMPLING_CONFIG   0x24 // Default 0x00111001
#define R_CALIBRATION       0x26 // Default 0b00000000
#define R_INTERRUPT_EN      0x27 // Default 0b11111111
#define R_REPEAT_EN         0x28 // Default 0b11111111
#define R_MTOUCH_CONFIG     0x2A // Default 0b11111111
#define R_MTOUCH_PAT_CONF   0x2B
#define R_MTOUCH_PATTERN    0x2D
#define R_COUNT_O_LIMIT     0x2E
#define R_RECALIBRATION     0x2F
#define R_CONFIGURATION2    0x44
#define R_GENERAL_CONFIG    0x20
#define R_SENSITIVITY       0x1F
#define R_MAIN_CONTROL      0x00

#define COMMAND_BIAS        0x14 // 0b00010100

#define BUILDING_DOTHAT
#include "dothat.h"

