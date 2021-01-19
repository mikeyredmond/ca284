#include <stdio.h>
#define MAXLINE 1000
/* copy:  copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]);
int main()
{
	char from[MAXLINE];
	char to[MAXLINE];
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
	printf("%s", to);
	return 0;
}
