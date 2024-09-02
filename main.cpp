#include <stdio.h>
#include "square_solver.h"
#include "utilities.h"
#include "input_data.h"
#include "solve_equation.h"
#include "output_data.h"
#include "unit_test.h"

// TODO: убрать лишние инклюды

int main()
{
    ui_unit_test();  // TODO: Убрать в отдельный файл со всеми printf'ами (взаимодействия с пользователями)
                     //       Например: ui_ask_for_tests()

     Equation_coefficients coefficients = {NAN, NAN, NAN};
     Equation_roots        roots        = {NAN, NAN, NO_ROOTS}; // TODO: у тебя есть функция для этого
    do
    {
        input_data(&coefficients);  // TODO: Убрать в файл, где находятся остальные
                                    //       функции взаимодействия с пользователем

        solve_equation(&coefficients, &roots);

        output_data(&roots);

        printf("Would you like to do it again?");  // TODO: убрать в функцию make_choice() и перемеиновать ее
    }
    while(make_choice());
    //    TODO: Переименовать
    return 0;
}
