/*
 cylinder-area.c
 author Michael Redmond
 */

/* includes*/
#include <stdio.h>
#include <stdlib.h> /* contains functions we may need*/

#define PI 3.1415 /*Defining PI as a constant*/

/* Function: Main
 parameters: int argc (argument count)
 char *argv[] an array of command-line arguments
description:  Takes two arguments, radius and height then computes area of cylinder
 */

int main(int argc, char *argv[1])
{
/* variable initialisation */
int radius = 0;
int height = 0;
int radius_squared = 0;
    float area = 0.0;
/* all command-line arguments come in as character strings, so atoi turns them into ints*/
radius = atoi(argv[1]);
height = atoi(argv[2]);

radius_squared = radius*radius; /* radius squared */

area  = 2*PI*radius*height+2*PI*radius_squared; /* calculate area of cylinder */

    /* print to two decimal places*/
    printf ("%.2f\n",area);
    return (0); /* exit correctly*/
} /* end program*/