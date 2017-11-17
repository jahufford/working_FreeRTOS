/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


//#include "stm32f4xx_nucleo.h"
extern "C" { // include C header files
	#include "stm32f4xx.h"
	#include "FreeRTOS.h"
	#include "task.h"
	#include "error.h"
    #include "stdio.h"
    #include "clock_config.h"
}
#include "uart.h"
#include "semphr.h"
#include <array>
#include <vector>

//void vSemaphoreCreateBinary(timer_signal);


//SemaphoreHandle_t timing_signal = xSemaphoreCreateBinary();
auto timing_signal = xSemaphoreCreateBinary();

auto TaskCritical = [](auto func){
	vTaskSuspendAll();
	func();
	xTaskResumeAll();
};
void MyTask(void* ptr)
{
	while(1){
		//printf("MyTask\r\n");
		//vTaskSuspendAll();
		//printf("aaaaaaaa\r\n");
		//xTaskResumeAll();
		xSemaphoreTake(timing_signal,portMAX_DELAY);
		TaskCritical([]{
          printf("aaaaaaaa\r\n");
		});
		vTaskDelay(1000);
		xSemaphoreGive(timing_signal);
		taskYIELD();
		//taskYIELD();
	}
}

void MyOtherTask(void* ptr)
{
	while(1){
		//printf("MyOtherTask\r\n");
		xSemaphoreTake(timing_signal,portMAX_DELAY);
		TaskCritical([]{
			printf("xxxxxxxx\r\n");
		});
		vTaskDelay(1000);
		xSemaphoreGive(timing_signal);
	    taskYIELD();
		//taskYIELD();
	}
}

Uart serial_port;
int main(void)
{
    /* STM32F4xx HAL library initialization:
       - Configure the Flash prefetch, instruction and Data caches
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Global MSP (MCU Support Package) initialization
     */
    HAL_Init();

    /* Configure the system clock to 180 MHz */
    SystemClock_Config();
    //Uart_Init(USART2, 9600);
    if(serial_port.Init(USART2, 9600) != HAL_OK){
    	Error_Handler();
    }
    printf("Hello World!\r\n");
//    std::array<char, 5> ary = {'H','e','l','l','o'};
//    std::array<char, 5> ary2 = {'H','o','l','l'};
//    std::vector<char> aaa = {'X','Y','Z'};
//    char my_ary[5] = {'Y','e','l','l','Y'};
//    char my_ary2[5] = {'X','e','l','l','X'};
//    uint8_t my_ary3[3] = {0x65,0x66,0x67};
//    uint8_t ch = static_cast<uint8_t>('a');
//    //serial_port.Write(ch);
//    serial_port.Write('b');
//    //serial_port.Write(static_cast<uint8_t*>(&my_ary[0]));
//    //serial_port.WriteArray((uint8_t*)&my_ary[0],5);
//    //serial_port.Write(my_ary,5);
////    serial_port.Write(ary);
////    //serial_port.WriteArray(ary2);
//    serial_port.Write(ary);
//    serial_port.Write(ch);
//    serial_port.Write(my_ary,5);
//    serial_port.Write(my_ary2,5);
//    serial_port.Write(my_ary3,3);
//    serial_port.Write((uint8_t*)my_ary,5);

    xTaskCreate(MyTask, "MyTask", 128,0,1,0);
    xTaskCreate(MyOtherTask, "MyOtherTask",128,0,1,0);
	xSemaphoreGive(timing_signal);

    vTaskStartScheduler();

	for(;;);
}


