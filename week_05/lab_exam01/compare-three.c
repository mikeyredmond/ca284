/*
compare-three.c
author Michael Redmond
*/

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions I may need*/

/* Functions: Main, check, print_largest
parameters: int argc (argument count) in all functions function
char *argv[] an array of command-line arguments in all functions function
description:  The main function calls the check function to make sure none of the
three numbers are the same and if so, an error message is printed and False is returned to main. Otherwise, it returns True to main
and then calls the print_largest function.
*/

// Forward declaration
int check(int argc, int numbers[]);
int print_largest(int argc, int numbers[]);

int main(int argc, char *argv[3])
{
    /* new array of integers */
    int numbers[4];
    numbers[1] = atoi(argv[1]);
    numbers[2] = atoi(argv[2]);
    numbers[3] = atoi(argv[3]);
    /* call the check function, if it returns True then call the print_largest function */
    if (check(argc, numbers)) {
        print_largest(argc, numbers);
    }
    return (0); /* exit correctly*/
} /* end program*/


int check(int argc, int numbers[])
{
    /* variable initialisation */
    int a, b, c = 0;
    int i = 1;
    /* all command-line arguments come in as character strings, so atoi turns them into ints*/
    a = numbers[1];
    b = numbers[2];
    c = numbers[3];
    /* if any of the numbers are equal then print an error message then return False */
    if (a == b || a == c || b == c) {
        printf("error: two numbers entered are the same\n");
        return (0); /* returns False */
    }
    else {
        return (1); /* returns True */
    }
}


int print_largest(int argc, int numbers[])
{
    // a nice while loop that compares the first number in the array with the next number and
    //if the next number is larger then the first, then it is changed to the larger number
    int i = 1;
    while (i < argc -1) {
        if (numbers[1] < numbers[i + 1]) {
            numbers[1] = numbers[i + 1];
        }
        ++i;
    }
    printf("%d is the largest number.\n",numbers[1]);
}