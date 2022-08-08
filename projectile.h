#pragma once
#include "position.h"
#include "velocity.h"
#include "uiDraw.h"
#include <vector>

using namespace std;

/********************************************
* PROJECTILE
* handles the projectile objects
********************************************/
class Projectile
{
private:
	double mass;
	double radius;
	Position flightPath[20];
	Velocity velocity;
	bool flightStatus;
	double launchAngle;
	double launchTime;
	Position launchPos;
	
public:
	// constructor
	Projectile();

	// resets projectile
	void reset();

	// fires projectile
	void fire(Position pos, Velocity vel, double angle, double time);

	// advances position based on time
	void advance(double time);

	// draws projectile
	void draw(ogstream& gout);
	
	/****************************************************
	* IS FLYING
	* returns true if the projectile is still flying
	****************************************************/
	bool isFlying() { return flightStatus; };

	// getters
	/****************************************************
	* GET ALTITUDE
	* returns the altitude of the projectile in meters
	****************************************************/
	double getAltitude(){ return flightPath[0].getMetersY(); };

	/****************************************************
	* GET POSITION
	* returns the position of the projectile
	****************************************************/
	Position getPosition(){ return flightPath[0]; };

	/****************************************************
	* GET LAST POSITION
	* returns the previous position of the projectile
	****************************************************/
	Position getLastPosition(){ return flightPath[1]; };

	/****************************************************
	* GET LAUNCH TIME
	* returns the simulation time at the time
	* the projectile was fired
	****************************************************/
	double getLaunchTime() { return launchTime; };

	/****************************************************
	* GET FLIGHT DISTANCE
	* returns the horizontal distance the projectile has
	* traveled in meters
	****************************************************/
	double getFlightDistance()
	{
		return abs(launchPos.getMetersX() - flightPath[0].getMetersX());
	};

	/****************************************************
	* GET SPEED
	* returns the speed of the projectile in meters/second
	****************************************************/
	double getSpeed() { return velocity.getSpeed(); };

	/****************************************************
	* SET MASS
	* sets the mass of the projectile in kg
	****************************************************/
	void setMass(double mass) { this->mass = mass; };

	/****************************************************
	* SET RADIUS
	* sets the radius of the projectile in meters
	****************************************************/
	void setRadius(double radius) { this->radius = radius; };
};