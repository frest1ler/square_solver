#ifndef COMPARING_NUMBERS_H
#define COMPARING_NUMBERS_H

#include <math.h>

const double EPSILON = 1e-9;

double max(const double x, const double y);
double min(const double x, const double y);

int  count_nan(const double x);
int  compare_double(const double x, const double y);
int  compare_double_complex(const double x, const double y);

#endif /*COMPARING_NUMBERS_H*/
