/*
substring.c
author Michael Redmond
*/

/* includes libraries I may need*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/* Forward declaration of functions */
int first_check(char *string, char *second_string);
void second_check(char *string, char *second_string);


/* Functions: main, check, convert
parameters: int argc (argument count)
char *string a string input by the user when asked to
char *second_string a substring input by the user when asked to
description:  Main checks if there are more than are more than one command-line arguments input by the user, if so it will
cause an error, so the user can only input the program name. If the user only inputs the program name, Main will call the first
check function and asks the user to input a string. It checks to see that input is made up of either upper or lowercase letters,
if input is valid it then asks for the user to input a substring. The input is checked again for upper and lowercase letters.
If it is made up of only letters then a void function is called to carry out the second check to see if it is a substring, this void function prints whether it is or not.
*/


int main(int argc)
{
    /* variable initialisation */
    char string[50];
    char second_string[50];
    if (argc > 1) {
        printf("No command line arguments allowed.\n");
        return (0);
    }
    else {
        if (first_check(string, second_string)) { // input is asked for in here and if it is valid it will carry out the void function which will check if the second string is a substring.
            second_check(string, second_string);
        }
    }
	return (0);
}

int first_check(char *string, char *second_string)
{
    int i;
    printf("Enter the first string:\n"); // this prints a prompt for the user
    scanf("%s", string); // takes input from the user and stores it in string
    for (i = 0; string[i] != '\0'; ++i) {
        if (!isalpha(string[i])) { // if a character isn't an uppercase or lowercase letter print an error
            printf("Invalid character entered\n");
            return (0); /* return False and exit program */
        }
    }
    printf("Enter the second string:\n"); // this prints a second prompt for the user
    scanf("%s", second_string);
    for (i = 0; second_string[i] != '\0'; ++i) {
        if (!isalpha(second_string[i])) { // if a character isn't an uppercase or lowercase letter print an error
            printf("Invalid character entered\n");
            return (0); /* return False and exit program */
        }
    }
    return *string;
}

// void function to check whether the second string is a substring or not.
void second_check(char *string, char *second_string)
{
    int i = 0;
    int j = 0;
    while (string[i] != '\0' && second_string[j] != '\0') {
        if (string[i] != second_string[j]) {
            ++i;
            j = 0;
        }
        else {
            ++j;
            ++i;
        }
    }
    if (second_string[j] == '\0') {
        printf("the string '%s' is contained in the string '%s'\n", second_string, string);
    }
    else {
        printf("the string '%s' is not contained in the string '%s'\n", second_string, string);
    }
}