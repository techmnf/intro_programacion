////////////////////////////////////////////////////
//////////////Fernandez Matias Nicolas//////////////
///////////////////////Tema 1///////////////////////
////////////////////////////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Elem{
  char info[100];
  struct Elem *next;
} TElem;

TElem *q;
int cant;
char msg[100];
char ciudad[100];

void MostrarLista(TElem *l, char x[100]);
void Crear(TElem **l);
void CargarLista(TElem *l, int n);

int main() {
  Crear(&q);
  printf("Cuantos nodos va a agregar?: ");
  
  scanf("%i", &cant);
  CargarLista(q, cant);
  
  printf("¿Que ciudad quiere contar?: ");
  scanf("%s", ciudad);
  MostrarLista(q, ciudad);
  
  return 0;
}

void MostrarLista(TElem *l, char x[100]) {
  TElem *aux = l->next;
  int cont = 0;
  
  while(aux != NULL) {
    if(strcmp(aux->info, x) == 0) {
      cont++;
    }
    aux = aux->next;
  }
  
  printf("%i \n", cont);
}

void Crear(TElem **l) {
  *l = (TElem *) malloc(sizeof(TElem));
  (*l)->next = NULL;
}

void CargarLista(TElem *l, int n) {
  char ciu[100];
  TElem *s;
  
  for(int i = 1; i <= n; i++) {
    scanf("%s", ciu);
    s = (TElem *) malloc(sizeof(TElem));
    strcpy(s->info, ciu);
    s->next = l->next;
    l->next = s;
  }
}
