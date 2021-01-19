#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main (int argc, char *argv[])
{
    printf("Number of bits in a char type:\t\t%d\n", CHAR_BIT);
    printf ("Size of a char is:\t\t%zu byte\n",sizeof(char)); /* sizeof returns a size of a thing %zu prints sizeof*/
    printf("Maximum value of char:\t\t%d\n", CHAR_MAX);

    printf("Minimum Value of char:\t\t%d\n", CHAR_MIN);
    printf("The size of an int is:\t\t%zu bytes\n",sizeof(int));
    printf("maximum value of int:\t\t%d\n", INT_MAX);
    printf("Minimum value of int:\t\t%d\n", INT_MIN);
    printf("Maximum value of long int:\t\t%ld\n", (long) LONG_MAX);
    printf("Minimum value for long int:\t\t%ld\n", (long) LONG_MIN);
    printf("You are recommended to do some research and customise this program to your own needs\n\n");

    return 0;
}