// This program will swap two values

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x= ");
    int y = get_int("y= ");

    int z = x;
    x = y;
    y = z;

    printf("\nx = %i & y = %i \n", x, y);
}