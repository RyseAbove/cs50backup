#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // USE DO WHILE LOOPS
    int start;
    do
    {
        start = get_int("What is the starting population? \n");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("\nWhat is the ending population? \n");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold

    int years = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        years++;
    }

    // TODO: Print number of years

    printf("\nYears: %i \n", years);
}