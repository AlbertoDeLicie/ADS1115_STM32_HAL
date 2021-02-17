#include <Registers_ADS1115.h>

#ifndef SRC_CHANNEL_H_
#define SRC_CHANNEL_H_

enum Channel {
	Channel_0 = AIN0_AIN_GND,
	Channel_1 = AIN1_AIN_GND,
	Channel_2 = AIN2_AIN_GND,
	Channel_3 = AIN3_AIN_GND,
	Differential_0_1 = AIN0_AIN1,
	Differential_0_3 = AIN0_AIN3,
	Differential_1_3 = AIN1_AIN3,
	Differential_2_3 = AIN2_AIN3
};

#endif /* SRC_CHANNEL_H_ */
