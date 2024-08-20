#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

const int INFINITY_ROOTS = -1;
const int NO_ROOTS = 0;

int data_entry( double* a, double* b, double* c);
int square_solver( double a, double b, double c, double* x1, double* x2, int* numberRoots);
int linear_solver( double b, double c, double* x1, double* x2, int* numberRoots);
int data_output( int nRoots, double x1, double x2);

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int numberRoots = 0;

    data_entry( &a, &b, &c );

    if ( a != 0 )
    {
        square_solver( a, b, c, &x1, &x2, &numberRoots);
    }
    else
    {
        linear_solver( b, c, &x1, &x2, &numberRoots);
    }

    data_output( numberRoots, x1, x2);
}

int data_entry( double* a, double* b, double* c)
{
    printf("a=");
    scanf("%lg",a);
    printf("\n");
    printf("b=");
    scanf("%lg",b);
    printf("\n");
    printf("c=");
    scanf("%lg",c);
    printf("\n"); //input a,b,c
}

int square_solver( double a, double b, double c, double* x1, double* x2, int* numberRoots)
{
    double d = NAN, sqrt_d = NAN;
    d = b * b - 4 * a * c;
    if ( d < 0 )
    *numberRoots = NO_ROOTS;
    if ( d == 0 )
    {
        *numberRoots = 1;
        *x1 = *x2 = -b / (2 * a);
    }
    if ( d > 0 )
    {
        *numberRoots = 2;
        sqrt_d = sqrt ( d );
        *x1 = ( -b + sqrt_d ) / ( 2 * a );
        *x2 = ( -b - sqrt_d ) / ( 2 * a );
    }
}

int data_output( int numberRoots, double x1, double x2)
{
    switch ( numberRoots )
    {
        case NO_ROOTS :
        {
            printf("Nule roots");
            break;
        }
        case 1 :
        {
            printf("One roots x=%lg", x1);
            break;
        }
        case 2 :
        {
            printf("Two roots x1=%lg , x2=%lg", x1, x2);
            break;
        }
        case INFINITY_ROOTS :
        {
            printf("infinitely many roots");
            break;
        }
        default :
        {
            printf("ERROR");
            break;
        }
    }
}

int linear_solver( double b, double c, double* x1, double* x2, int* numberRoots)
{

    if ( b == 0)
    {
        if ( c == 0)
        {
            *numberRoots = INFINITY_ROOTS;
        }
        else
        {
            *numberRoots = NO_ROOTS;
        }
    }
    else // ( b != 0 )
    {
        *numberRoots = 1;
        *x1 = *x2 = -c / b;
    }
}
