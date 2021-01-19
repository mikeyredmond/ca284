#include <stdio.h>
#include <stdlib.h>

int main (void)
{

char letter = 'a';

// char *letterptr = NULL; the pointer is pointing to a mem. address which does not exist since its set to NULL */

char *letterptr = &letter;

printf ("the initial value of letterptr is: %c\n\n",*letterptr);
printf("The thing pointed to by letterptr is: %p\n\n",letterptr);

letterptr = &letter;

printf ("Now the value of letterptr is: %c\n\nAnd now The // thing pointed to by letterptr is: %p\n",*letterptr,letterptr);

}