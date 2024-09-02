#include <stdio.h>
#include <assert.h>
#include "utilities.h"
#include "square_solver.h"

// TODO: расформировать файл utulities.h
int compare_with_zero(double x)    // comparing coeffs with zero
                                   // TODO: нахуя коммент
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

void clear_buffer() // TODO: функция не чистит буфер, переименовать
{
	int clean = 0; // TODO: название говно, хотя бы symbol/character

	do
	{
        clean = getchar();
	} while (clean != '\n' && clean != EOF);
}

void init_equation_roots(struct Equation_roots *roots)
{
    // TODO: где ассерты
    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = NO_ROOTS;
}

int make_choice() // TODO: переименовать
{

    // ^^^^^^^^^^^^^^^^^^^^^TODO: Убрать пустую строку
    int program_operation_mode = 0; // TODO: переименовать  

    printf("enter y or n\n");

    while (program_operation_mode != 'y' && program_operation_mode != 'n')
	{
        program_operation_mode = getchar();
	}

    clear_buffer();
    if (program_operation_mode == 'y')
    {
        return(YES); // TODO: Убрать скобки
    }
    return(NO); // TODO: Убрать скобки
}

int is_nan(double x)
{
    if (isfinite(x)) // TODO: попытка похвальная, но результат хромает
    {
        return 0; // nan or inf
    }
    return 1; // TODO: return not isfinite(x);
}

int compare_double(double x, double y)
{
    int number_of_nan_roots = is_nan(x) + is_nan(y); // TODO: либо везде number_of_..., либо ..._number

    if (number_of_nan_roots == 0)
    {
        if (fabs(x-y) <  EPSILON)
        {
            return THE_NUMBERS_ARE_EQUAL;
        }
        if (x-y  < -EPSILON)
// TODO:    ^~~^^ Пробелы поплыли
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
        } // TODO: используй один if
        else if (compare_double(x, y) == X_IS_GREATER_THAN_Y)
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
        } // TODO: используй один if
        if (compare_double(x, y) == X_IS_GREATER_THAN_Y)
        {
            return y;
        }
        return x;
    }
}
