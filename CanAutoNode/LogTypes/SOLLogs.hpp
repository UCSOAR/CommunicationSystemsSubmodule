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


// Custom Data Types
struct SOL_POWER_COMMAND {
	bool SolOn;
};

// Add CAN logs here in the order you want them
#define SOL_CAN_LOGS \
	X(SOL_POWER_COMMAND)


#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit SOL_Init[] = {SOL_CAN_LOGS};
#undef X

#define X(x) _ ## x ## _LOGINDEX,
enum SOL_LogIndexes {SOL_CAN_LOGS SOL_COUNT} ;
#undef X

#endif /* RPBLOGS_HPP_ */
