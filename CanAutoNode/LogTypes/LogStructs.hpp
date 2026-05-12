/*
 * LogStructs.hpp
 *
 *  Created on: May 2, 2026
 *      Author: Local user
 */

#ifndef LOGSTRUCTS_HPP_
#define LOGSTRUCTS_HPP_

#define PACK_CAN_STRUCTS

#ifdef PACK_CAN_STRUCTS
#pragma pack(push,1)
#endif
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
#ifdef PACK_CAN_STRUCTS
#pragma pack(pop)
#endif

#endif /* LOGSTRUCTS_HPP_ */
