#pragma once
#include <vector>
#include <cmath>
using namespace std;

class TestAcceleration;

/*****************************************
* ACCELERATION
* handles the acceleration of moving objects
*****************************************/
class Acceleration
{
	friend class TestAcceleration;

private:
	double ddx;
	double ddy;
	
	// tables used to look up values
	vector<vector<double>> dragTable;
	vector<vector<double>> densityTable;
	vector<vector<double>> soundTable;
	vector<vector<double>> gravityTable;

	/******************************************************
    * COMPUTE GRAVITY ACCELERATION
	* determines the gravity acting on an object on Earth at 
	* a given altitude.
	* INPUT
	*	altitude-- the altitude of the object in meters
	* OUTPUT
	*	the acceleration due to gravity acting on the object
    ******************************************************/
	double computeGravityAccel(double altitude)
	{
		vector<double> gravPoints = lookUpTable(gravityTable, altitude);
		return computeInterpolation(gravPoints);
	};

	/******************************************************
	* COMPUTE HORIZONTAL COMPONENT
	* determines the horizontal acceleration
	* INPUT
	*	angle-- the direction the object was launched from.
	*   total-- the total acceleration
	* OUTPUT
	*	the horizontal acceleration
	******************************************************/
	double computeHorizontalComponent(double angle, double total)
	{
		return cos(angle) * total;
    };

	/******************************************************
	* COMPUTE VERTICAL COMPONENT
	* determines the vertical acceleration due to forces other than gravity
	* INPUT
	*	angle-- the direction the object was launched from.
	*   total-- the total acceleration
	* OUTPUT
	*	the vertical acceleration other than gravity
	******************************************************/
	double computeVerticalComponent(double angle, double total)
	{
		return sin(angle) * total;
	};

	// used to compute the drag force acting on an object
	double computeSurfaceArea(double radius);
	vector<double> lookUpTable(vector<vector<double>> table, double value);
	double computeDragForce(double radius, double velocity,
		double altitude);

	double computeInterpolation(vector<double> points);

public:
	// constructors
	Acceleration();
	Acceleration(double ddx, double ddy);


	/******************************************************
	* GET DDX
	* returns the value for the horizontal acceleration
	******************************************************/
	double getDDX() { return ddx; };

	/******************************************************
	* GET DDY
	* returns the value for the vertical acceleration
	******************************************************/
	double getDDY() { return ddy; };

	/******************************************************
	* SET DDX
	* sets the value for the horizontal acceleration
	******************************************************/
	void setDDX(double ddx) { this->ddx = ddx; };

	/******************************************************
	* SET DDY
	* sets the value for the vertical acceleration
	******************************************************/
	void setDDY(double ddy) { this->ddy = ddy; };

	// computes the accleration based on mass, radius, speed, altitude, and direction
	void computeAcceleration(double mass, double radius, double speed,
		double altitude, double angle, double yVel);
};

