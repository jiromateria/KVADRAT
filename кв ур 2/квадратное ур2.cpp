#include <stdio.h>
#include <TXLib.h>
#include <math.h>
#include <ctype.h>


int SolveSquare(const double a, const double b, const double c, double* x1, double* x2);
double Discrim(const double a, const double b, const double c);
int PrintRoots(const int nRoots, const double x1,const  double x2);
int SolveLine(const double b,const double c,  double* x1);
void InputDouble(double* t);
void InputDobleAndPrintMassage(double* a);
void InputAllRatioEquation(double* a, double* b, double* c);
bool DoubleComparison(double a);
bool IsReadable();
// int TestALLVariants();
// int TestVariant(const int nTest,const double a,const double b,const double c,const double x1Real,const double x2Real,const int nRootsReal);

double const EPSILON = 1e-6;

enum NOMBEROFROOTS{
    ZEROD = -3,
    SS_INF_ROOTS = -1,
    NOROOTS = 0,
    ONEROOT,
    TWOROOTS
};


int main()
{
    //if(TestAllVariants())
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf("������� �������� ������������ ����������� ���������:\n");
    printf("ax^2+bx+c=0\n");

    InputAllRatioEquation(&a, &b, &c);

    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    if(PrintRoots(nRoots, x1, x2) == 1)
        return 1;

    return 0;
}


int SolveSquare(const double a,const double b,const double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if(DoubleComparison(a))
        return SolveLine(b, c, x1);
    else
    {
        double D = 0, sq_D = 0;
        D = Discrim(a, b, c);
        if(D < 0)
            return NOROOTS;
        else if(D == 0)
        {
            *x1= -b / (2*a);
            return ZEROD;
        }
        else
        {
            sq_D = sqrt(D);
            *x1 = (-b - sq_D) / (2*a);
            *x2 = (-b + sq_D) / (2*a);
            return TWOROOTS;
        }
    }
}


double Discrim(const double a,const double b,const double c)
{
    return b * b - 4 * a * c;
}


int PrintRoots(const int nRoots, const double x1, const double x2)
{
    switch(nRoots)
    {
        case NOROOTS: printf("������ ���\n");
                break;

        case ONEROOT: printf("1 ������ - %lg\n",x1);
                break;

        case TWOROOTS: printf("2 ����� - %lg � %lg\n", x1, x2);
                break;

        case ZEROD: printf("������������ = 0, ��� ���������� ����� - %lg\n",
        x1);

        case SS_INF_ROOTS: printf("����� �����\n");
                           break;

        default: printf("ERROR\n");
                    return 1;
        }
    return 0;
}

int SolveLine(const double b, const double c, double* x1)
{
    assert(x1 != NULL);

    if(DoubleComparison(b))
        return (DoubleComparison(c)) ? SS_INF_ROOTS: NOROOTS;
    else
        {
        *x1 = -b / c;
        return ONEROOT;
        }
}

void InputDobleAndPrintMassage(double* a)
{
    assert(a != NULL);
    InputDouble(a);
}

void InputDouble(double* t)
{
    assert(t != NULL);

    char ch='a';
    bool i=0;
    printf("������� ��������\n");
    while(scanf("%lg",t) != 1 || (i = IsReadable()))
        {

                while(ch = getchar() != '\n' && ch != EOF);
            printf("������, �� ����� �� �����, ��������� �������\n");


        }
}

void InputAllRatioEquation(double* a, double* b, double* c)
{
    assert(a != NULL);
    assert(b != NULL);
    assert(c != NULL);

    assert(a != c);
    assert(a != b);
    assert(b != c);

    InputDobleAndPrintMassage(a);
    InputDobleAndPrintMassage(b);
    InputDobleAndPrintMassage(c);
}

bool DoubleComparison(double a)
{
    return (fabs(a) < EPSILON);
}

bool IsReadable()
{
    char ch = 'a';
    while((ch = getchar()) != '\n')
        {
            if(isspace(ch));
            else
            {

                return 1;
            }
        }
        return 0;
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
