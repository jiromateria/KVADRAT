#include <stdio.h>
#include <TXLib.h>
#include <math.h>

int SolveSquare(double a, double b, double c, double* x1, double* x2);
double Discrim(double a, double b, double c);
int PrintRoots(int nRoots, double x1, double x2);
int SolveLine(double b,double c,double* x1);
double InputRatio(double* t);
void InputDobleAndPrintMassage(double* a);
void InputAll(double* a, double* b, double* c);

int const SS_INF_ROOTS = -1;
double const EPSILON = 1e-6;
int const ZEROD = -3;

int main()
{

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;

    printf("Введите значения коэфициентов квадратного уравнения:\n");
    printf("ax^2+bx+c=0\n");

    InputAll(&a, &b, &c);

    int nRoots = SolveSquare(a, b, c, &x1, &x2);
    if(PrintRoots(nRoots, x1, x2) == 1)
        return 1;

    return 0;
}


int SolveSquare( double a, double b, double c, double* x1, double* x2)
{
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if(fabs(a) < EPSILON)
        return SolveLine(b, c, x1);
    else
    {
        double D = 0, sq_D = 0;
        D = Discrim(a, b, c);
        if(D < 0)
            return 0;
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
            return 2;
        }
    }
}


double Discrim(double a, double b, double c)
{
    return b * b - 4 * a * c;
}


int PrintRoots(int nRoots, double x1, double x2)
{
    switch(nRoots)
    {
        case 0: printf("Корней нет\n");
                break;

        case 1: printf("1 корень - %lg\n",x1);
                break;

        case 2: printf("2 корня - %lg и %lg\n", x1, x2);
                break;

        case ZEROD: printf("Дискриминант = 0, два одинаковых корня - %lg\n",
        x1);

        case SS_INF_ROOTS: printf("Любое число\n");
                           break;

        default: printf("ERROR\n");
                    return 1;
        }
    return 0;
}

int SolveLine(double b, double c, double* x1)
{
    if(fabs(b) < EPSILON)
        return (fabs(c) < EPSILON) ? SS_INF_ROOTS: 0;
    else
        {
        *x1 = -b / c;
        return 1;
        }
}

void InputDobleAndPrintMassage(double* a)
{
    assert(a != NULL);
    printf("Введите значение\n");
    InputRatio(a);
}

double InputRatio(double* t)
{
    char ch;
    while(scanf("%lg",t) != 1)
        {
        while((ch = getchar()) != '\n' && ch != EOF);
        printf("Ошибка, вы ввели не число,повторите попытку\n");
        }
    return 0;
}

void InputAll(double* a, double* b, double* c)
{
    InputDobleAndPrintMassage(a);
    InputDobleAndPrintMassage(b);
    InputDobleAndPrintMassage(c);
}
