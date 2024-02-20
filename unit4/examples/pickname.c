#include "myfunctions.h"
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    system("clear");
    string names[] = {"Cecilia", "Rahaf", "Aidan", "Malya", "Ian", "Diego"};
    printf("%s\n", names[randomInt(0, 5)]);
}