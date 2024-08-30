#include <math.h>
#include <stdio.h>
#include <assert.h>
#include "input_data.h"

void input_data(struct equation_coefficients *coefficients)
{
    printf("Hi,hi, this program solves an equation of the form ax^2+bx + c = 0\n"
           "enter a, b, c\n");

    assert(coefficients);   //TODO ASSERT

    while((scanf("%lg %lg %lg", &(coefficients->a), &(coefficients->b), &(coefficients->c))) != 3)
    {
        clear_buffer();
        printf("Input error. Try again\a\n");
    }
    clear_buffer();
}

void clear_buffer()
{
	int clean = 0;

	do
	{
        clean = getchar();
	} while (clean != '\n' && clean != EOF);
}
