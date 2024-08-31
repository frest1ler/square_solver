#include <stdio.h>
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
