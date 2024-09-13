#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "onegin.h"
#include "sort.h"

int main()
{
    FILE * point_to_file = fopen("ONEGIN_SHORT.txt", "r");

    assert(point_to_file);

    char text[MAXIMUM_NUMBER_OF_COLUMNS][MAXIMUM_LINE_LENGTH] = {};

    char symbol = 0;
    int  x      = 0;
    int  y      = 0;

    //printf("1\n");
    while((symbol = getc(point_to_file)) != EOF)
    {
        text[y][x] = symbol;
        x++;

        if (symbol == '\n')
        {
            y++  ;
            x = 0;
        }
    }
    fclose(point_to_file);
    //printf("2\n");

    sort(&text[0]);

    for(y = 0; y < MAXIMUM_NUMBER_OF_COLUMNS; y++)
    {
        for(x = 0; x <MAXIMUM_LINE_LENGTH; x++)
        {
            putchar(text[y][x]);
        }
    }
    //printf("3\n");

    return 0;
}
