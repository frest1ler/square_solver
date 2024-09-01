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
    assert(data_for_test);  //TODO на стеке при выделении массивов можно не проверять, в динамической памяти стоит

    struct equation_roots roots = {NAN, NAN, 0};

    assert(&roots);

    const int max_number_test = sizeof(data_for_test) / sizeof(data_for_test[0]);

    for(int i = 0; i < max_number_test; i++)
    {
        test(data_for_test + i, &roots, i);//data_for_test[i] == *(data+i)
    }
}

void test(struct test_data *data_for_test, struct equation_roots *roots, int i) //TODO номер теста в структуре
{
    int comparing_roots = 0;

    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = 0;

    determine_roots(&data_for_test[i].coefficients, roots);

    int number_of_nan_roots_etalon = is_nan(data_for_test[i].roots_etalon.x1) + is_nan(data_for_test[i].roots_etalon.x2);
    int number_of_nan_roots = is_nan(roots->x1) + is_nan(roots->x2);
    printf("%lg\n", data_for_test[1].roots_etalon.x2);
    printf("%d %d\n", number_of_nan_roots, number_of_nan_roots_etalon);
    printf("\\\\\\\\\\\\\\\\\\\\\\\n"
           "%lg %lg %lg\n", data_for_test[i].coefficients.a, data_for_test[i].coefficients.b, data_for_test[i].coefficients.c);
    assert(&number_of_nan_roots_etalon);
    assert(&number_of_nan_roots);

    switch (number_of_nan_roots)
    {
        case 0 :
        {
            if (number_of_nan_roots_etalon == 0)
            {
                double min_roots = MIN(roots->x1, roots->x2);
                double max_roots = MAX(roots->x1, roots->x2);
                double min_roots_etalon = MIN(data_for_test[i].roots_etalon.x1, data_for_test[i].roots_etalon.x2);
                double max_roots_etalon = MAX(data_for_test[i].roots_etalon.x1, data_for_test[i].roots_etalon.x2);

                if (compare_with_zero(min_roots - min_roots_etalon) == 0 &&
                    compare_with_zero(max_roots - max_roots_etalon) == 0 &&
                    roots->number_roots == data_for_test[i].roots_etalon.number_roots)
                {
                    comparing_roots = 1;
                }
            }
            else
            {
                printf("ERROR CASE 0\n");
            }
            break;
        }
        case 1 : //x1 != NAN
        {
            if (number_of_nan_roots_etalon == 1)
            {
                if (is_nan(data_for_test[i].roots_etalon.x1)) // if x1_etalon = NAN
                {
                    if ((!compare_with_zero(roots->x2 - data_for_test[i].roots_etalon.x2)) &&
                        roots->number_roots == data_for_test[i].roots_etalon.number_roots) //if x1 = x2_etalon & nRoots = nRoots_etalon
                    {
                        comparing_roots = 1;
                    }
                }
                else // if x2_etanol = NAN
                {
                   if (!compare_with_zero(roots->x2 - data_for_test[i].roots_etalon.x1) &&
                       roots->number_roots == data_for_test[i].roots_etalon.number_roots) //if x1 = x1_etalon & nRoots = nRoots_etalon
                    {
                        comparing_roots = 1;
                    }
                }
            }
            else
            {
                printf("ERROR CASE 1\n");
            }
            break;
        }
        case 2 :
        {
            if (number_of_nan_roots_etalon == 2)
            {
                if (roots->number_roots == data_for_test[i].roots_etalon.number_roots)
                {
                    comparing_roots = 1;
                }
            }
            else
            {
                printf("ERROR CASE 2\n");
            }
            break;
        }
        default :
        {
            printf("ERROR DEFAULT\n");
            break;
        }
    }
    if (comparing_roots)
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
