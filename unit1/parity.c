// User input an integer. Output "even" or "odd"
// modulo finds the remainder (5 % 3 = 2, 22 % 3 = 1, even % 2 = 0, odd % 2 = 1)

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number = get_int("integer: ");

    if (number % 2 == 0) {
        printf("\nYour number (%i) is even! \n\n", number);
    } else {
        printf("\nYour number (%i) is odd! \n\n", number);
    }
}