#pragma once
#include "acceleration.h"

using namespace std;
class TestAcceleration
{
public:
	// code for simplicity
	void run();
	Acceleration set();
	void tearDown(Acceleration& testAccel);

	// test lookUpTable
	void TestLookUpTable_ExactValueinMiddleInTable();
	void TestLookUpTable_ExactValueIsFirstInTable();
	void TestLookUpTable_ExactValueIsLastInTable();
	void TestLookUpTable_ValueBetweenTwoPoints();
	void TestLookUpTable_ValueBelowFirstPoint();
	void TestLookUpTable_ValueAboveLastPoint();

	// test computeSurfaceArea
	void TestComputeSurfaceArea_NegativeRadius();
	void TestComputeSurfaceArea_0Radius();
	void TestComputeSurfaceArea_PositiveRadius();

	// test commputeInterpolation
	void TestComputeInterpolation_EmptyVector();
	void TestComputeInterpolation_ValidPoints();
	void TestComputeInterpolation_SamePointForEach();

	// test computeDragForce
	void TestComputeDragForce_0Velocity();
	void TestComputeDragForce_PositiveVelocity();
	void TestComputeDragForce_NegativeVelocity();
	void TestComputeDragForce_0Radius();
	void TestComputeDragForce_NegativeRadius();
	void TestComputeDragForce_PositiveRadius();
};

