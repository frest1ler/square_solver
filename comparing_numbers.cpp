#include <stdio.h>
#include <assert.h>
#include "comparing_numbers.h"
#include "square_solver.h"
// TODO: убрать лишние инклюды

// TODO: смотри TODO к функции compare_double()
int compare_with_zero(double x)
// TODO: ~~~~~~~~~~~~^ написать const
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                               // TODO: для кого пустая строка
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
{
    if (fabs(x) <  EPSILON)
// TODO: ~~~~~~~~~^ лишний пробел
    {
        return INSIDE_THE_EPSILON_NEIGHBORHOOD;
    }
    if (x  < -EPSILON)
    {
        return LESS_THAN_EPSILON;
    }
    return MORE_THAN_EPSILON;
}

// TODO: наверное, стоит поменять название
int is_nan(double x)
{
    if (x != x)
    {
        return 1;
    }
    return 0;

    // TODO: иначе говоря return x != x
}

// TODO: написать функцию сравнения даблов в общем случае
//       в функции compare_with_zero() вызывать эту функцию,
//       передавая в качестве одного из аргументов 0
//       в функции compare_double(), вызывать функцию сравнения в общем случае
//       саму функцию compare_double() (в смысле в ее данном значении), переименовать
int compare_double(double x, double y)
// TODO: ~~~~~~~~~~^~~~~~~~~^ написать const
{
    int number_nan_roots = is_nan(x) + is_nan(y);

    if (number_nan_roots == 0)
    {
        if (fabs(x - y) <  EPSILON)
// TODO: ~~~~~~~~~~~~~~~~~^ лишний пробел
        {
            return NUMBERS_ARE_EQUAL;
        }
        if (x - y  < -EPSILON) // TODO: формально можно сравнивать не с -EPSILON, а с 0
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

// TODO: переименовать
double max(double x, double y)
// TODO: ~^~~~~~~~~^ написать const
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
        // TODO:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Лишняя проверка на равенство,
        //                                            так как если x = y без разницы, что возвращать
        if (compare_double(x, y) == NUMBERS_ARE_EQUAL || compare_double(x, y) == X_IS_GREATER_THAN_Y)
        {
            return x;
        }
        return y;
    }
}

// TODO: переименовать
// TODO: что нибудь придумать с копипастой
double min(double x, double y)
// TODO: ~^~~~~~~~~^ написать const
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
        // TODO:~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Лишняя проверка на равенство
        if (compare_double(x, y) == NUMBERS_ARE_EQUAL || compare_double(x, y) == X_IS_GREATER_THAN_Y)
        {
            return y;
        }
        return x;
    }
}
