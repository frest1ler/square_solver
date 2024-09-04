#include "comparing_numbers.h"
#include "square_solver.h"

int compare_double(const double x, const double y)
{
    if (fabs(x - y) < EPSILON)
    {
        return NUMBERS_ARE_EQUAL;
    }

    if (x - y  < 0)
    {
        return Y_IS_GREATER_THAN_X;
    }
    return X_IS_GREATER_THAN_Y;
}

int count_nan(const double x)
{
    return (x != x);
}

int compare_double_complex(const double x, const double y)  //TODO  rename
{
    int number_nan_roots = count_nan(x) + count_nan(y);

    if (number_nan_roots == 0)
    {
        return compare_double(x, y);
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

double max(const double x, const double y)  //TODO переделать ф-цию
{
    if (compare_double_complex(x, y) == HAVE_ONE_NAN_ROOT)
    {
        if (count_nan(x))
        {
            return x;
        }
        return y;
    }
    else
    {
        if (compare_double_complex(x, y) == Y_IS_GREATER_THAN_X)
        {
            return y;
        }
        return x;
    }
}

double min(const double x, const double y)
{
    if (compare_double_complex(max(x, y), x) == 0)  //TODO 0
    {
        return y;
    }
    return x;
}

