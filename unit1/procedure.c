#include <stdio.h>
#include <cs50.h>


void print_hello(int times);

int main(void)
{
    int times = get_int("How many repeats? ");
    //times is called an argument in line 9
    print_hello(times);
}

//print hello is called a procedure
//times is called a parameter
void print_hello(int times)
{
     for(int counter = 0; counter < times; counter++)
    {
        printf("Hello!\n");
    }
}




