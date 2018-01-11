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

/* Defines -------------------------------------------------------------------*/

UART_HandleTypeDef     huart2;       //UART Driver Object Instance
osThreadId             tid_Console;  //Console Thread ID 


/*****************************************************************************
 * Function :   asciiToInt  
 * Input    :   none
 * Output   :   converted 16 bit integer value
 * Comment  :   Converts the asccii input from user to 16 bit integer value
 ****************************************************************************/
 
uint16_t asciiToInt(){
    
    uint16_t currentNumber = 0;
    uint16_t result = 0;
    uint16_t totalNumbers =  RXDataCount - 1;
    uint16_t power = totalNumbers;
    
    for(uint8_t i = 0; i < totalNumbers  ; i++){
        
        currentNumber = RXBuffer[i+1];
        power--;
        result += (currentNumber-0x30)*pow(10,power);
        
    }
    
    return result;

}

/*****************************************************************************
 * Function :   ConsoleThread  
 * Input    :   optional parameter passed into the thread
 * Output   :   none
 * Comment  :   Main Console Thread Function
 ****************************************************************************/

void ConsoleThread (void const *argument){
        
    while(1){
    
        //Wait for 0x01 signal from UART1 Interrupt Handler
        osSignalWait(0x0001,osWaitForever);

        uint8_t command = RXBuffer[0];
        //TODO: Add state machine or any other operation 
    
    }
}

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
