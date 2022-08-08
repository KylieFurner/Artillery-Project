#pragma once
#include "direction.h"


using namespace std;

/**************************************
*CONVERT TO DEGREES
* converts an angle in radians to
* degrees
*
* INPUT
*	radian- the angle to be converted
* Output
*	the angle in degrees
  ***************************************/
double Direction::convertToDegrees(double radian) 
{ 
    return (180 / M_PI) * radian; 
};

/**************************************
* CONVERT TO RADIANS
* converts an angle in degrees to
* radians
*
* INPUT
*	degree- the angle to be converted
* Output
*	the angle in radians
***************************************/
double Direction::convertToRadians(double degree) 
{ 
    return (M_PI / 180) * degree;
}

/**************************************
* NORMALIZE RADIANS
* standardizes angle passed in as radians
***************************************/
double Direction::normalizeRadians(double radians)
{
    int multiple = abs(radians / (2 * M_PI));
    if (radians >= 2 * M_PI)
    {
        return radians - (multiple * 2 * M_PI);
    }

    else if (radians < 0)
    {
        return radians + (multiple * 2 * M_PI) + (2 * M_PI);
    }

    else return radians;
}

/**************************************
* NORMALIZE DEGREES
* standardizes angle passed in as degrees
***************************************/
double Direction::normalizeDegrees(double degrees)
{
    int multiple = abs(degrees / 360);
    if (degrees >= 360)
    {
        return degrees - (multiple * 360);
    }

    else if (degrees < 0)
    {
        return degrees + (multiple * 360) + 360;
    }

    else return degrees;
}

/**************************************
* ASSIGN
* sets the value of the angle based on
* a passed in Direction object
***************************************/
void Direction::assign(Direction& rhs)
{
    if (rhs.radians >= 0)
    {
        radians = rhs.radians;
    }
    else if (rhs.radians < 0)
    {
        radians = ((2 * M_PI) + rhs.radians);
    }
}

/**************************************
* REVERSE
* reverses the angle by adding pi (180 degrees)
***************************************/
Direction Direction::reverse()
{
    Direction tempDirection;
    tempDirection.setRadians(radians + M_PI);
    return tempDirection;
}

/**************************************
* ADD OPERATOR
* adds to the angle based on rhs value
***************************************/
Direction& Direction::operator+(double rhs)
{
    Direction tempDirection;
    tempDirection.assign(*this);
    tempDirection.setRadians(tempDirection.getRadians() + rhs);
    return tempDirection;
}

/**************************************
* SET DOWN
* sets the angle to point down
***************************************/
void Direction::setDown() 
{ 
    radians = M_PI; 
};

/**************************************
* SET UP
* sets the angle to point up
***************************************/
void Direction::setUp() 
{
    radians = 0; 
};

/**************************************
* SET RIGHT
* sets the angle to point right
***************************************/
void Direction::setRight()
{
    radians = 0.5 * M_PI; 
};

/**************************************
* SET LEFT
* sets the angle to point left
***************************************/
void Direction::setLeft() 
{
    radians = 1.5 * M_PI; 
};