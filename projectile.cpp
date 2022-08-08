#include "projectile.h"
#include "acceleration.h"

/****************************************************
* DEFAULT CONSTRUCTOR
* sets up the projectile with all attributes set
* to 0.
****************************************************/
Projectile::Projectile() : mass(0), radius(0), flightStatus(false),
launchAngle(0.0), launchTime(0.0)
{
	for (int i = 0; i < 20; i++)
	{
		flightPath[i].setMeters(-1.0, -1.0);
    }
	velocity.setDxDy(0.0, 0.0);
}

/****************************************************
* RESET
* resets the velocity and position of the projectile
****************************************************/
void Projectile::reset()
{
	// reset position
	for (int i = 0; i < 20; i++)
	{
		flightPath[i].setPixelsX(-1.0);
		flightPath[i].setPixelsY(-1.0);
	}
	// reset velocity
	velocity.setDxDy(0.0, 0.0);
	flightStatus = false;
}

/****************************************************
* FIRE
* launches the projectile from the howitzers pozition
* and angle.
* INPUT
*	pos-- the position of the howitzer
*   vel-- the velocity of the projectile at launch
*	angle-- the direction the howitzer fired from
*	time-- the simulation time at the time of launch
****************************************************/
void Projectile::fire(Position pos, Velocity vel, double angle, double time)
{
	flightPath[0].setMeters(pos.getMetersX(), pos.getMetersY());
	velocity.setDxDy(vel.getDX(), vel.getDY());
	flightStatus = true;
	launchAngle = angle;
	launchTime = time;
	launchPos = pos;
}

/****************************************************
* ADVANCE
* advances the projectile based on how much time
* has elapsed.
*INPUT
*	time-- how much time has elapsed since the last render.
****************************************************/
void Projectile::advance(double time)
{
	if (flightStatus)
	{
		Acceleration accel;
		
		// compute the acceleration
		accel.computeAcceleration(mass, radius, velocity.getSpeed(),
			getAltitude(), launchAngle, velocity.getDY());

		// update velocity
		velocity.addDX(accel.getDDX() * time);
		velocity.addDY(accel.getDDY() * time);

		// update position for the tail
		for (int i = 19; i > 0; i--)
		{
			flightPath[i].setMeters(flightPath[i - 1].getMetersX(),
				flightPath[i - 1].getMetersY());
		}
		// update position
		flightPath[0].addMetersX(
			(velocity.getDX() * time)
			+ (0.5 * accel.getDDX() * time * time));

		flightPath[0].addMetersY(
			(velocity.getDY() * time)
			+ (0.5 * accel.getDDY() * time * time));
	}
}

/****************************************************
* DRAW
* draws the projectile and it's tail to the screen
****************************************************/
void Projectile::draw(ogstream& gout)
{
	for (int i = 0; i < 20; i++)
	{
		gout.drawProjectile(flightPath[i], (double)i);
	}
}