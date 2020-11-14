/*********************************************
 * Id: albe6306
 * w03.c
 * this program raises two to the power n recersively.
 *********************************************/
int recursen(int n);
#include<stdlib.h>
#include <stdio.h>
//main function, takes input from user on command line and outputs 2^n after calling recursive function.
int main(int argc, char *argv[])
{

   int n;
   n=atoi(argv[1]);
   if(n<1){
      printf("%d\n", 1);
      return 0;
   }

   int fin=recursen(n);
   printf("%d\n", fin);
   return 0;

}

//recurse function for 2^n
int recursen(int n)
{
   if(n==0){return 1;}
   else{
   return (recursen(n-1)+recursen(n-1));}
}