// Count the number of vowels (a, e, i, o, u)
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string text = get_string("Input: ");
    int length = strlen(text);
    int vowels = 0;
    char c;


    for (int i = 0; i < length; i++)
    {
        c = tolower(text[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            vowels++;
        }
    }

    int words = 5;
    float average = (float)vowels / (float)words;
    
    printf("There are %i vowels\n", vowels);
    printf("The average # of vowels per 5 words is %.2f\n", average);
}