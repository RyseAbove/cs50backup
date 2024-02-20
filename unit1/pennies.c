#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    // starting number of days
    int days;
    do
    {
        days = get_int("How many days in the month? \n");
    }
    while (days < 1 || days > 31);

    // starting number of pennies
    long double start_pennies;
    do
    {
        start_pennies = get_int("How many pennies to start with? \n");
    }
    while (start_pennies < 1);

    // final pennies
    long double final_pennies = start_pennies;

    // calculate how many pennies in a month
    for (int counter = 0; counter < days; counter++)
    {
        final_pennies = (final_pennies * 2);
    }
    printf("$%0.2Lf\n", (long double) (final_pennies - start_pennies) / 100);
}