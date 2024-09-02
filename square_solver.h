#ifndef SQUARE_SOLVER_H
#define SQUARE_SOLVER_H

struct Equation_coefficients
{
    double a;
    double b;
    double c;
};

enum Number_roots  // TODO: возможно лучше Roots_number 
{
    INFINITY_ROOTS                  = -1,
    NO_ROOTS                        =  0,
    ONE_ROOTS                       =  1,
    TWO_ROOTS                       =  2
};  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TODO: Дохуя места

struct Equation_roots
{
    double x1;
    double x2;
    enum Number_roots number_roots;
//  ~~~~ TODO: Можно не писать
};

enum Compare_constants
{
    LESS_THAN_EPSILON               = -1,
    INSIDE_THE_EPSILON_NEIGHBORHOOD =  0, // TODO: Возможно стоит убрать "THE"
    MORE_EPSILON                    =  1
};  //   ^THAN^ :ODOT //

enum Compare_double_constants
{
    THE_NUMBERS_ARE_EQUAL =  0, // TODO: Возможно стоит убрать "THE"
    X_IS_GREATER_THAN_Y   =  1,
    Y_IS_GREATER_THAN_X   = -1,
    HAVE_ONE_NAN_ROOT         =  2,
    //                    ~~~~ TODO: дохуя места
    ERROR_COMPARE         =  5,
    ERROR_MAX             =  6,
    ERROR_MIN             =  7
};

enum Communication // TODO: кажется надо убрать
{
    YES = 1,
    NO  = 0
};

struct Test_data
{
    struct Equation_coefficients coefficients;
    struct Equation_roots        roots_etalon;
    int                          number_test; // TODO: test_number may be
};
#endif /*SQUARE_SOLVER_H*/
