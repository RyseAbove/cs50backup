#include <cs50.h>
#include <stdio.h>

bool isprime(int number);

int main(void)
{

    int number = get_int("How many primes would you like? ");
    int count = 0;
    int check = 2;

    while (count < number)
    {
        if (isprime(check))
        {
            printf("%i\n", check);
            count++;
        }
        check++;
    }
}

bool isprime(int number)
{
    int count = 0;

    for(int i = 1; i <= number; i++)
    {
        if (number % i == 0)
        {
            count++;
        }
    }

    if (count == 2) {
    return true;
    }

    else
    {
    return false;
    }
}