#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H
struct equation_coefficients
{
    double a;
    double b;
    double c;
};

struct equation_roots
{
    double x1;
    double x2;
    int    number_roots;    //TODO enum type (я могу к number_roots присвоить только значения из енам, иначе ошибка
};

enum number_roots
{
    INFINITY_ROOTS                  = -1,
    NO_ROOTS                        =  0,
    ONE_ROOTS                       =  1,
    TWO_ROOTS                       =  2
};

enum compare_constants
{
    LESS_THAN_EPSILON               = -1,
    INSIDE_THE_EPSILON_NEIGHBORHOOD =  0,
    MORE_EPSILON                    =  1
};

enum compare_double_constants
{
    THE_NUMBERS_ARE_EQUAL =  0,
    X_IS_GREATER_THAN_Y   =  1,
    Y_IS_GREATER_THAN_X   = -1,
    ERROR_COMPARE         =  5,
    ERROR_MAX             =  6,
    ERROR_MIN             =  7
};

struct test_data
{
    struct equation_coefficients coefficients;
    struct equation_roots        roots_etalon;
    int                          number_test;
};
#endif /*SQUARE_SOLVER_H*/
