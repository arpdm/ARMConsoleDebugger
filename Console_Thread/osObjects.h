
//Console Thread ID 
extern osThreadId tid_Console; 	


/** @brief Console thread's mailbox 
    	   This mailbox includes the recieve buffer from UART
 **/

extern uint8_t RXBuffer[10];
extern uint8_t RXDataCount;