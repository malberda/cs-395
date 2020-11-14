/*********************************************
 * Id: albe6306
 * w09.c
 * this code solves the 9th weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w09  
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
void SS(int A[], int length);
void printArray(int A[], int length);
//main function, takes input from user on command line and runs the tower of hanoi problem
int main(int argc, char *argv[])
{
   int Arr[argc-1];
   int i;
   for(i=1;i<argc;i++){
      Arr[i-1]=atoi(argv[i]);
   }

   SS(Arr, argc-1);


   return 0;
}

//actual sorting code
void SS(int A[], int length)
{
   printArray(A, length);
   int i;
   int j;
   int min;
   int temp;
   for(i=0;i<length-1;i++)
   {
      min=i;
      for(j=i+1;j<length;j++)
      {
         if(A[j]<A[min])
         {
            min=j;
         }
      }
      temp=A[min];
      A[min]=A[i];
      A[i]=temp;
      printArray(A, length);
   }
 
}
//print function
void printArray(int A[], int length)
{
   int i;
   for(i=0;i<length;i++)
   {
      printf("%d ",A[i]);
   }
   printf("\n");
}