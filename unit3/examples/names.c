#include <cs50.h>
#include <stdio.h>
#include <string.h>

// useful for storing multiple groups of data in one spot
typedef struct
{
    string name;
    string number;
    int age;
}
contact;
// creates a new data type called contact


int main(void)
{
    contact person[4];

    person[0].name = "EMMA";
    person[0].number = "559-111-1111";
    person[0].age = 42;

    person[1].name = "RODRIGO";
    person[1].number = "559-222-2222";
    person[1].age = 65;


    // An array(list) of strings
    // string names[] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};
    // string phone[] = {"559-111-111", "559-222-2222", "559-333-3333", "5559-444"};

    // Search for a value
    string target = get_string("Which name would you like to search for? ");


    for (int i = 0; i < 4; i++)
    {
        // strcmp is used to compare two strings
        if (strcmp(target, person[i].name) == 0)
        {
            printf("%s's phone number is %s.\n", person[i].name, person[i].number);
            return 0;
        }

    }
    printf("Not found\n");
    return 1;

}