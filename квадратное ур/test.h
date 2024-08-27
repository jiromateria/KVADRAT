#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include "SquareEquation.h"

static int TestVariant(const testsq Test);
int TestAllVariants();
void GrowingX(decisionsq* TestDecisions, int nRootsExp);
static void TestPrint(const testsq Test, const decisionsq TestDecisions);
static bool TestReturn(const testsq Test, const decisionsq TestDecisions);
bool DoubleComparisonWDouble(double a, double b);

#endif // TEST_H_INCLUDED
