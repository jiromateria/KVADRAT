#include "SquareEquation.h"

void ColorPrintf(const unsigned int color, const char* str, ...)
{
    assert(str != NULL);

    int def = txGetConsoleAttr();
    txSetConsoleAttr(color);

    va_list factor;
    va_start(factor, str);
    vprintf(str, factor);
    txSetConsoleAttr(def);
}

