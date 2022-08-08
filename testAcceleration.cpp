#define _USE_MATH_DEFINES
#include <cmath>
#include "testAcceleration.h"
#include <cassert>
#include <iostream>


// run all tests
void TestAcceleration::run()
{
	// test lookUpTable
	
	TestLookUpTable_ExactValueinMiddleInTable();
	TestLookUpTable_ExactValueIsFirstInTable();
	TestLookUpTable_ExactValueIsLastInTable();
	TestLookUpTable_ValueBetweenTwoPoints();
	TestLookUpTable_ValueBelowFirstPoint();
	TestLookUpTable_ValueAboveLastPoint();


	// test computeSurfaceArea
	TestComputeSurfaceArea_NegativeRadius();
	TestComputeSurfaceArea_0Radius();
	TestComputeSurfaceArea_PositiveRadius();

	// test commputeInterpolation
	TestComputeInterpolation_EmptyVector();
	TestComputeInterpolation_ValidPoints();
	TestComputeInterpolation_SamePointForEach();
	

	// test computeDragForce
	TestComputeDragForce_0Velocity();
	TestComputeDragForce_PositiveVelocity();
	TestComputeDragForce_NegativeVelocity();
	TestComputeDragForce_0Radius();
	TestComputeDragForce_NegativeRadius();
	TestComputeDragForce_PositiveRadius();
}

// sets up a drag object to be used
Acceleration TestAcceleration::set()
{
	Acceleration testAccel(0.0, 0.0);
	return testAccel;
}

// destroys class object
void TestAcceleration::tearDown(Acceleration& testAccel)
{
	testAccel.~Acceleration();
}


// test lookUpTable
void TestAcceleration::TestLookUpTable_ExactValueinMiddleInTable()
{
	// setup
	Acceleration testAccel = set();

	// execute
	double machValue = 1.000;
	vector<double> dragPoints = 
		testAccel.lookUpTable(testAccel.dragTable, machValue);

	// verify
	assert(dragPoints[3] == 0.4258);
	assert(dragPoints[4] == 0.4258);

	// teardown
	tearDown(testAccel);
}

void TestAcceleration::TestLookUpTable_ExactValueIsFirstInTable()
{
	// setup
	Acceleration testAccel = set();

	// execute
	double machValue = 0.300;
	vector<double> dragPoints =
		testAccel.lookUpTable(testAccel.dragTable, machValue);

	// verify
	assert(dragPoints[3] == 0.1629);
	assert(dragPoints[4] == 0.1629);

	// teardown
	tearDown(testAccel);
}
void TestAcceleration::TestLookUpTable_ExactValueIsLastInTable()
{
	// setup
	Acceleration testAccel = set();

	// execute
	double machValue = 5.000;
	vector<double> dragPoints =
		testAccel.lookUpTable(testAccel.dragTable, machValue);

	// verify
	assert(dragPoints[3] == 0.2656);
	assert(dragPoints[4] == 0.2656);

	// teardown
	tearDown(testAccel);
}
void TestAcceleration::TestLookUpTable_ValueBetweenTwoPoints()
{
	// setup
	Acceleration testAccel = set();

	// execute
	double machValue = 0.950;
	vector<double> dragPoints =
		testAccel.lookUpTable(testAccel.dragTable, machValue);

	// verify
	assert(dragPoints[0] == 0.920);
	assert(dragPoints[1] == 0.950);
	assert(dragPoints[2] == 0.960);
	assert(dragPoints[3] == 0.3010);
	assert(dragPoints[4] == 0.3287);

	// teardown
	tearDown(testAccel);
}

void TestAcceleration::TestLookUpTable_ValueBelowFirstPoint()

{
	// setup
	Acceleration testAccel = set();

	// execute
	double machValue = 0.100;
	vector<double> dragPoints =
		testAccel.lookUpTable(testAccel.dragTable, machValue);

	// verify
	assert(dragPoints[0] == 0.300);
	assert(dragPoints[1] == 0.300);
	assert(dragPoints[2] == 0.300);
	assert(dragPoints[3] == 0.1629);
	assert(dragPoints[4] == 0.1629);

	// teardown
	tearDown(testAccel);
}
void TestAcceleration::TestLookUpTable_ValueAboveLastPoint()
{
	// setup
	Acceleration testAccel = set();

	// execute
	double machValue = 5.200;
	vector<double> dragPoints =
		testAccel.lookUpTable(testAccel.dragTable, machValue);

	// verify
	assert(dragPoints[0] == 5.000);
	assert(dragPoints[1] == 5.000);
	assert(dragPoints[2] == 5.000);
	assert(dragPoints[3] == 0.2656);
	assert(dragPoints[4] == 0.2656);

	// teardown
	tearDown(testAccel);
}


// test computeDragForce
void TestAcceleration::TestComputeDragForce_0Velocity()
{
	// setup
	Acceleration testAccel = set();

	double velocity = 0.0;
	double radius = 1.0;

	// execute and verify
	double velocity0 = testAccel.computeDragForce(radius, velocity, 0);
	assert(velocity0 == 0);

	tearDown(testAccel);

};
void TestAcceleration::TestComputeDragForce_PositiveVelocity()
{
	Acceleration testdrag = set();

	double velocity = 1020.0;
	//drag coefficient = 0.2324
	double radius = 1.0;
	//surface area = 3.1416
	//altitude = 0, density = 1.225


	double posvelocity = testdrag.computeDragForce(radius, velocity, 0);
	assert(posvelocity > 465305.8200 && posvelocity < 465305.8201);
	//roughly

	tearDown(testdrag);
};
void TestAcceleration::TestComputeDragForce_NegativeVelocity()
{
	Acceleration testdrag = set();

	double velocity = -1020.0;
	//drag coefficient = na
	double radius = 1.0;
	//surface area = 3.1416
	//altitude = 0, density = 1.225


	double negvelocity = testdrag.computeDragForce(radius, velocity, 0);
	assert(negvelocity > 465305.8200 && negvelocity < 465305.8201);
	//roughly
	// negative velocity doesn't matter for drag

	tearDown(testdrag);
};
void TestAcceleration::TestComputeDragForce_0Radius()
{
	Acceleration testdrag = set();

	double radius = 0.0;
	double velocity = 1.0;

	double radius0 = testdrag.computeDragForce(radius, velocity, 0);
	assert(radius0 == 0);

	tearDown(testdrag);

};
void TestAcceleration::TestComputeDragForce_NegativeRadius()
{
	Acceleration testdrag = set();

	double radius = -1.0;
	double velocity = 1.0;

	double negradius = testdrag.computeDragForce(radius, velocity, 0);
	assert(negradius == -1); // error
	//cannot have a negative radius and surface area

	tearDown(testdrag);
};
void TestAcceleration::TestComputeDragForce_PositiveRadius()
{
	Acceleration testdrag = set();

	double velocity = 1020.0;
	//drag coefficient = .4258
	double radius = 1.0;
	//surface area = 3.1416
	//altitude = 0, density = 1.225


	double posradius = testdrag.computeDragForce(radius, velocity, 0);
	assert(posradius > 465305.8200 && posradius < 465305.8201);
	
	//roughly

	tearDown(testdrag);
};

// test computeSurfaceArea
void TestAcceleration::TestComputeSurfaceArea_NegativeRadius()
{
	// setup
	Acceleration testdrag = set();

	//excersise
	double radius = -45;
	double surfaceArea = testdrag.computeSurfaceArea(radius);

	// verify
	assert(surfaceArea == -1); // error

	// teardown
	tearDown(testdrag);
}

void TestAcceleration::TestComputeSurfaceArea_0Radius()
{
	// setup
	Acceleration testdrag = set();

	//excersise
	double radius = 0;
	double surfaceArea = testdrag.computeSurfaceArea(radius);

	// verify
	assert(surfaceArea == 0);

	// teardown
	tearDown(testdrag);
}

void TestAcceleration::TestComputeSurfaceArea_PositiveRadius()
{
	// setup
	Acceleration testdrag = set();

	//excersise
	double radius = 45;
	double surfaceArea = testdrag.computeSurfaceArea(radius);

	// verify
	assert(surfaceArea == (45 * 45 * M_PI));

	// teardown
	tearDown(testdrag);
}


// test commputeInterpolation
void TestAcceleration::TestComputeInterpolation_EmptyVector()
{
	// setup
	Acceleration testdrag = set();

	//excersise
	vector<double> densityTable;
	double result = testdrag.computeInterpolation(densityTable);

	// verify
	assert(result == -1); // error case

	// teardown
	tearDown(testdrag);
}

void TestAcceleration::TestComputeInterpolation_ValidPoints()
{
	// setup
	Acceleration testdrag = set();

	//excersise
	vector<double> gravityTable = {0, 500, 1000, 9.807, 9.804 };
	double result = testdrag.computeInterpolation(gravityTable);

	// verify
	assert(result == 9.8055);

	// teardown
	tearDown(testdrag);
}

void TestAcceleration::TestComputeInterpolation_SamePointForEach()
{
	// setup
	Acceleration testdrag = set();

	//excersise
	vector<double> gravityTable = {1000, 1000, 1000, 9.807, 9.807 };
	double result = testdrag.computeInterpolation(gravityTable);
	cout << result;
	// verify
	assert(result == 9.807);

	// teardown
	tearDown(testdrag);
}