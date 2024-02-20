#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{

    string text = get_string("Input: ");

    // used to calculate letters
    char c;

    // if user gives no input
    int letters = 0;

    // always at least one word
    int words = 1;

    // always at least one sentence
    int sentences = 0;

    int length = strlen(text);

    // calculate letters
    for (int l = 0; l < length; l++)
    {
        c = text[l];

        if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
        {
            letters++;
        }
    }

    // calculate words
    for (int w = 0; w < length; w++)
    {
        c = text[w];

        if (isspace(c))
        {
            words++;
        }
    }

    // calculate sentences
    for (int s = 0; s < length; s++)
    {
        c = text[s];

        if (c == '!' || c == '?' || c == '.')
        {
            sentences++;
        }
    }

    float average_letters = ((float) letters * 100) / (float) words;
    float average_sentences = ((float) sentences * 100) / (float) words;

    int grade_level = round(0.0588 * average_letters - 0.296 * average_sentences - 15.8);

    if (grade_level < 1)
    {
        printf("Before Grade 1\n");
    }
    else

        if (grade_level > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade_level);
    }
}