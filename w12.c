/*********************************************
 * Id: albe6306
 * w11.c
 * this code solves the 10th weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w11  
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>



void getruntimeQS(int arr[], int l, int r, int count);
int HoarePartition(int A[], int l, int r);
int getruntimeSel(int arr[], int size);
int getruntimeIns(int arr[], int size);
void randomarr(int A0[], int l0, int A1[], int l1, int A2[], int l2);

//main function, takes input from user on command line and runs the iterative sort
int main()
{

   int runtime[9];
   int size[3];

   size[0]=10000;
   int arr0[size[0]];
   
   size[1]=25000;
   int arr1[size[1]];

   size[2]=50000;
   int arr2[size[2]];
   

   struct timeval start, stop;

   randomarr(arr0, size[0], arr1, size[1], arr2, size[2]);
   
   gettimeofday(&start, NULL);
   getruntimeQS(arr0, 0, size[0], 0);
   gettimeofday(&stop,NULL);
   int selection1Time=(double)(stop.tv_sec - start.tv_sec) * 100000 + (double)(stop.tv_usec - start.tv_usec)/10;
   runtime[0]=selection1Time;

   gettimeofday(&start, NULL);
   getruntimeQS(arr1, 0, size[1], 0);
   gettimeofday(&stop,NULL);
   selection1Time=(double)(stop.tv_sec - start.tv_sec) * 100000 + (double)(stop.tv_usec - start.tv_usec)/10;
   runtime[1]=selection1Time;

   gettimeofday(&start, NULL);
   getruntimeQS(arr2, 0, size[2], 0); 
   gettimeofday(&stop,NULL);
   selection1Time=(double)(stop.tv_sec - start.tv_sec) * 100000 + (double)(stop.tv_usec - start.tv_usec)/10;
   runtime[2]=selection1Time;


   randomarr(arr0, size[0], arr1, size[1], arr2, size[2]);

   runtime[3]=getruntimeSel(arr0, size[0]);
   runtime[4]=getruntimeSel(arr1, size[1]);
   runtime[5]=getruntimeSel(arr2, size[2]);

   randomarr(arr0, size[0], arr1, size[1], arr2, size[2]);

   runtime[6]=getruntimeIns(arr0, size[0]);
   runtime[7]=getruntimeIns(arr1, size[1]);
   runtime[8]=getruntimeIns(arr2, size[2]);

   printf("//+-----------------------+-----------------+----------------+------------+\n");
   printf("//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |\n");
   printf("//+-----------------------+-----------------+----------------+------------+\n");
   printf("//|                  10000|               %d|              %d|          %d|\n", runtime[3], runtime[6], runtime[0]);
   printf("//|                  25000|               %d|              %d|          %d|\n", runtime[4], runtime[7], runtime[1]);
   printf("//|                  50000|               %d|              %d|          %d|\n", runtime[5], runtime[8], runtime[2]);
   printf("//+-----------------------+-----------------+----------------+------------+\n");



   return 0;

}
//quicksort function
void getruntimeQS(int arr[], int l, int r, int count)
{
   int s;

   if(l<r)
   {
      s=HoarePartition(arr,l,r);
      getruntimeQS(arr, l, s-1, count+1);
      getruntimeQS(arr, s+1, r, count+1);
   }   


}
//horace partition program
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

//selection sort 
int getruntimeSel(int arr[], int size)
{
   struct timeval start, stop;
   gettimeofday(&start, NULL);
   
   int i;
   int j;
   int min;
   int temp;
   for(i=0;i<size-1;i++)
   {
      min=i;
      for(j=i+1;j<size;j++)
      {
         if(arr[j]<arr[min])
         {
            min=j;
         }
      }
      temp=arr[min];
      arr[min]=arr[i];
      arr[i]=temp;
   }

   gettimeofday(&stop,NULL);
   int selection1Time=(double)(stop.tv_sec - start.tv_sec) * 100000 + (double)(stop.tv_usec - start.tv_usec)/10;
   return selection1Time;
}
//insertion sort
int getruntimeIns(int arr[], int size)
{
   struct timeval start, stop;
   gettimeofday(&start, NULL);
   

   int i;
   int v;
   int j;
   for (i=1;i<=size-1;i++)
   {
      v=arr[i];
      j=i-1;
      while((j>=0) && (arr[j]>v))
      {
         arr[j+1]=arr[j];
         j=j-1;
      }
      arr[j+1]=v;

   }

   gettimeofday(&stop,NULL);
   int selection1Time=(double)(stop.tv_sec - start.tv_sec) * 100000 + (double)(stop.tv_usec - start.tv_usec)/10;
   return selection1Time;
}
//randomize array
void randomarr(int A0[], int l0, int A1[], int l1, int A2[], int l2)
{
   srand(time(NULL));
   int i;
   for(i=0;i<l0;i++)
   {
      A0[i]=rand()%10;
   }
   for(i=0;i<l1;i++)
   {
      A1[i]=rand()%10;
   }
   for(i=0;i<l2;i++)
   {
      A2[i]=rand()%10;
   }


}


//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                  10000|            14480|            7384|          64|
//|                  25000|            90508|           46354|         168|
//|                  50000|           362363|          184602|         353|
//+-----------------------+-----------------+----------------+------------+

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                  10000|            14499|            7490|          64|
//|                  25000|            90628|           46412|         170|
//|                  50000|           362425|          184299|         348|
//+-----------------------+-----------------+----------------+------------+

//+-----------------------+-----------------+----------------+------------+
//|    Number of Elements |  Selection Sort | Insertion sort |  Quicksort |
//+-----------------------+-----------------+----------------+------------+
//|                  10000|            14497|            7355|          65|
//|                  25000|            90506|           46402|         170|
//|                  50000|           362132|          183485|         347|
//+-----------------------+-----------------+----------------+------------+













