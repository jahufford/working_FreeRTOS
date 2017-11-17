/*
 * uart.cpp
 *
 *  Created on: Nov 13, 2017
 *      Author: joe
 */

#include "uart.h"
//#include "error.h"

// links that are eventually exported to C code
UART_HandleTypeDef *printfUartHandle = NULL;
UART_HandleTypeDef *wirelessUartHandle = NULL;

HAL_StatusTypeDef Uart_Init(USART_TypeDef* uart, uint32_t speed)
{
// TODO will need to expand this function to handle other uarts instead of usart2
   UART_HandleTypeDef UartHandle;
   if(uart == USART2){
       __HAL_RCC_USART2_CLK_ENABLE();
       __HAL_RCC_GPIOA_CLK_ENABLE(); // for the tx and rx pins

       GPIO_InitTypeDef h_gpio;
       h_gpio.Pin = GPIO_PIN_2;
       h_gpio.Mode = GPIO_MODE_AF_PP;
       h_gpio.Pull = GPIO_PULLUP;
       h_gpio.Alternate = GPIO_AF7_USART1;
       h_gpio.Speed = GPIO_SPEED_FREQ_HIGH;
       HAL_GPIO_Init(GPIOA, &h_gpio);

       h_gpio.Pin = GPIO_PIN_3;
       h_gpio.Mode = GPIO_MODE_AF_PP;
       h_gpio.Pull = GPIO_PULLUP;
       h_gpio.Alternate = GPIO_AF7_USART1;
       h_gpio.Speed = GPIO_SPEED_FREQ_HIGH;
       HAL_GPIO_Init(GPIOA, &h_gpio);
   }else if(uart == USART1){
       __HAL_RCC_USART1_CLK_ENABLE();
       __HAL_RCC_GPIOA_CLK_ENABLE(); // for the tx and rx pins

       GPIO_InitTypeDef h_gpio;
       h_gpio.Pin = GPIO_PIN_9;
       h_gpio.Mode = GPIO_MODE_AF_PP;
       h_gpio.Pull = GPIO_PULLUP;
       h_gpio.Alternate = GPIO_AF7_USART1;
       h_gpio.Speed = GPIO_SPEED_FREQ_HIGH;
       HAL_GPIO_Init(GPIOA, &h_gpio);

       h_gpio.Pin = GPIO_PIN_10;
       h_gpio.Mode = GPIO_MODE_AF_PP;
       h_gpio.Pull = GPIO_PULLUP;
       h_gpio.Alternate = GPIO_AF7_USART1;
       h_gpio.Speed = GPIO_SPEED_FREQ_HIGH;
       HAL_GPIO_Init(GPIOA, &h_gpio);
   }
   UartHandle.Instance 		    = uart;
   UartHandle.Init.BaudRate     = speed;
   UartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
   //UartHandle.Init.WordLength   = UART_WORDLENGTH_9B;
   UartHandle.Init.StopBits     = UART_STOPBITS_1;
   // to get parity to work right, you must use 9 bit transmission
   //UartHandle.Init.Parity       = UART_PARITY_ODD;
   //UartHandle.Init.Parity       = UART_PARITY_EVEN;
   UartHandle.Init.Parity       = UART_PARITY_NONE;
   UartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
   UartHandle.Init.Mode         = UART_MODE_TX_RX;
   UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
   if(HAL_UART_Init(&UartHandle) != HAL_OK)
   {
     /* Initialization Error */
     return HAL_ERROR;
   }
  // USART2->CR1 |= (0x1 << 5); // enable receive interrupt
   return HAL_OK;
}

HAL_StatusTypeDef Uart::Init(USART_TypeDef* uart, uint32_t speed)
{
	// TODO will need to expand this function to handle other uarts instead of usart2
	 //  UART_HandleTypeDef *uartHandle;
	   if(uart == USART2){
		   //uartHandle = &PrintfUartHandle; // to link the C printf code to this
		   printfUartHandle = &uartHandle;
	       __HAL_RCC_USART2_CLK_ENABLE();
	       __HAL_RCC_GPIOA_CLK_ENABLE(); // for the tx and rx pins

	       GPIO_InitTypeDef h_gpio;
	       h_gpio.Pin = GPIO_PIN_2;
	       h_gpio.Mode = GPIO_MODE_AF_PP;
	       h_gpio.Pull = GPIO_PULLUP;
	       h_gpio.Alternate = GPIO_AF7_USART1;
	       h_gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	       HAL_GPIO_Init(GPIOA, &h_gpio);

	       h_gpio.Pin = GPIO_PIN_3;
	       h_gpio.Mode = GPIO_MODE_AF_PP;
	       h_gpio.Pull = GPIO_PULLUP;
	       h_gpio.Alternate = GPIO_AF7_USART1;
	       h_gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	       HAL_GPIO_Init(GPIOA, &h_gpio);
	   }else if(uart == USART1){
		   wirelessUartHandle = &uartHandle;
	       __HAL_RCC_USART1_CLK_ENABLE();
	       __HAL_RCC_GPIOA_CLK_ENABLE(); // for the tx and rx pins

	       GPIO_InitTypeDef h_gpio;
	       h_gpio.Pin = GPIO_PIN_9;
	       h_gpio.Mode = GPIO_MODE_AF_PP;
	       h_gpio.Pull = GPIO_PULLUP;
	       h_gpio.Alternate = GPIO_AF7_USART1;
	       h_gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	       HAL_GPIO_Init(GPIOA, &h_gpio);

	       h_gpio.Pin = GPIO_PIN_10;
	       h_gpio.Mode = GPIO_MODE_AF_PP;
	       h_gpio.Pull = GPIO_PULLUP;
	       h_gpio.Alternate = GPIO_AF7_USART1;
	       h_gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	       HAL_GPIO_Init(GPIOA, &h_gpio);
	   }
	   uartHandle.Instance 		    = uart;
	   uartHandle.Init.BaudRate     = speed;
	   uartHandle.Init.WordLength   = UART_WORDLENGTH_8B;
	   //UartHandle.Init.WordLength   = UART_WORDLENGTH_9B;
	   uartHandle.Init.StopBits     = UART_STOPBITS_1;
	   // to get parity to work right, you must use 9 bit transmission
	   //UartHandle.Init.Parity       = UART_PARITY_ODD;
	   //UartHandle.Init.Parity       = UART_PARITY_EVEN;
	   uartHandle.Init.Parity       = UART_PARITY_NONE;
	   uartHandle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
	   uartHandle.Init.Mode         = UART_MODE_TX_RX;
	   uartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
	   if(HAL_UART_Init(&uartHandle) != HAL_OK)
	   {
	     /* Initialization Error */
	     return HAL_ERROR;
	   }
	  // USART2->CR1 |= (0x1 << 5); // enable receive interrupt
	   return HAL_OK;
}


