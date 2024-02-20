// Goal is to find the sum 1 + 2 + 3 + ... 123456

#include <stdio.h>

int main(void)
{
    int sum = 0;
    int counter = 1;
    // int term = 1;

    while (counter < 123456)
    {
        sum += counter;
        counter += 1;
    }

    printf("The sum = %i \n", sum);
}