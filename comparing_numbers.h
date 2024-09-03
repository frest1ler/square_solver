#ifndef COMPARING_NUMBERS_H
#define COMPARING_NUMBERS_H

#include <math.h>

const double EPSILON = 1e-9;

// TODO: смотри TODO для comparing_number.cpp
double max(double x, double y);
double min(double x, double y);

int  is_nan(double x);
int  compare_with_zero(double x);
int  compare_double(double x, double y);

#endif /*COMPARING_NUMBERS_H*/
