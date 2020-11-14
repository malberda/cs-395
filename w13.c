/*********************************************
 * Id: albe6306
 * w10.c
 * this code solves the 13th weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w13
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
int peasant(int m, int n, int result);
//main function, takes input from user on command line and runs the russian peasant multiplication
int main(int argc, char *argv[])
{
   int product;
   product=0;
   int m=atoi(argv[1]);
   int n=atoi(argv[2]);
   product=peasant(m, n, product);
   printf("%20s\n", "------");
   printf("%20d\n", product);

   return 0;

}

//peasant recursive function
int peasant(int m, int n, int result)
{
   printf("%6d %6d", m, n);  

   if(m==1)
   {
      printf("%7d\n", n);
      return n;
   } 
   if(m%2==1)
   {
      printf("%7d\n", n);
      result=n+peasant(m/2, 2*n, result);
      return result;
   }
   else if(m%2==0)
   {
      printf("\n");
      result=peasant(m/2, 2*n, result);
      return result;
   }
   
   return result;
}