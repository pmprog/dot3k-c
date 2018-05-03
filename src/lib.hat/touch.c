#include <math.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "i2c-dev.h"
#include "dothat_private.h"

void dothat_input_recalibrate(DOTHAT *dothat)
{
	if(NOT_OPEN(dothat)) return;
	// Target input device
	ioctl(dothat->i2c_fd, I2C_SLAVE, 0x2C);
	// Call recalibration
	i2c_smbus_write_i2c_block_data(dothat->i2c_fd, 0x26, 1, (uint8_t[]){0b00111111});
}

uint8_t dothat_input_poll(DOTHAT *dothat)
{
	uint8_t inputmap = 0x00;
	uint8_t threshold[6] = { 0, 0, 0, 0, 0, 0 };
	uint8_t delta[6] = { 0, 0, 0, 0, 0, 0 };
	
	int touched = i2c_smbus_read_byte_data(dothat->i2c_fd, R_INPUT_STATUS);

	i2c_smbus_read_i2c_block_data(dothat->i2c_fd, R_INPUT_1_THRESH, 6, &threshold);
	i2c_smbus_read_i2c_block_data(dothat->i2c_fd, R_INPUT_1_DELTA, 6, &delta);

	// TODO: Conver to bitmask

	return 0;
}