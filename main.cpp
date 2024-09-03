#include <stdio.h>
#include "square_solver.h"
#include "utilities.h"
#include "solve_equation.h"
#include "user_interaction.h"
#include "unit_test.h"
#include "comparing_numbers.h"

int main()
{
    ui_ask_for_tests();

     Equation_coefficients coefficients = {NAN, NAN,      NAN};
     Equation_roots        roots        = {NAN, NAN, NO_ROOTS};
    do
    {
        input_data(&coefficients);

        solve_equation(&coefficients, &roots);

        output_data(&roots);
    }
    while(get_user_feedback());

    return 0;
}
