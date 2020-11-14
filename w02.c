/*********************************************
 * Id: albe6306
 *w02.c
 * this program find the smallest distance between two points in an array. more efficiently than w01.c
 *********************************************/
int MinDistance(int A[], int n);
void quicksort(int *A[], int low, int high);
int partition(int *A[], int low, int high);
#include<stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{			//accepts command line arguments, inputs into mindistance
   int i; int vec[argc]; vec[0]=argc;

   for(i=1;i<argc;i++)
   {vec[i]=atoi(argv[i]);}	//convert char to int 
for(i=1;i<argc;i++){printf("%d\n", vec[i]);}
   quicksort(vec, vec[1], vec[argc]);
for(i=1;i<argc;i++){printf("%d\n", vec[i]);}

   int dmin=MinDistance(vec, argc);	//call func

   printf("%d\n", dmin);
   return 0;
}

//checks distance between all objects in array, returns smallestdistance
int MinDistance(int A[],int n) 
{
 
   int dmin=abs(A[3]-A[2]);
   int i; int j;
   for(i=1;i<n;i++){
      for(j=1;j<n;j++){			//check every combination
         if(i!=j){if(abs(A[i]-A[j])<dmin){dmin=abs(A[i]-A[j]);}}
      }
   }
   return dmin;  //returns minimum
}

void quicksort(int *A[], int low, int high)
{
   if(low<high)
      {int index=partition(A, low, high);

      quicksort(A, low, index-1);
      quicksort(A, index+1, high);
   }
}

int partition(int *A[], int low, int high)
{
   int temp;
   int pivot=A[high];
   int i=low-1;
   int j;
   for (j=low;j<=high-1;j++)
   {
      if(A[j]<pivot)
      {
         i++;
	 temp=(A+1);
	 A[i]=A[j];
	 A[j]=temp;
      }
   }
   temp=A[i+1];
   A[i]=A[j];
   A[j]=temp;
   return (i+1);

}
