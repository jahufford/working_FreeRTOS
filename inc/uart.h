/*
 * uart.h
 *
 *  Created on: Nov 13, 2017
 *      Author: joe
 */

#ifndef UART_H_
#define UART_H_
#include "stm32f4xx.h"
#include <array>
//extern UART_HandleTypeDef PrintfUartHandle;

HAL_StatusTypeDef Uart_Init(USART_TypeDef* uart, uint32_t speed);

template <typename T> struct WriteImpl; // forward declaration, of the class to which
										// we will forware write calls to

class Uart
{
public:
	Uart() = default;
	HAL_StatusTypeDef Init(USART_TypeDef* uart, uint32_t speed);
	~Uart() = default;
	template <typename T>
	inline HAL_StatusTypeDef Write(T var, uint8_t length=0)
	{
		// use a forwarding idiom so we can do template specialize
		// to allow Write() handle many types, include std::array
		return WriteImpl<T>::Write(var, &uartHandle, length);
	}
//	inline HAL_StatusTypeDef Write(uint8_t ch)
//	{
//	    return HAL_UART_Transmit(&uartHandle, &ch, 1, 0xFFFF);
//	}
//	inline HAL_StatusTypeDef WriteArray(const uint8_t *array, uint8_t length)
//	{
//		// const_cast to play nice with the existing C functions
//		return HAL_UART_Transmit(&uartHandle, const_cast<uint8_t*>(array), length, 0xFFFF);
//	}
//	template <typename Array_Type>
//	inline HAL_StatusTypeDef WriteArray(const Array_Type& array) {
//		// use the semantic sledgehammer of reinterpret cast
//		// since it's the bit pattern that we care about
//		uint8_t* array_ptr = reinterpret_cast<uint8_t*>(const_cast<char*>(array.data()));
//		return HAL_UART_Transmit(&uartHandle, array_ptr, array.size(), 0xFFFF);
//	}
private:
	UART_HandleTypeDef uartHandle;
};

//==================================================================
// the actual implementations of the Write function
template <typename T>
struct WriteImpl{
	static inline HAL_StatusTypeDef Write(const T& array, UART_HandleTypeDef *uartHandle, uint8_t length)
	{
		// use the semantic sledgehammer of reinterpret cast
		// since it's the bit pattern that we care about
		// const_cast to play nice with the existing C functions
		uint8_t* array_ptr = reinterpret_cast<uint8_t*>(const_cast<char*>(array.data()));
		return HAL_UART_Transmit(uartHandle, array_ptr, array.size(), 0xFFFF);
	}
};
template<>
struct WriteImpl<uint8_t>{
	static inline HAL_StatusTypeDef Write(uint8_t ch, UART_HandleTypeDef *uartHandle, uint8_t length)
	{
	    return HAL_UART_Transmit(uartHandle, &ch, 1, 0xFFFF);
	}
};
template<>
struct WriteImpl<char>{
	static inline HAL_StatusTypeDef Write(int8_t ch, UART_HandleTypeDef *uartHandle, uint8_t length)
	{
	    return HAL_UART_Transmit(uartHandle,(uint8_t*) &ch, 1, 0xFFFF);
	}
};
template<>
struct WriteImpl<char*>{
	static inline HAL_StatusTypeDef Write(char* array, UART_HandleTypeDef *uartHandle, uint8_t length)
	{
		// use the semantic sledgehammer of reinterpret cast
		// since it's the bit pattern that we care about
		return HAL_UART_Transmit(uartHandle, reinterpret_cast<uint8_t*>(array), length, 0xFFFF);
	}
};
template<>
struct WriteImpl<uint8_t*>{
	static inline HAL_StatusTypeDef Write(uint8_t* array, UART_HandleTypeDef *uartHandle, uint8_t length)
	{
		// use the semantic sledgehammer of reinterpret cast
		return HAL_UART_Transmit(uartHandle, reinterpret_cast<uint8_t*>(array), length, 0xFFFF);
	}
};
#endif /* UART_H_ */
//==================================================================
