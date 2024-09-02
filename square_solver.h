#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

struct Equation_coefficients
{
    double a;
    double b;
    double c;
};

enum Number_roots
{
    INFINITY_ROOTS                  = -1,
    NO_ROOTS                        =  0,
    ONE_ROOTS                       =  1,
    TWO_ROOTS                       =  2
};

struct Equation_roots
{
    double x1;
    double x2;
    enum Number_roots number_roots;
};

enum Compare_constants
{
    LESS_THAN_EPSILON               = -1,
    INSIDE_THE_EPSILON_NEIGHBORHOOD =  0,
    MORE_EPSILON                    =  1
};

enum Compare_double_constants
{
    THE_NUMBERS_ARE_EQUAL =  0,
    X_IS_GREATER_THAN_Y   =  1,
    Y_IS_GREATER_THAN_X   = -1,
    HAVE_ONE_NAN_ROOT         =  2,
    ERROR_COMPARE         =  5,
    ERROR_MAX             =  6,
    ERROR_MIN             =  7
};

enum Communication
{
    YES = 1,
    NO  = 0
};

struct Test_data
{
    struct Equation_coefficients coefficients;
    struct Equation_roots        roots_etalon;
    int                          number_test;
};
#endif /*SQUARE_SOLVER_H*/
