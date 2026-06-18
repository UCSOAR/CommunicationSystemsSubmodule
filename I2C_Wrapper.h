/*
 * I2C_Wrapper.h
 *
 *  Created on: Nov 16, 2024
 *      Author: diogo
 */

#ifndef I2C_WRAPPER_H_
#define I2C_WRAPPER_H_


#define COMM_ERROR 5;

typedef struct I2C_DATA_PACKAGE{
	I2C_HandleTypeDef *hi2c;  //I2Cx used - I2C_INTERFACE.hi2c = &hi2cx
	uint8_t device_address;   //Address of the device you wish to communicate with
	uint8_t register_address; //Register of the device you want to access
	uint8_t num_bytes;		  //Number of bytes you will be accessing (DO NOT count the register address!)
	uint8_t send_data[254];   //Array with the data you want to write
	uint8_t received_data[255];//Array that the data read will be saved
}I2C_INTERFACE;


//Function Prototypes
//================================================================
uint8_t I2C_writeReg(I2C_INTERFACE *interface);
/*
 * Function to Write a register
 * */

#endif /* I2C_WRAPPER_H_ */
