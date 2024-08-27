#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED
#include "SquareEquation.h"
/**
 \file
 \brief Input ratios
*/
/**
 \brief InputAllRatioEquation a function that assigns values to all variables

 \param MainRatios struct with variables
*/
int InputAllRatioEquation(ratiosq* MainRatios);
/**
 \brief InputDobleAndPrintMassage a function that assigns value to single variable and prints message

 \param a pointer to variable
 \param Message printable string
*/
int InputDobleAndPrintMassage(double* a, const char* Message);
/**
 \brief PrintMessage function that prints message
 */
void PrintMessage(const char* Message);
/**
 \brief InputDouble function that processes input and assigns value
 \param t pointer to variable
 */
int InputDouble(double* t);
/**
 \brief IsReadable The function that checks input for EOF or invalid values
*/
int IsReadable();

#endif // INPUT_H_INCLUDED
