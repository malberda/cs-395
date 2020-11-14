/*********************************************
 * Id: albe6306
 * w16.c
 * this solves the convex hull problem
 * /y/shared/Engineering/cs-drbc/submit ? cs395 w16 
 *********************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
 
typedef struct Point {
   int x, y;
} Point;
 
typedef struct Node {
   Point data;
   struct Node *next;
} Node;
int comp(const void *lhs, const void *rhs);
bool side(const Point *a, const Point *b, const Point *c);
void freeNode(Node *ptr);
Node* addback(Node *ptr, Point data);
void print(Node *ptr);
Node* convexHull(int len, Point p[]);

int main(int argc, char *argv[])
{
   int length=(argc-1)/2;
   int i,j;
   j = 1;
   Point points[length];
   for(i=1;i<=length;i++){
      Point temps = {atoi(argv[j]),atoi(argv[j+1])};
      points[i-1] = temps;
      //printf("%d, %d ", atoi(argv[j]),atoi(argv[j+1]));
      j = j +2;
   }
   Node *hull = convexHull(sizeof(points) / sizeof(Point), points);
   printf("The points in Convex Hull are:\n");
   print(hull);
   printf("\n");
   freeNode(hull);
   hull = NULL;
   return 0;
}
//find side function
bool side(const Point *a, const Point *b, const Point *c) {
   return (b->x - a->x) * (c->y - a->y) > (b->y - a->y) * (c->x - a->x);
}
//comparison function 
int comp(const void *lhs, const void *rhs) {
   Point lp = *((Point *)lhs);
   Point rp = *((Point *)rhs);
   if (lp.x < rp.x) return -1;
   if (rp.x < lp.x) return 1;
   return 0;
}
//frees nodes 
void freeNode(Node *ptr) {
   if (ptr == NULL) {
      return;
   }
 
   freeNode(ptr->next);
   ptr->next = NULL;
   free(ptr);
}
//pushes nodes 
Node* addback(Node *ptr, Point data) {
   Node *tmp = ptr;
 
   if (ptr == NULL) {
      ptr = (Node*)malloc(sizeof(Node));
      ptr->data = data;
      ptr->next = NULL;
      return ptr;
   }
   while (tmp->next != NULL) {
      tmp = tmp->next;
   }
 
   tmp->next = (Node*)malloc(sizeof(Node));
   tmp->next->data = data;
   tmp->next->next = NULL;
   return ptr;
}

//removes nodes 
Node* deletenode(Node *ptr) {
   Node *tmp = ptr;
 
   if (ptr == NULL) {
      return NULL;
   }
   if (ptr->next == NULL) {
      free(ptr);
      return NULL;
   }
 
   while (tmp->next->next != NULL) {
      tmp = tmp->next;
   }
 
   free(tmp->next);
   tmp->next = NULL;
   return ptr;
}

//prints everything 
void print(Node *ptr) {
   int length;
   Node *tmptr=ptr;
   while (tmptr != NULL) {
      length++;
      tmptr = tmptr->next;
   }
   int printergoesbrr[length][2];
   int i=0;
   while (ptr != NULL) {
      printergoesbrr[i][0]=ptr->data.x;
      printergoesbrr[i][0]=ptr->data.y;
      i++;
      ptr = ptr->next;
   }
   
   for(i=length;i>0;i--)
   {
      printf("(%d, %d)", printergoesbrr[i][0], printergoesbrr[i][1]);
   }
}

// convex hull prob 
Node* convexHull(int len, Point p[]) {
   Node *h = NULL;
   Node *hptr = NULL;
   size_t hLen = 0;
   int i;
   qsort(p, len, sizeof(Point), comp);
 
   // negative size 
   for (i = 0; i < len; ++i) {
      while (hLen >= 2) {
         hptr = h;
         while (hptr->next->next != NULL) {
            hptr = hptr->next;
         }
         if (side(&hptr->data, &hptr->next->data, &p[i])) {
            break;
         }
 
         h = deletenode(h);
         hLen--;
      }
 
      h = addback(h, p[i]);
      hLen++;
   }
 
   // positive side 
   for (i = len - 1; i >= 0; i--) {
      while (hLen >= 2) {
         hptr = h;
         while (hptr->next->next != NULL) {
            hptr = hptr->next;
         }
         if (side(&hptr->data, &hptr->next->data, &p[i])) {
            break;
         }
 
         h = deletenode(h);
         hLen--;
      }
 
      h = addback(h, p[i]);
      hLen++;
   }
 
   deletenode(h);
   return h;
}
 
