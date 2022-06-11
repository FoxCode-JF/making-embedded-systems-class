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

bool MotorControlScreenPresenter::getCircleXY(int32_t& x, int32_t& y)
{
	return view.getCircleXY(x, y);
}
