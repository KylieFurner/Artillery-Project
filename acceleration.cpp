#define _USE_MATH_DEFINES
#include "acceleration.h"
#include <iostream>

/******************************************************
* DEFAULT CONSTRUCTOR
* Sets acceleration to 0.
* Sets table values for all tables
******************************************************/
Acceleration::Acceleration() : ddx(0), ddy(0)
{
	gravityTable = {
	{ 0, 9.807 },
	{ 1000, 9.804 },
	{ 2000, 9.801 },
	{ 3000, 9.797 },
	{ 4000, 9.794 },
	{ 5000, 9.791 },
	{ 6000, 9.788 },
	{ 7000, 9.785 },
	{ 8000, 9.782 },
	{ 9000,9.779 },
	{ 10000,9.776 },
	{ 15000, 9.761 },
	{ 20000, 9.745 },
	{ 25000, 9.730 }
	};
	dragTable = {
	{0.300, 0.1629},
	{0.500,	0.1659},
	{0.700,	0.2031},
	{0.890,	0.2597},
	{0.920, 0.3010},
	{0.960, 0.3287},
	{0.980,	0.4002},
	{1.000,	0.4258},
	{1.020,	0.4335},
	{1.060,	0.4483},
	{1.240,	0.4064},
	{1.530,	0.3663},
	{1.990,	0.2897},
	{2.870,	0.2297},
	{2.890,	0.2306},
	{5.000,	0.2656}
	};

	densityTable = {
		{0,	1.2250000 },
		{1000, 1.1120000},
		{2000, 1.0070000},
		{3000, 0.9093000},
		{4000, 0.8194000},
		{5000, 0.7364000},
		{6000, 0.6601000},
		{7000, 0.5900000},
		{8000, 0.5258000},
		{9000, 0.4671000},
		{10000, 0.4135000},
		{15000, 0.1948000},
		{20000, 0.0889100},
		{25000,	0.0400800},
		{30000,	0.0184100},
		{40000,	0.0039960},
		{50000,	0.0010270},
		{60000,	0.0003097},
		{70000,	0.0000828},
		{80000, 0.0000185}
	};

	soundTable = {
		{ 0, 340 },
		{ 1000, 336 },
		{ 2000, 332 },
		{ 3000, 328 },
		{ 4000, 324 },
		{ 5000, 320 },
		{ 6000, 316 },
		{ 7000, 312 },
		{ 8000, 308 },
		{ 9000, 303 },
		{ 10000, 299 },
		{ 15000, 295 },
		{ 20000, 295 },
		{ 25000, 295 },
		{ 30000, 305 },
		{ 40000, 324 }
	};
}

/******************************************************
* NON-DEFAULT CONSTRUCTOR
* Sets acceleration to values passed in.
* Sets table values for all tables
******************************************************/
Acceleration::Acceleration(double ddx, double ddy) : ddx(ddx), ddy(ddy)
{
	gravityTable = {
	{ 0, 9.807 },
	{ 1000, 9.804 },
	{ 2000, 9.801 },
	{ 3000, 9.797 },
	{ 4000, 9.794 },
	{ 5000, 9.791 },
	{ 6000, 9.788 },
	{ 7000, 9.785 },
	{ 8000, 9.782 },
	{ 9000,9.779 },
	{ 10000,9.776 },
	{ 15000, 9.761 },
	{ 20000, 9.745 },
	{ 25000, 9.730 }
	};
	dragTable = {
	{0.300, 0.1629},
	{0.500,	0.1659},
	{0.700,	0.2031},
	{0.890,	0.2597},
	{0.920, 0.3010},
	{0.960, 0.3287},
	{0.980,	0.4002},
	{1.000,	0.4258},
	{1.020,	0.4335},
	{1.060,	0.4483},
	{1.240,	0.4064},
	{1.530,	0.3663},
	{1.990,	0.2897},
	{2.870,	0.2297},
	{2.890,	0.2306},
	{5.000,	0.2656}
	};

	densityTable = {
		{0,	1.2250000 },
		{1000, 1.1120000},
		{2000, 1.0070000},
		{3000, 0.9093000},
		{4000, 0.8194000},
		{5000, 0.7364000},
		{6000, 0.6601000},
		{7000, 0.5900000},
		{8000, 0.5258000},
		{9000, 0.4671000},
		{10000, 0.4135000},
		{15000, 0.1948000},
		{20000, 0.0889100},
		{25000,	0.0400800},
		{30000,	0.0184100},
		{40000,	0.0039960},
		{50000,	0.0010270},
		{60000,	0.0003097},
		{70000,	0.0000828},
		{80000, 0.0000185}
	};

	soundTable = {
		{ 0, 340 },
		{ 1000, 336 },
		{ 2000, 332 },
		{ 3000, 328 },
		{ 4000, 324 },
		{ 5000, 320 },
		{ 6000, 316 },
		{ 7000, 312 },
		{ 8000, 308 },
		{ 9000, 303 },
		{ 10000, 299 },
		{ 15000, 295 },
		{ 20000, 295 },
		{ 25000, 295 },
		{ 30000, 305 },
		{ 40000, 324 }
	};
}

/******************************************************
* COMPUTE ACCELERATION
* computes the acceleration of an object that has 
* a cross section of a circle.
* INPUT:
*		mass-- the mass of the object
*		radius-- the radius of the object's cross section
*		speed-- the speed of the object
*		altitude-- the current altitude of the object in meters
*		angle-- the angle the object was launched from
*		yVel-- the upwards velocity of the object
* OUTTPUT:
*		determines the acceleration in both the x and 
*		y directions. Returns nothing.
******************************************************/
void Acceleration::computeAcceleration(double mass, double radius, double speed,
	double altitude, double angle, double yVel)
{
	// compute the force
	double force = computeDragForce(radius, speed, altitude);

	// compute total acceleration and break it into components
	double totalAccel = force / mass;
	double gravity = computeGravityAccel(altitude);

	ddx = computeHorizontalComponent(angle, totalAccel);

	// if the object is moving upward, drag force is pulling down.
	if (yVel >= 0)
	    ddy = -computeVerticalComponent(angle, totalAccel) - gravity;

	// otherwise, it pushes up against gravity.
	else
		ddy = computeVerticalComponent(angle, totalAccel) - gravity;
}

/*******************************************************
* LOOK UP TABLE
* Determines the two closest points in a table by a given
* value.
*
* INPUT
*	table: a 2D vector that is a data table
*	value: the value to be searched for
* OUTPUT
*	a vector containing the two closest points and the value
*	in the form of {r0, r, r1, d0, d1}
********************************************************/
vector<double> Acceleration::lookUpTable(vector<vector<double>> table, double value)
{
	// Determine the last index value.
	int upperLimit = table.size() - 1;
	int lowerLimit = 0;
	bool search = true;

	while (search)
	{
		// Find the midpoint of the vector.
		int midpoint = (upperLimit + lowerLimit) / 2;
		double midpointElement = table[midpoint][0];

		if (midpointElement == value)
		{
			return {
				table[midpoint][0],
				value,
				table[midpoint][0],
				table[midpoint][1],
				table[midpoint][1]
			};
		}
		else if (value > midpointElement)
		{
			if (lowerLimit + 1 == upperLimit)
			{
				// check the value at the end of the vector
				if (upperLimit == table.size() - 1)
				{
					if (table[upperLimit][0] <= value)
					{
						return {
							table[upperLimit][0],
							table[upperLimit][0],
							table[upperLimit][0],
							table[upperLimit][1],
							table[upperLimit][1]
						};
					}
				}
				search = false;
			}
			// If the value comes after, change the lower limit.
			else
			{
				lowerLimit = midpoint;
			}
		}
		else if (value < midpointElement)
		{
			if (lowerLimit + 1 == upperLimit)
			{
				if (lowerLimit == 0)
				{
					if (table[lowerLimit][0] >= value)
					{
						return {
							table[lowerLimit][0],
							table[lowerLimit][0],
							table[lowerLimit][0],
							table[lowerLimit][1],
							table[lowerLimit][1]
						};
					}
				}
				search = false;
			}
			// If the value comes before, change the upper limit.
			else
				upperLimit = midpoint;
		}
		if (lowerLimit == upperLimit)
			upperLimit++;
	}
	return {
		table[lowerLimit][0],
		value,
		table[upperLimit][0],
		table[lowerLimit][1],
		table[upperLimit][1]
	};
}

/*******************************************************
*COMPUTE INTERPOLATION
* Determines the interpolation between two points and
* some value between those points.
* Formula:
*(r - r0)   (r1 - ro)
* -------- = -------- 
*(d - d0)   (d1 - d0)
*
*OR
* d = d0 + (((r - r0) * (d1 - d0)) / (r1 - r0))
*
*INPUT
*   points-- the points being interpolated between
* OUTPUT
* the value for d
********************************************************/
double Acceleration::computeInterpolation(vector<double> points)
{
	if (points.size() == 5)
	{
		double r0 = points[0];
		double r = points[1];
		double r1 = points[2];

		double d0 = points[3];
		double d1 = points[4];

		// check to see if points are equal
		if (r0 == r1)
		{
			return d0;
		}
		else
		{
			return (((r - r0) * (d1 - d0)) / (r1 - r0)) + d0;
		}
	}
	else
	{
		cout << "No vector passed into computeInterpolation\n";
		return -1; // error
	}
}


/*******************************************************
* COMPUTE SURFACE AREA
* Determines the surface area based on a given radius
* Formula:
*	SA = pi * r^2
*
* INPUT
*	radius: a value in meters
* OUTPUT
*	the surface area
********************************************************/
double Acceleration::computeSurfaceArea(double radius)
{
	if (radius < 0)
		return -1; //error
	else
		return radius * radius * M_PI;
}

/*******************************************************
* COMPUTE DRAG FORCE
* Determines the drag force acting on a projectile
* FORMULA:
*	d = 0.5 * c * p * v^2 * a

	c: drag coefficient
	p: density of fluid/gas
	v: velocity of the projectile
	a: surface area
	d: drag force in newtons
*
* INPUT
*	radius: the radius of the projectile
*	velocity: the velocity of the projectile
*	altitude: the altitude of the projectile
* OUTPUT
*	the drag force acting on the projectile
********************************************************/
double Acceleration::computeDragForce(double radius, double velocity,
	double altitude)
{
	// set up surface area
	double surfaceArea = computeSurfaceArea(radius);

	if (surfaceArea != -1)
	{
		// get air pressure
		vector<double> airPoints = lookUpTable(densityTable, altitude);
		double airPressure = computeInterpolation(airPoints);

		// calculate sound velocity
		vector<double> soundPoints = lookUpTable(soundTable, altitude);
		double soundVel = computeInterpolation(soundPoints);
		double mach = abs(velocity / soundVel);

		// calculate drag coefficient
		vector<double> dragPoints = lookUpTable(dragTable, mach);
		double dragCoef = computeInterpolation(dragPoints);


		return 0.5 * dragCoef * airPressure
			* (velocity * velocity) * surfaceArea;
	}
	else
	{
		cout << "Radius was found negative, aborting\n";
		return -1;
	}
}
	
