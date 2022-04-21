/**
 * @file Activity1.h
 * @author Nishitha Dokiparthi 
 * @brief contains all function prototypes
 * @version 0.1
 * @date 2022-04-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */
#ifndef ACTIVITY1_H_INCLUDED
#define ACTIVITY1_H_INCLUDED
/**
 * @brief function for configuring the registers
 * @param DDRx for denoting the direction of registers (i.e input or output)
 * @param PORTx for setting the bit at the respective register (i.e logic HIGH or logic LOW)
 */
void pin_config();

/**
 * @brief function for determining the status of LED actuator depending on the status of both passenger seat and heater button
 * @return int
 */
int activity1(void);
#endif // ACTIVITY1_H_INCLUDED