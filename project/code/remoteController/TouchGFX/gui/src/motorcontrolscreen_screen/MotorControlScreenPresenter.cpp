#include <gui/motorcontrolscreen_screen/MotorControlScreenView.hpp>
#include <gui/motorcontrolscreen_screen/MotorControlScreenPresenter.hpp>

extern "C"
{
#include "stdint.h"
}

MotorControlScreenPresenter::MotorControlScreenPresenter(MotorControlScreenView& v)
    : view(v)
{

}

void MotorControlScreenPresenter::activate()
{

}

void MotorControlScreenPresenter::deactivate()
{

}

uint8_t* MotorControlScreenPresenter::getTouchScreenCoordinates()
{
	ts_coordinates[0] = view.getCircleX();
	ts_coordinates[1] = view.getCircleY();

	return ts_coordinates;
}
