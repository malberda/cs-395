/*********************************************
 * Id: albe6306
 * w17.c
 * this code solves the 17 weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w17 
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int RobotCoinCollection( int n, int m, int  C[n][m]);
int MAX(int i, int j);

int main(int argc, char *argv[])
{
   int size1=atoi(argv[1]);
   int size2=atoi(argv[2]);
   int arr[size1][size2];
   int i, j;

   int q;

   for(i=0;i<size1;i++){
      for(j=0;j<size2;j++){
         q=strcmp(argv[i*size2+j+3],"X");
         if(q!=0)
         {arr[i][j]=atoi(argv[i*size2+j+3]);}
         else
         {arr[i][j]=10; }
      }
   }
   printf("Board Inputed:\n");
   for(i=0;i<size1;i++)
   {
      for(j=0;j<size2;j++)
      {
         if (arr[i][j]!=10)
         printf("%d\t",arr[i][j]);
         else
         printf("%c\t",'X');
      }
      printf("\n");
   }
   int total=RobotCoinCollection( size1, size2, arr);
   printf("\nThe optimal path with this board is: %d\n",total);

   return 0;
}
//main function
int RobotCoinCollection( int n, int m, int C[][m])
{
   int F[n][m];
   F[0][0]=C[0][0];
   int i,j;
   for (j=1;j<m;j++)
   {
      if(C[0][j]!=10)
      F[0][j]=F[0][j-1]+C[0][j];
      else
      {
         F[0][j]=0;
         for(j=j;j<m;j++)
         {
            F[0][j]=0;
         }
      }
   }
   for (i=1;i<n;i++)
   {
      if(C[i][0]!=10)
      F[i][0]=F[i-1][0]+C[i][0];
      else
      {
         F[i][0]=0;
         for(i=i;i<m;i++)
         {
            F[i][0]=0;
         }
      }

   }
   for (i=1;i<n;i++)
   {
      for (j=1;j<m;j++)
      {
         if(C[i][j]!=10)
         F[i][j]=MAX(F[i-1][j],F[i][j-1])+C[i][j];
         else
         F[i][j]=0;
      }
   }

   printf("\nCoin Collecting Table:\n");
   for(i=0;i<n;i++)
   {
      for(j=0;j<m;j++)
      {
         printf("%d\t",F[i][j]);
      }
      printf("\n");
   }

   return F[n-1][m-1];
}
// max function, could have done it in code but am too lazy
int MAX(int i, int j)
{
   if(i<j)
   return j;
   else
   return i;
}

