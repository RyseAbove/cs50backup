#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // a = 77, b = 52, c = 99
    int values[] = {77, 52, 99};

    char character = get_char("INPUT: ");

    printf("The value is %i\n", values[character - 97]);
}