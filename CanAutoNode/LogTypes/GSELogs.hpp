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

struct GSE_KILL_PADBOX_COMMAND {
	bool kill;
};

struct GSE_IGNITE_PADBOX_COMMAND {
	bool ignite;
};

struct GSE_OPEN_PBV1_COMMAND {
	bool open;
};

struct GSE_OPEN_PBV2_COMMAND {
	bool open;
};

struct GSE_OPEN_PBV3_COMMAND {
	bool open;
};

struct GSE_OPEN_PBV4_COMMAND {
	bool open;
};

struct GSE_OPEN_SOL5_COMMAND {
	bool open;
};

struct GSE_OPEN_SOL6_COMMAND {
	bool open;
};

struct GSE_OPEN_SOL7_COMMAND {
	bool open;
};

struct GSE_OPEN_SOL8A_COMMAND {
	bool open;
};

struct GSE_OPEN_SOL8B_COMMAND {
	bool open;
};

#define GSE_CAN_LOGS \
X(GSE_AC1_OPEN_COMMAND) \
X(GSE_KILL_PADBOX_COMMAND) \
X(GSE_IGNITE_PADBOX_COMMAND) \
X(GSE_OPEN_PBV1_COMMAND) \
X(GSE_OPEN_PBV2_COMMAND) \
X(GSE_OPEN_PBV3_COMMAND) \
X(GSE_OPEN_PBV4_COMMAND) \
X(GSE_OPEN_SOL5_COMMAND) \
X(GSE_OPEN_SOL6_COMMAND) \
X(GSE_OPEN_SOL7_COMMAND) \
X(GSE_OPEN_SOL8A_COMMAND) \
X(GSE_OPEN_SOL8B_COMMAND)

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
