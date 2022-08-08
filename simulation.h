#pragma once
#include "howitzer.h"
#include "projectile.h"
#include "ground.h"
#include "uiInteract.h"


class Simulation
{
private:
	double interval;
	Howitzer howitzer;
	Projectile projectile;
	bool isWinMessage;
	double simTime;
	Ground ground;
	Position  ptUpperRight;

	bool isTagetHit();
	bool isGroundHit();
	bool isBorderHit();
	bool isIntersect();

public:
	// constructor
	Simulation(Position& ptUpperRight);
	
	void reset();
	void fire();
	void display(ogstream& gout);
	void input(const Interface* ui);

	/****************************************************
	* ADVANCE
	* advances the simulation by half a second
	****************************************************/
	void advance()
	{
		projectile.advance(interval);
		simTime += 0.5;
	};

	/****************************************************
	* SET INTERVAL
	* sets the in game time interval.
	****************************************************/
	void setInterval(double interval) { this->interval = interval; };

	/****************************************************
	* SET MUZZLE VELOCITY
	* sets the muzzle velocity for the howitzer.
	****************************************************/
	void setMuzzleVelocity(double vel){ howitzer.setMuzzleVelocity(vel); };

	/****************************************************
	* SET RADIUS AND MASS
	* sets the values for the projectile's radius and mass
	****************************************************/
	void setRadiusAndMass(double radius, double mass)
	{
		projectile.setRadius(radius);
		projectile.setMass(mass);
	};

	/****************************************************
	* GET PT UPPER RIGHT
	* returns the top right position of the screen.
	****************************************************/
	Position getPtUpperRight() { return ptUpperRight; }

	// converts game angle into workable angle for physics
	double convertAngleToUnitCircleStd(double angle);
	void handleCollisions();
};