#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include "square_solver.h"
#include "utilities.h"
#include "input_data.h"
#include "determine_roots.h"
#include "output_data.h"
#include "unit_test.h"


int main()
{
    printf("Do you want to run tests? ");
    if (communication_with_user() == YES)
    {
        unit_test();
    }
    struct equation_coefficients coefficients = {NAN, NAN, NAN};
    struct equation_roots        roots        = {NAN, NAN, 0};

    do
    {
        input_data(&coefficients);

        determine_roots(&coefficients, &roots);

        output_data(&roots);

        printf("Would you like to do it again?");
    }
    while(communication_with_user() == YES);

    return 0;
}
