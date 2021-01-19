#include <stdio.h>

int main(void)
{
    char name[20];
    //scanf("%s", &name);  - deprecated
    fgets(name,20,stdin);
    printf("Hello %s\n", name);
    return 0;
}