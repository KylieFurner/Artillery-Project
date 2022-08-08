#pragma once
#include "position.h"
#include "direction.h"
#include "uiDraw.h"


class Howitzer
{
private:
	Position position;
	double muzzleVelocity;
	Direction elevation;

public:
	/**************************************
	* DEFAULT CONSTRUCTOR
	* sets up howitzer with a muzzle velocity
	* of 0.0
	***************************************/
	Howitzer() : muzzleVelocity(0.0) {};

	/**************************************
	* DRAW
	* draws the howitzer
	***************************************/
	void draw(ogstream& gout, double flightTime)
	{
		gout.drawHowitzer(position, elevation.getRadians(), flightTime);
	};

	/**************************************
	* GET POSITION
	* returns the position of the howitzer
	***************************************/
	Position getPosition() { return position; };

	/**************************************
	* GET ANGLE
	* returns the angle of the howitzer in radians
	***************************************/
	double getAngle() { return elevation.getRadians(); };

	/**************************************
	* GET MUZZLE VELOCITY
	* returns the muzzle velocity of the howitzer
	***************************************/
	double getMuzzleVelocity() { return muzzleVelocity; };
	
	/**************************************
	* SET MUZZLE VELOCITY
	* sets the muzzle velocity of the howitzer
	***************************************/
	void setMuzzleVelocity(double vel) { muzzleVelocity = vel; };

	/**************************************
	* SET POSITION
	* sets the position of the howitzer
	***************************************/
	void setPosition(Position pos)
	{
		position.setMeters(pos.getMetersX(), pos.getMetersY());
	};

	/**************************************
	* ROTATE
	* moves the angle of the howitzer left
	* or right
	***************************************/
	void rotate(double radians) { elevation += radians; };
	void raise(double radians);
};
