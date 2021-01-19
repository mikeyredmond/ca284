/*
case-converter.c
author Michael Redmond
*/

/* includes libraries I may need*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>

/* Forward declaration of functions */
int check(char *string);
void convert (char *string);


/* Functions: main, check, convert
parameters: int argc (argument count)
char *string a string input by the user when asked to
description:  Main checks if there are more than are more than one command-line arguments input by the user, if so it will
cause an error, so the user can only input the program name. If the user only inputs the program name, Main will call a
check function and asks the user to input a string. It checks to see that input is made up of either upper or lowercase letters,
if input is valid it then a void function is called to carry out the conversion, the converted string is then printed out by the main function.
*/


int main(int argc)
{
    char string[50];
    if (argc > 1) {
        printf("No command line arguments allowed.\n");
        return (0);
    }
    else {
        if (check(string)) { // input is asked for in here and if it is valid it will carry out the void function which will convert the string
            convert(string);
            printf("%s\n", string); // print the converted string
        }
    }
	return (0);
}

int check(char *string)
{
    int i;
    printf("Enter a string of upper and lower case letters\n"); // this prints a prompt for the user
    scanf("%s\n", string); // takes input from the user and stores it in string
    for (i = 0; string[i] != '\0'; ++i) {
        if (!isalpha(string[i])) { // if a character isn't an uppercase or lowercase letter print an error
            printf("Invalid character entered.\n");
            return (0); /* return False and exit program */
        }
    }
    return *string;
}

// void function to carry out the conversion without using builtin conversion functions
void convert(char *string)
{
    int i;
    for (i = 0; string[i] != '\0'; ++i) {
        if(string[i] >= 'A' && string[i] <= 'Z') {
            string[i] = string[i] + 32; // biwise conversion which flips bit 5 by adding 32 to it's decimal value so it is now lowercase
        }
        else if (string[i] >= 'a' && string[i] <= 'z') {
            string[i] = string[i] - 32; // biwise conversion which flips bit 5 by subtracting it's decimal value by 32 so it is now uppercase
        }
    }
}