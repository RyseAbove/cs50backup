#include <stdlib.h>
#include <time.h>

int randomInt(int min, int max)
{
    time_t t;
    // seed the random function with the current time
    srand(time(&t));
    // calculate a random value between min and max inclusive

    return rand() % (max - min + 1) + min;
}