#include <stdio.h>

int main(void)
{
    char name[20];
    printf("Enter your name: ");
    //scanf("%s", &name);  - deprecated
    fgets(name,20,stdin);
    printf("Hello %s\n", name);
    return 0;
}