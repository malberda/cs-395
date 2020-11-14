/*********************************************
 * Id: albe6306
 * w07.c
 * this code solves the cyclic tower of hanoi problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w05  
 *********************************************/
//printaction(int a, int b);
void towerofhanoi2(int n, char from, char to, char extrarod);
void towerofhanoi1(int n, char from, char to, char extrarod);
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//main function, takes input from user on command line and runs the tower of hanoi problem
int main(int argc, char *argv[])
{
   int i;
   i=atoi(argv[1]);

   towerofhanoi2(i, 'A', 'B', 'C');


   return 0;
}
//recursive tower of hanoi solution algorithm move two spaces
void towerofhanoi2(int n, char from, char to, char extrarod)
{
   if(n==1)
   {
      printf("MOVE %c TO %c\n", from, to);
      printf("MOVE %c TO %c\n", to, extrarod);

   }

   else
   {
      towerofhanoi2(n-1, from, to, extrarod);
      printf("MOVE %c TO %c\n", from, to);
      towerofhanoi1(n-1, extrarod, from, to);
      printf("MOVE %c TO %c\n", to, extrarod);
      towerofhanoi2(n-1, from, to, extrarod);
   }
}
//recrusive tower of hanoi move 1 space
void towerofhanoi1(int n, char from, char to, char extrarod)
{
   if(n==1)
   {

      printf("MOVE %c TO %c\n", from, to);
      
   }

   else
   {
      towerofhanoi2(n-1, from, to, extrarod);
      printf("MOVE %c TO %c\n", from, to);
      towerofhanoi2(n-1, extrarod, from, to);

   }



}
