#define _USE_MATH_DEFINES
#include "howitzer.h"

/**************************************
* RAISE
* moves the angle of the howitzer upward
***************************************/
void Howitzer::raise(double radians)
{
	if (elevation.getRadians() > 0.0
		&& elevation.getRadians() <= M_PI / 2.0)
		elevation += -radians;
	else if (elevation.getRadians() < M_PI * 2.0
		&& elevation.getRadians() >= (M_PI * 3.0) / 2.0)
		elevation += radians;
}