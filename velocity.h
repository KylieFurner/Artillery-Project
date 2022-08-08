#pragma once
#include "direction.h"

class Velocity
{
private:
	double dx;
	double dy;

public:
	/***********************************************************
	* DEFAULT CONSTRUCTOR
	* sets velocity to 0 for both components.
	***********************************************************/
	Velocity() : dx(0.0), dy(0.0) {};

	/***********************************************************
	* GET DX
	* returns horizontal velocity
	***********************************************************/
	double getDX() { return dx; };

    /***********************************************************
	* GET DY
	* returns vertical velocity
	***********************************************************/
	double getDY() { return dy; };

	/***********************************************************
	* GET SPEED
	* returns the speed of the object, regardless of direction.
	***********************************************************/
	double getSpeed() { return sqrt((dx * dx) + (dy * dy)); };
	

	/***********************************************************
	* SET DX
	* sets the value for horizontal velocity
	***********************************************************/
	void setDX(double dx) { this->dx = dx; };

	/***********************************************************
	* SET DY
	* sets the value for vertical velocity
	***********************************************************/
	void setDY(double dy) { this->dy = dy; };

	/***********************************************************
	* SET DX DY
	* sets values for both components of velocity
	***********************************************************/
	void setDxDy(double dx, double dy)
	{
		setDX(dx);
		setDY(dy);
	};

	/***********************************************************
	* ADD DX
	* increases horizontal velocity by passed in value
	***********************************************************/
	void addDX(double dx) { setDX(this->dx + dx); };

	/***********************************************************
	* ADD DY
	* increases vertical velocity by passed in value
	***********************************************************/
	void addDY(double dy) { setDY(this->dy + dy); };

	/***********************************************************
	* ADD V
	* increases both components of velocity by passed in 
	* velocity object.
	***********************************************************/
	void addV(Velocity& velocity)
	{
		addDX(velocity.getDX());
		addDY(velocity.getDY());
	};

	/***********************************************************
	* REVERSE
	* reverses the direction of the velocity
	***********************************************************/
	void reverse()
	{
		setDX(-this->dx);
		setDY(-this->dy);
	};

	/***********************************************************
	* SET VELOCITY FROM TOTAL
	* sets both components of velocity based on speed and 
	* direction
	* INPUT
	*	angle-- direction
	*	total-- speed
	***********************************************************/
	void setVelocityFromTotal(double angle, double total)
	{
		dx = cos(angle) * total;
		dy = sin(angle) * total;
	};
};
