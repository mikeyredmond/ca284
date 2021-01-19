#include <stdio.h>

int swap (int a, int b);

int main ()
{

	int a=5;
	int b=6;

	printf ("Before the swap function the value of a is: %d\nBefore the swap function the value of b is: %d\n\n",a,b);
	swap(a,b);
	printf("The value of a after the swap function is: %d\nThe value of b after the swap function is: %d\n\n",a,b);
}

int swap(int a,int b)
{
	int temp =0;

	temp = a;
	a = b;
	b = temp;

	printf("The value of a at the end of the swap function is: %d\nThe value of b at the end of the swap function is: %d\n\n",a,b);
	return (0);
}