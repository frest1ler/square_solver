#include <assert.h>
#include "solve_equation.h"
#include "square_solver.h"
#include "utilities.h"

void solve_equation(struct Equation_coefficients *coefficients, struct Equation_roots *roots)
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

void solve_square(struct Equation_coefficients *coefficients, struct Equation_roots *roots)
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
            roots->number_roots = ONE_ROOTS;
        }
    }
    else // b != 0 //
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD) //b != 0 && c == 0
        {
            roots->x1 = 0;
            roots->x2 = - coefficients->b / coefficients->a;
            roots->number_roots = TWO_ROOTS;
        }
        else // b != 0 && c != 0
        {
            double discriminant = NAN, sqrt_discriminant = NAN;

            discriminant = coefficients->b * coefficients->b - 4 * coefficients->a * coefficients->c;

            if (compare_with_zero(discriminant) == LESS_THAN_EPSILON)
            {
                roots->number_roots = NO_ROOTS;
            }
            if (compare_with_zero(discriminant) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
            {
                roots->number_roots = ONE_ROOTS;
                roots->x1 = -coefficients->b / (2 * coefficients->a);
            }

            if (compare_with_zero(discriminant) == MORE_THAN_EPSILON)
            {
                roots->number_roots = TWO_ROOTS;
                sqrt_discriminant = sqrt(discriminant);
                roots->x1 = (-coefficients->b + sqrt_discriminant) / (2 * coefficients->a);
                roots->x2 = (-coefficients->b - sqrt_discriminant) / (2 * coefficients->a);
            }
        }
    }
}

void solve_linear(struct Equation_coefficients *coefficients, struct Equation_roots *roots)
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
            roots->number_roots = INFINITY_ROOTS;
        }
        else
        {
            roots->number_roots = NO_ROOTS;
        }
    }
    else
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            roots->x1 = 0;
            roots->number_roots = ONE_ROOTS;
        }
        else
        {
            roots->number_roots = ONE_ROOTS;
            roots->x1 = -coefficients->c / coefficients->b;
        }
    }
}
