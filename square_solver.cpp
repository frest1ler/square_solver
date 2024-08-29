#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

enum number_roots
{
    INFINITY_ROOTS                  = -1,
    NO_ROOTS                        =  0,
    ONE_ROOTS                       =  1,
    TWO_ROOTS                       =  2
};

enum compare_constants
{
    LESS_THAN_EPSILON               = -1,
    INSIDE_THE_EPSILON_NEIGHBORHOOD =  0,
    MORE_EPSILON                    =  1
};

const double EPSILON = 1e-9;

void input_data(struct equation_coefficients *coefficients);
void clear_buffer();
void math_calculus(struct equation_coefficients *coefficients, struct equation_roots *roots);
void square_solver(struct equation_coefficients *coefficients, struct equation_roots *roots);
void linear_solver(struct equation_coefficients *coefficients, struct equation_roots *roots);
void output_data(struct equation_roots *roots);
void test_one(struct test_data *data_for_test, struct equation_roots *roots, int i);
void test();
int  compare_with_zero (double x);

struct equation_coefficients
{
    double a;
    double b;
    double c;
};
struct equation_roots
{
    double x1;
    double x2;
    int    number_roots;
};

struct test_data
{
    struct equation_coefficients coefficients;
    struct equation_roots        roots;
    int                          number_test;
};

int main()
{
    struct equation_coefficients coefficients  = {NAN, NAN, NAN};
    struct equation_roots        roots         = {NAN, NAN, 0};

    test();

    input_data(&coefficients);

    math_calculus(&coefficients, &roots);   //TODO mask_anus

    output_data(&roots);
}

void input_data(struct equation_coefficients *coefficients)
{
    printf("Hi,hi, this program solves an equation of the form ax^2+bx + c = 0\n"
           "enter a, b, c\n");

    while((scanf("%lg %lg %lg", &(coefficients->a), &(coefficients->b), &(coefficients->c))) != 3)
    {
        clear_buffer();
        printf("Input error. Try again\a\n");
    }
    clear_buffer();
}

void square_solver(struct equation_coefficients *coefficients, struct equation_roots *roots)
{
    assert(isfinite(coefficients->a));//бро красава
    assert(isfinite(coefficients->b));
    assert(isfinite(coefficients->c));

    assert(roots);//bro cool

    if (compare_with_zero(coefficients->b) == INSIDE_THE_EPSILON_NEIGHBORHOOD &&
        compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        roots->x1 = roots->x2 = 0;
        roots->number_roots = ONE_ROOTS;
    }
    else
    { // compare_with_zero(b) != 0 || compare_with_zero(c) != 0
        double discriminant = NAN, sqrt_discriminant = NAN;

        discriminant = coefficients->b * coefficients->b - 4 * coefficients->a * coefficients->c;

        if (compare_with_zero(discriminant) == LESS_THAN_EPSILON)
        {
            roots->number_roots = NO_ROOTS;
            roots->x1 = roots->x2 = 0;
        }
        if (compare_with_zero(discriminant) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            roots->number_roots = ONE_ROOTS;
            roots->x1 = roots->x2 = -coefficients->b / (2 * coefficients->a);
        }

        if (compare_with_zero(discriminant) == MORE_EPSILON)
        {
            roots->number_roots = TWO_ROOTS;
            sqrt_discriminant = sqrt(discriminant);
            roots->x1 = (-coefficients->b + sqrt_discriminant) / (2 * coefficients->a);
            roots->x2 = (-coefficients->b - sqrt_discriminant) / (2 * coefficients->a);
        }
    }
}

void output_data(struct equation_roots *roots)
{
    switch (roots->number_roots)
    {
        case NO_ROOTS :
        {
            printf("Nule roots\n");
            break;
        }
        case ONE_ROOTS :
        {
            printf("One roots x=%lg\n", roots->x1);
            break;
        }
        case TWO_ROOTS :
        {
            printf("Two roots x1=%lg , x2=%lg\n", roots->x1, roots->x2);
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

void linear_solver(struct equation_coefficients *coefficients, struct equation_roots *roots)
{
    assert(isfinite(coefficients->a));
    assert(isfinite(coefficients->b));
    assert(isfinite(coefficients->c));

    assert(roots);

    if (compare_with_zero(coefficients->b) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            roots->number_roots = INFINITY_ROOTS;
            roots->x1 = roots->x2 = 0;
        }
        else
        {
            roots->number_roots = NO_ROOTS;
        }
    }
    else
    {
        if (compare_with_zero(coefficients->c) == INSIDE_THE_EPSILON_NEIGHBORHOOD)
        {
            roots->x1 = roots->x2 = 0;
            roots->number_roots = ONE_ROOTS;
        }
        else
        {
            roots->number_roots = ONE_ROOTS;
            roots->x1 = roots->x2 = -coefficients->c / coefficients->b;
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

void math_calculus(struct equation_coefficients *coefficients, struct equation_roots *roots)
{
   if (compare_with_zero(coefficients->a) != INSIDE_THE_EPSILON_NEIGHBORHOOD)
    {
        square_solver(coefficients, roots);
    }
    else
    {
        linear_solver(coefficients, roots);
    }
}
void clear_buffer()
{
	int clean = 0;

	do
	{
        clean = getchar();
	} while (clean != '\n' && clean != EOF);
}

void test_one(struct test_data *data_for_test, struct equation_roots *roots, int i) //ПЕИМЕНОВАТЬ ХУЙНЮ
{
    roots->x1 = NAN;
    roots->x2 = NAN;
    roots->number_roots = 0;

    math_calculus(&data_for_test[i].coefficients, roots);//TODO ЧУТЬ ЧУТЬ ХУЙНЮ ПРЕКРАТИТЬ, ПРОБЕЛ
    if (compare_with_zero(roots->x1 - data_for_test[i].roots.x1) != 0 &&
    compare_with_zero(roots->x2 - data_for_test[i].roots.x2) != 0 &&
        roots->number_roots != data_for_test[i].roots.number_roots)
    {
        printf("\n%d TEST ERROR , got the results:\n\nx1=%lg ; expected x1=%lg\n"
               "x2=%lg ; expected x2=%lg\n"
               "number_roots=%d ; expected number_roots=%d\n\n",
               data_for_test[i].number_test, roots->x1, data_for_test[i].roots.x1,
               roots->x2, data_for_test[i].roots.x2,
               roots->number_roots, data_for_test[i].roots.number_roots);
    }
    else
    {
        printf("TEST OK\n");
    }
}
void test()
{
    struct test_data data_for_test[] =
    {
        {{1, -5, 6}, {2, 3, 2}, 0},//TODO ДОБАВИТЬ ХУЙНЮ(СОРТИРОВКУ)
        {{0,  0, 0}, {0, 0, -1}, 1}
    };

    struct equation_coefficients coefficients  = {NAN, NAN, NAN};
    struct equation_roots        roots         = {NAN, NAN, 0};

    const int max_number_test = sizeof(data_for_test) / sizeof(data_for_test[0]);

    for(int i = 0; i < max_number_test; i++)
    {
        test_one(data_for_test + i, &roots, i);//data_for_test[i] == *(data+i)
    }
}
