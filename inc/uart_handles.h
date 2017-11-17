#ifdef __cplusplus
extern "C" {
#endif
/*
 * uart_handles.h
 *
 *  Created on: Nov 13, 2017
 *      Author: joe
 */

#ifndef UART_HANDLES_H_
#define UART_HANDLES_H_

// these shenanigans are necessary to get the mix of C and C++ to work
extern UART_HandleTypeDef *printfUartHandle;
extern UART_HandleTypeDef *wirelessUartHandle;

#endif /* UART_HANDLES_H_ */
#ifdef __cplusplus
}

#endif //{include_guard_symbol}
