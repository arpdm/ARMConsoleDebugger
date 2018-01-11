/**
  ******************************************************************************
  * @file    Console.c
  * @author  AD
  * @date    12/08/2017
  * @brief   Source file of Console Module.
  ******************************************************************************
  *
  * @comments
  *
  *
  *****************************************************************************/

/* Includes ------------------------------------------------------------------*/

#include "Console.h"

//Standard Library includes

#include <stddef.h>         
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <math.h>


/*****************************************************************************
 * Function :   initConsoleThread  
 * Input    :   none
 * Output   :   State
 * Comment  :   Initialize the Console Thread
 ****************************************************************************/

int initConsoleThread(void){
  
    //Define console thread object
    osThreadDef(consoleThread,ConsoleThread, osPriorityNormal, 0, 128); 
    
    //Create console thread
    tid_Console = osThreadCreate(osThread(consoleThread), NULL);
 
    //Enable UART Interrupt
    //NOTE: This can change based on toolchain and MCU used
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_TC);

    if (!tid_Console) return(-1);
   
    return(0);
    
}
