#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    string buffer[1];
    while(fread(buffer, 1, 1, input))
    {
        fwrite(buffer, 1, 1, output);
    }
    //   where to hold info, how many to hold, how many to read at a time, what to read
    //   where to get info, how big is it, how many to write at a time, where to write

    fclose(input);
    fclose(output);
}