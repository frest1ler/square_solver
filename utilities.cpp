#include <stdio.h>
#include <assert.h>
#include "utilities.h"
#include "square_solver.h"

// TODO: расформировать файл utulities.h
int compare_with_zero(double x)

{
    if (fabs(x) <  EPSILON)
    {
        return INSIDE_THE_EPSILON_NEIGHBORHOOD;
    }
    if (x  < -EPSILON)
    {
        return LESS_THAN_EPSILON;
    }
    return MORE_THAN_EPSILON;
}

void skip_buffer()
{
	int symbol = 0;

	do
	{
        symbol = getchar();
	} while (symbol != '\n' && symbol != EOF);
}

void init_equation_roots(struct Equation_roots *roots)
{
    assert(&roots);

    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = NO_ROOTS;
}

int make_choice() // TODO: переименовать
{
    int program_operation_mode = 0; // TODO: переименовать

    printf("enter y or n\n");

    while (program_operation_mode != 'y' && program_operation_mode != 'n')
	{
        program_operation_mode = getchar();
	}

    skip_buffer();
    if (program_operation_mode == 'y')
    {
        return 1;
    }
    return 0;
}

int is_nan(double x)
{
    if (x != x)
    {
        return 1;
    }
    return 0;
}

int compare_double(double x, double y)
{
    int number_nan_roots = is_nan(x) + is_nan(y);

    if (number_nan_roots == 0)
    {
        if (fabs(x - y) <  EPSILON)
        {
            return NUMBERS_ARE_EQUAL;
        }
        if (x - y  < -EPSILON)
        {
            return Y_IS_GREATER_THAN_X;
        }
        return X_IS_GREATER_THAN_Y;
    }
    else // have a nan roots
    {
        if (number_nan_roots == 2)
        {
            return NUMBERS_ARE_EQUAL;
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
        if (compare_double(x, y) == NUMBERS_ARE_EQUAL || compare_double(x, y) == X_IS_GREATER_THAN_Y)
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
        if (compare_double(x, y) == NUMBERS_ARE_EQUAL || compare_double(x, y) == X_IS_GREATER_THAN_Y)
        {
            return y;
        }
        return x;
    }
}
