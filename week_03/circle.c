#include <stdio.h>

#define PI 3.1415

void calculateArea (int radius, float *area); /* function definition that returns nothing gives it a type SEMICOLON REQUIRED*/

int main (void)
{

int radius = 0;
float circleArea = 0.0;

printf ("Enter the radius for the circle: ");;
scanf("%d",&radius); /*formatted input from user and stores it at memory address of radius*/
calculateArea (radius, &circleArea); /*passing in value of radius which isn't being changed and address of circleArea which value will be changed*/

printf ("The area of the circle is: %.2f\n",circleArea); /* output is formatted to print 6 characters before the decimal point and 2 after it*/
return (0);
}

void calculateArea (int radius, float *circleArea) /*takes the value of circleArea from main NO SEMICOLON as we are calling the function*/
{

*circleArea = PI*(radius*radius); /* value of circleArea is now the result of this calculation*/
}