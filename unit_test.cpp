#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "unit_test.h"
#include "utilities.h"
#include "solve_equation.h"
#include "comparing_numbers.h"
// TODO: файла utilities.h вообще нет в проекте

int unit_test()
{
    Test_data data_for_test[] =
    {
        {{1, -5, 6}, {2,    3,   TWO_ROOTS},      0},
        {{1, -5, 6}, {2,    3,   TWO_ROOTS},      1},
        {{1,  2, 1}, {-1,  NAN,  ONE_ROOTS},      2},
        {{1,  5, 6}, {-2,   -3,  TWO_ROOTS},      3},
        {{0,  0, 0}, {NAN, NAN,  INFINITY_ROOTS}, 4}
        // TODO: ~~~~~~~~~~~~~~~^ лишний пробел
        // TODO: возможно выравнить так:
        // {{1, -5, 6}, {2,    3,  TWO_ROOTS     }, 0},
        // {{1, -5, 6}, {2,    3,  TWO_ROOTS     }, 1},
        // {{1,  2, 1}, {-1,  NAN, ONE_ROOTS     }, 2},
        // {{1,  5, 6}, {-2,   -3, TWO_ROOTS     }, 3},
        // {{0,  0, 0}, {NAN, NAN, INFINITY_ROOTS}, 4}
    };

    Equation_roots roots = {NAN, NAN, NO_ROOTS}; // TODO: в этой функции не используется roots, 
                                                 //       перенеси в test()

    const int max_test_number = sizeof(data_for_test) / sizeof(data_for_test[0]);

    for(int i = 0; i < max_test_number; i++)
    {
        // TODO:                             ~~~~~~~~~~ Почему столько пробелов
        if (test(data_for_test + i, &roots))           //data_for_test[i] == *(data+i)
        // TODO: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^ где пробел
        {
            return 1;
        }
        // TODO: Если один тест не прошел, следующие тесты не выполняются, что, наверное, неправильно
    }
    return 0;
    // TODO: Dima ka ti testiruesh svoi cod?
    // TODO: Dima jak ti testiruesh tviy cod?
    // TODO: Dima how did you test your code?
    // TODO: Dima Wie haben Sie Ihren Code getestet?
    // TODO: Dima, sez yz kodygyzny nicek synadygyz?
}

// TODO: переименуй
int test(Test_data *data_for_test, Equation_roots *roots)
// TODO: ^ Добавить const
// TODO: Переименуй data_for_test
{
    assert(&data_for_test);
    assert(&roots);

    // TODO: нет инклюда для этой функции
    init_equation_roots(roots);
    // TODO: это можно записать так:
    // *roots = (Equation_roots) {NAN, NAN, NO_ROOTS};

    solve_equation(&data_for_test->coefficients, roots);

// ^ TODO: добавить const
    double min_root = min(roots->x1, roots->x2);
// ^ TODO: добавить const
    double max_root = max(roots->x1, roots->x2);
// ^ TODO: добавить const
    double min_root_reference = min(data_for_test->roots_etalon.x1, data_for_test->roots_etalon.x2);
// ^ TODO: добавить const
    double max_root_reference = max(data_for_test->roots_etalon.x1, data_for_test->roots_etalon.x2);
// ^ TODO: добавить const

    // TODO: у тебя для этого есть enum
    if (!compare_double(min_root, min_root_reference) && !compare_double(max_root, max_root_reference) &&
        roots->number_roots == data_for_test->roots_etalon.number_roots)
    {
        printf("%d TEST OK\n", data_for_test->number_test);

        return 0;
    }
    printf("\n%d TEST ERROR, got the results:\n\nx1=%lg; expected x1 = %lg\n"
           "x2 = %lg; expected x2 = %lg\n"
           "number_roots = %d; expected number_roots = %d\n\n",
           data_for_test->number_test, roots->x1, data_for_test->roots_etalon.x1,
           roots->x2, data_for_test->roots_etalon.x2,
           roots->number_roots, data_for_test->roots_etalon.number_roots);
    // TODO: поплыл отступ у return'a
           return 1;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                               // TODO: для кого пустая строка
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
}
