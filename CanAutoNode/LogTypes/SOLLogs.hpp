/*
 * CanStructs.hpp
 *
 *  Created on: May 2, 2026
 *      Author: Local user
 */

#ifndef SOLLOGS_HPP_
#define SOLLOGS_HPP_

#include "LogStructs.hpp"
#include "CanAutoNodeDaughter.hpp"

#ifdef PACK_CAN_STRUCTS
#pragma pack(push,1)
#endif
// Custom Data Types
struct SOL_POWER_COMMAND {
	enum SOLENOID {
		SOL_30W_A,
		SOL_30W_B,
		SOL_30W_C,
		SOL_30W_D,
		SOL_15W_A,
		SOL_15W_B,

	} sol;
	bool powerOn;
};

#ifdef PACK_CAN_STRUCTS
#pragma pack(pop)
#endif

// Add CAN logs here in the order you want them
#define SOL_CAN_LOGS \
	X(SOL_POWER_COMMAND)

#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit SOL_Init[] = {SOL_CAN_LOGS};
#undef X

#define X(x) _ ## x ## _LOGINDEX,
enum SOL_LogIndexes {SOL_CAN_LOGS SOL_COUNT} ;
#undef X


#undef struct
#endif /* SOLLOGS_HPP_ */
