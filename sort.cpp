#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "compare_char.h"
#include "onegin.h"
#include "sort.h"

int replace_values(int y, char text[MAXIMUM_NUMBER_OF_COLUMNS][MAXIMUM_LINE_LENGTH]);
int sort_columns(int y, char text[MAXIMUM_NUMBER_OF_COLUMNS][MAXIMUM_LINE_LENGTH]);
int check_characters(char a);

int sort(char text[MAXIMUM_NUMBER_OF_COLUMNS][MAXIMUM_LINE_LENGTH])
{
    assert(text);

    for(int i = 1; i < MAXIMUM_NUMBER_OF_COLUMNS; i++)
    {
        //printf("%d\n ", i);
        for(int y = 1; y < MAXIMUM_NUMBER_OF_COLUMNS; y++)
        {
            //printf("%d ", y);
            sort_columns(y, text);
        }
    }
    return 0;
}

int replace_values(int y, char text[MAXIMUM_NUMBER_OF_COLUMNS][MAXIMUM_LINE_LENGTH])
{
    assert(text);

    for(int x = 0; x < MAXIMUM_LINE_LENGTH; x++)
    {
        char storage_symbol = text[y-1][x];
        text[y-1][x] = text[y][x];
        text[y][x] = storage_symbol;
    }
    return 0;
}
int sort_columns(int y, char  text[MAXIMUM_NUMBER_OF_COLUMNS][MAXIMUM_LINE_LENGTH])
{
    assert(text);

    int skip_symbols_first_string  = 0;
    int skip_symbols_second_string = 0;

    for(int x = 0; x < MAXIMUM_LINE_LENGTH; x++)
    {
        while(check_characters(text[y-1][x+skip_symbols_first_string]))
        {
            skip_symbols_first_string++;
        }
        while(check_characters(text[y][x+skip_symbols_second_string]))
        {
            skip_symbols_second_string++;
        }
        if (text[y-1][x+skip_symbols_first_string] != '\n' &&
            text[y][x+skip_symbols_second_string] != '\n')
        {
            char first  = toupper(text[y-1][x+skip_symbols_first_string]);
            char second = toupper(text[y  ][x+skip_symbols_second_string]);

            int solution_option = compare_char(first, second);
            switch(solution_option)
            {
                case 1 :
                {
                    replace_values(y, &text[0]);
                    return 0;
                }
                case -1 :
                {
                    return 0;
                }
                case 0 :
                {
                    break;
                }
                default:
                {
                    printf("ERROR\n");
                    break;
                }
            }
        }
        else
        {
            return 0;
        }
    }
    return 0;
}

int check_characters(char a)
{
    return (isspace(a) || ispunct(a));
}
