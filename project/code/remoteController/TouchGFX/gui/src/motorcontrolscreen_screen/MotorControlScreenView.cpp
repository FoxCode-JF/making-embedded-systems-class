#include <gui/motorcontrolscreen_screen/MotorControlScreenView.hpp>

extern "C"
{
#include "coordinates_handler.h"
}

MotorControlScreenView::MotorControlScreenView()
{

}

void MotorControlScreenView::setupScreen()
{
    MotorControlScreenViewBase::setupScreen();
}

void MotorControlScreenView::tearDownScreen()
{
    MotorControlScreenViewBase::tearDownScreen();
}

bool MotorControlScreenView::getCircleXY(int32_t& x, int32_t& y)
{
	int32_t radius, circle_centerX, circle_centerY;

	bool circleTouchDetected = this->sampleTouch(x, y);

	motorControlArea.getRadius(radius);
	motorControlArea.getCenter(circle_centerX, circle_centerY);

	/*check if touch is inside a ciecle*/
	if (true == circleTouchDetected)
	{
		/*Move coordinate system to center of the circle*/
		x = x - circle_centerX;
		y = y - circle_centerY;

		int16_t radiusSquared = radius*radius;

		if ((x*x + y*y) > radiusSquared)
		{
			/*Stop if touch is detected outside of the circle*/
			x = 0;
			y = 0;
//			if (x > 0)
//			{
//				if (x > radius)
//				{
//					x = radius;
//				}
//			}
//			else
//			{
//				if (abs(x) > radius)
//				{
//					x = radius;
//				}
//			}
//
//			if (y > 0)
//			{
//				if (y > radius)
//				{
//					y = radius;
//				}
//			}
//			else
//			{
//				if (abs(y) > radius)
//				{
//					y = (-radius);
//				}
//			}
		}
	} else
	{
		/*not touch detected --> STOP!*/
		x = 0;
		y = 0;
	}


	return circleTouchDetected;
}
