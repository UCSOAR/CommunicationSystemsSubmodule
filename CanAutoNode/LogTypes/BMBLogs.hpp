/*
 * CanStructs.hpp
 *
 *  Created on: May 2, 2026
 *      Author: Local user
 */

#ifndef BMBLOGS_HPP_
#define BMBLOGS_HPP_

#include "LogStructs.hpp"
#include "CanAutoNodeDaughter.hpp"


// Custom Data Types
struct BMB_POWER_COMMAND {
	bool enable;
};


// Add CAN logs here in the order you want them
#define BMB_CAN_LOGS \
	X(BMB_POWER_COMMAND)

#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit BMB_Init[] = {BMB_CAN_LOGS};
#undef X

#define X(x) _ ## x ## _LOGINDEX,
enum BMB_LogIndexes {BMB_CAN_LOGS BMB_COUNT} ;
#undef X

#endif /* BMBLOGS_HPP_ */
