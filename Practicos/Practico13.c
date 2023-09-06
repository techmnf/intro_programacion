#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Nodo {
  char info[100];
  struct Nodo *back;
  struct Nodo *next;
} TNodo;

TNodo *r, *s, *t, *p;

void MostrarLista(TNodo *l);

int main() {
  //creación de la lista doblemente encadenada "Hola" "Como" "te" "va?"
  r = (TNodo *) malloc(sizeof(TNodo));
  p = r;
  strcpy(r->info, "va?");
  r->next = NULL;
  r->back = NULL;
  
  t = (TNodo *) malloc(sizeof(TNodo));
  strcpy(t->info, "te");
  t->next = r;
  t->back = NULL;
  r->back = t;
  r = t;
  
  t = (TNodo *) malloc(sizeof(TNodo));
  strcpy(t->info, "Como");
  t->next = r;
  t->back = NULL;
  r->back = t;
  r = t;
  
  t = (TNodo *) malloc(sizeof(TNodo));
  strcpy(t->info, "Hola");
  t->next = r;
  t->back = NULL;
  r->back = t;
  r = t;
  
  // mostramos la lista inicial completa
  MostrarLista(r);
  
  s = r;
  
  
  
  //Creamos e insertamos el nuevo nodo Tito
  t = (TNodo *) malloc(sizeof(TNodo));
  strcpy(t->info, "Tito");
  t->back = s;
  t->next = s->next;
  (t->next)->back = t;
  s->next = t;
  
  // mostramos la lista completa con la insercion del nuevo nodo
  MostrarLista(r);
  
  // Recorremos la lista para encontrar el nodo a modificar
  s = r;
  while(strcmp((s->info), "te") != 0) {
    s = s->next;
  }
  
  // modificamos el nodo reemplazando "te" por "estás?"
  strcpy(s->info, "estas?");
  
  //mostramos la lista completa modificada
  MostrarLista(r);
  
  // buscamos el elemento que queremos eliminar
  s = r;
  while(strcmp(s->info, "va?") != 0) {
    s = s->next;
  }
  
  
  (s->back)->next = NULL;
  p = p->back;
  free(s);
  
  //mostramos la secuencia completa con todas las modificaciones.
  MostrarLista(r);

  return 0;
}

void MostrarLista(TNodo *l) {
  TNodo *aux = l;
  while(aux != NULL) {
    printf("%s", aux->info);
    printf(" ");
    
    aux = aux->next;
  }
  printf("\n");
}
