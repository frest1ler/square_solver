#include <stdio.h>
#include <assert.h>
#include "square_solver.h"
#include "input_data.h"
#include "utilities.h"

void input_data(Equation_coefficients *coefficients)
{
    assert(coefficients);

    printf("Hi, this program solves an equation of the form ax^2 + bx + c = 0\n"
           "enter a, b, c\n");
    while((scanf("%lg %lg %lg", &coefficients->a, &coefficients->b, &coefficients->c)) != 3)
    {
        skip_buffer();
        printf("Input error. Try again\a\n");
    }
    skip_buffer();
}
