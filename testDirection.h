#pragma once
#include "direction.h"

class TestDirection
{
public:
	// code for simplicity
	void run();
	Direction set();
	void tearDown(Direction& testDirection);

	// test assign
	void TestAssign_PosititveDirection();
	void TestAssign_NegativeDirection();
	void TestAssign_ZeroDirection();
	void TestAssign_DefaultDirection();

	// test setRadians
	void TestSetRadians_PositiveAngle();
	void TestSetRadians_NegativeAngle();
	void TestSetRadians_ZeroAngle();
	void TestSetRadians_GreaterThan2Pi();
	void TestSetRadians_LessThanNeg2Pi();

	// test setDegrees
	void TestSetDegrees_PositiveAngle();
	void TestSetDegrees_NegativeAngle();
	void TestSetDegrees_ZeroAngle();
	void TestSetDegrees_GreaterThan360();
	void TestSetDegrees_LessThanNeg360();

	// test setDown
	void TestSetDown_AngleVertical();
	void TestSetDown_AnglePointingUp();
	void TestSetDown_AnglePointingDown();
	void TestSetDown_AnglePointingHorizontal();

	// test setUp
	void TestSetUp_AngleVertical();
	void TestSetUp_AnglePointingUp();
	void TestSetUp_AnglePointingDown();
	void TestSetUp_AnglePointingHorizontal();

	// test setRight
	void TestSetRight_AngleVertical();
	void TestSetRight_AnglePointingUp();
	void TestSetRight_AnglePointingDown();
	void TestSetRight_AnglePointingHorizontal();

	// test setLeft
	void TestSetLeft_AngleVertical();
	void TestSetLeft_AnglePointingUp();
	void TestSetLeft_AnglePointingDown();
	void TestSetLeft_AnglePointingHorizontal();

	// test reverse
	void TestReverse_Angle0();
	void TestReverse_AnglePi();
	void TestReverse_PositiveAngle();
	void TestReverse_NegativeAngle();

	// test getRadians and getDegrees
	void TestGetRadians_AngleSetTo0();
	void TestGetRadians_PositiveAngle();
	void TestGetRadians_NegativeAngle();

	void TestGetDegrees_AngleSetTo0();
	void TestGetDegrees_PositiveAngle();
	void TestGetDegrees_NegativeAngle();

	// test getDx and getDy
	void TestGetDx_0Value();
	void TestGetDx_PositiveValue();
	void TestGetDx_NegativeValue();

	void TestGetDy_0Value();
	void TestGetDy_PositiveValue();
	void TestGetDy_NegativeValue();
};

