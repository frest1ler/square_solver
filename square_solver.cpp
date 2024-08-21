#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

const int INFINITY_ROOTS = -1;
const int NO_ROOTS = 0;
const double EPSILON = 1e-9;

int data_entry(double* a, double* b, double* c);
int square_solver(double a, double b, double c, double* x1, double* x2, int* number_roots);
int linear_solver(double b, double c, double* x1, double* x2, int* number_roots);
int data_output(int number_roots, double x1, double x2);
int compare_with_zero (double x);

int main()
{
    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    int number_roots = 0;

    data_entry(&a, &b, &c);

    if (compare_with_zero(a) != 0)
    {
        square_solver(a, b, c, &x1, &x2, &number_roots);
    }
    else
    {
        linear_solver(b, c, &x1, &x2, &number_roots);
    }

    data_output(number_roots, x1, x2);
}

int data_entry(double* a, double* b, double* c)
{
    printf("a=");
    scanf("%lg",a);

    printf("\n"
           "b=");
    scanf("%lg",b);

    printf("\n"
           "c=");
    scanf("%lg",c);

    printf("\n"); //input a,b,c

}

int square_solver(double a, double b, double c, double* x1, double* x2, int* number_roots)
{
    if (compare_with_zero(b) == 0 && compare_with_zero(c) == 0)
    {
        *x1 = *x2 = fabs(-b / (2 * a));
        *number_roots = 1;
    }
    else
    { // compare_with_zero(b) != 0 || compare_with_zero(c) != 0
        double d = NAN, sqrt_d = NAN;

        d = b * b - 4 * a * c;

        if (d < 0)
        {
            *number_roots = NO_ROOTS;
        }
        if (d == 0)
        {
            *number_roots = 1;
            *x1 = *x2 = -b / (2 * a);
        }

        if (d > 0)
        {
        *number_roots = 2;
        sqrt_d = sqrt(d);
        *x1 = (-b + sqrt_d) / (2 * a);
        *x2 = (-b - sqrt_d) / (2 * a);
        }
    }
}

int data_output(int number_roots, double x1, double x2)
{
    switch (number_roots)
    {
        case NO_ROOTS :
        {
            printf("Nule roots\n");
            break;
        }
        case 1 :
        {
            printf("One roots x=%lg\n", x1);
            break;
        }
        case 2 :
        {
            printf("Two roots x1=%lg , x2=%lg\n", x1, x2);
            break;
        }
        case INFINITY_ROOTS :
        {
            printf("infinitely many roots\n");
            break;
        }
        default :
        {
            printf("ERROR\n");
            break;
        }
    }
}

int linear_solver(double b, double c, double* x1, double* x2, int* number_roots)
{

    if (compare_with_zero(b) == 0)
    {
        if (compare_with_zero(c) == 0)
        {
            *number_roots = INFINITY_ROOTS;
        }
        else
        {
            *number_roots = NO_ROOTS;
        }
    }
    else // (b != 0)
    {
        if (compare_with_zero(c) == 0)
        {
            *x1 = *x2 = fabs(-c / b);
            *number_roots = 1;
        }
        else
        {
            *number_roots = 1;
            *x1 = *x2 = -c / b;
        }
    }
}

int compare_with_zero (double x)    // comparing coeffs with zero
{
    if (fabs(x) < EPSILON) return 0;
    else if (x < -EPSILON) return -1;
    else return 1;
}
