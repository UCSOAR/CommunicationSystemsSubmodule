/*
 * CanStructs.hpp
 *
 *  Created on: Nov 14, 2026
 *      Author: Aleks G
 */

#ifndef PTLOGS_HPP_
#define PTLOGS_HPP_

#include "LogStructs.hpp"
#include "CanAutoNodeDaughter.hpp"

#ifdef PACK_CAN_STRUCTS
#pragma pack(push,1)
#endif
//One CAN log holding all four PT readings (milli-psi)
struct PT_PRESSURE_DATA {
	int32_t pt_mPSI[4];
};
#ifdef PACK_CAN_STRUCTS
#pragma pack(pop)
#endif


//Add CAN logs here in the order you want them
#define PT_CAN_LOGS X(PT_PRESSURE_DATA)

#define X(x) sizeof(x),
const CanAutoNodeDaughter::LogInit PT_Init[] = {PT_CAN_LOGS};
#undef X

#define X(x) _ ## x ## _LOGINDEX,
enum PT_LogIndexes {PT_CAN_LOGS PT_COUNT};
#undef X

#endif /* PTLOGS_HPP_ */
