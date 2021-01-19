#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[1])
{
   int day = 0;
   day = atoi(argv[1]);
   if (day == 1) {
      printf("Sunday\n");
   }

   else if (day == 2) {
      printf("Monday\n");
   }

   else if (day == 3) {
      printf("Tuesday\n");
   }

   else if (day == 4) {
      printf("Wednesday\n");
   }

   else if (day == 5) {
      printf("Thursday\n");
   }

   else if (day == 6) {
      printf("Friday\n");
   }

   else if (day == 7) {
      printf("Saturday\n");
   }

   return (0);
}