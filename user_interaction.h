#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H

void input_data(Equation_coefficients *coefficients);
void skip_buffer();
void output_data(Equation_roots *roots);

int ui_ask_for_tests();
int  get_user_feedback();

#endif /*USER_INTERACTION_H*/
