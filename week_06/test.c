/*
count-numbers.c
author Michael Redmond
*/

/* includes libraries I may need*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/* Forward declaration of functions */
int check(int argc, char *argv[], int numbers[]);
void secondLargest(int *numbers, int *index, int len);


/* Functions: main, check, is_odd, is_even, is_prime
parameters: int argc (argument count)
char *argv[] an array of command-line arguments
int len (length of the new array of numbers)
int numbers[] (new array of integers input by the user)
int odd, even, prime are all counts for their respective functions
description:  Takes any amount of command-line arguments and computes firstly that
there are no negative numbers or non-digits, otherwise an error will appear, if all numbers are positive it
computes how many numbers are odd, even, or prime.
*/


int main (int argc, char *argv[])
{
    /* variable initialisation */
    int numbers[argc - 1];
    int index = 0;
    int i;
    if (argc == 1 || argc == 2) {
        printf("insufficient command line arguments.\n");
        return (0); /* return False and exit program */
    }
    if (check(argc, argv, numbers)) { /* If all of the numbers inputted by the user were positive and digits then make a new array with those values */
        for (i = 0; i < argc; ++i) {
            numbers[i - 1] = atoi(argv[i]);
        }
        int len = sizeof(numbers) / sizeof(numbers[0]);
        secondLargest(numbers, &index, len);
    }
}

/* checks to see if numbers are negative or if non-digits are in the input, exits program if it fails any */
int check(int argc, char *argv[], int numbers[])
{
    int i, j;
    for (i = 1; i < argc; ++i) {
        for (j = 0; j < strlen(argv[i]); ++j) {
            if (*argv[i] == '-') {
                printf("Error: Only positive integers are permitted.\n"); // if number is negative print an error message and exit the program
                return (0); /* returns False */
            }
            if (!isdigit(argv[i][j])) {
                printf("Error: only numbers are permitted.\n");
                return (0); /* return False and exit program */
            }
        }
    }
    return (1); // returns True
}

// this function finds out the second largest element in the array, index is a pointer to the position of the second largest integer, len is
// the amount of numbers entered by the user
void secondLargest(int *numbers, int *index, int len)
{
    int i;
  	int first = 0;
	for (i = 0; i < len; ++i) {
		if (numbers[i] > first) { // if the current element is bigger than first, update it and change index's value to first's previous value
		    *index = first;
			first = numbers[i];
		}
		else if (numbers[i] > *index && numbers[i] != first) { // if the current value is greater than index and not the same as first, set index's value to it
			*index = numbers[i];
        }
	}
	if (*index != 0) { // this if statement shows that index's value has changed so now it will print the second largest value
        printf("The second largest element is %d\n", *index);
    }
	else { // this else statement means that index's value hasn't changed so all values were equal
        printf("There is no second largest element\n");
    }
}