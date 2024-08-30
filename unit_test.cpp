#include <stdio.h>
#include <math.h>
#include "unit_test.h"
#include "utilities.h"
#include "determine_roots.h"

void unit_test()
{
    struct test_data data_for_test[] =
    {
        {{1, -5, 6}, {2, 3, 2}, 0},//TODO ДОБАВИТЬ ХУЙНЮ(СОРТИРОВКУ)
        {{0,  0, 0}, {0, 0, -1}, 1}
    };

    struct equation_roots roots = {NAN, NAN, 0};

    const int max_number_test = sizeof(data_for_test) / sizeof(data_for_test[0]);

    for(int i = 0; i < max_number_test; i++)
    {
        test(data_for_test + i, &roots, i);//data_for_test[i] == *(data+i)
    }
}

void test(struct test_data *data_for_test, struct equation_roots *roots, int i) //TODO номер теста в структуре
{
    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = 0;

    determine_roots(&data_for_test[i].coefficients, roots);

    if (compare_with_zero(roots->x1 - data_for_test[i].roots.x1) != 0 &&
        compare_with_zero(roots->x2 - data_for_test[i].roots.x2) != 0 &&
        roots->number_roots != data_for_test[i].roots.number_roots)
    {
        printf("\n%d TEST ERROR , got the results:\n\nx1=%lg ; expected x1=%lg\n"
               "x2=%lg ; expected x2=%lg\n"
               "number_roots=%d ; expected number_roots=%d\n\n",
               data_for_test[i].number_test, roots->x1, data_for_test[i].roots.x1,
               roots->x2, data_for_test[i].roots.x2,
               roots->number_roots, data_for_test[i].roots.number_roots);
    }
    else
    {
        printf("TEST OK\n");
    }
}
