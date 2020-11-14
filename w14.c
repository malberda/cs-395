/*********************************************
 * Id: albe6306
 * w14.c
 * this code solves the 14th weekly problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w14 
 *********************************************/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX_ALPHABET 128
#define TABLE_ROW_LENGTH 16
#define MIN_WRITEABLE 32

int *shifttable(char needle[], int size);
int horspoolmatching(char needle[], char haystack[], int sizen, int sizeh);
void printshifttable( int table[]);

//main function, takes input from user on command line and runs the Horspool algorithm
int main(int argc, char *argv[])
{

   int q;
   q=horspoolmatching(argv[1], argv[2], strlen(argv[1]), strlen(argv[2]));

   return q;
   
   return 0;
}

//creates shifttable
int *shifttable(char needle[], int size)
{  
   int *table=malloc(sizeof(int)*MAX_ALPHABET);
   int i, j;
   for(i=0;i<=MAX_ALPHABET-1;i++)
   {
      table[i]=size;
   }
   for(j=0;j<=size-2;j++)
   {
      table[(int)needle[j]]=size-1-j;
   }
   printshifttable(table);
   return table;
}

//actual pattern matching code
int horspoolmatching(char needle[], char haystack[], int sizen, int sizeh)
{
   int i,k,m,j,n;
   int matches[sizeh];
   int matchnum;
   matchnum=0;
   k=0;
   j=0;
   n=sizeh;
   m=sizen;
   int *p;
   p=shifttable(needle, sizen);
   printf("%s\n", haystack);
   i=m-1;
   while(i<=n-1)
   {
     
      k=0;
      while((k<=m-1) && (needle[m-1-k]==haystack[i-k]))
      {
         k++;

      }
      if(k!=m)
      {
         printf("%*s%s\n", i-m+1,"", needle);
      }
      if(k==m)
      {
         matchnum++;
         matches[j]=i;
         j++;
         printf("%*s%s---found\n", i-m+1,"", needle);
      }
      i=i+p[(int)haystack[i]];

   }
   printf("Matches found at locations:");
   for(i=0;i<matchnum;i++)
   {
      printf(" %d",matches[i]-2);
   }
   printf("\n");
   return -1;

}






//print function
void printshifttable(int table[])
{
   int i, start;
   for(start=MIN_WRITEABLE;start<MAX_ALPHABET;start+=TABLE_ROW_LENGTH)
   {
      for(i=start;i<start+TABLE_ROW_LENGTH;i++)
      {
         printf("%c\t",i);
      }
      printf("\n");

      for(i=start;i<start+TABLE_ROW_LENGTH;i++)
      {
         printf("%d\t",table[i]);
      }
      printf("\n\n");
   
   }
}


