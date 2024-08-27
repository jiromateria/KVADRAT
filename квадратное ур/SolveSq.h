#ifndef SOLVESQ_H_INCLUDED
#define SOLVESQ_H_INCLUDED
#include "SquareEquation.h"

void SolveSquare(ratiosq MainRatios, decisionsq* MainDecisions);
static double Discrim(const double a,const double b,const double c);
static int SolveLine(const double b,const double c, double* x1);
static bool DoubleComparison(const double a);

#endif // SOLVESQ_H_INCLUDED
