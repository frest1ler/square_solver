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
    if (isfinite(x) == 1)
    {
        return 0;
    }
    return 1;
}
