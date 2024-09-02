#include <stdio.h>
#include <assert.h>
#include "utilities.h"
#include "square_solver.h"

int compare_with_zero(double x)    // comparing coeffs with zero
{
    if (fabs(x) <  EPSILON)
    {
        return INSIDE_THE_EPSILON_NEIGHBORHOOD;
    }
    if (x  < -EPSILON)
    {
        return LESS_THAN_EPSILON;
    }
    return MORE_EPSILON;
}

void clear_buffer()
{
	int clean = 0;

	do
	{
        clean = getchar();
	} while (clean != '\n' && clean != EOF);
}

void init_equation_roots(struct Equation_roots *roots)
{
    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = NO_ROOTS;
}

int make_choice()
{

    int program_operation_mode = 0;

    printf("enter y or n\n");

    while (program_operation_mode != 'y' && program_operation_mode != 'n')
	{
        program_operation_mode = getchar();
	}

    clear_buffer();
    if (program_operation_mode == 'y')
    {
        return(YES);
    }
    return(NO);
}

int is_nan(double x)
{
    if (isfinite(x))
    {
        return 0; // nan or inf
    }
    return 1;
}

int compare_double(double x, double y)
{
    int number_of_nan_roots = is_nan(x) + is_nan(y);

    if (number_of_nan_roots == 0)
    {
        if (fabs(x-y) <  EPSILON)
        {
            return THE_NUMBERS_ARE_EQUAL;
        }
        if (x-y  < -EPSILON)
        {
            return Y_IS_GREATER_THAN_X;
        }
        return X_IS_GREATER_THAN_Y;
    }
    else // have a nan roots
    {
        if (number_of_nan_roots == 2)
        {
            return THE_NUMBERS_ARE_EQUAL;
        }
        return HAVE_ONE_NAN_ROOT;
    }
}

double max(double x, double y)
{
    if (compare_double(x, y) == HAVE_ONE_NAN_ROOT)
    {
        if (is_nan(x))
        {
            return x;
        }
        return y;
    }
    else
    {
        if (compare_double(x, y) == THE_NUMBERS_ARE_EQUAL)
        {
            return x;
        }
        if (compare_double(x, y) == X_IS_GREATER_THAN_Y)
        {
            return x;
        }
        return y;
    }
}

double min(double x, double y)
{
    if (compare_double(x, y) == HAVE_ONE_NAN_ROOT)
    {
        if (is_nan(x))
        {
            return y;
        }
        return x;
    }
    else
    {
        if (compare_double(x, y) == THE_NUMBERS_ARE_EQUAL)
        {
            return y;
        }
        if (compare_double(x, y) == X_IS_GREATER_THAN_Y)
        {
            return y;
        }
        return x;
    }
}
