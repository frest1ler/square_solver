#ifndef DETERMINE_ROOTS_H_
#define DETERMINE_ROOTS_H_

void determine_roots(struct equation_coefficients *coefficients, struct equation_roots *roots);
void square_solver(struct equation_coefficients *coefficients, struct equation_roots *roots);
void linear_solver(struct equation_coefficients *coefficients, struct equation_roots *roots);
#endif /*DETERMINE_ROOTS_H_*/
