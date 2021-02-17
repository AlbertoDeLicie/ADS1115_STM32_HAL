#ifndef SRC_REGISTERS_H_
#define SRC_REGISTERS_H_

enum ADS1115_ADDRESS {
	ADDR_TO_GND = 0x48,
	ADDR_TO_VDD = 0x49,
	ADDR_TO_SDA = 0x4A,
	ADDR_TO_SCL = 0x4B

};

enum REG {
	CONV_REG = 0x0,
	CONF_REG = 0x1,
	Lo_thresh_REG = 0x2,
	Hi_thresh_REG = 0x3
};

enum OS {
	W_NE = 0x0,
	W_SC = 0x1,
	R_CC = 0x0,
	R_NCC = 0x1
};


enum MUX {
	AIN0_AIN1 = 0x0,
	AIN0_AIN3 = 0x1,
	AIN1_AIN3 = 0x2,
	AIN2_AIN3 = 0x3,
	AIN0_AIN_GND = 0x4,
	AIN1_AIN_GND = 0x5,
	AIN2_AIN_GND = 0x6,
	AIN3_AIN_GND = 0x7
};

enum PGA {
	FS6144 = 0x0,
	FS4096 = 0x1,
	FS2048 = 0x2,
	FS1024 = 0x3,
	FS0512 = 0x4,
	FS0256_0 = 0x5,
	FS0256_1 = 0x6,
	FS0256_2 = 0x7
};

enum MODE {
	CCM = 0x0,
	PDSSM = 0x1
};

enum DR {
	SPS8 = 0x0,
	SPS16 = 0x1,
	SPS32 = 0x2,
	SPS64 = 0x3,
	SPS128 = 0x4,
	SPS250 = 0x5,
	SPS475 = 0x6,
	SPS860 = 0x7
};

enum COMP_MODE {
	TCWH = 0x0,
	WC = 0x1
};

enum COMP_POL {
	AL = 0x0,
	AH = 0x1
};

enum COMP_LAT {
	NLC = 0x0,
	LC = 0x1
};

enum COMP_QUE {
	AAOC = 0x0,
	AATC = 0x1,
	AAFC = 0x2,
	DC = 0x3
};

#endif /* SRC_REGISTERS_H_ */

