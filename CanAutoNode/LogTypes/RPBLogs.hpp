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


// Add CAN logs here in the order you want them
#define RPB_LOGS_X \
	X(ExampleDataA) \
	X(ExampleDataB)




#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit RPB_Init[] = {RPB_LOGS_X};
#undef X

#define X(x) RPB_ ## x ## _LOGINDEX,
enum RPB_LogIndexes {RPB_LOGS_X};
#undef X

#endif /* RPBLOGS_HPP_ */
