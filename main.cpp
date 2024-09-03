#include <stdio.h>
#include "square_solver.h"
#include "utilities.h"
#include "solve_equation.h"
#include "user_interaction.h"
#include "unit_test.h"
#include "comparing_numbers.h"
// TODO: убрать лишние инклюды
// TODO: файла utilities.h вообще нет в проекте

int main()
{
    ui_ask_for_tests();

//~~~ TODO: поехал отступ
     Equation_coefficients coefficients = {NAN, NAN,      NAN};
     Equation_roots        roots        = {NAN, NAN, NO_ROOTS};
     // TODO: Или можешь написать, как больше нравится
     // Equation_coefficients coefficients = {NAN, NAN, NAN     };
     // Equation_roots        roots        = {NAN, NAN, NO_ROOTS};
    do
    {
        input_data(&coefficients); // TODO: лучше переименовать в get_input_data()

        solve_equation(&coefficients, &roots);

        output_data(&roots); // TODO: лучше переименовать     
    }
    while(get_user_feedback());

    return 0;
}
