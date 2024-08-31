#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "unit_test.h"
#include "utilities.h"
#include "determine_roots.h"

void unit_test()
{
    int yes_no_response = 0;    //TODO rename режим рабоы программы

    assert(&yes_no_response);

    printf("Do you want to run tests? enter y or n\n");

    while (yes_no_response != 'y' && yes_no_response != 'n')    //TODO перенести в main и переименовать
	{
        yes_no_response = getchar();
	}

    clear_buffer();

    struct test_data data_for_test[] =
    {
        {{1, -5, 6}, {2, 3, 2}, 0},
        {{0,  0, 0}, {0, 0, -1}, 1}
    };

    assert(data_for_test);  //TODO на стеке при выделении массивов можно не проверять, в динамической памяти стоит

    struct equation_roots roots = {NAN, NAN, 0};

    assert(&roots);

    const int max_number_test = sizeof(data_for_test) / sizeof(data_for_test[0]);

    if (yes_no_response == 'y')
    {
        for(int i = 0; i < max_number_test; i++)
        {
            test(data_for_test + i, &roots, i);//data_for_test[i] == *(data+i)
        }
    }
    else
    {
        printf("let's move on to solving the quadratic equation\n");
    }
}

void test(struct test_data *data_for_test, struct equation_roots *roots, int i) //TODO номер теста в структуре
{
    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = 0;

    determine_roots(&data_for_test[i].coefficients, roots);

    double min_roots = MIN(roots->x1, roots->x2);
    double max_roots = MAX(roots->x1, roots->x2);
    double min_roots_etanol = MIN(data_for_test[i].roots_etanol.x1, data_for_test[i].roots_etanol.x2);
    double max_roots_etanol = MAX(data_for_test[i].roots_etanol.x1, data_for_test[i].roots_etanol.x2); //TODO rename

    if (compare_with_zero(min_roots - min_roots_etanol) != 0 &&
        compare_with_zero(max_roots - max_roots_etanol) != 0 &&
        roots->number_roots != data_for_test[i].roots_etanol.number_roots)
    {
        printf("\n%d TEST ERROR , got the results:\n\nx1=%lg ; expected x1=%lg\n"
               "x2=%lg ; expected x2=%lg\n"
               "number_roots=%d ; expected number_roots=%d\n\n",
               data_for_test[i].number_test, roots->x1, data_for_test[i].roots_etanol.x1,
               roots->x2, data_for_test[i].roots_etanol.x2,
               roots->number_roots, data_for_test[i].roots_etanol.number_roots);
    }
    else
    {
        printf("TEST OK\n");
    }
}
