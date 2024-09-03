#include <stdio.h>
#include <assert.h>
#include "unit_test.h"
#include "solve_equation.h"
#include "comparing_numbers.h"

int unit_test()
{
    Test_data data_for_test[] =
    {
        {{1, -5, 6}, { 2 ,   3, TWO_ROOTS     }, 0},
        {{1, -5, 6}, { 2 ,   3, TWO_ROOTS     }, 1},
        {{1,  2, 1}, {-1 , NAN, ONE_ROOT      }, 2},
        {{1,  5, 6}, {-2 ,  -3, TWO_ROOTS     }, 3},
        {{0,  0, 0}, {NAN, NAN, INFINITY_ROOTS}, 4}
    };

    Equation_roots roots = {NAN, NAN, NO_ROOTS}; // TODO: в этой функции не используется roots,
                                                 //       перенеси в test()

    const int max_test_number = sizeof(data_for_test) / sizeof(data_for_test[0]);

    for(int i = 0; i < max_test_number; i++)
    {
        if (test(data_for_test + i, &roots)) // data_for_test[i] == *(data+i)
        {
            return 1;
        }
        // TODO: Если один тест не прошел, следующие тесты не выполняются, что, наверное, неправильно
    }
    return 0;
}

// TODO: переименуй
int test(Test_data *data_for_test, Equation_roots *roots)
// TODO: ^ Добавить const
// TODO: Переименуй data_for_test
{
    assert(&data_for_test);
    assert(&roots);

    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->roots_number = NO_ROOTS;
    // TODO: это можно записать так:
    // *roots = (Equation_roots) {NAN, NAN, NO_ROOTS};

    solve_equation(&data_for_test->coefficients, roots);

    const double min_root = min(roots->x1, roots->x2);
    const double max_root = max(roots->x1, roots->x2);
    const double min_root_reference = min(data_for_test->roots_expected.x1, data_for_test->roots_expected.x2);
    const double max_root_reference = max(data_for_test->roots_expected.x1, data_for_test->roots_expected.x2);

    if (compare_double(min_root, min_root_reference) == INSIDE_THE_EPSILON_NEIGHBORHOOD &&
        compare_double(max_root, max_root_reference) == INSIDE_THE_EPSILON_NEIGHBORHOOD &&
        roots->roots_number == data_for_test->roots_expected.roots_number)
    {
        printf("%d TEST OK\n", data_for_test->test_number);
        return 0;
    }
    printf("\n%d TEST ERROR, got the results:\n\nx1=%lg; expected x1 = %lg\n"
           "x2 = %lg; expected x2 = %lg\n"
           "number_roots = %d; expected number_roots = %d\n\n",
           data_for_test->test_number, roots->x1, data_for_test->roots_expected.x1,
           roots->x2, data_for_test->roots_expected.x2,
           roots->roots_number, data_for_test->roots_expected.roots_number);
           return 1; // TODO: для кого пустая строка (для TODO ментора)
}
