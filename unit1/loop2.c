#include <stdio.h>

int main(void) {
    // example of a WHILE loop
    int i = 0;
    while(i < 3) {
        printf("Hello!\n");
        i++;
    }

    // example of a FOR loop
    for(int j = 0; j < 3; j++) {
        printf("Goodbye!\n");
    }

    //example of a DO WHILE loop
    int k = 0;
    do {
        printf("Have a nice day \n");
        k++;
    } while(k < 3);

}