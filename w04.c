/*********************************************
 * Id: albe6306
 * w04.c
 * this program solves a matrix using Gaussian Elimination.
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w04  
 *********************************************/
void printmatrix(int m, int n, float A[n][m]);
#include<stdlib.h>
#include <stdio.h>
//main function, takes input from user on command line and outputs 2^n after calling recursive function.
int main(int argc, char *argv[])
{
   int n=atoi(argv[1]);
   float Arr[n][n+1];

   int i; int j; int k;
   for(i=0;i<n;i++){
      for(j=0;j<n+1;j++){
         Arr[i][j]=atoi(argv[(n+1)*i+j+2]);
      }
   }
   printmatrix(n+1, n, Arr);

   for (i=0;i<=n-2;i++)
   {
      for (j=i+1;j<=n-1;j++)
      { 
         float tempji=Arr[j][i];
         for(k=i;k<=n;k++){
            Arr[j][k]=Arr[j][k]-((Arr[i][k] * tempji) / Arr[i][i]);
         }
      }
      printmatrix(n+1, n, Arr);
   }

   return 0;
}
//prints matrix given length, width, and values
void printmatrix(int m, int n, float A[n][m])
{
   int i;int j;
   for(i=0;i<n;i++){
      for(j=0;j<m;j++){
         printf("%.2f", A[i][j]);
         printf(" ");
      }
      printf("\n");
   }
   printf("\n");
}
