#include<stdio.h>
#include<stdlib.h>

typedef struct TNodo1 {
  int info;
  struct TNodo1 *next;
} TNodo;

TNodo *q;
TNodo *r;
TNodo *s;
TNodo *t;
TNodo *p;

int main() {
  q = (TNodo *) malloc(sizeof(TNodo));
  q->info = 14;
  q->next = NULL;
  
  s = (TNodo *) malloc(sizeof(TNodo));
  s->info = 25;
  s->next = q;
  q = s;
  
  s = (TNodo *) malloc(sizeof(TNodo));
  s->info = 20;
  s->next = q;
  q = s;
  
  s = (TNodo *) malloc(sizeof(TNodo));
  s->info = 11;
  s->next = q;
  q = s;
  
  
  r = q;
  r = r->next;
  t = r->next;
  
  s = (TNodo *) malloc(sizeof(TNodo));
  s->info = 3;
  s->next = r->next;
  r->next = s;
  p = s;
  
  t->info = 29;
  printf("%i", t->info);
  printf("\n");
  
  
  r = q;
  while(r != NULL) {
    printf("%i ", r->info);

    r = r->next;
  }
  printf("\n");
  
  return 0;
}
