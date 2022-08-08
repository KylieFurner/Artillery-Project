#define _USE_MATH_DEFINES
#include "testDirection.h"
#include <cassert>
#include <cmath>

using namespace std;
void TestDirection::run()
{
	// test assign
	TestAssign_PosititveDirection();
	TestAssign_NegativeDirection();
	TestAssign_ZeroDirection();
	TestAssign_DefaultDirection();

	// test setRadians
	TestSetRadians_PositiveAngle();
	TestSetRadians_NegativeAngle();
	TestSetRadians_ZeroAngle();
	TestSetRadians_GreaterThan2Pi();
	TestSetRadians_LessThanNeg2Pi();

	// test setDegrees
	TestSetDegrees_PositiveAngle();
	TestSetDegrees_NegativeAngle();
	TestSetDegrees_ZeroAngle();
	TestSetDegrees_GreaterThan360();
	TestSetDegrees_LessThanNeg360();

	// test setDown
	TestSetDown_AngleVertical();
	TestSetDown_AnglePointingUp();
	TestSetDown_AnglePointingDown();
	TestSetDown_AnglePointingHorizontal();

	// test setUp
	TestSetUp_AngleVertical();
	TestSetUp_AnglePointingUp();
	TestSetUp_AnglePointingDown();
	TestSetUp_AnglePointingHorizontal();

	// test setRight
	TestSetRight_AngleVertical();
	TestSetRight_AnglePointingUp();
	TestSetRight_AnglePointingDown();
	TestSetRight_AnglePointingHorizontal();

	// test setLeft
	TestSetLeft_AngleVertical();
	TestSetLeft_AnglePointingUp();
	TestSetLeft_AnglePointingDown();
	TestSetLeft_AnglePointingHorizontal();

	// test reverse
	TestReverse_Angle0();
	TestReverse_AnglePi();
	TestReverse_PositiveAngle();
	TestReverse_NegativeAngle();

	// test getRadians and getDegrees
	TestGetRadians_AngleSetTo0();
	TestGetRadians_PositiveAngle();
	TestGetRadians_NegativeAngle();

	TestGetDegrees_AngleSetTo0();
	TestGetDegrees_PositiveAngle();
	TestGetDegrees_NegativeAngle();

	// test getDx and getDy
	TestGetDx_0Value();
	TestGetDx_PositiveValue();
	TestGetDx_NegativeValue();

	TestGetDy_0Value();
	TestGetDy_PositiveValue();
	TestGetDy_NegativeValue();
}

// sets up the direction object
Direction TestDirection::set()
{
	Direction testDirection;
	testDirection.radians = 0;
	return testDirection;
}

// destroys the direction object
void TestDirection::tearDown(Direction& testDirection)
{
	testDirection.~Direction();
}

// test assign in positive angle
void TestDirection::TestAssign_PosititveDirection()
{
	// set
	Direction testDirection = set();

	// execute
	Direction newDirection;
	newDirection.radians = 3;
	testDirection.assign(newDirection);

	// verify
	assert(testDirection.radians == 3);

	// teardown
	tearDown(testDirection);
	tearDown(newDirection);
}

// test assign with negative angle
void TestDirection::TestAssign_NegativeDirection()
{
	// set
	Direction testDirection = set();

	// execute
	Direction newDirection;
	newDirection.radians = -3;
	testDirection.assign(newDirection);

	// verify
	assert(testDirection.radians > 3.2830 && testDirection.radians < 3.2832);

	// teardown
	tearDown(testDirection);
	tearDown(newDirection);
}

// test assign with 0 angle
void TestDirection::TestAssign_ZeroDirection()
{
	// set
	Direction testDirection = set();

	// execute
	Direction newDirection;
	newDirection.radians = 0;
	testDirection.assign(newDirection);

	// verify
	assert(testDirection.radians == 0);

	// teardown
	tearDown(testDirection);
	tearDown(newDirection);
}

// test assign with default value
void TestDirection::TestAssign_DefaultDirection()
{
	// set
	Direction testDirection = set();

	// execute
	Direction newDirection;
	testDirection.assign(newDirection);

	// verify
	assert(testDirection.radians == testDirection.radians);

	// teardown
	tearDown(testDirection);
	tearDown(newDirection);
}

// test setRadians with positive angle
void TestDirection::TestSetRadians_PositiveAngle()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setRadians(3);
	assert(testDirection.radians == 3);

	// teardown
	tearDown(testDirection);
}

// test setRadians with negative angle
void TestDirection::TestSetRadians_NegativeAngle()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setRadians(-3);
	assert(testDirection.radians > 3.2830 && testDirection.radians < 3.2832);

	// teardown
	tearDown(testDirection);
}

// test setRadians with zero angle
void TestDirection::TestSetRadians_ZeroAngle()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setRadians(0);
	assert(testDirection.radians == 0);

	// teardown
	tearDown(testDirection);
}

// test setRadians with positive angle greater than 2pi
void TestDirection::TestSetRadians_GreaterThan2Pi()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setRadians(3 * M_PI);
	assert(testDirection.radians == M_PI);

	// teardown
	tearDown(testDirection);
}

// test setRadians with positive angle greater than 2pi
void TestDirection::TestSetRadians_LessThanNeg2Pi()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setRadians(-3.5 * M_PI);
	assert(testDirection.radians == 0.5 * M_PI);

	// teardown
	tearDown(testDirection);
}

// test setDegrees with positive angle
void TestDirection::TestSetDegrees_PositiveAngle()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setDegrees(45);
	assert(testDirection.radians == M_PI / 4);

	// teardown
	tearDown(testDirection);
}

// test setDegrees with negative angle
void TestDirection::TestSetDegrees_NegativeAngle()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setDegrees(-30);
	assert(testDirection.radians > 5.7595 && testDirection.radians < 5.7596);

	// teardown
	tearDown(testDirection);
}

// test setDegrees with zero angle
void TestDirection::TestSetDegrees_ZeroAngle()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setDegrees(0);
	assert(testDirection.radians == 0);

	// teardown
	tearDown(testDirection);
}

// test setDegrees with positive angle greater than 2pi
void TestDirection::TestSetDegrees_GreaterThan360()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setDegrees(390);
	assert(testDirection.radians > 0.5235 && testDirection.radians < 0.5236);

	// teardown
	tearDown(testDirection);
}

// test setDegrees with positive angle greater than 2pi
void TestDirection::TestSetDegrees_LessThanNeg360()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setDegrees(-390);
	assert(testDirection.radians > 5.7595 && testDirection.radians < 5.7596);

	// teardown
	tearDown(testDirection);
}


// test setDown
void TestDirection::TestSetDown_AngleVertical()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setDown();
	assert(testDirection.radians == M_PI);

	testDirection.radians = M_PI;
	testDirection.setDown();
	assert(testDirection.radians == M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetDown_AnglePointingUp()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 1;

	// execute and verify
	testDirection.setDown();
	assert(testDirection.radians == M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetDown_AnglePointingDown()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 3;

	// execute and verify
	testDirection.setDown();
	assert(testDirection.radians == M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetDown_AnglePointingHorizontal()
{
	// set
	Direction testDirection = set();
	testDirection.radians = M_PI / 2.0;

	// execute and verify
	testDirection.setDown();
	assert(testDirection.radians == M_PI);

	testDirection.radians = 1.5 * M_PI;
	testDirection.setDown();
	assert(testDirection.radians == M_PI);

	// teardown
	tearDown(testDirection);
}

// test setUp
void TestDirection::TestSetUp_AngleVertical()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setUp();
	assert(testDirection.radians == 0);

	testDirection.radians = M_PI;
	testDirection.setUp();
	assert(testDirection.radians == 0);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetUp_AnglePointingUp()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 1;

	// execute and verify
	testDirection.setUp();
	assert(testDirection.radians == 0);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetUp_AnglePointingDown()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 3;

	// execute and verify
	testDirection.setUp();
	assert(testDirection.radians == 0);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetUp_AnglePointingHorizontal()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 0.5 * M_PI;

	// execute and verify
	testDirection.setUp();
	assert(testDirection.radians == 0);

	testDirection.radians = 1.5 * M_PI;
	testDirection.setUp();
	assert(testDirection.radians == 0);

	// teardown
	tearDown(testDirection);
}

// test setRight

void TestDirection::TestSetRight_AngleVertical()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setRight();
	assert(testDirection.radians == 0.5 * M_PI);

	testDirection.radians = M_PI;
	testDirection.setRight();
	assert(testDirection.radians == 0.5 * M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetRight_AnglePointingUp()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 1;

	// execute and verify
	testDirection.setRight();
	assert(testDirection.radians == 0.5 * M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetRight_AnglePointingDown()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 3;

	// execute and verify
	testDirection.setRight();
	assert(testDirection.radians == 0.5 * M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetRight_AnglePointingHorizontal()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 0.5 * M_PI;

	// execute and verify
	testDirection.setRight();
	assert(testDirection.radians == 0.5 * M_PI);

	testDirection.radians = 1.5 * M_PI;
	testDirection.setRight();
	assert(testDirection.radians == 0.5 * M_PI);

	// teardown
	tearDown(testDirection);
}

// test setLeft
void TestDirection::TestSetLeft_AngleVertical()
{
	// set
	Direction testDirection = set();

	// execute and verify
	testDirection.setLeft();
	assert(testDirection.radians == 1.5 * M_PI);

	testDirection.radians = M_PI;
	testDirection.setLeft();
	assert(testDirection.radians == 1.5 * M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetLeft_AnglePointingUp()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 1;

	// execute and verify
	testDirection.setLeft();
	assert(testDirection.radians == 1.5 * M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetLeft_AnglePointingDown()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 3;

	// execute and verify
	testDirection.setLeft();
	assert(testDirection.radians == 1.5 * M_PI);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestSetLeft_AnglePointingHorizontal()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 0.5 * M_PI;

	// execute and verify
	testDirection.setLeft();
	assert(testDirection.radians == 1.5 * M_PI);

	testDirection.radians = 1.5 * M_PI;
	testDirection.setLeft();
	assert(testDirection.radians == 1.5 * M_PI);

	// teardown
	tearDown(testDirection);
}

// test reverse
void TestDirection::TestReverse_Angle0()
{
	// set
	Direction testDirection = set();
	Direction newDirection;

	// execute and verify
	newDirection = testDirection.reverse();
	assert(newDirection.radians > 3.14158 && newDirection.radians < 3.14160);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestReverse_AnglePi()
{
	// set
	Direction testDirection = set();
	testDirection.radians = M_PI;

	// execute and verify
	Direction newDirection = testDirection.reverse();
	assert(newDirection.radians == 0);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestReverse_PositiveAngle()
{
	// set
	Direction testDirection = set();
	testDirection.radians = M_PI / 4;

	// execute and verify
	Direction newDirection = testDirection.reverse();
	assert(newDirection.radians == 5 * M_PI / 4);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestReverse_NegativeAngle()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 3 * M_PI / 4;

	// execute and verify
	Direction newDirection = testDirection.reverse();
	assert(newDirection.radians == 7 * M_PI / 4);

	// teardown
	tearDown(testDirection);
}

// test getRadians and getDegrees
void TestDirection::TestGetRadians_AngleSetTo0()
{
	// set
	Direction testDirection = set();

	// execute and verify
	double value = testDirection.getRadians();
	assert(value == 0);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestGetRadians_PositiveAngle()
{
	// set
	Direction testDirection = set();
	testDirection.radians = 1;

	// execute and verify
	double value = testDirection.getRadians();
	assert(value == 1);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestGetRadians_NegativeAngle()
{
	// set
	Direction testDirection = set();
	testDirection.setRadians(-1);

	// execute and verify
	double value = testDirection.getRadians();
	assert(value > 5.2831 && value < 5.2832);

	// teardown
	tearDown(testDirection);
}

void TestDirection::TestGetDegrees_AngleSetTo0()
{
	// set
	Direction testDirection = set();

	// execute and verify
	double value = testDirection.getDegrees();
	assert(value == 0);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestGetDegrees_PositiveAngle()
{
	// set
	Direction testDirection = set();
	testDirection.radians = M_PI / 4;

	// execute and verify
	double value = testDirection.getDegrees();
	assert(value == 45);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestGetDegrees_NegativeAngle()
{
	// set
	Direction testDirection = set();
	testDirection.setRadians(-M_PI / 4);

	// execute and verify
	double value = testDirection.getDegrees();
	assert(value == 315);

	// teardown
	tearDown(testDirection);
}

// test getDx and getDy
void TestDirection::TestGetDx_0Value()
{
	// set
	Direction testDirection = set();

	// execute and verify
	double value = testDirection.getDx();
	assert(value == 0);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestGetDx_PositiveValue()
{
	// set
	Direction testDirection = set();
	testDirection.radians = M_PI / 4;

	// execute and verify
	double value = testDirection.getDx();
	assert(value > 0.7071 && value < 0.7072);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestGetDx_NegativeValue()
{
	// set
	Direction testDirection = set();
	testDirection.setRadians(-3 * M_PI / 4);

	// execute and verify
	double value = testDirection.getDx();
	assert(value > -0.7072 && value < -0.7071);

	// teardown
	tearDown(testDirection);
}

void TestDirection::TestGetDy_0Value()
{
	// set
	Direction testDirection = set();

	// execute and verify
	double value = testDirection.getDy();
	assert(value == 1);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestGetDy_PositiveValue()
{
	// set
	Direction testDirection = set();
	testDirection.radians = M_PI / 4;

	// execute and verify
	double value = testDirection.getDy();
	assert(value > 0.7071 && value < 0.7072);

	// teardown
	tearDown(testDirection);
}
void TestDirection::TestGetDy_NegativeValue()
{
	// set
	Direction testDirection = set();
	testDirection.setRadians(-5 * M_PI / 4);

	// execute and verify
	double value = testDirection.getDy();
	assert(value > -0.7072 && value < -0.7071);

	// teardown
	tearDown(testDirection);
}