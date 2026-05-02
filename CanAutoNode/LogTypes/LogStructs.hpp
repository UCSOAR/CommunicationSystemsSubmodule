/*
 * LogStructs.hpp
 *
 *  Created on: May 2, 2026
 *      Author: Local user
 */

#ifndef LOGSTRUCTS_HPP_
#define LOGSTRUCTS_HPP_

// Possible IMU structs
struct CanImuData9Axis {
	uint32_t accel_x;
	uint32_t accel_y;
	uint32_t accel_z;
	uint32_t gyro_x;
	uint32_t gyro_y;
	uint32_t gyro_z;
	uint32_t mag_x;
	uint32_t mag_y;
	uint32_t mag_z;
};

struct CanImuData6Axis {
	uint32_t accel_x;
	uint32_t accel_y;
	uint32_t accel_z;
	uint32_t gyro_x;
	uint32_t gyro_y;
	uint32_t gyro_z;
};

struct CanAccelData {
	uint32_t accel_x;
	uint32_t accel_y;
	uint32_t accel_z;
};

struct CanGyroData {
	uint32_t gyro_x;
	uint32_t gyro_y;
	uint32_t gyro_z;
};

struct CanMagData {
	uint32_t mag_x;
	uint32_t mag_y;
	uint32_t mag_z;
};


// Template Examples - Will be removed later
struct ExampleDataA {
	uint32_t a;
	uint8_t b;
	uint8_t c[10];
};

struct ExampleDataB {

	uint8_t b;
	uint8_t c[5];
};




#endif /* LOGSTRUCTS_HPP_ */
