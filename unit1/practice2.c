#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = get_int("Number: ");
    for (int final = 0; final < number; final++) {
        if(final == number - 1)
        {
        printf("%i!!!\n\n", final + 1);
        break;
        }
        printf("%i, ", final + 1);
    }
}