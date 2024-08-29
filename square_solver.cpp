#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

enum const_data
{
    INFINITY_ROOTS = -1,
    NO_ROOTS       =  0,
    ONE_ROOTS      =  1,
    TWO_ROOTS      =  2,
    LESS_THAN_EPSILON               = -1,
    INSIDE_THE_EPSILON_NEIGHBORHOOD = 0,
    MORE_EPSILON                    = 1
};

const double EPSILON        =  1e-9;

void input_data(struct equalization_coefficients *input);
void clear_buffer();
void math_calculus(enum const_data data, struct equalization_coefficients *input, struct roots_of_equation *output);
void square_solver(enum const_data data, struct equalization_coefficients *input, struct roots_of_equation *output);
void linear_solver(enum const_data data, struct equalization_coefficients *input, struct roots_of_equation *output);
void output_data(enum const_data data, struct roots_of_equation *output);
void test_one(struct test_data *data_for_test, struct roots_of_equation *output, int i, enum const_data data);
void test(struct test_data *data_for_test, struct roots_of_equation *output, enum const_data data);
int  compare_with_zero (double x);

struct equalization_coefficients //TODO RENAME
{
    double a;
    double b;
    double c;
};
struct roots_of_equation
{
    double x1;
    double x2;
    int    number_roots;
};

struct test_data
{
    struct equalization_coefficients input_test;
    struct roots_of_equation         output_test;
    int                              number_test;
};

int main()
{
    enum const_data data;
    struct test_data data_for_test[2] =
    {
        {{1, -5, 6}, {2, 3, 2}, 0},
        {{0, 0, 0}, {NAN, NAN, -1}, 1}
    };
    struct equalization_coefficients input = {NAN, NAN, NAN};
    struct roots_of_equation         output = {NAN, NAN, 0};

    input_data(&input);

    math_calculus(data, &input, &output);

    output_data(data, &output);

    test(data_for_test, &output, data);
}

void input_data(struct equalization_coefficients *input)
{
    printf("Hi,hi, this program solves an equation of the form ax^2+bx + c = 0\n"
           "enter a, b, c\n");
    while((scanf("%lg%lg%lg", &(input->a), &(input->b), &(input->c))) != 3
          || (isfinite(input->a)) == 0 || (isfinite(input->b)) == 0 || (isfinite(input->c)) == 0)
    {
        clear_buffer();
        printf("Input error. Try again\007\n");
    }
    clear_buffer();

    assert(isfinite(input->a));
    assert(isfinite(input->b));
    assert(isfinite(input->c));

    assert(&input->a != &input->b);
    assert(&input->a != &input->c);
    assert(&input->b != &input->c);
}

void square_solver(enum const_data data, struct equalization_coefficients *input, struct roots_of_equation *output)
{
    assert(isfinite(input->a));
    assert(isfinite(input->b));
    assert(isfinite(input->c));

    assert(&output->x1); //TODO adress struct != 0
    assert(&output->x2);

    if (compare_with_zero(input->b) == INSIDE_THE_EPSILON_NEIGHBORHOOD &&
        compare_with_zero(input->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        output->x1 = output->x2 = 0;
        output->number_roots = ONE_ROOTS;
    }
    else
    { // compare_with_zero(b) != 0 || compare_with_zero(c) != 0
        double discriminant = NAN, sqrt_discriminant = NAN;

        discriminant = input->b * input->b - 4 * input->a * input->c;

        if (compare_with_zero(discriminant) == LESS_THAN_EPSILON)
        {
            output->number_roots = NO_ROOTS;
        }
        if (compare_with_zero(discriminant) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            output->number_roots = ONE_ROOTS;
            output->x1 = output->x2 = -input->b / (2 * input->a);
        }

        if (compare_with_zero(discriminant) == MORE_EPSILON)
        {
            output->number_roots = TWO_ROOTS;
            sqrt_discriminant = sqrt(discriminant);
            output->x1 = (-input->b + sqrt_discriminant) / (2 * input->a);
            output->x2 = (-input->b - sqrt_discriminant) / (2 * input->a);
        }
    }
}

void output_data(enum const_data data, struct roots_of_equation *output)
{
    switch (output->number_roots)
    {
        case NO_ROOTS :
        {
            printf("Nule roots\n");
            break;
        }
        case ONE_ROOTS :
        {
            printf("One roots x=%lg\n", output->x1);
            break;
        }
        case TWO_ROOTS :
        {
            printf("Two roots x1=%lg , x2=%lg\n", output->x1, output->x2);
            break;
        }
        case INFINITY_ROOTS :
        {
            printf("infinitely many roots\n");
            break;
        }
        default :
        {
            printf("ERROR\n");
            break;
        }
    }
}

void linear_solver(enum const_data data, struct equalization_coefficients *input, struct roots_of_equation *output)
{
    assert(isfinite(input->a));
    assert(isfinite(input->b));
    assert(isfinite(input->c));

    assert(&output->x1);
    assert(&output->x2);

    if (compare_with_zero(input->b) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        if (compare_with_zero(input->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            output->number_roots = INFINITY_ROOTS;
        }
        else
        {
            output->number_roots = NO_ROOTS;
        }
    }
    else
    {
        if (compare_with_zero(input->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            output->x1 = output->x2 = 0;
            output->number_roots = ONE_ROOTS;
        }
        else
        {
            output->number_roots = ONE_ROOTS;
            output->x1 = output->x2 = -input->c / input->b;
        }
    }
}

int compare_with_zero(double x)    // comparing coeffs with zero
{
    if (fabs(x) <  EPSILON)
    {
        return INSIDE_THE_EPSILON_NEIGHBORHOOD;
    }
    else if (x  < -EPSILON)
    {
        return LESS_THAN_EPSILON;
    }
    else return MORE_EPSILON;
}

void math_calculus(enum const_data data, struct equalization_coefficients *input, struct roots_of_equation *output) //TODO rename
{
   if (compare_with_zero(input->a) != INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        square_solver(data, input, output);
        printf ("x1=%lg\n x2=%lg\n nRoots=%d", output->x1, output->x2, output->number_roots);
    }
    else
    {
        linear_solver(data, input, output);
        printf ("x1=%lg\n x2=%lg\n nRoots=%d", output->x1, output->x2, output->number_roots);
    }
}
void clear_buffer()
{
	char clean = 0;

	do
	{
        clean = getchar();
	} while (clean != '\n' && clean != EOF);
}

void test_one(struct test_data *data_for_test, struct roots_of_equation *output, int i,
              enum const_data data)
{
    output->x1 = NAN;
    output->x2 = NAN;
    output->number_roots = 0;

    math_calculus(data, &data_for_test[i].input_test, output);
    if (output->x1 != data_for_test[i].output_test.x1 && output->x2 != data_for_test[i].output_test.x2 &&
        output->number_roots != data_for_test[i].output_test.number_roots)
    {
        printf("\n%d TEST ERROR , got the results:\n\nx1=%lg ; expected x1=%lg\n"
               "x2=%lg ; expected x2=%lg\n"
               "number_roots=%d ; expected number_roots=%d\n\n",
               data_for_test[i].number_test, output->x1, data_for_test[i].output_test.x1,
               output->x2, data_for_test[i].output_test.x2,
               output->number_roots, data_for_test[i].output_test.number_roots);
    }
    else
    {
        printf("TEST OK");
    }
}
void test(struct test_data *data_for_test, struct roots_of_equation *output,
          enum const_data data)
{
    for(int i = 0; i < 2; ++i) //sizeof(massive)/sizepf(struct)
    {
        test_one(&data_for_test[i], output, i, data);
    }
}
