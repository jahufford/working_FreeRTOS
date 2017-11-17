#include "error.h"

void Error_Handler(void)
{
	while(1){
	}
}

//UART_HandleTypeDef UartHandle;
//
//HAL_StatusTypeDef Uart_Init(USART_TypeDef* uart, uint32_t speed)
//{
//   UartHandle.Instance 		   = uart;
//   UartHandle.Init.BaudRate     = speed;
//   UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
//   //UartHandle.Init.WordLength   = UART_WORDLENGTH_9B;
//   UartHandle.Init.StopBits     = UART_STOPBITS_1;
//   // to get parity to work right, you must use 9 bit transmission
//   //UartHandle.Init.Parity       = UART_PARITY_ODD;
//   //UartHandle.Init.Parity       = UART_PARITY_EVEN;
//   UartHandle.Init.Parity       = UART_PARITY_NONE;
//   UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
//   UartHandle.Init.Mode         = UART_MODE_TX_RX;
//   UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
//   if(HAL_UART_Init(&UartHandle) != HAL_OK)
//   {
//     /* Initialization Error */
//     return HAL_ERROR;
//   }
//   __HAL_RCC_USART1_CLK_ENABLE();
//  // USART2->CR1 |= (0x1 << 5); // enable receive interrupt
//   return HAL_OK;
//}
