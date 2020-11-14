/*********************************************
 * Id: albe6306
 * w05.c
 * this program solves a matrix using Gaussian Elimination.
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w05  
 *********************************************/
void towerofhanoi(int n);
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//main function, takes input from user on command line and runs the tower of hanoi problem
int main(int argc, char *argv[])
{
   int i;
   i=atoi(argv[1]);
   towerofhanoi(i);

   return 0;
}
//iterative tower of hanoi solution algorithm
void towerofhanoi(int n)
{
   int i;
   int towers[n];
   for(i=0;i<n;i++)
   {
      towers[i]=0;
   }
   char from;
   char to;

   int tempmin[2];
   int max=1;
   for(i=0;i<n;i++)
   {
      max=max*2;
   }

   int j;
   for(j=1;j<max-1;j++)
   {
      if(j%2==1)
      {
         if(n%2==0)//move smallest disk right
         {
            if(towers[0]==0)
            {from = 'A'; to = 'B';}
            else if(towers[0]==1)
            {from = 'B'; to = 'C';}
            else if(towers[0]==2)
            {from = 'C'; to = 'A';}
            towers[0]++;
            towers[0]=towers[0]%3;
         }
         else if(n%2==1)//move smallest disk left
         {
            if(towers[0]==0)
            {from = 'A'; to = 'C';}
            else if(towers[0]==1)
            {from = 'B'; to = 'A';}
            else if(towers[0]==2)
            {from = 'C'; to = 'B';}
            towers[0]++;//move smallest disk left
            towers[0]++;
            towers[0]=towers[0]%3;

         }         



      }
      else//move furthest left disk to possible tower
      {  
         tempmin[0]=2;
         for(i=1;i<n;i++)
         {
            if(towers[i]<tempmin[0])
            {
               tempmin[1]=i;//1 is disk number, 0 is initial placement
               tempmin[0]=towers[i];
            }
         }
         printf("%d %d \n",tempmin[0],tempmin[1]);

         if(towers[0]==0)
         {
            from = 'C'; to = 'B';towers[tempmin[1]]=2;
         }
         else  if(towers[0]==1)
         {
            from = 'A'; to = 'C';towers[tempmin[1]]=0;
         }
         else if(towers[0]==2)
         {
            from = 'A'; to = 'B';towers[tempmin[1]]=1;
         }   

      }

      printf("MOVE %c TO %c\n", from, to);
   }

}



