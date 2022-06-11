#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <STM32TouchController.hpp>

extern "C"
{
#include "coordinates_handler.h"
#include "main.h"
#include "radio_controller.h"
}

//static STM32TouchController tc;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if (sample_touch_flag == FLAG_SET)
	{
		int32_t x, y;
//		tc.sampleTouch(x, y);
//		static uint8_t radio_tick;

		modelListener->getCircleXY(x, y);
		setCoordinates((int16_t) x, (int16_t) y);
		sample_touch_flag = FLAG_RESET;
		UART_SendStr("x: ");
		UART_SendInt(x);
		UART_SendStr(", y: ");
		UART_SendInt(y);
		UART_SendStr("\r\n");
	}
}
