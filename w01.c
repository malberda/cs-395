/*********************************************
 * Id: albe6306
 *
 * this program find the smallest distance between two points in an array.
 *********************************************/
int MinDistance(int A[], int n);

#include<stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{			//accepts command line arguments, inputs into mindistance
   int i; int vec[argc]; vec[0]=argc;

   for(i=1;i<argc;i++)
   {vec[i]=atoi(argv[i]);}	//convert char to int 
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
      for(j=i+1;j<n;j++){			//check every combination
         if(i!=j){if(abs(A[i]-A[j])<dmin){dmin=abs(A[i]-A[j]);}}
      }
   }
   return dmin;  //returns minimum
}
