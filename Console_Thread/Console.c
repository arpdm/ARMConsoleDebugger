/**
  ******************************************************************************
  * @file    Console.c
  * @author  AD
  * @date    12/08/2017
  * @brief   Source file of Console Module.
  ******************************************************************************
  *
  * @Notes
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

extern UART_HandleTypeDef     huart2;               //UART Driver Object Instance
osThreadId                    tid_Console;          //Console Thread ID 
uint8_t                       RXDataCount;
uint8_t                       RXBuffer[20];         //Debug Console RX Buffer  
char                          TXBuffer[20];         //Debug Console Transmit buffer
uint8_t                       rxCounter;            //Internal RX Counter
uint8_t                       recieved;             //RX Recieved Char

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);


/* Console Commands Table ----------------------------------------------------*/

    
/*****************************************************************************
 * Function :   Console_Send_Data  
 * Input    :   none
 * Output   :   none
 * Comment  :   Send data to console
 *
 *              Implementation Example:
 *              double value = 1.59;
                sprintf(TXBuffer,"%f\r\n",value);
                Console_Send_Data(TXBuffer,sizeof(TXBuffer));
 ****************************************************************************/

void Console_Send_Data(char *txBuffer, uint8_t size){
    
    HAL_UART_Transmit_IT(&huart2,(uint8_t *)txBuffer,size);
    
}

/*****************************************************************************
 * Function :   HAL_UART_RxCpltCallback  
 * Input    :   huart2 instance
 * Output   :   none
 * Comment  :   UART Interrupt RX Function
 ****************************************************************************/

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){

    HAL_UART_Receive_IT(&huart2,&recieved,1);
    
    //On interrupt if received data is not 0 or CR, append to the RX Buffer
    
    if(recieved > 0 && recieved != 0x0D){
        
       RXBuffer[rxCounter] = recieved;
       rxCounter++;
        
    }
    
    //If the the CR is transmitted, it means it is the end of packet
    //At end of each packet, we want to send a signal to console thread to wake it up
    
    if(recieved==0x0D){
        
        recieved = 0x00;
        RXDataCount = rxCounter;
        
        //Send the signal when user sends CR to complete the packet
        osSignalSet(tid_Console,0x0001);
        
        //Reset the RX counter and RX Buffer
        rxCounter = 0; 
        
    }  
}


/*****************************************************************************
 * Function :   ParserStateMachine  
 * Input    :   none
 * Output   :   none
 * Comment  :   This function parses user inputs and statemachine decides
 *              what to do with individual inputs
 ****************************************************************************/
 
void ParserStateMachine(){
 
    uint8_t command = RXBuffer[0];
          
    switch (command){
         
        case 0x31:
             
            sprintf(TXBuffer,"Systen In Console Mode\r\n");
            Console_Send_Data(TXBuffer,sizeof(TXBuffer));
            break;
        
        case 0x30:
            
            printf("System Status. Console Thread running\r");
            break;
         
        default:
             
            printf("Invalid Command\r");
            break;
     
     }  
 }
 
/*****************************************************************************
 * Function :   ConsoleThread  
 * Input    :   optional parameter passed into the thread
 * Output   :   none
 * Comment  :   Main Console Thread Function
 ****************************************************************************/

void ConsoleThread (void const *argument){
    
    //Enable UART RX Interrupt
    HAL_UART_Receive_IT(&huart2,&recieved,1);
   
    while(1){
    
        //Wait for 0x01 signal from UART Interrupt Handler
        osSignalWait(0x0001,osWaitForever);

        ParserStateMachine();
        osDelay(5);     

    }
}

/*****************************************************************************
 * Function :   initConsoleThread  
 * Input    :   none
 * Output   :   State
 * Comment  :   Initialize the Console Thread. 
 ****************************************************************************/

int initConsoleThread(void){

    //Define console thread object
    osThreadDef(consoleThread,ConsoleThread, osPriorityNormal, 0, 200); 
    
    //Create console thread
    tid_Console = osThreadCreate(osThread(consoleThread), NULL);
 
    //Enable UART Interrupt
    __HAL_UART_ENABLE_IT(&huart2, UART_IT_TC);

    //If Console thread did not get initialized, return -1
    if (!tid_Console) return(-1);
   
    return(0);
    
}
