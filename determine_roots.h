#ifndef DETERMINE_ROOTS_H
#define DETERMINE_ROOTS_H

void determine_roots(struct equation_coefficients *coefficients, struct equation_roots *roots);
void square_solver(struct equation_coefficients *coefficients, struct equation_roots *roots);
void linear_solver(struct equation_coefficients *coefficients, struct equation_roots *roots);
#endif /*DETERMINE_ROOTS_H*/
