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
int is_odd(int len, int numbers[], int odd);
int is_even(int len, int numbers[], int even);
int is_prime(int len, int numbers[], int prime);


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
    int numbers[argc];
    int i;
    if (argc == 1) {
        printf("insufficient command line arguments.\n");
        return (0); /* return False and exit program */
    }
    if (check(argc, argv, numbers)) { /* If all of the numbers inputted by the user were positive and digits then make a new array with those values */
        for (i = 0; i < argc; ++i) {
            numbers[i - 1] = atoi(argv[i]);
        }
        int len = sizeof(numbers) / sizeof(numbers[0]);
        /* Initialising counts for odd, even and prime functions */
        int odd = 0;
        int even = 0;
        int prime = 0;
        /* set each count equal to its corresponding function's return value */
        odd = is_odd(len, numbers, odd);
        even = is_even(len, numbers, even);
        prime = is_prime(len, numbers, prime);
        printf("Number of odd numbers: %d\nNumber of even numbers: %d\nNumber of prime numbers: %d\n", odd, even, prime);
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

/* checks how many odd numbers (if any), are in the array and returns a count of them */
int is_odd(int len, int numbers[], int odd)
{
    int i;
    for (i = 0; i < len - 1; ++i) {
        if (numbers[i] % 2 == 1) { /* checks to see if number is odd */
            odd += 1;
        }
    }
    return odd;
}

/* checks how many even numbers (if any), are in the array and returns a count of them */
int is_even(int len, int numbers[], int even)
{
    int i;
    for (i = 0; i < len - 1; ++i) {
        if (numbers[i] % 2 == 0 && numbers[i] != 0) { /* checks to see if number is even, also eliminates 0 from being even */
            even += 1;
        }
    }
    return even;
}

/* checks how many prime numbers (if any), are in the array and returns a count of them */
int is_prime(int len, int numbers[], int prime)
{
    int i, j;
    int number = 0;
    for (i = 0; i < len - 1; ++i) {
        bool result_num = true; /* result_num will be set to false if the number inside the array isn't prime */
        for(j = 2; j * j <= numbers[i]; ++j) {
            if (numbers[i] % j == 0) {
                result_num = false;
                break;
            }
        }
        if (result_num && numbers[i] != 1 && numbers[i] != 0) { /* if result_num is True and not equal to either both 1 and 0, then it is a prime number so the count increments by 1 */
            prime += 1;
        }
    }
    return prime;
}