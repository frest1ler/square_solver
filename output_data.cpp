#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "output_data.h"
#include "square_solver.h"

void output_data(struct Equation_roots *roots)
{
    assert(roots);

    switch (roots->number_roots)
    {
        case NO_ROOTS :
        {
            printf("Nule roots\n");
            break;
        }
        case ONE_ROOTS :
        {
            printf("One roots x=%lg\n", roots->x1);
            break;
        }
        case TWO_ROOTS :
        {
            printf("Two roots x1=%lg , x2=%lg\n", roots->x1, roots->x2);
            break;
        }
        case INFINITY_ROOTS :
        {
            printf("infinitely many roots\n");
            break;
        }
        default :
        {
            printf("ERROR\n");
            break;
        }
    }
}
