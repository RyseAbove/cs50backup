// a substring is a part of a string
// string is "Mississippi", substring "ssippi"
// ./substring Mississippi 3 6
// output: siss

// argv = ("./ substring", "Mississippi", "3", "6")
// argc = 4

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h> // convert string to int (for caesar)

bool check_int(string number);

int main(int argc, string argv[])
{
    // check for 4 arguments

    bool error1 = argc != 4;
    if (error1)
    {
        printf("Usage: ./substring word startIndex endIndex\n");
        return 1;
    }

    // check that both indecies are integers

    bool isNumber1 = check_int(argv[2]);
    bool isNumber2 = check_int(argv[3]);
    bool error2 = !(isNumber1 && isNumber2);

    if (error2)
    {
        printf("startIndex and endIndex must be integers\n");
        return 1;
    }

    string word = argv[1]; // mississippi
    int startIndex = atoi(argv[2]); // 3
    int endIndex = atoi(argv[3]); // 6

    for (int index = startIndex; index <= endIndex; index++)
    {
        printf("%c", word[index]);
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