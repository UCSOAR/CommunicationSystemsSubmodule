/*
 * CanStructs.hpp
 *
 *  Created on: May 2, 2026
 *      Author: Local user
 */

#ifndef GSELOGS_HPP_
#define GSELOGS_HPP_

#include "LogStructs.hpp"
#include "CanAutoNodeDaughter.hpp"


// Custom Data Types
struct GSE_AC1_OPEN_COMMAND {
	bool open;
};

// struct RPB_CAMERA_RECORDING_COMMAND {
// 	uint8_t camera;
// 	bool record;
// };

// struct RPB_CAMERA_SWITCH_COMMAND {
// 	uint8_t camera;
// };

// struct RPB_AIR_BRAKES_COMMAND {
// 	bool openAirBrakes;
// };

// struct RPB_FROM_DAQ_AIR_BRAKES_LEVEL {
// 	uint8_t level;
// };

// // Add CAN logs here in the order you want them
#define GSE_CAN_LOGS \
X(GSE_AC1_OPEN_COMMAND)

// #define X(x) sizeof(x),
// const CanAutoNodeDaughter::LogInit RPB_Init[] = {RPB_CAN_LOGS};
// #undef X

// #define X(x) _ ## x ## _LOGINDEX,
// enum RPB_LogIndexes {RPB_CAN_LOGS RPB_COUNT} ;
// #undef X


#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit GSE_Init[] = {GSE_CAN_LOGS};
#undef X

#define X(x) _ ## x ## _LOGINDEX,
enum GSE_LogIndexes {GSE_CAN_LOGS GSE_COUNT} ;
#undef X

#endif /* GSELOGS_HPP_ */
