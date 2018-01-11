/**
  ******************************************************************************
  * @file    Console.h
  * @author  AD
  * @date    12/6/2017
  * @brief   Header file of Console.c module
  ******************************************************************************
  * @attention
  *
  * @Configuration
  *
  * Baud Rate: 9600
  * Parity:    None
  * Data Bits: 8
  * Stop Bits: 1
  *
  ******************************************************************************/
  
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __CONSOLE_H
#define __CONSOLE_H

/* Includes ------------------------------------------------------------------*/

#include "stm32f0xx_hal.h"
#include "cmsis_os.h" 
#include "osObjects.h" 

/* Definitions ---------------------------------------------------------------*/


/* Functions -----------------------------------------------------------------*/


/*****************************************************************************
 * Function :   initConsoleThread  
 * Input    :   none
 * Output   :   State
 * Comment  :  	Initialize the Console Thread
 ****************************************************************************/
 
int initConsoleThread(void);


#endif /* __CONSOLE_H */
