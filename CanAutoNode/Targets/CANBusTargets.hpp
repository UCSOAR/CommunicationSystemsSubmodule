/**
 ********************************************************************************
 * @file    CANBusTargets.hpp
 * @author  Shivam Desai
 * @date    May 2, 2026
 * @brief
 ********************************************************************************
 */

#ifndef CANBUSTARGETS_HPP_
#define CANBUSTARGETS_HPP_

/************************************
 * INCLUDES
 ************************************/

/************************************
 * MACROS AND DEFINES
 ************************************/
/**
 * ROCKET TARGETS
 */

// Mother Target
#define CAN_ROCKET_TARGET_FCB "FCB"

// Daughter Targets
#define CAN_ROCKET_TARGET_BMB "BMB"
#define CAN_ROCKET_TARGET_DAQ "DAQ"
#define CAN_ROCKET_TARGET_RPB "RPB"

/**
 * GSE TARGETS
 */

// Mother Target
#define CAN_GSE_TARGET_FSB "FSB"

// Thermocouple Daughter Targets
#define CAN_GSE_TARGET_TC1 "TC1"
#define CAN_GSE_TARGET_TC2 "TC2"
#define CAN_GSE_TARGET_TC3 "TC3"

// Pressure Transducer Daughter Targets
#define CAN_GSE_TARGET_PT1 "PT1"
#define CAN_GSE_TARGET_PT2 "PT2"
#define CAN_GSE_TARGET_PT3 "PT3"

// Load Cell Daughter Targets
#define CAN_GSE_TARGET_LC1 "LC1"
#define CAN_GSE_TARGET_LC2 "LC2"
#define CAN_GSE_TARGET_LC3 "LC3"

// Solenoid Daughter Targets
#define CAN_GSE_TARGET_SOL1 "SOL1"
#define CAN_GSE_TARGET_SOL2 "SOL2"
#define CAN_GSE_TARGET_SOL3 "SOL3"

// Ignitor Daughter Targets
#define CAN_GSE_TARGET_IGNITOR1 "IGNITOR1"
#define CAN_GSE_TARGET_IGNITOR2 "IGNITOR2"

/************************************
 * TYPEDEFS
 ************************************/

/************************************
 * CLASS DEFINITIONS
 ************************************/

/************************************
 * FUNCTION DECLARATIONS
 ************************************/

#endif /* CANBUSTARGETS_HPP_ */
