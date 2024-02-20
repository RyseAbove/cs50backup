#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{
    // opens the file
    FILE *file = fopen(argv[1], "read");

    // read first 3 bytes
    unsigned char bytes[3];
    fread(bytes, 3, 1, file);

    // check first 3 bytes
    if (bytes[0] == 0xFF && bytes[1] == 0xD8 && bytes[2] == 0xFF)
    {
        printf("This MIGHT be a jpeg file\n");
    }

    else
    {
        printf("This is NOT a jpeg file\n");
    }

    fclose(file);
}