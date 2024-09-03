#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

#include "square_solver.h"

void solve_equation(const Equation_coefficients *coefficients, Equation_roots *roots);
void solve_square(const Equation_coefficients *coefficients, Equation_roots *roots);
void solve_linear(const Equation_coefficients *coefficients, Equation_roots *roots);
#endif /*SOLVE_EQUATION_H*/
