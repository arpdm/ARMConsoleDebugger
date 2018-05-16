/**
  ******************************************************************************
  * @file    Console.h
  * @author  AD
  * @date    12/6/2017
  * @brief   Header file of Console.c module
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 Company Name</center></h2>
  * 
  *
  * @Configuration
  *
  * Baud Rate: 115200
  * Parity:    None
  * Data Bits: 8
  * Stop Bits: 1
  *
  ******************************************************************************/
  
  
/* Define to prevent recursive inclusion -------------------------------------*/

#ifndef __CONSOLE_H
#define __CONSOLE_H

/* Includes ------------------------------------------------------------------*/

#include "stm32f4xx_hal.h"
#include "cmsis_os.h" 

/* Definitions ---------------------------------------------------------------*/


/* Functions -----------------------------------------------------------------*/


/*****************************************************************************
 * Function :   initConsoleThread  
 * Input    :   none
 * Output   :   State
 * Comment  :   Initialize the Console Thread
 ****************************************************************************/
 
int initConsoleThread(void);


#endif /* __CONSOLE_H */
