#include <cs50.h>
#include <stdio.h>

int main(void) {

    int guesses = 0;
    while (true) {
        guesses = guesses + 1;
        int number = get_int("Guess my number: ");

        if (number == 20) {
            printf("\n You win! It took you %i guesses. \n\n", guesses);
            break;
        } else if (number < 20) {
            printf("\n Too low! You lose! \n\n");
        } else if (number > 20) {
            printf("\n Too high! You lose! \n\n");
        }
        // } else {
        //     printf("\n You lose! \n\n");
        // }
    }
}