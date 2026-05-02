/*
 * CanStructs.hpp
 *
 *  Created on: May 2, 2026
 *      Author: Local user
 */

#ifndef DAQLOGS_HPP_
#define DAQLOGS_HPP_

#include "LogStructs.hpp"
#include "CanAutoNodeDaughter.hpp"

// Custom Data Types
struct DAQ_AIR_BRAKES_COMMAND {
	bool airBrakesGo;
};

// Add CAN logs here in the order you want them
#define DAQ_LOGS_X \
	X(CanImuData6Axis) \
	X(DAQ_AIR_BRAKES_COMMAND)





#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit DAQ_Init[] = {DAQ_LOGS_X};
#undef X

#define X(x) DAQ_ ## x ## _LOGINDEX,
enum DAQ_LogIndexes {DAQ_LOGS_X};
#undef X

#endif /* DAQLOGS_HPP_ */
