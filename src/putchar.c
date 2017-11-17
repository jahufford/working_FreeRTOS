/*
 * putchar.c
 *
 *  Created on: Nov 13, 2017
 *      Author: joe
 */

#include "putchar.h"
#include "stm32f4xx.h"
//#include "uart.h"
#include "uart_handles.h"
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(printfUartHandle, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}
