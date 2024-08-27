#include "SolveSq.h"
#include "Menu.h"
#include <stdlib.h>


int Menu(int n, char* Ar[])
{
    assert(Ar != NULL);

    switch(n)
    {
        case 1: return 1;

        case 2: ColorPrintf(TX_RED,"Вы не ввели номер операции\n");
                return 2;

        case 3: return (IsGoodMenu(Ar));

        default: ColorPrintf(TX_RED, "Слишком много написали\n");
                 return 2;
    }

}

int IsGoodMenu(char* Ar[])
{
    unsigned int size1 = strlen(Ar[1]);
    unsigned int size2 = strlen(Ar[2]);
    if(size1 != 2 || size2 != 1)
        {
            ColorPrintf(TX_RED, "Ошибка ввода\n");
            return 2;
        }
    if(Ar[1][0] == '-' && Ar[1][1] == 'm')
        {
            if(Ar[2][0] == '1')
                return 1;
            else if(Ar[2][0] == '0')
                return 0;
        }
    ColorPrintf(TX_RED, "Ошибка ввода\n");;
    return 2;
}
