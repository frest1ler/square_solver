#ifndef COMPARE_WITH_ZERO_H_
#define COMPARE_WITH_ZERO_H_
#include <math.h>

const double EPSILON = 1e-9;

int max(double x, double y);
int min(double x, double y);
int compare_with_zero(double x);
void clear_buffer();
int communication_with_user();
int is_nan(double x);
int compare_double(double x, double y);
#endif /*COMPARE_WITH_ZERO_H_*/
