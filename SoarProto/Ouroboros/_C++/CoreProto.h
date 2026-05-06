/*
 *  This file is generated with Embedded Proto, PLEASE DO NOT EDIT!
 *  source: CoreProto.proto
 */

// This file is generated. Please do not edit!
#ifndef COREPROTO_H
#define COREPROTO_H

#include <cstdint>
// Include external proto definitions

namespace Proto {

enum class Node : uint32_t
{
  NODE_INVALID = 0,
  NODE_UNKNOWN = 1,
  NODE_ANY = 2,
  NODE_RCU = 3,
  NODE_DMB = 4,
  NODE_PBB = 5,
  NODE_SOB = 6
};

enum class MessageID : uint32_t
{
  MSG_INVALID = 0,
  MSG_UNKNOWN = 1,
  MSG_CONTROL = 2,
  MSG_COMMAND = 3,
  MSG_TELEMETRY = 4,
  MSG_MAX_INVALID = 5
};

enum class RocketState : uint32_t
{
  DMB_INVALID = 0,
  RS_PRELAUNCH = 1,
  RS_FILL = 2,
  RS_ARM = 3,
  RS_IGNITION = 4,
  RS_LAUNCH = 5,
  RS_BURN = 6,
  RS_COAST = 7,
  RS_DESCENT = 8,
  RS_RECOVERY = 9,
  RS_ABORT = 10,
  RS_TEST = 11,
  RS_NONE = 12
};

} // End of namespace Proto
#endif // COREPROTO_H