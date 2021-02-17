#include "ADS1115.h"

ADS1115::ADS1115(I2C_HandleTypeDef* hi2c, ADS1115_ADDRESS addr) : hi2c(hi2c), addr(addr) {}

ADS1115::~ADS1115() {
	delete[] regBits;
}

void ADS1115::setRegBits(OS os, MUX mux, PGA pga, MODE mode, DR dr, COMP_MODE comp_mode, COMP_POL comp_pol, COMP_LAT comp_lat, COMP_QUE comp_que) {
	regBits[1] = (os << 7) | (mux << 4) | (pga << 1) | mode;
	regBits[2] = (dr << 5) | (comp_mode << 4) | (comp_pol << 3) | (comp_lat << 2) | comp_que;
}

int16_t ADS1115::write_ADS1115(OS os, MUX mux, PGA pga, MODE mode, DR dr, COMP_MODE comp_mode, COMP_POL comp_pol, COMP_LAT comp_lat, COMP_QUE comp_que){
	regBits[0] = CONF_REG;
	setRegBits(os, mux, pga, mode, dr, comp_mode, comp_pol, comp_lat, comp_que);
	HAL_I2C_Master_Transmit(hi2c, addr<<1, regBits, 3, 10);

	regBits[0] = CONV_REG;
	HAL_I2C_Master_Transmit(hi2c, addr<<1, regBits, 1, 10);

	HAL_I2C_Master_Receive(hi2c, addr<<1, regBits, 2, 10);

	reading = (regBits[0] << 8 | regBits[1]);
	if(reading < 0 ) {
		reading = 0;
	}

	return reading;
}

int16_t ADS1115::read_ADS1115(Channel channel, PGA pga, DR dr){
	return write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC);
}

float ADS1115::readVoltage_ADS1115(Channel channel, PGA pga, DR dr){
	float voltage;

	switch(pga){
		case(FS6144):
				voltage = write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC) * CONVERT6144;
				break;
		case(FS4096):
				voltage = write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC) * CONVERT4096;
				break;
		case(FS2048):
				voltage = write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC) * CONVERT2048;
				break;
		case(FS1024):
				voltage = write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC) * CONVERT1024;
				break;
		case(FS0512):
				voltage = write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC) * CONVERT0512;
				break;
		case(FS0256_0):
				voltage = write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC) * CONVERT0256;
				break;
		case(FS0256_1):
				voltage = write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC) * CONVERT0256;
				break;
		case(FS0256_2):
				voltage = write_ADS1115(W_SC, (MUX)channel, pga, PDSSM, dr, TCWH, AL, NLC, DC) * CONVERT0256;
				break;
	}

	return voltage;
}
