#include <cs50.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check for 2 command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // check to make sure file exists
    if (argv[1] == NULL)
    {
        printf("File does not exist");
        return 1;
    }

    // open the file in read mode
    FILE *file = fopen(argv[1], "r");

    // unsigned char buffer[512];
    typedef uint8_t BYTE;
    BYTE buffer[512];
    char filename[8];
    FILE *picture = fopen("gumber", "w");
    int count = 0;

    // repeat the following using a while loop
    // read 512 bytes into the buffer
    while (fread(buffer, 512, 1, file) == 1)
    {
        // if start of jpeg
        // check if the first 3 bytes are 0xff, 0xd8, and 0xff
        // check if the 4th byte is one of the following: 0xe0,0xe1, 0xe2 ... 0xef
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            fclose(picture);
            sprintf(filename, "%03i.jpg", count);
            count++;
            picture = fopen(filename, "w");
        }
        fwrite(buffer, 512, 1, picture);
    }
    fclose(picture);
    fclose(file);
}
