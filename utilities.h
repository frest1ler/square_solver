#ifndef COMPARE_WITH_ZERO_H_
#define COMPARE_WITH_ZERO_H_
#include <math.h>

#define MIN(i, j) (((i) < (j)) ? (i) : (j))
#define MAX(i, j) (((i) > (j)) ? (i) : (j))

const double EPSILON = 1e-9;

int compare_with_zero(double x);
void clear_buffer();
int communication_with_user();
int is_nan(double x);
#endif /*COMPARE_WITH_ZERO_H_*/
