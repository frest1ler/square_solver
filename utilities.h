#ifndef UTILITIES_H
#define UTILITIES_H
#include <math.h>

const double EPSILON = 1e-9;

double max(double x, double y);
double min(double x, double y);

void skip_buffer();
void init_equation_roots(struct Equation_roots *roots);

int  make_choice();
int  is_nan(double x);
int  compare_with_zero(double x);
int  compare_double(double x, double y);

#endif /*UTILITIES_H*/
