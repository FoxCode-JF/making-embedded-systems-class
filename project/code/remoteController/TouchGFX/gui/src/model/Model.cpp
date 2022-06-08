#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <STM32TouchController.hpp>

extern "C"
{
#include "coordinates_handler.h"
#include "main.h"
#include "radio_controller.h"
}

static STM32TouchController tc;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if (sample_touch_flag == FLAG_SET)
	{
		int32_t x, y;
		tc.sampleTouch(x, y);
		static uint8_t radio_tick;
		UART_SendStr("tick ");
//		UART_SendInt(radio_tick++);
		UART_SendInt(x);
		UART_SendStr("\r\n");
		uint8_t* ts_coordinates = modelListener->getTouchScreenCoordinates();
		setCoordinates(ts_coordinates[TS_COORDINATE_X], ts_coordinates[TS_COORDINATE_Y]);
		sample_touch_flag = FLAG_RESET;
	}
}
