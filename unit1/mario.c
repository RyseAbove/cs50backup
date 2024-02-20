// use for loops
// use boolean expressions

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("How tall? ");
    }
    while (height <= 0 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int h = height; h > i + 1; h--)
        {
            printf(" ");
        }

        for (int j = 1; j <= i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}