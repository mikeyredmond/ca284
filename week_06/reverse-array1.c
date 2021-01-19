#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[5])
{
    char **values = argv;
    int i = 0;
    for (i = 1; i < argc - 1; ++i){
        printf("%s\n", values[i]);
    }
    printf("\n");
    for (i = argc - 2; i > 0; --i){
        printf("%s\n", values[i]);
    }
    return (0);
}