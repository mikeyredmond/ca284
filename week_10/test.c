#include <stdio.h>
int main(void)
{
    char *string;
    printf("Please enter a string: \n");
    gets(string);
    printf("%s\n", string);
}