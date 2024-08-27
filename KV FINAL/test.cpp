#include "test.h"
#include "SolveSq.h"


int TestVariant(const testsq Test)
{
    decisionsq TestDecisions = {0, 0, 0};
    SolveSquare(Test.TestRatios, &TestDecisions);
    GrowingX(&TestDecisions, Test.TestDecisionsExp.nRoots);
    return TestReturn(Test, TestDecisions);

}

int TestAllVariants()
{

    const testsq A[] =
    {
        {1, 0, 0, 0, NAN, NAN, SS_INF_ROOTS},
        {2, 0, 0, 1, NAN, NAN, NOROOTS},
        {3, 0, 1, 1, -1, NAN, ONEROOT},
        {4, 1, 2, -3, -3, 1, TWOROOTS},
        {5, 1e-7,1e-7,1e-7, NAN, NAN, SS_INF_ROOTS},
        {6, 1, -2, 1, 1, NAN, ZEROD},
        {7, 1, 0, -4, -2, +2, TWOROOTS}
    };

    unsigned int size = sizeof(A) / sizeof(A[0]);

    for(unsigned int i = 0; i < size; i++)
    {
        assert(i < size);

        if(!TestVariant(A[i]))
            return 0;
    }
    return 1;
}

void GrowingX(decisionsq* TestDecisions, int nRootsExp)
{
    assert(TestDecisions != NULL);

    if(nRootsExp == TWOROOTS)
    {
        double swapper = 0;
        if(TestDecisions -> x1 > TestDecisions -> x2)
        {
            swapper = TestDecisions -> x2;
            TestDecisions -> x2 = TestDecisions -> x1;
            TestDecisions -> x1 = swapper;
        }
}   }

void TestPrint(const testsq Test, const decisionsq TestDecisions)
{
        printf("ERROR in test ¹%d: a=%lg, b=%lg, c=%lg\n"
        "x1=%lg , x2=%lg, nRoots=%d\nMust be: x1=%lg, x2=%lg, nRoots=%d\n",
        Test.nTest, Test.TestRatios.a, Test.TestRatios.b, Test.TestRatios.c, TestDecisions.x1,TestDecisions.x2,
        TestDecisions.nRoots, Test.TestDecisionsExp.x1, Test.TestDecisionsExp.x2, Test.TestDecisionsExp.nRoots);
}

bool TestReturn(const testsq Test, const decisionsq TestDecisions)
{
    unsigned int def = txGetConsoleAttr();
    txSetConsoleAttr(TX_RED);
    switch(Test.TestDecisionsExp.nRoots)
    {
        case NOROOTS: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots)
                    {
                        TestPrint(Test, TestDecisions);
                        txSetConsoleAttr(def);
                        return 0;
                    }
                txSetConsoleAttr(def);
                return 1;

        case ONEROOT: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots ||
                   !DoubleComparisonWDouble(TestDecisions.x1, Test.TestDecisionsExp.x1))
                    {
                        TestPrint(Test, TestDecisions);
                        txSetConsoleAttr(def);
                        return 0;
                    }
                txSetConsoleAttr(def);
                return 1;

        case ZEROD: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots ||
                   !DoubleComparisonWDouble(TestDecisions.x1, Test.TestDecisionsExp.x1))
                    {
                        TestPrint(Test, TestDecisions);
                        txSetConsoleAttr(def);
                        return 0;
                    }
                txSetConsoleAttr(def);
                return 1;

        case TWOROOTS: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots ||
                   !DoubleComparisonWDouble(TestDecisions.x1, Test.TestDecisionsExp.x1) ||
                   !DoubleComparisonWDouble(TestDecisions.x2, Test.TestDecisionsExp.x2))
                    {
                        TestPrint(Test, TestDecisions);
                        txSetConsoleAttr(def);
                        return 0;
                    }
                txSetConsoleAttr(def);
                return 1;

        case SS_INF_ROOTS: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots)
                    {
                        TestPrint(Test, TestDecisions);
                        txSetConsoleAttr(def);
                        return 0;
                    }
                txSetConsoleAttr(def);
                return 1;

        default: printf("ERROR\n");
                 txSetConsoleAttr(def);
                 return 0;
    }
}

bool DoubleComparisonWDouble(double a, double b)
{
    return (fabs(a - b) < EPSILON);
}

