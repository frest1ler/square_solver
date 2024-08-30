#ifndef SQUARE_SOLVER_H_    //TODO remove _
#define SQUARE_SOLVER_H_
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
    int    number_roots;    //TODO enum type
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
#endif /*SQUARE_SOLVER_H_*/
