// prompt the user for a number
// tell the user if it is prime or not prime

#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int number;

    do
    {
        number = get_int("Number: ");
    }
    while (number < 2);

    // test modulo for each number
    int count = 0;
    for(int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            count++;
        }
    }
    if (count == 2) {
        printf("\nPRIME!\n\n");
    }
    else
    {
        printf("\nNOT PRIME!\n\n");
    }
}