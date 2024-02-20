#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    int *pointer = &n;
    printf("%p\n", pointer);
}