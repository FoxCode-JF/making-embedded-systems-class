#ifndef MOTORCONTROLSCREENVIEW_HPP
#define MOTORCONTROLSCREENVIEW_HPP

#include <gui_generated/motorcontrolscreen_screen/MotorControlScreenViewBase.hpp>
#include <gui/motorcontrolscreen_screen/MotorControlScreenPresenter.hpp>

extern "C"
{
#include "stdint.h"
}

class MotorControlScreenView : public MotorControlScreenViewBase
{
public:
    MotorControlScreenView();
    virtual ~MotorControlScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual uint8_t getCircleX();
    virtual uint8_t getCircleY();
protected:
};

#endif // MOTORCONTROLSCREENVIEW_HPP
