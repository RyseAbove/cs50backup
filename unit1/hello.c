#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // string first_name = get_string("\n First Name: ");
    // string last_name = get_string("\n Last Name: ");
    string name = get_string("\n What is your name? ");
    printf("\n   Hello %s! \n\n", name);
}