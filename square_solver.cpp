#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

const int    INFINITY_ROOTS = -1;
const int    NO_ROOTS       =  0;
const int    ONE_ROOTS      =  1;
const int    TWO_ROOTS      =  2;            //TODO
const double EPSILON        =  1e-9;

int data_entry(double* a, double* b, double* c);
int math_calculus(double a, double b, double c, double* x1, double* x2, int* number_roots);
int square_solver(double a, double b, double c, double* x1, double* x2, int* number_roots);
int linear_solver(double b, double c, double* x1, double* x2, int* number_roots);
int data_output(int number_roots, double x1, double x2);
int compare_with_zero (double x);

int main()
{
    double a = NAN, b = NAN, c = NAN, x1 = NAN, x2 = NAN;
    int number_roots = 0;

    data_entry(&a, &b, &c);

    math_calculus(a, b, c, &x1, &x2, &number_roots);

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
    assert(isfinite(*a));//TODO
    assert(isfinite(*b));
    assert(isfinite(*c));
}

int square_solver(double a, double b, double c, double* x1, double* x2, int* number_roots)
{
    if (compare_with_zero(b) == 0 && compare_with_zero(c) == 0)//TODO check is NULL x1, x2 - adress
    {
        *x1 = *x2 = 0;
        *number_roots = ONE_ROOTS;
    }
    else
    { // compare_with_zero(b) != 0 || compare_with_zero(c) != 0
        double discriminant = NAN, sqrt_discriminant = NAN;

        discriminant = b * b - 4 * a * c;

        if (compare_with_zero(discriminant) == -1)
        {
            *number_roots = NO_ROOTS;
        }
        if (compare_with_zero(discriminant) == 0)
        {
            *number_roots = ONE_ROOTS;
            *x1 = *x2 = -b / (2 * a);
        }

        if (compare_with_zero(discriminant) == 1)
        {
            *number_roots = TWO_ROOTS;
            sqrt_discriminant = sqrt(discriminant);
            *x1 = (-b + sqrt_discriminant) / (2 * a);
            *x2 = (-b - sqrt_discriminant) / (2 * a);
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
        case ONE_ROOTS :
        {
            printf("One roots x=%lg\n", x1);
            break;
        }
        case TWO_ROOTS :
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
    else
    {
        if (compare_with_zero(c) == 0)
        {
            *x1 = *x2 = 0;
            *number_roots = ONE_ROOTS;
        }
        else
        {
            *number_roots = ONE_ROOTS;
            *x1 = *x2 = -c / b;
        }
    }
}

int compare_with_zero(double x)    // comparing coeffs with zero
{
    if (fabs(x) <  EPSILON)
    {
        return 0;
    }
    else if (x  < -EPSILON)
    {
        return -1;
    }
    else return 1;
}

int math_calculus(double a, double b, double c, double* x1, double* x2, int* number_roots)
{
   if (compare_with_zero(a) != 0)
    {
        square_solver(a, b, c, x1, x2, number_roots);
    }
    else
    {
        linear_solver(b, c, x1, x2, number_roots);
    }
}
