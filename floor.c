#include <stdio.h>
#include <math.h>

int main () {
   float val1, val2, val3, val4;

   val1 = 270;
   val2 = 64;
   val3 = 64;

   printf("Value1 = %f\n", (floor(val1 / val2) * val3));
   
   return(0);
}