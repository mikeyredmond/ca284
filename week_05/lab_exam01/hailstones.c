/*
hailstones.c
author Michael Redmond
*/

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions I may need*/

/* Functions: Main and hailstone
parameters: int argc (argument count) in hailstone function
char *argv[] an array of command-line arguments in hailstone function
description:  The function "hailstone" takes 1 argument called "n" and prints the first n numbers in the hailstones sequence
 */

// Forward declaration
void hailstone(int argc, char *argv[1]);

int main(int argc, char *argv[1])
{
    /* call the hailstone function */
    hailstone(argc, argv);
    return (0); /* exit correctly*/
} /* end program*/


void hailstone(int argc, char *argv[1])
{
    /* variable initialisation */
    int n = 0;
    /* all command-line arguments come in as character strings, so atoi turns them into ints*/
    n = atoi(argv[1]);
    /* a while loop to start us off */
    while (n != 1) {
        if (n % 2 == 0) { /* if number is even */
            n = n / 2;
            printf("%d\n",n);
        }
        else { /* else number is odd */
            n = (n * 3) + 1;
            printf("%d\n",n);
        }
    }
}