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


// Custom Data Types
struct RPB_CAMERA_POWER_COMMAND {
	bool cameraOn;
};

struct RPB_CAMERA_RECORDING_COMMAND {
	bool startRecording;
};

struct RPB_AIR_BRAKES_COMMAND {
	bool openAirBrakes;
};

// Add CAN logs here in the order you want them
#define RPB_CAN_LOGS \
	X(RPB_CAMERA_POWER_COMMAND) \
	X(RPB_CAMERA_RECORDING_COMMAND) \
	X(RPB_AIR_BRAKES_COMMAND)

#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit RPB_Init[] = {RPB_CAN_LOGS};
#undef X

#define X(x) _ ## x ## _LOGINDEX,
enum RPB_LogIndexes {RPB_CAN_LOGS};
#undef X

#endif /* RPBLOGS_HPP_ */
