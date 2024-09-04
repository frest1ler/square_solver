#include "square_solver.h"
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

        display_output(&roots); //TODO rename
    }
    while(get_user_feedback()); //TODO rename feedback - отзыв о работе

    return 0;
}
