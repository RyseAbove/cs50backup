#include <cs50.h>
#include <stdio.h>

int main(void) {
    long x = get_int("First #: ");
    long y = get_int("Second #: ");

    long sum = x + y;
    long pro = x * y;
    long difference = x - y;
    float quotient = (float) x / (float) y;

    printf ("\n The sum of %li and %li is %li \n\n The product of %li and %li is %li \n\n The difference of %li and %li is %li \n\n The quotient of %li and %li is %f \n\n", x, y, sum, x, y, pro, x, y, difference, x, y, quotient);
}