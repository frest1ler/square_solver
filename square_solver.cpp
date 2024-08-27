#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

const int    INFINITY_ROOTS = -1;
const int    NO_ROOTS       =  0;
const int    ONE_ROOTS      =  1;
const int    TWO_ROOTS      =  2;            //TODO enum
const double EPSILON        =  1e-9;

void input_data(struct input_coeff *input);
void math_calculus(struct input_coeff input, struct output_coeff *output);
void square_solver(struct input_coeff input, struct output_coeff *output);
void linear_solver(struct input_coeff input, struct output_coeff *output);
void output_data(struct output_coeff output);
int  compare_with_zero (double x);

struct input_coeff
{
    double a;
    double b;
    double c;
};
struct output_coeff
{
    double x1;
    double x2;
    int number_roots;
};

int main()
{
    struct input_coeff input = {NAN, NAN, NAN};
    struct output_coeff output = {NAN, NAN, 0};
    input_data(&input);

    math_calculus(input, &output);

    output_data(output);
}

void input_data(struct input_coeff *input)
{
    printf("Hi,hi, this program solves an equation of the form ax^2+bx + c = 0\n"
           "enter a, b, c\n");
    scanf("%lg%lg%lg", &(input->a), &(input->b), &(input->c));

    assert(isfinite(input->a));
    assert(isfinite(input->b));
    assert(isfinite(input->c));

    assert(&input->a != &input->b);
    assert(&input->a != &input->c);
    assert(&input->b != &input->c);
}

void square_solver(struct input_coeff input, struct output_coeff *output)
{
    assert(isfinite(input.a));
    assert(isfinite(input.b));
    assert(isfinite(input.c));

    assert(&output->x1);
    assert(&output->x2);

    if (compare_with_zero(input.b) == 0 && compare_with_zero(input.c) == 0)//TODO check is NULL x1, x2 - adress
    {
        output->x1 = output->x2 = 0;
        output->number_roots = ONE_ROOTS;
    }
    else
    { // compare_with_zero(b) != 0 || compare_with_zero(c) != 0
        double discriminant = NAN, sqrt_discriminant = NAN;

        discriminant = input.b * input.b - 4 * input.a * input.c;

        if (compare_with_zero(discriminant) == -1)
        {
            output->number_roots = NO_ROOTS;
        }
        if (compare_with_zero(discriminant) == 0)
        {
            output->number_roots = ONE_ROOTS;
            output->x1 = output->x2 = -input.b / (2 * input.a);
        }

        if (compare_with_zero(discriminant) == 1)
        {
            output->number_roots = TWO_ROOTS;
            sqrt_discriminant = sqrt(discriminant);
            output->x1 = (-input.b + sqrt_discriminant) / (2 * input.a);
            output->x2 = (-input.b - sqrt_discriminant) / (2 * input.a);
        }
    }
}

void output_data(struct output_coeff output)
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

void linear_solver(struct input_coeff input, struct output_coeff *output)
{
    assert(isfinite(input.a));
    assert(isfinite(input.b));
    assert(isfinite(input.c));

    assert(&output->x1);
    assert(&output->x2);

    if (compare_with_zero(input.b) == 0)
    {
        if (compare_with_zero(input.c) == 0)
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
        if (compare_with_zero(input.c) == 0)
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
        return 0; //TODO name
    }
    else if (x  < -EPSILON)
    {
        return -1;
    }
    else return 1;
}

void math_calculus(struct input_coeff input, struct output_coeff *output) //TODO rename
{
   if (compare_with_zero(input.a) != 0)
    {
        square_solver(input, output);
    }
    else
    {
        linear_solver(input, output);
    }
}
