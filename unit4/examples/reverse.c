#include <stdio.h>

int main(void)
{
    int list[] = {1, 2, 3, 4, 5};
    int length = 5;

    // int reverse[length];
    // for (int i = 0; i <= length; i++)
    // {
    //     reverse[i] = list[i];
    // }

    // int k = 0;
    // for (int j = length; j > 0; j--)
    // {
    //     list[k] = reverse[j - 1];
    //     k++;
    // }

    int temp;
    for (int i = 0; i < length; i++)
    {
        temp = list[i];
        list[i] = list[length - 1];
        list[length - 1] = temp;
        length--;
    }

    printf("%i %i %i %i %i\n", list[0], list[1], list[2], list[3], list[4]);
}