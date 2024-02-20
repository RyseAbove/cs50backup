#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool check_int(string number);

int main(int argc, string argv[])
{
    // Make sure you only have 2 command-line arguments.
    // Make sure key is only made of digits.

    bool error_com1 = argc != 2;
    if (error_com1)
    {
        printf("Usage: ./caeser key\n");
        return 1;
    }

    bool isNumber = check_int(argv[1]);
    bool error_com2 = !(isNumber);
    if (error_com2)
    {
        printf("key must be an integer\n");
        return 1;
    }

    // Change key from string to int.
    int key = atoi(argv[1]);

    // Prompt the user for text.
    string text = get_string("Message: ");

    int length = strlen(text);

    // Change text to ciphertext
    // Loop through each char of text one at a time.
    // If the char is a letter, then change it.
    // You can detect a letter using isalpha().
    // If the char is not a letter, then don't change it.
    char temp;

    // LOWER CASE LETTER EXAMPLE
    // We subtract 97 because all the lowercase letters are 97
    // above the alphabetic index ... 0, 1, 2, ..., 25.
    // Then % 26 divides by 26 and give the remainder.
    // This allows us to loop around and stay within 0 to 26.
    // Then we go back to ASCII by adding 97.

    printf("ciphertext: ");
    for (int n = 0; n < length; n++)
    {
        if (isalpha(text[n]))
        {
            if (isupper(text[n]))
            {
                temp = ((text[n] - 65 + key) % 26) + 65;
                printf("%c", temp);
            }
            if (islower(text[n]))
            {
                temp = ((text[n] - 97 + key) % 26) + 97;
                printf("%c", temp);
            }
        }
        else
        {
            printf("%c", text[n]);
        }
    }
    printf("\n");
}

bool check_int(string number)
{
    int length = strlen(number);
    for (int i = 0; i < length; i++)
    {
        if (!(isdigit(number[i])))
        {
            return false;
        }
    }
    return true;
}