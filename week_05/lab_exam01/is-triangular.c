/*
is-triangular.c
author Michael Redmond
*/

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions I may need*/

/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Takes 1 argument called "number" and determines if it is a triangular number or not.
 */

int main(int argc, char *argv[1]) {
    /* variable initialisation */
    int number = 0;
    int i = 0;
    int j = 1;
    /* all command-line arguments come in as character strings, so atoi turns them into ints*/
    number = atoi(argv[1]);
    /* a while loop to start us off */
    while (i < number) {
        i += j; /* this increment will get larger depending on the input */
        if (i == number) { /* if number is triangular */
            printf("%d is a triangular number.\n",number);
        }
        ++j;
    }
    /* if number is not triangular */
    if (i != number) {
        printf("%d is not a triangular number.\n",number);
    }
    return (0); /* exit correctly*/
} /* end program*/