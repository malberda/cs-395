/*********************************************
 * Id: albe6306
 * w18.c
 * this code solves the 18 weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w18 
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int checkclique(int size, int arr[][size], int i, int clique[], int total);
int aintnobodyfresherthanmymfingclique(int size, int arr[][size]);

int main(int argc, char *argv[])
{
   int size=atoi(argv[1]);
   int arr[size][size];
   int i, q, j, temp;
   j=0;
   for(q=0;q<size-1;q++)
   {
      temp=0;
      for(i=q+1;i<size;i++)
      {
         arr[q][i]=atoi(argv[2+j+temp]);
         temp++;
      } 
      j+=temp;
   }




   for(i=0;i<size;i++)
   {
      for(j=0;j<i+1;j++)
      {
         arr[i][j]=0;
      }
   }   

   for(i=0;i<size;i++)
   {
      for(j=0;j<size;j++)
      {
         arr[j][i]=arr[i][j];
      }
   }   

   for(i=0;i<size;i++)
   {
      for(j=0;j<size;j++)
      {
         printf("%d ",arr[i][j]);
      }
      printf("\n");
   }

   int result = aintnobodyfresherthanmymfingclique(size, arr);

   for(i=size;i>0;i--)
   {
      if(result<i)
      printf("No clique found of size %d\n",i);
      if(result==i)
      printf("Clique found of size %d\n",i);

   }
   
   return 0;
}

//yeezy yeezy, why so easy?
int aintnobodyfresherthanmymfingclique(int size, int arr[][size])
{
   int i,j,q,k,sum,largestclique;
   largestclique=2;
   int clique[size];
   sum=1;
   for(q=0;q<size;q++)
   { 
      for(j=0;j<size;j++)
      {
         clique[j]=0;
      }
      clique[q]=1;
      for(i=0;i<size;i++)
      {
         k=0;
         if(arr[q][i]==1)
         {k=checkclique(size, arr, i, clique, sum);}//printf(" location searched %d %d\n",q,i);}
         if(k==1)
         {sum++; clique[i]=1;}
      }

      if(sum>largestclique)
      largestclique=sum;
      //printf("sum %d clique %d",sum, largestclique);
      sum=1;

   }
   return largestclique;
}

//checks if makes clique with existing clique
int checkclique(int size, int arr[][size], int i, int clique[], int total)
{
   int j;
   int sum=0;
   for(j=0;j<size;j++)
   {
      if(clique[j]==1&&arr[i][j]==1)
      {
         sum++;
      }
   }
   if(sum==total)
   return 1;
   else
   return 0;
}



