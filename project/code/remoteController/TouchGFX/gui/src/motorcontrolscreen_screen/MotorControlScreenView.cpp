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

uint8_t MotorControlScreenView::getCircleX()
{
	return (uint8_t)motorControlArea.getX();
}

uint8_t MotorControlScreenView::getCircleY()
{
	int32_t r, x, y;
//	touchgfx::TouchController::sampleTouch(x, y);
	motorControlArea.getRadius(r);
	return (uint8_t)motorControlArea.getY();
}
