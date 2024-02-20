#include <cs50.h>
#include <stdio.h>

int main(void) {
    int score = get_int("\nWhat was your test score? ");

    if (score >= 90 && score <= 100) {
        printf("\nYou got an A! Congratulations! \n\n");
    } else if (score >= 80 && score < 90) {
        printf("\nYou got a B! \n\n");
    } else if (score >= 70 && score < 80) {
        printf("\nYou got a C! \n\n");
    } else if (score >= 60 && score < 70) {
        printf("\nYou got a D! \n\n");
    } else {
        printf("\nYou failed \n\n");
    }
}