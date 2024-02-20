#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = 0;
    int number = get_int("Number: ");
    while(x < number) {
        x++;
        printf("%i\n", x);
    }
    printf("\n\n");

}