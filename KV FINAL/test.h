#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "SquareEquation.h"
/**
 \file
 \brief test for solving
*/
/**
 \brief TestVariant tests one variant
 \param Test struct with parameters of Test Equation
*/
int TestVariant(const testsq Test);
/**
 \brief TestAllVariants creates and tests all them
*/
int TestAllVariants();
/**
 \brief GrowingX puts roots of equation in acsending order
 \param TestDecisions struct with roots
 \param nRootsEsp value of expected number of roots
*/
void GrowingX(decisionsq* TestDecisions, int nRootsExp);
/**
 \brief TestPrint print prepared text for test
*/
void TestPrint(const testsq Test, const decisionsq TestDecisions);
/**
 \brief TestReturn analysis accuracy decisions of tests
*/
bool TestReturn(const testsq Test, const decisionsq TestDecisions);
/**
 \brief DoubleComparisonWDouble compare two double values
*/
bool DoubleComparisonWDouble(double a, double b);

#endif // TEST_H_INCLUDED
