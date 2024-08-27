#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>
#include <stdarg.h>
#include "ColorPrint.h"
/**
 \file
 \brief main header
*/
/**
 \brief ratiosq struct for ratios of Sq equation
*/
struct ratiosq
{
    double a; ///< coeff a
    double b; ///< coeff b
    double c; ///< coeff c
};
/**
 \brief decisionsq struct for decisions of Sq equation
*/
struct decisionsq
{
    double x1; /// < first root
    double x2; /// < second root
    int nRoots; /// < numbers of roots
};
/**
 \brief testsq struct for test
*/
struct testsq
{
    int nTest; /// < number of test
    ratiosq TestRatios; /// < ratios for test
    decisionsq TestDecisionsExp; /// < expected decisions
};

double const EPSILON = 1e-6;
/**
 \brief NOMBEROFROOTS consts of nombers of roots
*/
enum NOMBEROFROOTS{
    ZEROD = -3, /// < discrim = 0
    SS_INF_ROOTS = -1, /// < infinite roots
    NOROOTS = 0, /// < zero roots
    ONEROOT, /// < one root
    TWOROOTS /// < two roots
};
/**
 \brief ISEOF consts for analysis input
*/
enum ISEOF{
    ZEROOK=0, /// < all is OK
    ONEEOF=1, /// < Bad
    TWOEOF=2  /// < EOF
};

#define TX_GREEN  0x00000002 /// < green color
#define TX_RED 0x00000004 /// < red color
#define TX_YELLOW 0x000000006 /// < yellow color



#endif // MAIN_H_INCLUDED
