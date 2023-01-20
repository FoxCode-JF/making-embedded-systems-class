#ifndef MOTORCONTROLSCREENVIEW_HPP
#define MOTORCONTROLSCREENVIEW_HPP

#include <gui_generated/motorcontrolscreen_screen/MotorControlScreenViewBase.hpp>
#include <gui/motorcontrolscreen_screen/MotorControlScreenPresenter.hpp>
#include "STM32TouchController.hpp"

extern "C"
{
#include "stdint.h"
}

class MotorControlScreenView : public MotorControlScreenViewBase, public STM32TouchController
{
public:
    MotorControlScreenView();
    virtual ~MotorControlScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual bool getCircleXY(int32_t& x, int32_t& y);
protected:
};

#endif // MOTORCONTROLSCREENVIEW_HPP
