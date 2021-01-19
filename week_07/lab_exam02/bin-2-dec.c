/*
bin-2-dec.c
author Michael Redmond
*/

/* includes libraries I may need*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* Forward declaration of functions */
int check(int len, char numbers[]);
void bin2dec(int len, char numbers[], long *dec);

/* Functions: main, check, bin2dec
parameters: int argc (argument count)
char *argv[] an array of command-line arguments
int len (length of the string)
char numbers[] holds the concatenated string made up of integers typed by user
long *dec will hold my newly converted decimal number
description:  Accepts up to 8 digits as command-line arguments, digits are either one or zero, no other input is valid.
If the already mentioned conditions are met then this program converts this string of binary digits to it's decimal equivalent.
*/


int main (int argc, char *argv[])
{
    /* variable initialisation */
    char numbers[9];
    int i;
    int len;
    long dec;
    /* for loop to make a new string of the digits input by the user */
    strcpy(numbers, argv[1]);
    if (argc > 1) {
        for (i = 2; i < argc; ++i) {
            strcat(numbers, argv[i]);
        }
    }
    len = strlen(numbers); /* length of string */
    if (check(len, numbers)) { /* if the input is binary then call the converting function */
        bin2dec(len, numbers, &dec);
        printf("%ld\n", dec); /* prints the decimal equivalent of input after it was passed by the void bin2dec function*/
    }
}

/* check function to see if there are too many digits entered, it also checks to see if any invalid digits were entered */
int check(int len, char numbers[])
{
    int i;
    if (len > 8) {
        printf("Too many binary digits entered.\n"); /* if more than 8 digits are entered return error */
        return (0);
    }
    for (i = 0; i < len; ++i) {
        if (numbers[i] == '0' || numbers[i] == '1') { /* if the string digit is a binary one then continue on */
            continue;
        }
        else {
            printf("Only digits 1 and 0 are permitted.\n"); /* returns error if non binary digit is entered */
            return (0);
        }
    }
    return (1); /* returns True if it is a binary */
}

/* void function to carry out the calculation as required */
void bin2dec(int len, char numbers[], long *dec)
{
    /* this function converts the string into a long integer */
    char *ptr;
    *dec = strtol(numbers, &ptr, 2); // takes my string and converts it to decimal, 2 at the end shows it is a binary number
}