#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "square_solver.h"
#include "input_data.h"
#include "utilities.h"
// TODO: Убрать лишние инклюды

//              ~~~~~~ TODO: Можно убрать (лучше убрать)
void input_data(struct Equation_coefficients *coefficients)
{
    assert(coefficients);
    //      hi-hi-hi-hi TODO: (убрать)           
    printf("Hi,hi, this program solves an equation of the form ax^2+bx + c = 0\n"
    // ~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~^ TODO: проебались пробелы
           "enter a, b, c\n");
    while((scanf("%lg %lg %lg", &(coefficients->a), &(coefficients->b), &(coefficients->c))) != 3)
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~^~~~^~~~~~~~~~~~~~~~^~~~^~~~~~~~~~~~~~~~^
    // TODO: Убрать скобки
    {
        clear_buffer();
        printf("Input error. Try again\a\n");
    }
    clear_buffer();
}
