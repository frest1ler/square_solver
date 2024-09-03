#include <stdio.h>
#include <assert.h>
#include "square_solver.h"
#include "user_interaction.h"
#include "utilities.h"
#include "unit_test.h"
// TODO: убрать лишние инклюды
// TODO: файла utilities.h вообще нет в проекте

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

void skip_buffer()
{
    // TODO: почему здесь символ tab'a, когда в остальных местах пробел
	int symbol = 0;

	do
	{
        symbol = getchar();
	} while (symbol != '\n' && symbol != EOF);
}

void output_data(Equation_roots *roots)
// TODO: ~~~~~~~^ добавить const
{
    assert(roots);

    switch (roots->number_roots)
    {
        case NO_ROOTS :
        {
            printf("Nule roots\n"
                   "Would you like to do it again?"); // TODO: убрать хуйню (копипасту)
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                               // TODO: для кого пустая строка
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
            break;
        }
        case ONE_ROOTS :
        {
            printf("One roots x = %lg\n"
                   "Would you like to do it again?", roots->x1); // TODO: убрать хуйню (копипасту)
            break;
        }
        case TWO_ROOTS :
        {
            printf("Two roots x1 = %lg, x2 = %lg\n"
                   "Would you like to do it again?", roots->x1, roots->x2); // TODO: убрать хуйню (копипасту)
            break;
        }
        case INFINITY_ROOTS :
        {
            printf("Infinitely many roots\n"
                   "Would you like to do it again?"); // TODO: убрать хуйню (копипасту)
            break;
        }
        default :
        {
            printf("ERROR\n");
            break;
        }
    }
}

int ui_ask_for_tests()
{
    printf("Do you want to run tests? ");

    if (get_user_feedback())
    {
        if (unit_test())
        {
            return 1;
        }
        return 0;
        // TODO: return unit_test()
    }
    return 0;
}

int get_user_feedback()
{
    // TODO: перенеси поближе к while
    int symbol = 0;

    printf("enter y or n\n");

    // TODO: почему здесь символ tab'a, когда в остальных местах пробел
    while (symbol != 'y' && symbol != 'n')
	{
        symbol = getchar();
	}

    skip_buffer();
    if (symbol == 'y')
    {
        return 1;
    }
    return 0;
    // TODO: return symbol == 'y'
}
