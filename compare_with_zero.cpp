#include "utilities.h"
#include "square_solver.h"

int compare_with_zero(double x)    // comparing coeffs with zero
{
    if (fabs(x) <  EPSILON)
    {
        return INSIDE_THE_EPSILON_NEIGHBORHOOD;
    }
    else if (x  < -EPSILON)
    {
        return LESS_THAN_EPSILON;
    }
    else return MORE_EPSILON; //TODO убрать else
}
