#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>
#include "ColorPrint.h"

struct ratiosq
{
    double a, b, c;
};

struct decisionsq
{
    double x1, x2;
    int nRoots;
};

struct testsq
{
    int nTest;
    ratiosq TestRatios;
    decisionsq TestDecisionsExp;
};

double const EPSILON = 1e-6;

enum NOMBEROFROOTS{
    ZEROD = -3,
    SS_INF_ROOTS = -1,
    NOROOTS = 0,
    ONEROOT,
    TWOROOTS
};

enum ISEOF{
    ZEROOK=0,
    ONEEOF=1,
    TWOEOF=2
};

#define TX_GREEN  0x00000002
#define TX_RED 0x00000004
#define TX_YELLOW 0x000000006



#endif // MAIN_H_INCLUDED
