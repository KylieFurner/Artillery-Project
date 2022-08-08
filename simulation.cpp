/*************************************************************
 * 1. Name:
 *      Jake Rammell
 * 2. Assignment Name:
 *      Lab 12: Code Complete
 * 3. Assignment Description:
 *      Simulate firing the M777 howitzer 15mm artillery piece
 * 4. What was the hardest part? Be as specific as possible.
 *      Getting the physics to work correctly. Velocity and Acceleration
 *      work off of the standard unit circle for radians, whereas the 
 *      rest of the program us straight up as 0 and moving clockwise increases
 *      the angle. I made a facade to temporarilly marry the two.
 * 5. How long did it take for you to complete the assignment?
 *      20
 *****************************************************************/

#define _USE_MATH_DEFINES
#include "simulation.h"
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"   // for POSITION
#include "test.h"

using namespace std;

/****************************************************
* NON DEFAULT CONSTRUCTOR
* this is the only constructor, and requires the 
* top right position of the screen.
* INPUT
*   ptUpperRight-- the top right position of the screen
****************************************************/
Simulation::Simulation(Position& ptUpperRight): interval(0.0), 
isWinMessage(false), simTime(0.0), ground(ptUpperRight), ptUpperRight(ptUpperRight)
{}

/****************************************************
* IS BORDER HIT
* returns true if the projectile has left the screen
* either left or right.
****************************************************/
bool Simulation::isBorderHit()
{
    if (projectile.isFlying())
    {
        if (projectile.getPosition().getPixelsX() < 0
            || projectile.getPosition().getPixelsX() > ptUpperRight.getPixelsX())
            return true;
    }
    return false;
}

/****************************************************
* IS GROUND HIT
* returns true if the projectile has hit the ground
****************************************************/
bool Simulation::isGroundHit()
{
    if (projectile.isFlying())
    {
        //getElevationMeters returns the elevation of the ground at 
        // the projectiles x position.
        if (projectile.getAltitude()
            <= ground.getElevationMeters(projectile.getPosition()))
            return true;
    }
    return false;
}

/****************************************************
* IS TARGET HIT
* returns true if the projectile has hit the target.
****************************************************/
bool Simulation::isTagetHit()
{
    if (projectile.isFlying())
    {
        // determine if the projectile is within the x limits
        if
            (projectile.getPosition().getPixelsX()
                >= ground.getTarget().getPixelsX() - 5.0
                &&
                projectile.getPosition().getPixelsX()
                <= ground.getTarget().getPixelsX() + 5.0)
        {
           // determine if the projectile is within the y limits
            if (projectile.getPosition().getPixelsY()
                >= ground.getTarget().getPixelsY() - 5.0
                &&
                projectile.getPosition().getPixelsY()
                <= ground.getTarget().getPixelsY() + 5.0)
            {
                return true;
            }
        }
    }
    // determine if the projectile intersected with the target
    return isIntersect();
}

/****************************************************
* IS INTERSECT
* returns true if the projectile's path intersects the
* target's position.
****************************************************/
bool Simulation::isIntersect()
{
    // get the last 2 known positions
    Position currentPos;
    Position lastPos;
    currentPos = projectile.getPosition();
    lastPos = projectile.getLastPosition();

    // find the slope
    double slope = (currentPos.getPixelsY() - lastPos.getPixelsY())
        / (currentPos.getPixelsX() - lastPos.getPixelsX());

    // find the y intercept
    double intercept = 
        (-currentPos.getPixelsX() * slope) + currentPos.getPixelsY();

    // check each point
    for (int i = 0;
        i <= currentPos.getPixelsX() - lastPos.getPixelsX();
        i++)
    {   
        double x = lastPos.getPixelsX() + (double)i;
        double y = (slope * x) + intercept;
        if
            ( x >= ground.getTarget().getPixelsX() - 5.0
                &&
              x <= ground.getTarget().getPixelsX() + 5.0)
        {
           
            // determine if the projectile is within the y limits
            if (y >= ground.getTarget().getPixelsY() - 5.0
                &&
                y <= ground.getTarget().getPixelsY() + 5.0)
            {
                cout << "Target Hit!\n";
                return true;
            }
        }   
    }
    return false;
}

/****************************************************
* HANDLE COLLISIONS
* takes appropriate action if the border is hit, 
* the ground is hit, or if the target is hit.
****************************************************/
void Simulation::handleCollisions()
{
    // 
    if (isTagetHit())
        isWinMessage = true;

    // handle all other collisions
    if (isGroundHit() || isBorderHit())
        projectile.reset();
}

void Simulation::reset()
{
    // reset the projectile
    projectile.reset();

    // reset the ground
    Position tempPos;
    ground.reset(tempPos);

    // reset the howitzer
    howitzer.setPosition(tempPos);
}

/****************************************************
* FIRE
* launches the projectile, if available.
****************************************************/
void Simulation::fire()
{
    if (!projectile.isFlying())
    {
        double speed = howitzer.getMuzzleVelocity();
        double simAngle = howitzer.getAngle();

        // convert angle for easy physics use
        double angle = convertAngleToUnitCircleStd(simAngle);
        Velocity vel;
        vel.setVelocityFromTotal(angle, speed);
        projectile.fire(howitzer.getPosition(), vel, angle, simTime);
    }
}

/****************************************************
* CONVERT ANGLE TO UNIT CIRCLE STD
* converts the angle to be used in the physics engine.
* returns the new angle
****************************************************/
double Simulation::convertAngleToUnitCircleStd(double angle)
{
    // create a direction object to normalize the angle
    Direction tempDir;
    
    // step 1: add pi / 2 to the angle 
    //    --> rotates the angle 90 degrees: in unit circle, up is pi / 2
    tempDir.setRadians(angle + (M_PI / 2));

    // step 2: convert from polar to cartesian. radius is 1 
    //     --> this allows us to manipulate just the x value.
    double x = cos(tempDir.getRadians());
    double y = sin(tempDir.getRadians());

    // step 3: reflect about the y-axis. (x,y) -> (-x,y)
    //    --> the unit circle angle increases counter-clockwise.
    x = -x;

    // step 4: convert back to polar. Radius is 1
    double newAngle = 0.0;

    // if the angle is in the 2nd or 3rd quadrant
    if (x < 0)
        newAngle = atan(y / x) + M_PI;

    // if the angle is in the 1st or 4th quadrant
    else if (x > 0)
        newAngle = atan(y / x);

    // if the angle is on the y axis
    else
    {
        if (y > 0)
            newAngle = M_PI / 2;
        else if (y < 0)
            newAngle = (3 * M_PI) / 2;
    }
    // step 5: normalize the angle
    tempDir.setRadians(newAngle);
    return tempDir.getRadians();

}
/****************************************************
* DISPLAY
* displays everything to the user through the screen
****************************************************/
void Simulation::display(ogstream& gout)
{
    // draw the ground
    ground.draw(gout);

    // draw the howitzer
    howitzer.draw(gout, simTime - projectile.getLaunchTime());

    // draw the projectile
    projectile.draw(gout);

    // draw status text on the screen
    Position textPos;
    textPos = ptUpperRight;
    textPos.addPixelsX(-130);
    textPos.addPixelsY(-20);
    gout.setf(ios::fixed | ios::showpoint);
    gout.precision(1);
    gout.setPosition(textPos);

    if (projectile.isFlying())
    {
        gout << "Altitude:  " << projectile.getAltitude() << "m\n"
             << "speed:     " << projectile.getSpeed() << "m/s\n"
             << "distance:  " << projectile.getFlightDistance() << "m\n"
             << "hang time: " << simTime - projectile.getLaunchTime() << "s\n";
    }
    else
    {
        gout << "Altitude:  " << howitzer.getPosition().getMetersY() << "m\n"
             << "speed:     " << projectile.getSpeed() << "m/s\n"
             << "distance:  " << "0.0" << "m\n"
             << "hang time: " << "0.0" << "s\n";
    }

    // draw win message on screen
    if (isWinMessage)
    {
        // center text
        Position winPos;
        winPos.setMeters(ptUpperRight.getMetersX() / 2,
            ptUpperRight.getMetersY() / 2);
        gout.setPosition(winPos);
        gout << "Target Hit!\n" << "(Press Space to Play Again)\n";
    }
}

/****************************************************
* INPUT
* handles user input.
****************************************************/
void Simulation::input(const Interface* ui)
{
    if (ui->isLeft())
    {
        if (howitzer.getAngle() - 0.05 >= 3 * M_PI / 2 
            || howitzer.getAngle() - 0.05 <= M_PI /2)
        {
            howitzer.rotate(-0.05);
        }
    }
    if (ui->isRight())
        if (howitzer.getAngle() + 0.05 >= 3 * M_PI / 2
            || howitzer.getAngle() + 0.05 <= M_PI / 2)
        {
            howitzer.rotate(0.05);
        }

    if (ui->isUp())
    {
            howitzer.raise(0.003);
    }
    if (ui->isDown())
    {
        if (howitzer.getAngle() - 0.003 >= 3 * M_PI / 2
            || howitzer.getAngle() - 0.003 <= M_PI / 2)
            howitzer.raise(-0.003);
    }
    if (!isWinMessage)
    {
        if (ui->isSpace())
            fire();
    }
    // reset the game if the player hits space after win.
    else
    {
        if (ui->isSpace())
        {
            isWinMessage = false;
            reset();
        }
    }       
}

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
    // the first step is to cast the void pointer into a game object. This
    // is the first step of every single callback function in OpenGL. 
    Simulation* pSim = (Simulation*)p;

    // accept input
    pSim->input(pUI);
   
    // move the projectile across the screen
    pSim->advance();

    // handle collisions
    pSim->handleCollisions();
   
    // draw everything
    ogstream gout(Position(10.0, pSim->getPtUpperRight().getPixelsY() - 20.0));
    pSim->display(gout);
}

double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
 #ifdef _WIN32_X
 #include <windows.h>
 int WINAPI wWinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ PWSTR pCmdLine,
    _In_ int nCmdShow)
 #else // !_WIN32
 int main(int argc, char** argv)
 #endif // !_WIN32
 {
     //tests
     testRunner();

    // Initialize OpenGL
    Position().setZoom(40.0 /* 42 meters equals 1 pixel*/);
    Position ptUpperRight;
    ptUpperRight.setPixelsX(700.0);
    ptUpperRight.setPixelsY(500.0);
    
    Interface ui(0, NULL,
       "Howitzer Simulator",   /* name on the window*/
       ptUpperRight);

    // Initialize the simulation
    Simulation sim(ptUpperRight);
    sim.reset();
    sim.setInterval(1.0);
    sim.setMuzzleVelocity(827);
    sim.setRadiusAndMass(0.077445, 46.7);

    // set everything into action
    ui.run(callBack, &sim);

    return 0;
 }
