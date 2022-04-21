/**
 * @file Activity2.h
 * @author Nishitha Dokiparthi
 * @brief header file contains the functions which convert the analog temperature value into digital value
 * @version 0.1
 * @date 2022-04-17
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ACTIVITY2_H_INCLUDED
#define ACTIVITY2_H_INCLUDED
/**
 * @brief function which configures the ADC registers for enabling the Analog-to-Digital conversion
 * 
 */
void InitADC();
/**
 * @brief function that configures the ADC control and data registers
 * 
 * @param ch unsigned 8-bit integer character for conversion
 * @return uint16_t unsigned 16-bit integer after conversion 
 */
uint16_t ReadADC(uint8_t ch);
/**
 * @brief function that converts the analog value into digital by sampling
 * 
 * @return int 
 */
int activity2();
/**
 * @brief unsigned 16-bit integer that contains the converted value which is stored in parts in ADCH & ADCL
 * 
 */
uint16_t volatile ADCregister;
/**
 * @brief 
 * 
 */
#define  ADCregister ADCL+(ADCH*256)

#endif // ACTIVITY2_H_INCLUDED