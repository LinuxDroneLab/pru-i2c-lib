/*
 * pru_i2c_driver.h
 *
 *  Created on: 04 mar 2018
 *      Author: andrea
 */

#ifndef PRU_I2C_DRIVER_H_
#define PRU_I2C_DRIVER_H_

#include <stdint.h>

uint8_t pru_i2c_driver_ReadBytes(uint8_t address, uint8_t reg, uint8_t bytes, uint8_t* buffer);
uint8_t pru_i2c_driver_WriteBytes(uint8_t address, uint8_t reg, uint8_t bytes, uint8_t* buffer);
uint8_t pru_i2c_driver_ReadReg(uint8_t address, uint8_t reg, uint8_t* buffer);
uint8_t pru_i2c_driver_WriteReg(uint8_t address, uint8_t reg, uint8_t value);
void pru_i2c_driver_Set400KHz();
void pru_i2c_driver_Set100KHz();
uint8_t pru_i2c_driver_Init();

#endif /* PRU_I2C_DRIVER_H_ */
