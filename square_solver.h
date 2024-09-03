#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

struct Equation_coefficients
{
    double a;
    double b;
    double c;
};

enum Roots_number
{
    INFINITY_ROOTS = -1,
    NO_ROOTS       =  0,
    ONE_ROOT      =  1,
    TWO_ROOTS      =  2,
};

struct Equation_roots
{
    double x1;
    double x2;
    Roots_number roots_number;
};

enum Compare_constants
{
    LESS_THAN_EPSILON               = -1,
    INSIDE_THE_EPSILON_NEIGHBORHOOD =  0,
    MORE_THAN_EPSILON               =  1,
};

enum Compare_double_constants
{
    NUMBERS_ARE_EQUAL   =  0,
    X_IS_GREATER_THAN_Y =  1,
    Y_IS_GREATER_THAN_X = -1,
    HAVE_ONE_NAN_ROOT   =  2,
};

struct Test_data
{
    Equation_coefficients coefficients;
    Equation_roots        roots_expected;
    int                   test_number;
};
#endif /*SQUARE_SOLVER_H*/
