#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

extern "C"
{
#include "stdint.h"
}

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    /**
	 * Call this function to get the values of touch screen coordinates (X, Y) inside motorControlArea
	 */
	virtual uint8_t* getTouchScreenCoordinates() {return 0;}

    void bind(Model* m)
    {
        model = m;
    }
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
