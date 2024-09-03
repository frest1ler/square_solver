#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

void get_input(Equation_coefficients *coefficients);
void skip_buffer();
void print();
void display_output(const Equation_roots *roots);

int ui_ask_for_tests();
int get_user_feedback();

#endif /*USER_INTERACTION_H*/
