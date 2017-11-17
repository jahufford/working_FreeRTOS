/*
 * error.h
 *
 *  Created on: Nov 5, 2017
 *      Author: joe
 */

#ifndef ERROR_H_
#define ERROR_H_
#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
//#include "stm32f4xx.h"
/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void);
//HAL_StatusTypeDef Uart_Init(USART_TypeDef* uart, uint32_t speed);
#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* ERROR_H_ */
