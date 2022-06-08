/*
 * coordinates_handler.h
 *
 *  Created on: Jun 5, 2022
 *      Author: Fox
 */

#ifndef INC_COORDINATES_HANDLER_H_
#define INC_COORDINATES_HANDLER_H_

#include "stdint.h"

/*Touch screen coodrinates*/
#define TS_COORDINATE_X	0U
#define TS_COORDINATE_Y	1U

void setCoordinates(uint8_t ts_X, uint8_t ts_Y);
uint8_t* getCoordinates();

#endif /* INC_COORDINATES_HANDLER_H_ */
