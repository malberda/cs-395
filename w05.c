/*********************************************
 * Id: albe6306
 * w05.c
 * this program solves a matrix using Gaussian Elimination.
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w05  
 *********************************************/
//printaction(int a, int b);
void towerofhanoi(int n, char from, char to, char extrarod);
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//main function, takes input from user on command line and runs the tower of hanoi problem
int main(int argc, char *argv[])
{
   int i;
   i=atoi(argv[1]);
   towerofhanoi(i, 'A', 'C', 'B');


   return 0;
}
//recursive tower of hanoi solution algorithm
void towerofhanoi(int n, char from, char to, char extrarod)
{
   if (n==1) 
   printf("MOVE %c TO %c\n", from, to);

   else
   {
      towerofhanoi(n-1, from, extrarod, to);
      printf("MOVE %c TO %c\n", from, to);
      towerofhanoi(n-1, extrarod, to, from);

   }



}


