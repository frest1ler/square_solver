#ifndef UNIT_TEST_H_
#define UNIT_TEST_H_

#include "square_solver.h"

struct test_data
{
    struct equation_coefficients coefficients;
    struct equation_roots        roots;             //TODO эталонная величина
    int                          number_test;
};

void test(struct test_data *data_for_test, struct equation_roots *roots, int i);
void unit_test();
#endif /*UNIT_TEST_H_*/
