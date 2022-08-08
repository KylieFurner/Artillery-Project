#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


// forward test declaration for Direction unit tests
class TestDirection;

/********************************************
* DIRECTION
* handles angles for the simulation
********************************************/
class Direction
{
	friend class TestDirection;
private:
	double radians;


	double normalizeRadians(double radians);
	double normalizeDegrees(double degrees);
	double convertToDegrees(double radian);
	double convertToRadians(double degree);

public:
	/**************************************
	* DEFAULT CONSTRUCTOR
	* sets the anlge to 0 (straight up)
    ***************************************/
	Direction() : radians(0) {}

	// assigns the angle value
	void assign(Direction& rhs);

	// setters
	/**************************************
	* SET RADIANS
	* sets the angle based on passed in radians
	* value.
	***************************************/
	void setRadians(double rhs) { radians = normalizeRadians(rhs); };

	/**************************************
	* SET DEGREES
	* sets the anlge based on passed in degrees
	* value.
	***************************************/
	void setDegrees(double rhs)
	{
		double degrees = normalizeDegrees(rhs);
		radians = convertToRadians(degrees);
	};

	void setDown();
	void setUp();
	void setRight();
	void setLeft();

	// reverses direction angle
	Direction reverse();

	// getters
	/**************************************
	* GET RADIANS
	* returns the angle in radians.
	***************************************/
	double getRadians() { return radians; };

	/**************************************
	* GET DEGREES
	* returns the angle in degrees
	***************************************/
	double getDegrees() { return convertToDegrees(radians); };

	/**************************************
	* GET DX
	* returns the ratio of DX
	***************************************/
	double getDx() { return sin(radians); };

	/**************************************
	* GET DY
	* returns the ratio of DY
	***************************************/
	double getDy() { return cos(radians); };

	// operators
	/**************************************
	* PLUS EQUAL OPERATOR
	* adds to the radians based on rhs value
	***************************************/
	Direction& operator+=(double rhs)
	{
		setRadians(radians + rhs);
		return *this;
	};
	/**************************************
	* EQUAL OPERATOR
	* sets the value of radians to rhs value
	***************************************/
	Direction& operator=(double rhs)
	{
		setRadians(rhs);
		return*this;
	};
	Direction& operator+(double rhs);
};