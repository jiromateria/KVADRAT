#include "PrintSq.h"


int PrintRoots(decisionsq* MainDecisions)
{
    unsigned int def = txGetConsoleAttr();
    txSetConsoleAttr(TX_GREEN);
    switch(MainDecisions -> nRoots)
    {
        case NOROOTS: printf("������ ���\n");
                break;

        case ONEROOT: printf("1 ������ - %lg\n",MainDecisions -> x1);
                break;

        case TWOROOTS: printf("2 ����� - %lg � %lg\n",MainDecisions -> x1, MainDecisions -> x2);
                break;

        case ZEROD: printf("������������ = 0, ��� ���������� ����� - %lg\n",
                    MainDecisions -> x1);
                    break;

        case SS_INF_ROOTS: printf("����� �����\n");
                           break;

        default: ColorPrintf(TX_RED,"ERROR\n");
                    return 1;
        }
    txSetConsoleAttr(def);
    return 0;
}

