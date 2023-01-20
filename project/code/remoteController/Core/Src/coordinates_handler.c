/*
 * coordinates_handler.c
 *
 *  Created on: Jun 5, 2022
 *      Author: Fox
 */
#include "coordinates_handler.h"

static int16_t ts_coordinates[2]; /*Stores coordinates of a touch screen*/

void setCoordinates(int16_t ts_X, int16_t ts_Y)
{
	ts_coordinates[TS_COORDINATE_X] = ts_X;
	ts_coordinates[TS_COORDINATE_Y] = ts_Y;
}

void getCoordinates(int16_t* coordinates)
{
	coordinates[TS_COORDINATE_X] = ts_coordinates[TS_COORDINATE_X];
	coordinates[TS_COORDINATE_Y] = ts_coordinates[TS_COORDINATE_Y];
}
