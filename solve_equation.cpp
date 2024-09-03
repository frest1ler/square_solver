#include <assert.h>
#include "solve_equation.h"
#include "comparing_numbers.h"

void solve_equation(const Equation_coefficients *coefficients, Equation_roots *roots)
{
    assert(coefficients);
    assert(roots);

    assert(isfinite(coefficients->a));
    assert(isfinite(coefficients->b));
    assert(isfinite(coefficients->c));
    if (compare_with_zero(coefficients->a) != INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        solve_square(coefficients, roots);
    }
    else
    {
        solve_linear(coefficients, roots);
    }
}

void solve_square(const Equation_coefficients *coefficients, Equation_roots *roots)
{
    assert(roots);
    assert(coefficients);

    assert(isfinite(coefficients->a));
    assert(isfinite(coefficients->b));
    assert(isfinite(coefficients->c));

    if (compare_with_zero(coefficients->b) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            roots->x1 = 0;
            roots->roots_number = ONE_ROOT;
        }
    }
    else // b != 0 //
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD) //b != 0 && c == 0
        {
            roots->x1 = 0;
            roots->x2 = - coefficients->b / coefficients->a;
            roots->roots_number = TWO_ROOTS;
        }
        else // b != 0 && c != 0
        {
            double const discriminant = coefficients->b * coefficients->b - 4 * coefficients->a * coefficients->c;

            if (compare_with_zero(discriminant) == LESS_THAN_EPSILON)
            {
                roots->roots_number = NO_ROOTS;
            }
            else if (compare_with_zero(discriminant) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
            {
                roots->roots_number = ONE_ROOT;
                roots->x1 = -coefficients->b / (2 * coefficients->a);
            }

            else if (compare_with_zero(discriminant) == MORE_THAN_EPSILON)
            {
                roots->roots_number = TWO_ROOTS;
                double const sqrt_discriminant = sqrt(discriminant);
                roots->x1 = (-coefficients->b + sqrt_discriminant) / (2 * coefficients->a);
                roots->x2 = (-coefficients->b - sqrt_discriminant) / (2 * coefficients->a);
            }
        }
    }
}

void solve_linear(const Equation_coefficients *coefficients, Equation_roots *roots)
{
    assert(roots);
    assert(coefficients);

    assert(isfinite(coefficients->a));
    assert(isfinite(coefficients->b));
    assert(isfinite(coefficients->c));

    if (compare_with_zero(coefficients->b) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            roots->roots_number = INFINITY_ROOTS;
        }
        else
        {
            roots->roots_number = NO_ROOTS;
        }
    }
    else
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            roots->x1 = 0;
            roots->roots_number = ONE_ROOT;
        }
        else
        {
            roots->roots_number = ONE_ROOT;
            roots->x1 = -coefficients->c / coefficients->b;
        }
    }
}
