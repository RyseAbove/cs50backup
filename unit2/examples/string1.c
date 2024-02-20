#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string word = get_string("Input: ");
    int length = strlen(word);
    // a - z is 97 - 122 and A - Z is 65 - 90

    for (int i = 0; i < length; i++)
    {
        // if (word[i] >= 'a' && word[i] <= 'z')
        if (isupper(word[i]))
        {
            printf("%c", tolower(word[i]));
        }
        else
        {
            printf("%c", word[i]);
        }
    }

    printf("\n");
}