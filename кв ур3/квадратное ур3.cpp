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
    ratiosq TestRatios;
    decisionsq TestDecisionsExp;
};



void SolveSquare(ratiosq MainRatios, decisionsq* MainDecisions);
double Discrim(const double a, const double b, const double c);
int PrintRoots(decisionsq* MainDecisions);
int SolveLine(const double b,const double c,  double* x1);
int InputDouble(double* t);
int InputDobleAndPrintMassage(double* a, const char* Message);
int InputAllRatioEquation(ratiosq* MainRatio);
bool DoubleComparison(double a);
bool DoubleComparisonWDouble(double a, double b);
int IsReadable();
void GrowingX(decisionsq* TestDecisions, int nRoots);
void PrintMessage(const char* Message);
void TestPrint(const testsq Test,const testsq TestDecisions);
int TestAllVariants();
int TestVariant(const testsq Test);
bool TestReturn(const testsq Test, const decisionsq TestDecisions);
void TestPrint(const testsq Test,const decisionsq TestDecisions);

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

const testsq A[] =
{
    {1, 0, 0, 0, 0, 0, SS_INF_ROOTS},
    {2, 0, 0, 1, 0, 0, NOROOTS},
    {3, 0, 1, 1, -1, 0, ONEROOT},
    {4, 1, 2, -3, -3, 1, TWOROOTS},
    {5, 1e-7,1e-7,1e-7, 0, 0, SS_INF_ROOTS},
    {6, 1, -2, 1, 1, 0, ZEROD},
    {7, 1, 0, -4, -2, +2, TWOROOTS}
};


int main()
{
    if(TestAllVariants())
        printf("IZI PIZI\n");
    struct ratiosq MainRatios = {0, 0, 0};
    struct decisionsq MainDecisions = {0, 0, 0};

    printf("Введите значения коэфициентов квадратного уравнения:\n");
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
        case NOROOTS: printf("Корней нет\n");
                break;

        case ONEROOT: printf("1 корень - %lg\n",MainDecisions -> x1);
                break;

        case TWOROOTS: printf("2 корня - %lg и %lg\n",MainDecisions -> x1, MainDecisions -> x2);
                break;

        case ZEROD: printf("Дискриминант = 0, два одинаковых корня - %lg\n",
        MainDecisions -> x1);

        case SS_INF_ROOTS: printf("Любое число\n");
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
            printf("Ошибка, вы ввели не число, повторите попытку\n");
        }
    return ZEROOK;
}

int InputAllRatioEquation(ratiosq* MainRatios)
{
    assert(MainRatios != NULL);

    if(InputDobleAndPrintMassage(&(MainRatios -> a), "Введите а") == ONEEOF)
        return ONEEOF;
    if(InputDobleAndPrintMassage(&(MainRatios -> b), "Введите b") == ONEEOF)
        return ONEEOF;
    return (InputDobleAndPrintMassage(&(MainRatios -> c), "Введите c"));
}

bool DoubleComparison(const double a)
{
    return (fabs(a) < EPSILON);
}

bool DoubleComparisonWDouble(double a, double b)
{
    return (fabs(a - b) < EPSILON);
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


int TestVariant(const testsq Test)
{
    decisionsq TestDecisions = {0, 0, 0};
    SolveSquare(Test.TestRatios, &TestDecisions);
    GrowingX(&TestDecisions, Test.TestDecisionsExp.nRoots);
    return TestReturn(Test, TestDecisions);

}

int TestAllVariants()
{
    for(int i=0; i < 7; i++)
        if(!TestVariant(A[i]))
            return 0;
    return 1;
}

void GrowingX(decisionsq* TestDecisions, int nRootsExp)
{
    assert(TestDecisions != NULL);

    if(nRootsExp == TWOROOTS)
    {
        double swapper = 0;
        if(TestDecisions -> x1 > TestDecisions -> x2)
        {
            swapper = TestDecisions -> x2;
            TestDecisions -> x2 = TestDecisions -> x1;
            TestDecisions -> x1 = swapper;
        }
}   }

void TestPrint(const testsq Test, const decisionsq TestDecisions)
{
        printf("ERROR in test №%d: a=%lg, b=%lg, c=%lg\n"
        "x1=%lg , x2=%lg, nRoots=%d\nMust be: x1=%lg, x2=%lg, nRoots=%d\n",
        Test.nTest, Test.TestRatios.a, Test.TestRatios.b, Test.TestRatios.c, TestDecisions.x1,TestDecisions.x2,
        TestDecisions.nRoots, Test.TestDecisionsExp.x1, Test.TestDecisionsExp.x2, Test.TestDecisionsExp.nRoots);
}

bool TestReturn(const testsq Test, const decisionsq TestDecisions)
{
    switch(Test.TestDecisionsExp.nRoots)
    {
        case NOROOTS: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots)
                    {
                        TestPrint(Test, TestDecisions);
                        return 0;
                    }
                return 1;

        case ONEROOT: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots ||
                   !DoubleComparisonWDouble(TestDecisions.x1, Test.TestDecisionsExp.x1))
                    {
                        TestPrint(Test, TestDecisions);
                        return 0;
                    }
                return 1;

        case ZEROD: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots ||
                   !DoubleComparisonWDouble(TestDecisions.x1, Test.TestDecisionsExp.x1))
                    {
                        TestPrint(Test, TestDecisions);
                        return 0;
                    }
                return 1;

        case TWOROOTS: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots ||
                   !DoubleComparisonWDouble(TestDecisions.x1, Test.TestDecisionsExp.x1) ||
                   !DoubleComparisonWDouble(TestDecisions.x2, Test.TestDecisionsExp.x2))
                    {
                        TestPrint(Test, TestDecisions);
                        return 0;
                    }
                return 1;

        case SS_INF_ROOTS: if(TestDecisions.nRoots != Test.TestDecisionsExp.nRoots)
                    {
                        TestPrint(Test, TestDecisions);
                        return 0;
                    }
                return 1;
    }
}


