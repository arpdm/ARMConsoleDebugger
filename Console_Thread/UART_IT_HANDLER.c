//Standard Library includes

#include <stddef.h>         
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

uint8_t RXDataCount;    //RX Buffer Counter
uint8_t rxCounter;      //Internal RX Counter
uint8_t recieved;       //RX Recieved Char
uint8_t RXBuffer[10];   //RX Buffer

//This function handles USART2 global interrupt

void USART2_IRQHandler(void){
    
    HAL_UART_IRQHandler(&huart2);
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
        
        //Send the signal
        osSignalSet(tid_Console,0x0001);
        
        //Reset the RX counter and RX Buffer
        rxCounter = 0; 
        
    }  

}