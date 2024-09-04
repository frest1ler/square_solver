#include <stdio.h>
#include <assert.h>
#include "unit_test.h"
#include "square_solver.h"
#include "comparing_numbers.h"

static int inspect_equation(const Test_data *data_for_test, Equation_roots *roots);

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

    Equation_roots roots = {NAN, NAN, NO_ROOTS};

    const int max_test_number = sizeof(data_for_test) / sizeof(data_for_test[0]);

    int counting_errors = 0;
    for(int i = 0; i < max_test_number; i++)
    {
        counting_errors += inspect_equation(data_for_test + i, &roots);
    }
    return counting_errors;
}

static int inspect_equation(const Test_data *check_the_roots, Equation_roots *roots)
{
    assert(&check_the_roots);
    assert(&roots);

    *roots = (Equation_roots) {NAN, NAN, NO_ROOTS};

    solve_equation(&check_the_roots->coefficients, roots);

    const double min_root = min(roots->x1, roots->x2);
    const double max_root = max(roots->x1, roots->x2);
    const double min_root_reference = min(check_the_roots->roots_expected.x1, check_the_roots->roots_expected.x2);
    const double max_root_reference = max(check_the_roots->roots_expected.x1, check_the_roots->roots_expected.x2);

    if (compare_double_complex(min_root, min_root_reference) == NUMBERS_ARE_EQUAL &&
        compare_double_complex(max_root, max_root_reference) == NUMBERS_ARE_EQUAL &&
        roots->roots_number == check_the_roots->roots_expected.roots_number)
    {
        printf("%d TEST OK\n", check_the_roots->test_number);
        return 0;
    }
    printf("\n%d TEST ERROR, got the results:\n\nx1=%lg; expected x1 = %lg\n"
           "x2 = %lg; expected x2 = %lg\n"
           "number_roots = %d; expected number_roots = %d\n\n",
           check_the_roots->test_number, roots->x1, check_the_roots->roots_expected.x1,
           roots->x2, check_the_roots->roots_expected.x2,
           roots->roots_number, check_the_roots->roots_expected.roots_number);
           return 1;
}
