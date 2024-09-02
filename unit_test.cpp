#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "unit_test.h"
#include "utilities.h"
#include "solve_equation.h"

void ui_unit_test() // TODO: переименовать, убрать в отдельный файл
{
    printf("Do you want to run tests? "); 
        if (make_choice() == YES)
        {
            unit_test();
        }
//  ~~~~  TODO: Поправить табуляцию
    // TODO: если тесты не прошли, программа продолжает работать???
}

void unit_test()
{
    struct Test_data data_for_test[] =
//  ~~~~~~ TODO: Убрать
//  TODO: Добавить const                                                      
    {
        {{1, -5, 6}, {2,    3,   TWO_ROOTS},      0},
        {{1, -5, 6}, {2,    3,   TWO_ROOTS},      1},
        {{1,  2, 1}, {-1,  NAN,  ONE_ROOTS},      2},
        {{1,  5, 6}, {-2,   -3,  TWO_ROOTS},      3},
        {{0,  0, 0}, {NAN, NAN,  INFINITY_ROOTS}, 4}
    };

    struct Equation_roots roots = {NAN, NAN, NO_ROOTS};
//  ~~~~~~ TODO: Убрать    

    assert(&roots); // TODO: Не нужный ассерт

    const int max_number_test = sizeof(data_for_test) / sizeof(data_for_test[0]);
    // TODO:  max_test_number may be
    
    for(int i = 0; i < max_number_test; i++)
    {
        test(data_for_test + i, &roots);//data_for_test[i] == *(data+i)
    } // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^ TODO: Где пробел
}

void test(struct Test_data *data_for_test, struct Equation_roots *roots)
{   //    ~~~~~                            ~~~~~~
    // TODO: Где ассерты
    init_equation_roots(roots);

    solve_equation(&data_for_test->coefficients, roots);

    double min_roots = min(roots->x1, roots->x2); // TODO: min_root
    double max_roots = max(roots->x1, roots->x2); // TODO: max_root
    double min_roots_etalon = min(data_for_test->roots_etalon.x1, data_for_test->roots_etalon.x2);
    double max_roots_etalon = max(data_for_test->roots_etalon.x1, data_for_test->roots_etalon.x2);
    //               ~~~~~~ не эталон (reference например)
    if (!compare_double(min_roots, min_roots_etalon) && !compare_double(max_roots, max_roots_etalon) &&
        roots->number_roots == data_for_test->roots_etalon.number_roots)
    // TODO: либо пользуйся своим enum'ом либо нахуй убери
    {
        printf("%d TEST OK\n", data_for_test->number_test);
    }
    else
    {
        printf("\n%d TEST ERROR , got the results:\n\nx1=%lg ; expected x1=%lg\n"
    //  ~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~^ Убрать пробелы 
               "x2=%lg ; expected x2=%lg\n"
    //  ~~~~~~~~~~~~~~^ Убрать пробелы 
               "number_roots=%d ; expected number_roots=%d\n\n",
    //  ~~~~~~~~~~~~~~~~~~~~~~~^ Убрать пробелы 
               data_for_test->number_test, roots->x1, data_for_test->roots_etalon.x1,
               roots->x2, data_for_test->roots_etalon.x2,
               roots->number_roots, data_for_test->roots_etalon.number_roots);
    }
}
