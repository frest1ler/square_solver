#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

void solve_equation(struct Equation_coefficients *coefficients, struct Equation_roots *roots);
void solve_square(struct Equation_coefficients *coefficients, struct Equation_roots *roots);
void solve_linear(struct Equation_coefficients *coefficients, struct Equation_roots *roots);

#endif /*SOLVE_EQUATION_H*/
