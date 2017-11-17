#ifdef __cplusplus
extern "C" {
#endif
/*
 * putchar.h
 *
 *  Created on: Nov 13, 2017
 *      Author: joe
 */

/* Private function prototypes -----------------------------------------------*/
// make a putchar function that using HAL_UART_Transmit() to write characters
// out to the uart. This allows us to printf
#ifndef PUTCHAR_H_
#define PUTCHAR_H_

#ifdef __GNUC__
  /* With GCC, small printf (option LD Linker->Libraries->Small printf
     set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */

PUTCHAR_PROTOTYPE;

#ifdef __cplusplus
}

#endif //{include_guard_symbol}

#endif /* PUTCHAR_H_ */
