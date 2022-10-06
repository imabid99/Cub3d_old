#include <stdio.h>
#include <math.h>

int main () {
   float py, ts, val3, val4;

   py = 68;
   ts = 64;

   printf("Value1 = %f\n", ((py / ts) * ts));
   printf("Value1 = %f\n", (floor(py / ts) * ts));
   
   return(0);
}