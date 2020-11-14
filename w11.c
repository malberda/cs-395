/*********************************************
 * Id: albe6306
 * w11.c
 * this code solves the 10th weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w11  
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
void printarray(int A[], int l, int n);
void sort(int A[], int l);
//main function, takes input from user on command line and runs the iterative sort
int main(int argc, char *argv[])
{
   int Arr[argc-1];
   int i;
   for(i=1;i<argc;i++)
   {
      Arr[i-1]=atoi(argv[i]);
   }
   sort(Arr, argc-1);
   return 0;
}
//quicksort function
void sort(int A[], int l)
{
   printarray(A, l, 0);
   int i;
   int v;
   int j;
   for (i=1;i<=l-1;i++)
   {
      v=A[i];
      j=i-1;
      while((j>=0) && (A[j]>v))
      {
         A[j+1]=A[j];
         j=j-1;
      }
      A[j+1]=v;
      printarray(A, l, i);
   }
   printf("| \n");
}

//print function
void printarray(int A[], int l, int n)
{
   
   int i=0;
   for(i=0;i<l;i++)
   {
      if(i==n+1)
      printf("| ");

      printf("%d ",A[i]);
   }
   if(i!=n+1)
   printf("\n");
}




