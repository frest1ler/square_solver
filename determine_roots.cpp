#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "determine_roots.h"
#include "square_solver.h"
#include "utilities.h"

void determine_roots(struct equation_coefficients *coefficients, struct equation_roots *roots)
{
   if (compare_with_zero(coefficients->a) != INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        square_solver(coefficients, roots);
    }
    else
    {
        linear_solver(coefficients, roots);
    }
}

void square_solver(struct equation_coefficients *coefficients, struct equation_roots *roots)
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
            roots->x1 = roots->x2 = 0;
            roots->number_roots = ONE_ROOTS;
        }
    }
    else // compare_with_zero(b) != 0
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
                roots->x1 = roots->x2 = 0;
            }
            if (compare_with_zero(discriminant) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
            {
                roots->number_roots = ONE_ROOTS;
                roots->x1 = roots->x2 = -coefficients->b / (2 * coefficients->a);
            }

            if (compare_with_zero(discriminant) == MORE_EPSILON)
            {
                roots->number_roots = TWO_ROOTS;
                sqrt_discriminant = sqrt(discriminant);
                roots->x1 = (-coefficients->b + sqrt_discriminant) / (2 * coefficients->a);
                roots->x2 = (-coefficients->b - sqrt_discriminant) / (2 * coefficients->a);
            }
        }
    }
}

void linear_solver(struct equation_coefficients *coefficients, struct equation_roots *roots)
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
            roots->x1 = roots->x2 = 0;      //TODO NAN
        }
        else
        {
            roots->number_roots = NO_ROOTS; //TODO
        }
    }
    else
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            roots->x1 = roots->x2 = 0;
            roots->number_roots = ONE_ROOTS;
        }
        else
        {
            roots->number_roots = ONE_ROOTS;
            roots->x1 = roots->x2 = -coefficients->c / coefficients->b; //TODO ОДИН КОРЕНЬ
        }
    }
}
