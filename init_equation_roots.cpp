#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "utilities.h"
#include "square_solver.h"

void init_equation_roots(Equation_roots *roots)
{
    assert(roots);

    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = NO_ROOTS;

}

