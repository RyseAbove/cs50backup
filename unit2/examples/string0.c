#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    string word = get_string("Input: ");
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        if (word[i] > 'm')
        {
            printf("%c", word[length - i - 1]);
        }
    }
    printf("\n");
}