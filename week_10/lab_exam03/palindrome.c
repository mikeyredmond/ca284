/*
palindrome.c
author Michael Redmond
*/

/* includes libraries I may need*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/* Forward declaration of functions */
void check(char* fstring, char* nstring);
void ispalindrome(char* nstring);

/* Functions: main, check, ispalindrome
parameters: int argc (argument count)
char *fstring the first string input by the user when asked to
char *nstring a new string made which is made up of the string without punctuation and spaces
description: This program prompts the user to input a string. If numbers are entered it will print an error message and exit the program. Otherwise it will
get rid of white space and punctuation and then checks if the string is a palindrome or not. It eventually returns and frees up memory used.
*/


int main(int argc)
{
    /* variable initialisation */
    char* fstring = NULL;
    char* nstring = NULL;
    if (argc > 1) { // check for excess command-line arguments
        printf("no command line arguments allowed.\n");
        return (0); /* return False and exit program */
    }
    check(fstring, nstring);
    if (fstring != NULL) { // freeing up memory used to hold data in the program
        free(fstring);
    }

    if (nstring != NULL) {
        free(nstring);
    }
    return (0);
}


void check(char* fstring, char* nstring)
{
    int i, j, len;
    fstring = malloc(100); // this allocates 100 bytes to fstring and tests to see if it has enough memory
    if (NULL == fstring)
    {
        printf("Out of memory.");
        return;
    }
    printf("Please enter a string:  \n");
    fgets(fstring, 100, stdin); // the maximum a user can input is 100 characters
    len = strlen(fstring);
    fstring = realloc(fstring, len * sizeof(char)); // re-allocate memory to the actual size inputted by the user to free up memory
    nstring = realloc(nstring, len * sizeof(char)); // re-allocate memory to the actual size inputted by the user for our new string
    for (i = 0; fstring[i] != '\0'; ++i) {
        if (isdigit(fstring[i])) {
            printf("Invalid input: Numbers not permitted.\n");
            return;
        }
    }
    for (i = 0, j = 0; fstring[i] != '\0'; ++i, ++j) {
        if (!isspace(fstring[i]) && !ispunct(fstring[i])) { // if a character isn't a space or punctuation character add it to the new string
            nstring[j] = tolower(fstring[i]); // converts any uppercase letters to lowercase letters as this will be needed by my ispalindrome function.
        }
        else {
            --j;
        }
    }
    ispalindrome(nstring); // call this function if input is valid
}

void ispalindrome(char* nstring) // this function checks whether the string is a palindrome or not.
{
    int left = 0;
    int right = strlen(nstring) - 1;
    while (right > left) {
        if (nstring[++left] != nstring[--right]) {
            printf("This string is not a palindrome.\n");
            return;
        }
    }
    printf("This string is a palindrome.\n");
    return;
}