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
#define CAN_ROCKET_TARGET_BMB_BOARDTYPE 1
#define CAN_ROCKET_TARGET_DAQ "DAQ"
#define CAN_ROCKET_TARGET_DAQ_BOARDTYPE 2
#define CAN_ROCKET_TARGET_RPB "RPB"
#define CAN_ROCKET_TARGET_RPB_BOARDTYPE 3

/**
 * GSE TARGETS
 */

// Mother Target
#define CAN_GSE_TARGET_FSB "FSB"

// Thermocouple Daughter Targets
#define CAN_GSE_TARGET_TC1 "TC1"
#define CAN_GSE_TARGET_TC2 "TC2"
#define CAN_GSE_TARGET_TC3 "TC3"
#define CAN_GSE_TARGET_TCX_BOARDTYPE 4

// Pressure Transducer Daughter Targets
#define CAN_GSE_TARGET_PT1 "PT1"
#define CAN_GSE_TARGET_PT2 "PT2"
#define CAN_GSE_TARGET_PT3 "PT3"
#define CAN_GSE_TARGET_PTX_BOARDTYPE 5

// Load Cell Daughter Targets
#define CAN_GSE_TARGET_LC1 "LC1"
#define CAN_GSE_TARGET_LC2 "LC2"
#define CAN_GSE_TARGET_LC3 "LC3"
#define CAN_GSE_TARGET_LCX_BOARDTYPE 6

// Solenoid Daughter Targets
#define CAN_GSE_TARGET_SOL1 "SOL1"
#define CAN_GSE_TARGET_SOL2 "SOL2"
#define CAN_GSE_TARGET_SOL3 "SOL3"
#define CAN_GSE_TARGET_SOLX_BOARDTYPE 7

// Ignitor Daughter Targets
#define CAN_GSE_TARGET_IGNITOR1 "IGNITOR1"
#define CAN_GSE_TARGET_IGNITOR2 "IGNITOR2"
#define CAN_GSE_TARGET_IGNITORX_BOARDTYPE 8

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
