#ifndef COLORPRINT_H_INCLUDED
#define COLORPRINT_H_INCLUDED

/**
 \file
 \brief Print color text
*/
/**
 \brief ColorPrintf
 \param color The color of text
 \param str the output colorized line
 \param def The Parameter that saves default color of text
 */
void ColorPrintf(const unsigned int color, const char* str, ...);

#endif // COLORPRINT_H_INCLUDED
