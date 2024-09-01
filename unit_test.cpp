#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "unit_test.h"
#include "utilities.h"
#include "determine_roots.h"

void unit_test()
{
    struct test_data data_for_test[] =
    {
        {{1, -5, 6}, {2,    3,   2}, 0},
        {{1,  2, 1}, {-1,  NAN,  1}, 1},
        {{1,  5, 6}, {-2,   -3,  2}, 2},
        {{0,  0, 0}, {NAN, NAN, -1}, 3}
    };

    //assert(data_for_test);  //TODO на стеке при выделении массивов можно не проверять, в динамической памяти стоит

    struct equation_roots roots = {NAN, NAN, 0};

    assert(&roots);

    const int max_number_test = sizeof(data_for_test) / sizeof(data_for_test[0]);

    for(int i = 0; i < max_number_test; i++)
    {
        printf("roots et%lg %lg %d\n", data_for_test[i].roots_etalon.x1,
               data_for_test[i].roots_etalon.x2, data_for_test[i].roots_etalon.number_roots);
        printf("coeff   %lg %lg %lg\n", data_for_test[i].coefficients.a,
               data_for_test[i].coefficients.b, data_for_test[i].coefficients.c);
               
        test(data_for_test + i, &roots, i);//data_for_test[i] == *(data+i)
    }
}

void test(struct test_data *data_for_test, struct equation_roots *roots, int i) //TODO номер теста в структуре
{

    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = 0;

    printf("coeff   %lg %lg %lg\n", data_for_test[i].coefficients.a,
           data_for_test[i].coefficients.b, data_for_test[i].coefficients.c);

    determine_roots(&data_for_test[i].coefficients, roots);

    printf("coeff   %lg %lg %lg\n", data_for_test[i].coefficients.a,
           data_for_test[i].coefficients.b, data_for_test[i].coefficients.c);
    printf("roots   %lg %lg %d\n", roots->x1, roots->x2, roots->number_roots);

    double min_roots = min(roots->x1, roots->x2);
    double max_roots = max(roots->x1, roots->x2);
    double min_roots_etalon = min(data_for_test[i].roots_etalon.x1, data_for_test[i].roots_etalon.x2);
    double max_roots_etalon = max(data_for_test[i].roots_etalon.x1, data_for_test[i].roots_etalon.x2);

    if (!compare_double(min_roots, min_roots_etalon) && !compare_double(max_roots, max_roots_etalon) &&
        roots->number_roots == data_for_test[i].roots_etalon.number_roots)
    {
        printf("%d TEST OK\n", data_for_test[i].number_test);
    }
    else
    {
        printf("\n%d TEST ERROR , got the results:\n\nx1=%lg ; expected x1=%lg\n"
               "x2=%lg ; expected x2=%lg\n"
               "number_roots=%d ; expected number_roots=%d\n\n",
               data_for_test[i].number_test, roots->x1, data_for_test[i].roots_etalon.x1,
               roots->x2, data_for_test[i].roots_etalon.x2,
               roots->number_roots, data_for_test[i].roots_etalon.number_roots);
    }
}
