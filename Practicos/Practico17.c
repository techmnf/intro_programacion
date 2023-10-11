#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100

typedef struct {
  int a[MAX];
  int cant;
} TData;

time_t t;
TData datos;
int i;

void InicializacionR(TData *d);
void Burbuja(TData *d);

int main() {
  printf("Ingrese la cantidad de elementos a cargar: ");
  scanf("%d", &(datos.cant));
  
  InicializacionR(&datos);
  
  printf("Datos sin ordenar: ");
  for(int i = 0; i < datos.cant; i++) {
    printf("%d ", datos.a[i]);
  }
  printf("\n");
  
  Burbuja(&datos);
  
  printf("Datos ordenados: ");
  for(int i = 0; i < datos.cant; i++) {
    printf("%d ", datos.a[i]);
  }
  printf("\n");
  return 0;
}

void InicializacionR(TData *d) {
  int i;
  srand((unsigned) time(&t));
  for(i = 0; i < d->cant; i++) {
    d->a[i] = rand()%100 +1;
  }
}

void Burbuja(TData *d) {
  for(int i = (d->cant)-1; i >= 0; i--) {
    for(int j = 0; j < i; j++) {
      if(d->a[j] > d->a[j+1]) {
        d->a[j] = d->a[j] + d->a[j+1];
        d->a[j+1] = d->a[j] - d->a[j+1];
        d->a[j] = d->a[j] - d->a[j+1];
      }
    }
  }
}
