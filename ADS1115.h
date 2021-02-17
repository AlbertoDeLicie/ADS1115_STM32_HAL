#include <Channel_ADS1115.h>
#include <Registers_ADS1115.h>
#include <VoltageConvert_ADS1115.h>
#include "stm32f4xx_hal.h"

#ifndef SRC_ADS1115_H_
#define SRC_ADS1115_H_

class ADS1115 {
public:
	ADS1115(I2C_HandleTypeDef* hi2c, ADS1115_ADDRESS addr);
	int16_t write_ADS1115(OS os, MUX mux, PGA pga, MODE mode, DR dr, COMP_MODE comp_mode, COMP_POL comp_pol, COMP_LAT comp_lat, COMP_QUE comp_que);

	int16_t read_ADS1115(Channel channel, PGA pga, DR dr = SPS128);

	float readVoltage_ADS1115(Channel channel, PGA pga, DR dr = SPS128);

	virtual ~ADS1115();

private:
	void setRegBits(OS os, MUX mux, PGA pga, MODE mode, DR dr, COMP_MODE comp_mode, COMP_POL comp_pol, COMP_LAT comp_lat, COMP_QUE comp_que);

	I2C_HandleTypeDef* hi2c;
	ADS1115_ADDRESS addr;
	unsigned char * regBits = new unsigned char[3];
	int16_t reading;
};

#endif /* SRC_ADS1115_H_ */
