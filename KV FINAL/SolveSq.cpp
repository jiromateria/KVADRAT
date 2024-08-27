#include "SolveSq.h"


void SolveSquare(ratiosq MainRatios, decisionsq* MainDecisions)
{
    assert(&MainRatios != NULL);
    assert(MainDecisions != NULL);

    if(DoubleComparison(MainRatios.a))
    {
        (MainDecisions -> x2) = NAN;
        (MainDecisions -> nRoots) = SolveLine(MainRatios.b, MainRatios.c, &(MainDecisions -> x1));
    }
    else
    {
        double D = 0, sq_D = 0;
        D = Discrim(MainRatios.a, MainRatios.b, MainRatios.c);
        if(D < 0)
        {
            (MainDecisions -> x1) = NAN;
            (MainDecisions -> x2) = NAN;
            (MainDecisions -> nRoots) = NOROOTS;
        }
        else if(DoubleComparison(D))
        {
            (MainDecisions -> x1) = -(MainRatios.b) / (2*(MainRatios.a));
            (MainDecisions -> x2) = NAN;
            (MainDecisions -> nRoots) = ZEROD;
        }
        else
        {
            sq_D = sqrt(D);
            (MainDecisions -> x1) = (-(MainRatios.b) - sq_D) / (2*(MainRatios.a));
            (MainDecisions -> x2) = (-(MainRatios.b) + sq_D) / (2*(MainRatios.a));
            (MainDecisions -> nRoots) = TWOROOTS;
        }
    }
}


double Discrim(const double a,const double b,const double c)
{
    return b * b - 4 * a * c;
}

int SolveLine(const double b,const double c, double* x1)
{
    assert(x1 != NULL);

    if(DoubleComparison(b))
    {
        *x1 = NAN;
        return ((DoubleComparison(c)) ? SS_INF_ROOTS: NOROOTS);
    }
    else
        {
        *x1 = -c / b;
        return ONEROOT;
        }
}

bool DoubleComparison(const double a)
{
    return (fabs(a) < EPSILON);
}

