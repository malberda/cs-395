/*********************************************
 * Id: albe6306
 * w08.c
 * this code solves the 8th weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w08  
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
int BFSM(char T[], char P[], int tlen, int plen, int startpos);
//main function, takes input from user on command line and runs the tower of hanoi problem
int main(int argc, char *argv[])
{
   int q;
   int i;
   printf("Matches found at locations:");
   for(i=0;i<strlen(argv[2]);i++)
   { 
      q=-1;
      q=BFSM(argv[2], argv[1], strlen(argv[2]), strlen(argv[1]), i);
      if(q!=-1)
      {
         printf(" %d",q);
      }
   }
   printf("\n");

   
   return 0;
}

//actual pattern matching code
int BFSM(char T[], char P[], int tlen, int plen, int startpos)
{
   int i;
   int j;
   for(i=startpos;i<=tlen-plen;i++)
   {
      j=0;
      while((j<plen) && (P[j]==T[i+j]))
      {
         j=j+1;
      }
      if(j==plen && i==startpos)
      {
         return i;
      }
   }
   return -1;
   
}