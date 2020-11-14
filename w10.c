/*********************************************
 * Id: albe6306
 * w10.c
 * this code solves the 10th weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w10  
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
void QS(int A[], int l, int r);
int HoarePartition(int A[], int l, int r);
void printsubarray(int A[], int l, int h);
//main function, takes input from user on command line and runs the quicksort function
int main(int argc, char *argv[])
{
   int Arr[argc-1];
   int i;
   for(i=1;i<argc;i++)
   {
      Arr[i-1]=atoi(argv[i]);
   }
   QS(Arr, 0, argc-2);
   printsubarray(Arr, 0, argc-2);
   return 0;
}

//quicksort function
void QS(int A[], int l, int r)
{
   int s;
   if(l<r)
   {
      s=HoarePartition(A,l,r);
      QS(A, l, s-1);
      QS(A, s+1, r);
   }   

}

//partition function
int HoarePartition(int A[], int l, int r)
{
   int p;
   int i;
   int j;
   int temp;
   p=A[l];
   i=l;
   j=r+1; 
   
   do
   {
      do
      {
         i++;
      }while(A[i]<p);
      do
      {
         j--;
      }while(A[j]>p);
      temp=A[j];
      A[j]=A[i];
      A[i]=temp;
   }while(i<j);

   temp=A[j];
   A[j]=A[i];
   A[i]=temp;
   
   temp=A[j];
   A[j]=A[l];
   A[l]=temp;
   return j;
}

//print function
void printsubarray(int A[], int l, int h)
{
   int i;
   for(i=l;i<=h;i++)
   {
      printf("%d ",A[i]);
   }
   printf("\n");
}




