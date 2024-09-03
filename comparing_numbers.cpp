#include "comparing_numbers.h"
#include "square_solver.h"

// TODO: смотри TODO к функции compare_double()
int compare_with_zero(const double x)
{
    if (fabs(x) < EPSILON)
    {
        return INSIDE_THE_EPSILON_NEIGHBORHOOD; // = 0
    }
    if (x  < -EPSILON)
    {
        return LESS_THAN_EPSILON; // = -1
    }
    return MORE_THAN_EPSILON; // = 1
}

int count_nan(const double x)
{
    return (x != x);
}

// TODO: написать функцию сравнения даблов в общем случае
//       в функции compare_with_zero() вызывать эту функцию,
//       передавая в качестве одного из аргументов 0
//       в функции compare_double(), вызывать функцию сравнения в общем случае
//       саму функцию compare_double() (в смысле в ее данном значении), переименовать
int compare_double(const double x, const double y)
{
    int number_nan_roots = count_nan(x) + count_nan(y);

    if (number_nan_roots == 0)
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
    // TODO: 6457913675462376542376492734 COPYPASTE
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

double max(const double x, const double y)
{
    if (compare_double(x, y) == HAVE_ONE_NAN_ROOT)
    {
        if (count_nan(x))
        {
            return x;
        }
        return y;
    }
    else
    {
        // TODO:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Лишняя проверка на равенство,
        //                                            так как если x = y без разницы, что возвращать
        if (compare_double(x, y) == NUMBERS_ARE_EQUAL || compare_double(x, y) == X_IS_GREATER_THAN_Y)
        {
            return x;
        }
        return y;
    }
}

// TODO: что нибудь придумать с копипастой
double min(const double x, const double y)
{
    if (compare_double(x, y) == HAVE_ONE_NAN_ROOT)
    {
        if (count_nan(x))
        {
            return y;
        }
        return x;
    }
    else
    {
        // TODO:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Лишняя проверка на равенство
        if (compare_double(x, y) == NUMBERS_ARE_EQUAL || compare_double(x, y) == X_IS_GREATER_THAN_Y)
        {
            return y;
        }
        return x;
    }
}
