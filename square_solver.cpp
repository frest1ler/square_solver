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

void input_data(struct input_coeff *input);
void clear_buffer();
void math_calculus(enum const_data data, struct input_coeff input, struct output_coeff *output);
void square_solver(enum const_data data, struct input_coeff input, struct output_coeff *output);
void linear_solver(enum const_data data, struct input_coeff input, struct output_coeff *output);
void output_data(enum const_data data, struct output_coeff output);
int  compare_with_zero (double x);

struct input_coeff //TODO RENAME
{
    double a;
    double b;
    double c;
};
struct output_coeff
{
    double x1;
    double x2;
    enum const_data data;
};

struct input_test_coeff
{
    double a_test;
    double b_test;
    double c_test;
};

struct output_test_coeff
{
    double x1_test;
    double x2_test;
    int    number_roots_test;
};

int main()
{
    enum const_data data;
    struct input_coeff input = {NAN, NAN, NAN};
    struct output_coeff output = {NAN, NAN, 0};
    struct input_test_coeff input_test[] =
    {
        {1, -5, 6};
        {0, 0, 0};
    };
    struct output_test_coeff output_test[] =
    {
        {2, 3, TWO_ROOTS};
        {0, 0, INFINITY_ROOTS};
    };

    input_data(&input);

    math_calculus( data, input, &output);

    output_data( data, output);
}

void input_data(struct input_coeff *input)
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

void square_solver(enum const_data data, struct input_coeff input, struct output_coeff *output)
{
    assert(isfinite(input.a));
    assert(isfinite(input.b));
    assert(isfinite(input.c));

    assert(&output->x1); //TODO adress struct != 0
    assert(&output->x2);

    if (compare_with_zero(input.b) == INSIDE_THE_EPSILON_NEIGHBORHOOD &&
        compare_with_zero(input.c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        output->x1 = output->x2 = 0;
        output->number_roots = ONE_ROOTS;
    }
    else
    { // compare_with_zero(b) != 0 || compare_with_zero(c) != 0
        double discriminant = NAN, sqrt_discriminant = NAN;

        discriminant = input.b * input.b - 4 * input.a * input.c;

        if (compare_with_zero(discriminant) == LESS_THAN_EPSILON)
        {
            output->number_roots = NO_ROOTS;
        }
        if (compare_with_zero(discriminant) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            output->number_roots = ONE_ROOTS;
            output->x1 = output->x2 = -input.b / (2 * input.a);
        }

        if (compare_with_zero(discriminant) == MORE_EPSILON)
        {
            output->number_roots = TWO_ROOTS;
            sqrt_discriminant = sqrt(discriminant);
            output->x1 = (-input.b + sqrt_discriminant) / (2 * input.a);
            output->x2 = (-input.b - sqrt_discriminant) / (2 * input.a);
        }
    }
}

void output_data(enum const_data data, struct output_coeff output)
{
    switch (output.number_roots)
    {
        case NO_ROOTS :
        {
            printf("Nule roots\n");
            break;
        }
        case ONE_ROOTS :
        {
            printf("One roots x=%lg\n", output.x1);
            break;
        }
        case TWO_ROOTS :
        {
            printf("Two roots x1=%lg , x2=%lg\n", output.x1, output.x2);
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

void linear_solver(enum const_data data, struct input_coeff input, struct output_coeff *output)
{
    assert(isfinite(input.a));
    assert(isfinite(input.b));
    assert(isfinite(input.c));

    assert(&output->x1);
    assert(&output->x2);

    if (compare_with_zero(input.b) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        if (compare_with_zero(input.c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
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
        if (compare_with_zero(input.c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            output->x1 = output->x2 = 0;
            output->number_roots = ONE_ROOTS;
        }
        else
        {
            output->number_roots = ONE_ROOTS;
            output->x1 = output->x2 = -input.c / input.b;
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

void math_calculus(enum const_data data, struct input_coeff input, struct output_coeff *output) //TODO rename
{
   if (compare_with_zero(input.a) != INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        square_solver(data, input, output);
    }
    else
    {
        linear_solver(data, input, output);
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

void test_one(struct input_test_coeff input.test[], struct output_test_coeff output.test[]);
{
    math_calculus(struct input_test_coeff input.test[]);
    if ()
    {
        printf("ERROR TEST");
    }
}
void test(struct input_test_coeff input.test[], struct output_test_coeff output.test[]);
{
    while()
    {
        test_one();
    }
}

