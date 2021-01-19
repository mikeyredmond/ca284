#include <stdio.h>
//this is for storing numbers
int main()
{

    float inch; //this makes a vairable for you to store the value in
    int cm;

    printf("Enter an Amount in Centimetres: "); //this prints a prompt for the user
    scanf("%d", &cm); //this takes in the argument given and stores it
                       //into the address of age
    inch = cm / 2.54;
    printf("The Amount in Inches is: %.2f\n", inch);

	return 0;
}