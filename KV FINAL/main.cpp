
#include "test.h"
#include "Input.h"
#include "SolveSq.h"
#include "PrintSq.h"
#include "SquareEquation.h"
#include "Menu.h"




int main(int argc, char* argv[])
{
        ColorPrintf(TX_YELLOW, "fff%d %f %c))\n" , 1000, (float)7, 'z');
        switch(Menu(argc, argv))
        {
            case 1: break;

            case 0: if(TestAllVariants())
                        ColorPrintf(TX_GREEN, "IZI PIZI\n");
                    return 0;

            case 2: return 0;

            default: ColorPrintf(TX_RED, "ERROR\n");
                     return 0;
        }
        struct ratiosq MainRatios = {0, 0, 0};
        struct decisionsq MainDecisions = {0, 0, 0};

        printf("������� �������� ������������ ����������� ���������:\n");
        printf("ax^2+bx+c=0\n");

        if(InputAllRatioEquation(&MainRatios) == ONEEOF)
        {
            ColorPrintf(TX_YELLOW, "EOF");
            return 0;
        }

        SolveSquare(MainRatios, &MainDecisions);
        if(PrintRoots(&MainDecisions) == 1)
            return 1;

        return 0;

}
