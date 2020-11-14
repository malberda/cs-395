//check/*********************************************
 * Id: albe6306
 * w20.c
 * this code solves the 20 weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w20 
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>



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


return 0;
}



