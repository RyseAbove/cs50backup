#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // open file
    FILE *file = fopen("phonebook.csv", "a");

    // get strings from user
    string name = get_string("NAME: ");
    string number = get_string("NUMBER: ");

    // print (write) strings to the file
    fprintf(file, "%s, %s\n", name, number);

    // close file
    fclose(file);
}