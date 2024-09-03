#include "square_solver.h"
#include "solve_equation.h"
#include "user_interaction.h"
#include "comparing_numbers.h"

int main()
{
    ui_ask_for_tests();

    Equation_coefficients coefficients = {NAN, NAN, NAN     };
    Equation_roots        roots        = {NAN, NAN, NO_ROOTS};

    do
    {
        get_input(&coefficients);

        solve_equation(&coefficients, &roots);

        display_output(&roots);
    }
    while(get_user_feedback());

    return 0;
}
