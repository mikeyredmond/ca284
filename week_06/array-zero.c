/*
 array-zero.c
 author Michael Redmond
 */

/* includes*/
#include <stdio.h>

/* Function: Main
 parameters: void
description: print contents of an array using pointers
 */

int main (void)
{

	#define MAX 10
	int array[10];
    int i = 0;
	int *ptr = array;
	for (i = 0; i< MAX; i++)
		*(ptr + i) = 0;

	for (i =0; i <MAX; i++)
		printf ("%d\n",*(ptr + i));
	return (0);
}