#include <stdio.h>
#include <assert.h>
#include "square_solver.h"
#include "user_interaction.h"
#include "unit_test.h"

void get_input(Equation_coefficients *coefficients)
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
    int symbol = 0;

	do
	{
        symbol = getchar();
	} while (symbol != '\n' && symbol != EOF);
}

void display_output(const Equation_roots *roots)
{
    assert(roots);

    switch (roots->roots_number)
    {
        case NO_ROOTS :
        {
            printf("Nule roots\n"
                   "Would you like to do it again?"); // TODO: убрать хуйню (копипасту)
            break;
        }
        case ONE_ROOT :
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
    printf("enter y or n\n");

    int symbol = 0;

    while (symbol != 'y' && symbol != 'n')
	{
        symbol = getchar();
	}

    skip_buffer();
    return (symbol == 'y');
}
