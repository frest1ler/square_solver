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

int communication_with_user()
{

    int program_operation_mode = 0;

    assert(&program_operation_mode);

    printf("enter y or n\n");

    while (program_operation_mode != 'y' && program_operation_mode != 'n')
	{
        program_operation_mode = getchar();
	}

    clear_buffer();
    if (program_operation_mode == 'y')
    {
        return(1);
    }
    return(0);
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
            return  THE_NUMBERS_ARE_EQUAL;
        }
        else // have the one nan roots
        {
            printf("ERROR COMPARE DOUBLE\n");
            return ERROR_COMPARE;
        }
    }
}

double max(double x, double y)
{
    switch(compare_double(x, y))
    {
        case THE_NUMBERS_ARE_EQUAL :
        {
            return x;
        }
        case Y_IS_GREATER_THAN_X :
        {
            return y;
        }
        case X_IS_GREATER_THAN_Y :
        {
            return x;
        }
        default :
        {
            printf("ERROR MAX");
            return ERROR_MAX;
            break;
        }
    }
}

double min(double x, double y)
{
    switch(compare_double(x, y))
    {
        case THE_NUMBERS_ARE_EQUAL :
        {
            return y;
        }
        case Y_IS_GREATER_THAN_X :
        {
            return x;
        }
        case X_IS_GREATER_THAN_Y :
        {
            return y;
        }
        default :
        {
            printf("ERROR MIN");
            return ERROR_MIN;
            break;
        }
    }
}



