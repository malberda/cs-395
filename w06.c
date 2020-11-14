/*********************************************
 * Id: albe6306
 * w06.c
 * this code solves the restricted tower of hanoi problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w05  
 *********************************************/
//printaction(int a, int b);
void towerofhanoi(int n, char from, char to, char extrarod);
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
//main function, takes input from user on command line and runs the restricted tower of hanoi problem
int main(int argc, char *argv[])
{
   int i;
   i=atoi(argv[1]);
   towerofhanoi(i, 'A', 'B', 'C');


   return 0;
}
//restricted tower of hanoi solution algorithm
void towerofhanoi(int n, char a, char b, char c)
{
   int i;
   int table[n];
   for(i=0;i<n;i++)
   {
      table[i]=0;
   }

   int max=1;
   for(i=0;i<n;i++)
   {
      max=max*3;
   }
   int smallesttable[3];
   for(i=0;i<3;i++)
   {
      smallesttable[i]=n+1;
   }


   for(i=1;i<max;i++)
   {
      if(i%3==1)
      {
         if(table[0]==0)
         {
            printf("MOVE %c TO %c\n",a,b);
            printf("MOVE %c TO %c\n",b,c);
            i++; table[0]=2;
         }
         else if(table[0]==2)
         {
            printf("MOVE %c TO %c\n",c,b);
            printf("MOVE %c TO %c\n",b,a);
            i++; table[0]=0;
         }
       
      }
      else 
      {  
         if(table[0]==0)
         {
            if(smallesttable[1]<smallesttable[2])
            {
               printf("MOVE %c TO %c\n",b,c);
               table[smallesttable[1]]=2;
            }
            else if(smallesttable[1]>smallesttable[2])
            {
               printf("MOVE %c TO %c\n",c,b);
               table[smallesttable[2]]=1;
            }
         }
         else if(table[0]==2)
         {
            if(smallesttable[0]<smallesttable[1])
            {//printf("help1\n");
               printf("MOVE %c TO %c\n",a,b);
               table[smallesttable[0]]=1;
            }
            else if(smallesttable[0]>smallesttable[1])
            {//printf("help2\n");
               printf("MOVE %c TO %c\n",b,a);
               table[smallesttable[1]]=0;
            }

         }
      }
      //printf("modulo %d\n",i);
      int j; int k;
      //fix smallesttable
      for(k=0;k<3;k++)
      {
         smallesttable[k]=n+1;
      }
      for(j=0;j<n;j++)
      {
         for(k=0;k<3;k++)
         {
            if(table[j]==k && j<smallesttable[k])
            {
               smallesttable[k]=j; 
            }
         }
      }
      for(k=0;k<3;k++)
      {
         //printf(" table %d  %d",smallesttable[k], table[k]);
      }
      //printf("\n");
   }
}


