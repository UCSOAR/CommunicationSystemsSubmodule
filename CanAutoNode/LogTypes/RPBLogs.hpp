/*
 * CanStructs.hpp
 *
 *  Created on: May 2, 2026
 *      Author: Local user
 */

#ifndef RPBLOGS_HPP_
#define RPBLOGS_HPP_

#include "LogStructs.hpp"
#include "CanAutoNodeDaughter.hpp"

#ifdef PACK_CAN_STRUCTS
#pragma pack(push,1)
#endif
// Custom Data Types
struct RPB_CAMERA_POWER_COMMAND {
	uint8_t camera;
	bool enable;
};

struct RPB_CAMERA_RECORDING_COMMAND {
	uint8_t camera;
	bool record;
};

struct RPB_CAMERA_SWITCH_COMMAND {
	uint8_t camera;
};

struct RPB_AIR_BRAKES_COMMAND {
	bool openAirBrakes;
};

struct RPB_FROM_DAQ_AIR_BRAKES_LEVEL {
	uint8_t level;
};

struct RPB_CAMERA_SIMULATE_BUTTON_COMMAND {
	uint8_t cam;
	// 0x00 wifi btn
	// 0x01 power btn
	// 0x02 mode switch
	uint8_t button;
};

#ifdef PACK_CAN_STRUCTS
#pragma pack(pop)
#endif
// Add CAN logs here in the order you want them
#define RPB_CAN_LOGS \
	X(RPB_CAMERA_POWER_COMMAND) \
	X(RPB_CAMERA_RECORDING_COMMAND) \
	X(RPB_CAMERA_SWITCH_COMMAND) \
	X(RPB_AIR_BRAKES_COMMAND) \
	X(RPB_FROM_DAQ_AIR_BRAKES_LEVEL) \
	X(RPB_CAMERA_SIMULATE_BUTTON_COMMAND)

#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit RPB_Init[] = {RPB_CAN_LOGS};
#undef X

#define X(x) _ ## x ## _LOGINDEX,
enum RPB_LogIndexes {RPB_CAN_LOGS RPB_COUNT} ;
#undef X

#endif /* RPBLOGS_HPP_ */
