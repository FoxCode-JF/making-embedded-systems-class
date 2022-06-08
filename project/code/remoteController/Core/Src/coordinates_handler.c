/*
 * coordinates_handler.c
 *
 *  Created on: Jun 5, 2022
 *      Author: Fox
 */
#include "coordinates_handler.h"

static uint8_t ts_coordinates[2]; /*Stores coordinates of a touch screen*/

void setCoordinates(uint8_t ts_X, uint8_t ts_Y)
{
	ts_coordinates[TS_COORDINATE_X] = ts_X;
	ts_coordinates[TS_COORDINATE_Y] = ts_Y;
}

uint8_t* getCoordinates()
{
	return ts_coordinates;
}
