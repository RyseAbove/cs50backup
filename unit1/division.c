#include <cs50.h>
#include <stdio.h>

float divide(int a, int b);

int main(void) {
    long x = get_int("First #: ");
    long y = get_int("Second #: ");

    float z = divide(x,y);
    printf("\n\nThe quotient of %li / %li is %.2f \n\n", x, y, z);
}

float divide(int a, int b)
{
    float c = (float) a / (float) b;
    return c;
}