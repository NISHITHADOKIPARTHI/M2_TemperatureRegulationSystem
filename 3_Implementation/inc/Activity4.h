/**
 * @file Activity4.h
 * @author Nishitha Dokiparthi
 * @brief header file that contains functions for communication through UART protocol
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ACTIVITY4_H_INCLUDED
#define ACTIVITY4_H_INCLUDED
/**
 * @brief function that sets the baud rate (bits per second to be sent) and enables the registers for UART comm.
 * 
 */
void USARTInit(uint16_t );
/**
 * @brief function that reads the data from UDR Register of the Receiver channel
 * 
 * @return char 
 */
char USARTReadChar();
/**
 * @brief function that writes the data to UDR Resistor of Transmiter Channel
 * 
 * @return char 
 */
void USARTWriteChar(char data);
/**
 * @brief function that communicates and displays temperature values on serial monitor
 * 
 * @return int 
 */
int activity4();

#endif // ACTIVITY4_H_INCLUDED