/*
leap-years.c
author Michael Redmond
*/

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions I may need*/

/* Functions: Main and leap_year
parameters: int argc (argument count) in all functions function
char *argv[] an array of command-line arguments in all functions function
description:  The main function calls the leap_year function which prints all leap
years between the first and second numbers.
 */

// Forward declaration
int leap_year(int argc, int numbers[]);

int main(int argc, char *argv[2])
{
    /* new array of integers */
    int numbers[3];
    numbers[1] = atoi(argv[1]);
    numbers[2] = atoi(argv[2]);
    /* call the check function, if it returns True then call the leap_year function */
    leap_year(argc, numbers);
    return (0); /* exit correctly*/
} /* end program*/


int leap_year(int argc, int numbers[])
{
    /* variable initialisation */
    int start_year, end_year = 0;
    int i = 1;
    /* all command-line arguments come in as character strings, so atoi turns them into ints*/
    start_year = numbers[1];
    end_year = numbers[2];
    /* while loop to start us off */
    while (start_year <= end_year) {
        /* if year is divisible by four */
        if (start_year % 4 == 0) {
            /* cenurial years are only leap years if they're also divisible by 400 */
            if (start_year % 100 == 0 && start_year % 400 == 0) {
                printf("%d\n",start_year);
            }
            /* this else if statement prints the rest of the leap years that aren't
            centurial years */
            else if (start_year % 100 != 0) {
                printf("%d\n",start_year);
            }
        }
        ++start_year;
    }
}

