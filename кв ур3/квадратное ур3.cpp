#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>

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
    double a, b, c;
    double x1Exp,x2Exp;
    int nRootsExp;
}



void SolveSquare(ratiosq MainRatios, decisionsq* MainDecisions);
double Discrim(const double a, const double b, const double c);
int PrintRoots(decisionsq* MainDecisions);
int SolveLine(const double b,const double c,  double* x1);
int InputDouble(double* t);
int InputDobleAndPrintMassage(double* a, const char* Message);
int InputAllRatioEquation(ratiosq* MainRatio);
bool DoubleComparison(double a);
int IsReadable();
void PrintMessage(const char* Message);
// int TestALLVariants();
int TestVariant(const testsq Test);

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


int main()
{
    //if(TestAllVariants())
    struct ratiosq MainRatios = {0, 0, 0};
    struct decisionsq MainDecisions = {0, 0, 0};

    printf("������� �������� ������������ ����������� ���������:\n");
    printf("ax^2+bx+c=0\n");

    if(InputAllRatioEquation(&MainRatios) == ONEEOF)
    {
        printf("EOF");
        return 0;
    }

    SolveSquare(MainRatios, &MainDecisions);
    if(PrintRoots(&MainDecisions) == 1)
        return 1;

    return 0;
}


void SolveSquare(ratiosq MainRatios, decisionsq* MainDecisions)
{
    assert(&MainRatios != NULL);
    assert(MainDecisions != NULL);

    if(DoubleComparison(MainRatios.a))
        (MainDecisions -> nRoots) = SolveLine(MainRatios.b, MainRatios.c, &(MainDecisions -> x1));
    else
    {
        double D = 0, sq_D = 0;
        D = Discrim(MainRatios.a, MainRatios.b, MainRatios.c);
        if(D < 0)
            (MainDecisions -> nRoots) = NOROOTS;
        else if(DoubleComparison(D))
        {
            (MainDecisions -> x1) = -(MainRatios.b) / (2*(MainRatios.a));
            (MainDecisions -> nRoots) = ZEROD;
        }
        else
        {
            sq_D = sqrt(D);
            (MainDecisions -> x1) = (-(MainRatios.b) - sq_D) / (2*(MainRatios.a));
            (MainDecisions -> x2) = (-(MainRatios.b) + sq_D) / (2*(MainRatios.a));
            (MainDecisions -> nRoots) = TWOROOTS;
        }
    }
}


double Discrim(const double a,const double b,const double c)
{
    return b * b - 4 * a * c;
}


int PrintRoots(decisionsq* MainDecisions)
{
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

        case SS_INF_ROOTS: printf("����� �����\n");
                           break;

        default: printf("ERROR\n");
                    return 1;
        }
    return 0;
}

int SolveLine(const double b,const double c, double* x1)
{
    assert(x1 != NULL);

    if(DoubleComparison(b))
        return ((DoubleComparison(c)) ? SS_INF_ROOTS: NOROOTS);
    else
        {
        *x1 = -c / b;
        return ONEROOT;
        }
}

int InputDobleAndPrintMassage(double* a, const char* Message)
{
    assert(a != NULL);
    assert(Message != NULL);

    PrintMessage(Message);
    return InputDouble(a);
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
            else if(!k)
                return ONEEOF;
            while((ch = getchar()) != '\n' && ch != EOF);
            if(ch == EOF)
                return ONEEOF;
            printf("������, �� ����� �� �����, ��������� �������\n");
        }
    return ZEROOK;
}

int InputAllRatioEquation(ratiosq* MainRatios)
{
    assert(MainRatios != NULL);

    if(InputDobleAndPrintMassage(&(MainRatios -> a), "������� �") == ONEEOF)
        return ONEEOF;
    if(InputDobleAndPrintMassage(&(MainRatios -> b), "������� b") == ONEEOF)
        return ONEEOF;
    return (InputDobleAndPrintMassage(&(MainRatios -> c), "������� c"));
}

bool DoubleComparison(double a)
{
    return (fabs(a) < EPSILON);
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

void PrintMessage(const char* Message)
{
    assert(Message != NULL);

    printf("%s\n",Message);
}

/*
int TestVariant(const int nTest,const double a,const double b,const double c,const double x1Real,const double x2Real,const int nRootsReal)
{
    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare(a , b, c, &x1, &x2);
    if(nRoots != nRootsReal || x1 != x1real || x2 != x2real );
        printf("ERROR in test �%d: a=%lg, b=%lg, c=%lg\n"
        "x1=%lg , x2=%lg, nRoots=%d\nMust be: x1=%lg, x2=%lg, nRoots=%d",
        nTest, a, b, c, x1, x2, nRoots, x1Real, x2Real, nRootsReal);
        Return 0;
    Return 1;
}

int TestAllVariants()
{
    TestVariant(1, 0, 0, 0, 0, 0, SS_INF_ROOTS);
    TestVariant(2, 0, 0, 1, 0, 0, 0);
}
*/
