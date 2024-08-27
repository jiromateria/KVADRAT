#include "Input.h"

int InputAllRatioEquation(ratiosq* MainRatios)
{
    assert(MainRatios != NULL);

    if(InputDobleAndPrintMassage(&(MainRatios -> a), "������� �") == ONEEOF)
        return ONEEOF;
    if(InputDobleAndPrintMassage(&(MainRatios -> b), "������� b") == ONEEOF)
        return ONEEOF;
    return (InputDobleAndPrintMassage(&(MainRatios -> c), "������� c"));
}

int InputDobleAndPrintMassage(double* a, const char* Message)
{
    assert(a != NULL);
    assert(Message != NULL);

    PrintMessage(Message);
    return InputDouble(a);
}

void PrintMessage(const char* Message)
{
    assert(Message != NULL);

    printf("%s\n",Message);
}

int InputDouble(double* t)
{
    assert(t != NULL);

    int ch='a';
    int i = 0,k = 0;
    while((k = scanf("%lg",t)) != 1 || (i = IsReadable()))
        {
            if(k && i == TWOEOF)
                return TWOEOF;
            else if(k)
                return ONEEOF;
            while((ch = getchar()) != '\n' && ch != EOF);
            if(ch == EOF)
                return ONEEOF;
            ColorPrintf(TX_RED,"������, �� ����� �� �����, ��������� �������\n");
        }
    return ZEROOK;
}

int IsReadable()
{
    int ch = 'a';

    while((ch = getchar()) != '\n' && ch != EOF)
        {
            if(!isspace(ch))
                return 1;
        }
    if(ch == EOF)
        return TWOEOF;
    return 0;
}

