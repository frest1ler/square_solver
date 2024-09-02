#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "square_solver.h"
#include "utilities.h"
#include "input_data.h"
#include "solve_equation.h"
#include "output_data.h"
#include "unit_test.h"

int main()
{
    ui_unit_test();

    struct Equation_coefficients coefficients = {NAN, NAN, NAN};
    struct Equation_roots        roots        = {NAN, NAN, NO_ROOTS};

    do
    {
        input_data(&coefficients);

        solve_equation(&coefficients, &roots);

        output_data(&roots);

        printf("Would you like to do it again?");
    }
    while(make_choice() == YES);

    return 0;
}
