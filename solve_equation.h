#ifndef SOLVE_EQUATION_H
#define SOLVE_EQUATION_H

void solve_equation(struct Equation_coefficients *coefficients, struct Equation_roots *roots);
void square_solver(struct Equation_coefficients *coefficients, struct Equation_roots *roots);
void linear_solver(struct Equation_coefficients *coefficients, struct Equation_roots *roots);
#endif /*SOLVE_EQUATION_H*/
