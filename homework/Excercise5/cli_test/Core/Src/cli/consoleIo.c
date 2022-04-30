// Console IO is a wrapper between the actual in and output and the console code
// In an embedded system, this might interface to a UART driver.

#include "consoleIo.h"
#include <stdio.h>
#include "usart.h"
#include "STM32F4xx_hal.h"

eConsoleError ConsoleIoInit(void)
{
	if(HAL_UART_Init(&huart1) != HAL_OK)
    {
		return CONSOLE_ERROR;
    }
	return CONSOLE_SUCCESS;
}

// This is modified for the Wokwi RPi Pico simulator. It works fine 
// but that's partially because the serial terminal sends all of the 
// characters at a time without losing any of them. What if this function
// wasn't called fast enough?
eConsoleError ConsoleIoReceive(uint8_t *buffer, const uint32_t bufferLength, uint32_t *readLength)
{
	uint32_t chIdx = 0;
	char ch;

//	while (HAL_UART_GetState(&huart1) == HAL_UART_STATE_READY)
	while (__HAL_UART_GET_FLAG(&huart1, UART_FLAG_RXNE) == SET)
	{
		HAL_UART_Receive(&huart1, (uint8_t*)&ch, 1, 0xFFFF);
		HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, 0xFFFF); // echo
		buffer[chIdx] = (uint8_t) ch;
		chIdx++;
	}

	*readLength = chIdx;
	return CONSOLE_SUCCESS;
}

eConsoleError ConsoleIoSendString(const char *buffer)
{
	uint32_t chIdx = 0;
	while (buffer[chIdx] != '\0') {
		HAL_UART_Transmit(&huart1,(uint8_t*)&buffer[chIdx], 1, 0xFFFF);
		chIdx++;
	}

	return CONSOLE_SUCCESS;
}
