#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "unit_test.h"
#include "utilities.h"
#include "solve_equation.h"

void ui_unit_test() // TODO: переименовать, убрать в отдельный файл
{
    printf("Do you want to run tests? ");
    if (make_choice())
    {
        unit_test();
    }
    // TODO: если тесты не прошли, программа продолжает работать???
}

void unit_test()
{
    Test_data data_for_test[] =
    {
        {{1, -5, 6}, {2,    3,   TWO_ROOTS},      0},
        {{1, -5, 6}, {2,    3,   TWO_ROOTS},      1},
        {{1,  2, 1}, {-1,  NAN,  ONE_ROOTS},      2},
        {{1,  5, 6}, {-2,   -3,  TWO_ROOTS},      3},
        {{0,  0, 0}, {NAN, NAN,  INFINITY_ROOTS}, 4}
    };

    Equation_roots roots = {NAN, NAN, NO_ROOTS};

    const int max_test_number = sizeof(data_for_test) / sizeof(data_for_test[0]);

    for(int i = 0; i < max_test_number; i++)
    {
        test(data_for_test + i, &roots); //data_for_test[i] == *(data+i)
    }
}

void test(Test_data *data_for_test, Equation_roots *roots)
{
    assert(&data_for_test);
    assert(&roots);

    init_equation_roots(roots);

    solve_equation(&data_for_test->coefficients, roots);

    double min_root = min(roots->x1, roots->x2);
    double max_root = max(roots->x1, roots->x2);
    double min_root_reference = min(data_for_test->roots_etalon.x1, data_for_test->roots_etalon.x2);
    double max_root_reference = max(data_for_test->roots_etalon.x1, data_for_test->roots_etalon.x2);

    if (!compare_double(min_root, min_root_reference) && !compare_double(max_root, max_root_reference) &&
        roots->number_roots == data_for_test->roots_etalon.number_roots)
    {
        printf("%d TEST OK\n", data_for_test->number_test);
    }
    else
    {
        printf("\n%d TEST ERROR, got the results:\n\nx1=%lg; expected x1 = %lg\n"
               "x2 = %lg; expected x2 = %lg\n"
               "number_roots = %d; expected number_roots = %d\n\n",
               data_for_test->number_test, roots->x1, data_for_test->roots_etalon.x1,
               roots->x2, data_for_test->roots_etalon.x2,
               roots->number_roots, data_for_test->roots_etalon.number_roots);
    }
}
